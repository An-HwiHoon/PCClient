/**
 * @file connection.c Connection API
 * @ingroup core
 */

/* purple
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */
#define _PURPLE_CONNECTION_C_

#include "internal.h"
#include "account.h"
#include "blist.h"
#include "connection.h"
#include "dbus-maybe.h"
#include "debug.h"
#include "log.h"
#include "notify.h"
#include "prefs.h"
#include "proxy.h"
#include "request.h"
#include "server.h"
#include "signals.h"
#include "util.h"


#include "cJSON.h"
//#include "gtkblist.h"

#define CURL_STATICLIB
#include <curl/curl.h>
#include <json/json.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <time.h>

#define KEEPALIVE_INTERVAL 30

static GList *connections = NULL;
static GList *connections_connecting = NULL;
static PurpleConnectionUiOps *connection_ui_ops = NULL;

static int connections_handle;

struct jsonstr{
	int           code;
	char           extNum[33];
	char           sipId[33];
	char           sipPassword[33];
	char           domain[33];
	char           proxy[33];
	char           usrGrpIdx[33];
};

void json_parse_array(json_object *jobj, char *key, PurpleAccount * account); 
struct jsonstr jsonparser(char *buff)
{
	struct jsonstr re;
	json_object *myobj;//
//	json_object *headerobj;
	json_object *dataobj;//
//	json_object *dobj;
	json_object *dval;//

	/* JSON type의 데이터를 읽는다. */
	myobj = json_tokener_parse(buff);
	dataobj   = json_object_object_get(myobj, "result");

	//구조체
	dval = json_object_object_get(dataobj, "code");
	re.code = json_object_get_int(dval);
	if(re.code==100)
	{		
		dval = json_object_object_get(dataobj, "extNum");
		strcpy(re.extNum ,json_object_get_string(dval));
												
		dval = json_object_object_get(dataobj, "sipId");
		strcpy(re.sipId ,json_object_get_string(dval));

		dval = json_object_object_get(dataobj, "sipPassword");
		strcpy(re.sipPassword ,json_object_get_string(dval));

		dval = json_object_object_get(dataobj, "domain");
		strcpy(re.domain ,json_object_get_string(dval));

		dval = json_object_object_get(dataobj, "usrGrpIdx");
		strcpy(re.usrGrpIdx ,json_object_get_string(dval));

		dval = json_object_object_get(dataobj, "proxy");
		strcpy(re.proxy ,json_object_get_string(dval));
	}

	return re;
};
////////////추가
int groupvalue=0;//그룹확인 변수
int uservalue=0;//유저확인 변수
int catevalue=0;//중그룹확인 변수
char* decryptbuddy(char *buddyusr);
char buddyaddgroup1[128];
char buddyaddgroup2[64];
char buddyaddjid[64];
char buddyaddname[64];
int countbuddy=0;
int countgroup=0;
char charcountbuddy[16];
char charcountgroup[16];
int blistdelet=1;

static int cJSON_strcasecmp(const char *s1,const char *s2)
{
	if (!s1) return (s1==s2)?0:1;if (!s2) return 1;
	for(; tolower(*s1) == tolower(*s2); ++s1, ++s2)	if(*s1 == 0)	return 0;
	return tolower(*(const unsigned char *)s1) - tolower(*(const unsigned char *)s2);
}

PurpleBuddy *jsonbuddy;
PurpleGroup *jsong;


void json_parsek(json_object * jobj, PurpleAccount * account); /*Forward Declaration*/
void json_parse_array1( json_object *jobj, char *key, PurpleAccount * account) {
	enum json_type type;

	json_object *jarray = jobj; /*Simply get the array*/
	if(key) {
		jarray = json_object_object_get(jobj, key); /*Getting the array if it is a key value pair*/
	}

	int arraylen = json_object_array_length(jarray); /*Getting the length of the array*/
	int i;
	json_object * jvalue;

	for (i=0; i< arraylen; i++){
		jvalue = json_object_array_get_idx(jarray, i); /*Getting the array element at position i*/
		type = json_object_get_type(jvalue);
		if (type == json_type_array) {
			json_parse_array1(jvalue, NULL, account);
		}
		else if (type != json_type_object) {
//			print_json_value(jvalue);
		}
		else {
			json_parsek(jvalue, account);
		}
    }
}

char* timeToString(struct tm *t) {
	static char s[20];

	sprintf(s, "%04d%02d%02d%02d%02d%02d",
		t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
		t->tm_hour, t->tm_min, t->tm_sec
	);

	return s;
}


//void json_parsej(json_object * jobj, PurpleAccount * account) {

void json_parsek(json_object * jobj, PurpleAccount * account) {
	enum json_type type;
	struct tm *t;
	time_t timer;


	json_object_object_foreach(jobj, key1, val1) { /*Passing through every array element*/
		type = json_object_get_type(val1);

		switch (type) {
			case json_type_boolean:
			case json_type_double:
			case json_type_int:
			case json_type_string:
			if(strcmp(key1,"changeFlag")==0)//조직도 변환
			{
				if(strcmp(json_object_get_string(val1),"N")==0)
				{
					purple_debug_warning("anhh", "[%s:%d(%s)] 조직도 변화 없음 @debug \n", __FILE__, __LINE__, __func__);
//					purple_blist_load();
					return 0;
				}
				else if(blistdelet == 1)
				{
			//		PurpleBuddyList *a = purple_get_blist();
			//		PurpleBlistNode *b = purple_blist_get_root();
					purple_debug_warning("anhh", "[%s:%d(%s)] 조직도 변화 있음 @debug \n", __FILE__, __LINE__, __func__);
//					printf("blist 삭제 \n");

//					purple_blist_node_destroy(purple_blist_get_root());	
/*					const char *user_dir = purple_user_dir();
					gchar *filename_full;

				
					filename_full = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", user_dir, "blist.xml");
					if(strstr(filename_full, "blist.xml")!=NULL)
					{
						printf("%s\n",filename_full);
						printf("%d\n",g_remove(filename_full));
						printf("삭제=========\n");
					}
*/
//					purple_blist_destory();
//					purple_blist_uninit();
//					purple_set_blist(purple_blist_new());

					blistdelet = 0;
				}
			}
		}
	}    

	purple_debug_warning("anhh", "[%s:%d(%s)] 조직도 추가 @debug \n", __FILE__, __LINE__, __func__);
	json_object_object_foreach(jobj, key, val) { /*Passing through every array element*/
//		      printf("type: ",type);
//		      printf("json_parse\n%s \n",key);
		type = json_object_get_type(val);
//		      printf("key = %s\n",key);

		switch (type) {
			case json_type_boolean:
			case json_type_double:
			case json_type_int:
			case json_type_string:
				if(strcmp(key,"identity") == 0)
				{
					groupvalue = strlen(json_object_get_string(val));
					groupvalue = (groupvalue/2)-2;
					purple_debug_warning("anhh", "[%s:%d(%s)] groupvalue : %d @debug \n", __FILE__, __LINE__, __func__,groupvalue);
//					printf("%d\n",groupvalue);
				}
				else if(strcmp(key, "jid") == 0)
				{
//					printf("key : %s \n", decryptbuddy(json_object_get_string(val)));
					purple_debug_warning("anhh", "[%s:%d(%s)] 조직원 key : %s @debug \n", __FILE__, __LINE__, __func__,decryptbuddy(json_object_get_string(val)));
					strcpy(buddyaddjid, decryptbuddy(json_object_get_string(val)));
					uservalue = 1;
				}
				else if(groupvalue == 1)//그룹
				{
					if(strcmp(key, "name")==0)// || strcmp(key, "usrList")==0 || strcmp(key, "orgChartList")==0)        
					{
//						printf("catevalue = %d\n",catevalue);
//						printf("그룹 key = %s\n",key);
//						printf("group1: %s \n", json_object_get_string(val));
						purple_debug_warning("anhh", "[%s:%d(%s)] 그룹 key : %s @debug \n", __FILE__, __LINE__, __func__,key);

						countgroup++;

//						printf("그룹수 : %d\n",countgroup);
				
						sprintf(charcountgroup,"%d",countgroup);	
						purple_account_set_string(account,"lastgroup", charcountgroup);

						strcpy(buddyaddgroup2,json_object_get_string(val));
						printf("buddyaddgroup1: %s \n",buddyaddgroup2);
					
						groupvalue = 0;
						catevalue++;
					}
				}
				else if(groupvalue == 2)//그룹
				{
					if(strcmp(key, "name")==0)// || strcmp(key, "usrList")==0 || strcmp(key, "orgChartList")==0)        
					{
//						printf("catevalue = %d\n",catevalue);
//						printf("그룹 key = %s\n",key);
//						printf("group2: %s \n", json_object_get_string(val));

						countgroup++;

//						printf("그룹수 : %d\n",countgroup);

						sprintf(charcountgroup,"%d",countgroup);	
						purple_account_set_string(account,"lastgroup", charcountgroup);
	
						strcpy(buddyaddgroup1,buddyaddgroup2);
						strcat(buddyaddgroup1,"/");
						strcat(buddyaddgroup1,json_object_get_string(val));

//						printf("buddyaddgroup2: %s \n",buddyaddgroup1);
						purple_debug_warning("anhh", "[%s:%d(%s)] 조직도 그룹생성 @debug \n", __FILE__, __LINE__, __func__);

						jsong = purple_group_new(buddyaddgroup1);	

						//purple_group_destroy(jsong);
						//purple_blist_remove_group(jsong);

						groupvalue = 0;
						catevalue++;
					}
				}
									
				else if(uservalue == 1)//유저
				{
					if(strcmp(key, "name")==0)// || strcmp(key, "usrList")==0 || strcmp(key, "orgChartList")==0)        
					{
//						printf("name : %s\n",decryptbuddy(json_object_get_string(val)));
					
						strcpy(buddyaddname,decryptbuddy(json_object_get_string(val)));
						

						purple_debug_warning("anhh", "[%s:%d(%s)] 친구 추가 %s @debug \n", __FILE__, __LINE__, __func__,buddyaddname);
						jsonbuddy = purple_buddy_new(account, buddyaddjid, buddyaddname);
						purple_blist_add_buddy(jsonbuddy, NULL, jsong, NULL);
						purple_account_add_buddy_with_invite(account,jsonbuddy,NULL );

						countbuddy++;
//						printf("buddy수 : %d\n",countbuddy);

						purple_debug_warning("anhh", "[%s:%d(%s)] 버디 수 : %d @debug \n", __FILE__, __LINE__, __func__,countbuddy);
						sprintf(charcountbuddy,"%d",countbuddy);	
						purple_account_set_string(account,"lastbuddy", charcountbuddy);


						timer = time(NULL);    // 현재 시각을 초 단위로 얻기
				    	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

//			  			printf("%s\n", timeToString(t));		

						purple_account_set_string(account,"lastblist", timeToString(t));

	
						uservalue = 0;
						catevalue= 1;

					}
				}
				else if(strcmp(key,"changeFlag")==0)//조직도 변환
				{
					if(strcmp(json_object_get_string(val),"N")==0)
					{
						purple_debug_warning("anhh", "[%s:%d(%s)] 조직도 변화 없음 @debug \n", __FILE__, __LINE__, __func__);
						return 0;
					}
				}
									break;
			case json_type_object: //printf("json_type_object\n");
									jobj = json_object_object_get(jobj, key);
									json_parsek(jobj, account);
									break;
			case json_type_array: //printf("type: json_type_array, ");
									json_parse_array1(jobj, key, account);
									break;
		}
    }

	purple_debug_warning("anhh", "[%s:%d(%s)] 조직도 로드 @debug \n", __FILE__, __LINE__, __func__);
	purple_blist_load();

}






/////////////////whwlreh
//void json_parse_array(json_object *jobj, char *key, PurpleAccount * account); 
struct jsonstring{
	char           jid[65];
	char           name[33];
};
  
char* print_json_value1(json_object *jobj){//(char *key1, json_object *jobj){
	enum json_type type;
	    
	return json_object_get_string(jobj);
}	

//void json_parsej(json_object * jobj, PurpleAccount * account) {
//	enum json_type type;
//	struct jsonstring* rel;
//	char *inname;
//	char *injid;
//	int idval=0;
//	int i;
								
//	json_object_object_foreach(jobj, key, val) { /*Passing through every array element*/
//		type = json_object_get_type(val);
//		switch (type) {
//			case json_type_object: printf("json_type_objectn");
//			     jobj = json_object_object_get(jobj, key);
//			     json_parsej(jobj, account); 
//			     break;
//			case json_type_array: printf("type: json_type_array, ");
//				 json_parse_array(jobj, key, account);
//				 break;
 //		}
//	}
//}

//struct jsonstring json_parse1(json_object * jobj, PurpleAccount * account) {
//	enum json_type type;
//	struct jsonstring re;
//	char *inname;
//	char *injid;
//	int idval=0;
//							
//	json_object_object_foreach(jobj, key, val) { /*Passing through every array element*/
//		type = json_object_get_type(val);
/*		switch (type) {
			case json_type_boolean: 
			case json_type_double: 
			case json_type_int: 
			case json_type_string:
				if(strcmp(key ,"jid") == 0)
			 	{
					idval = 1;
					strcpy(re.jid, print_json_value1(val));
				}
				else if(strcmp(key ,"name") == 0)
				{
					strcpy(re.name, print_json_value1(val));
				}
			    break; 
			case json_type_object: printf("json_type_objectn");
			     jobj = json_object_object_get(jobj, key);
			     json_parsej(jobj, account); 
				 break;
		}
	}
	return re;
}
*/

char* decryptbuddy(char *buddyusr)
{
	EVP_CIPHER_CTX  de;
	char    *key="fe8025947de7cd71";
	char	*data,*ptr;
	char    buf[80];
	int     datasize,c;
	int     p_len,f_len=0;
	char    *plaintext;
									
	data=malloc(strlen(buddyusr));
	for(ptr=buddyusr,c=0;*ptr!='\0';ptr+=2,c++){
		buf[0]=*ptr;
		buf[1]=*(ptr+1);
		buf[2]='\0';
		data[c]=strtol(buf,NULL,16);
	}

	datasize=c;
	EVP_CIPHER_CTX_init(&de);
	EVP_DecryptInit_ex(&de,EVP_aes_128_ecb(),NULL,(unsigned char *)key,NULL);
	p_len=datasize;
	plaintext=calloc(p_len+1,sizeof(char));
	EVP_DecryptUpdate(&de,(unsigned char *)plaintext,&p_len,(unsigned char *)data,datasize);
	EVP_DecryptFinal_ex(&de,(unsigned char *)(plaintext+p_len),&f_len);
																		
	plaintext[p_len+f_len]='\0';
																			
	EVP_CIPHER_CTX_cleanup(&de);
	return plaintext;
}


/*
void json_parse_array(json_object *jobj, char *key, PurpleAccount * account) {
	enum json_type type;

	json_object *jarray = jobj; /*Simply get the array*/
/*	if(key) {
		jarray = json_object_object_get(jobj, key); /*Getting the array if it is a key value pair*/
/*	}
	int arraylen = json_object_array_length(jarray); /*Getting the length of the array*/
/*	printf("Array Length: %d\n",arraylen);
	int i;
	struct jsonstring *re = (struct jsonstring *)malloc(sizeof(struct jsonstring)*arraylen);
									
	PurpleBuddy *buddy;
	json_object * jvalue;
	PurpleGroup *g;

//	purple_blist_destory();
//	purple_set_blist(purple_blist_new());
	g = purple_group_new("buddy");
													
	for (i=0; i< arraylen; i++){
		jvalue = json_object_array_get_idx(jarray, i); /*Getting the array element at position i*/
/*		type = json_object_get_type(jvalue);

		if (type == json_type_array) {
			json_parse_array(jvalue, NULL, account);
		}
		else if (type != json_type_object) {
		    printf("value[%d]: ",i);
		}
		else {
			printf("array[%d]\n",i);
			re[i] = json_parse1(jvalue, account);
			printf("%s\n%s\n",re[i].jid,re[i].name);
			printf("=======\n");
			printf("jid:%s\nname:%s\n",decryptbuddy(re[i].jid), decryptbuddy(re[i].name));
			printf("=======\n");
			//durltj cheo 
			//add_buddy_cb(account, decryptbuddy(re[i].jid), decryptbuddy(re[i].name));

			//add_orgchart_cb(account, decryptbuddy(re[i].jid), decryptbuddy(re[i].name));
			if(strncmp(account->username, decryptbuddy(re[i].jid), 10))
			{
				purple_debug_warning("anhh", "[%s:%d(%s)] jid account: %s json: %s   @debug \n", __FILE__, __LINE__, __func__,account->username, decryptbuddy(re[i].jid));
				buddy = purple_buddy_new(account, decryptbuddy(re[i].jid), decryptbuddy(re[i].name));
				purple_blist_add_buddy(buddy, NULL, g, NULL);
				purple_account_add_buddy_with_invite(account,buddy,NULL );
				//gtkblist.c
//				if (decryptbuddy(re[i].name) != NULL && g != NULL)
//	            gtk_blist_auto_personize((PurpleBlistNode *)g, decryptbuddy(re[i].name));

	
				//
			}
		}
	}
	purple_blist_load();
}
*/

///////////////////
struct url_data {
    size_t size;
    char* data;
};
 
size_t write_data(void *ptr, size_t size, size_t nmemb, struct url_data *data) {
    size_t index = data->size;
    size_t n = (size * nmemb);
    char* tmp;
    data->size += (size * nmemb);
    tmp = realloc(data->data, data->size + 1); /* +1 for '\0' */
    if(tmp) {
        data->data = tmp;
    } else {
        if(data->data) {
            free(data->data);
        }
        fprintf(stderr, "Failed to allocate memory.\n");
		return 0;
	}
	memcpy((data->data + index), ptr, n);
	data->data[data->size] = '\0';
	return size * nmemb;
}
 
char *handle_url(char* url, char* para) {
	CURL *curl;
		 
	struct url_data data;
	data.size = 0;
	data.data = malloc(4096); /* reasonable size initial buffer */
	if(NULL == data.data) {
		fprintf(stderr, "Failed to allocate memory.\n");
		return NULL;
	}
						 
	data.data[0] = '\0';
							 
	CURLcode res;
								 
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, para);
																	
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK) {
		    fprintf(stderr, "curl_easy_perform() failed: %s\n", 
		    curl_easy_strerror(res));
	    }
																							 
	    curl_easy_cleanup(curl);
								 
    }
	return data.data;
}




static gboolean
send_keepalive(gpointer data)
{
	PurpleConnection *gc = data;
	PurplePluginProtocolInfo *prpl_info;

	/* Only send keep-alives if we haven't heard from the
	 * server in a while.
	 */
	if ((time(NULL) - gc->last_received) < KEEPALIVE_INTERVAL)
		return TRUE;

	prpl_info = PURPLE_PLUGIN_PROTOCOL_INFO(gc->prpl);
	if (prpl_info->keepalive)
		prpl_info->keepalive(gc);

	return TRUE;
}

static void
update_keepalive(PurpleConnection *gc, gboolean on)
{
	PurplePluginProtocolInfo *prpl_info = NULL;

	if (gc != NULL && gc->prpl != NULL)
		prpl_info = PURPLE_PLUGIN_PROTOCOL_INFO(gc->prpl);

	if (!prpl_info || !prpl_info->keepalive)
		return;

	if (on && !gc->keepalive)
	{
		purple_debug_info("connection", "Activating keepalive.\n");
		gc->keepalive = purple_timeout_add_seconds(KEEPALIVE_INTERVAL, send_keepalive, gc);
	}
	else if (!on && gc->keepalive > 0)
	{
		purple_debug_info("connection", "Deactivating keepalive.\n");
		purple_timeout_remove(gc->keepalive);
		gc->keepalive = 0;
	}
}

void
purple_connection_new(PurpleAccount *account, gboolean regist, const char *password)
{
	_purple_connection_new(account, regist, password);
}

void
_purple_connection_new(PurpleAccount *account, gboolean regist, const char *password)
{
	PurpleConnection *gc;
	PurplePlugin *prpl;
	PurplePluginProtocolInfo *prpl_info;

	char *data;
//	char* url = "27.1.48.149/api/login.do";
	char url[30]="";
//	char url[64]="";
	char id[33]="";
	char pass[33];
	char para[112] = "id=";
//	char para[256] = "id=";
	struct jsonstr re;
	int i=0;
	char *ptr;

    EVP_CIPHER_CTX  en;
	char    *key="fe8025947de7cd71";
	int     datasize;
	int     c_len,f_len=0;
	unsigned char   *ciphertext;
	char enval[33];
	char enval1[65];
	char vval[3];
	//
//	PurpleBuddy *buddy;
//	PurpleGroup *g;

    char* data1;//json 받아오는 변수
    char* url1 = "http://27.1.48.149/api/test/userList.do";
    char *ptr1=NULL;
    int count=0;
	int val=1;

	//
//	char *url2 = "http://27.1.48.153/api/newOrgChart.do";	
	char url2[50];// = "http://27.1.48.153/api/newOrgChart.do";	
//	char *test="usrGrpIdx=e615309652fadb7e471603bf6870be91&checkUpdateTime=ba1fc00a180c98056e900a481eed23d2";
	char test[160]="usrGrpIdx=e615309652fadb7e471603bf6870be91&checkUpdateTime=92742ad2ef70575a5db9f440a86a2b248bd16bac1c28e713a7535d7a0a3ddf63";
//	char *test="usrGrpIdx=e615309652fadb7e471603bf6870be91&checkUpdateTime=9d5186471bf8f5777ca6be66a678c0c4";
	char *data2;
	char test1[32];
	//account에서 id, pass, url 가져와야됨
	strcpy(id,account->username);

	ptr = strtok(id,"@");

	while((ptr=strtok(NULL,"@")))
	{
		if(i == 0)
		{
			strcpy(url,ptr);
			strcat(url,"api/login.do");
			strcpy(url2,ptr);
			strcat(url2,"api/newOrgChart.do");
			i++;
		}
	}
//9d5186471bf8f5777ca6be66a678c0c4
	
//	strcpy(buddyaddaccount, account);

//		purple_debug_warning("anhh", "[%s:%d(%s)] id:%s, url:%s  @debug \n", __FILE__, __LINE__, __func__,id,url);

//		strcpy(pass,account->password);
//		purple_debug_warning("anhh", "[%s:%d(%s)] 암호화 전 id: %s pass : %s  @debug \n", __FILE__, __LINE__, __func__,id,pass);

	purple_debug_warning("anhh", "[%s:%d(%s)] id:%s, url:%s  @debug \n", __FILE__, __LINE__, __func__,id,url);
	
	strcpy(pass,account->password);

	purple_debug_warning("anhh", "[%s:%d(%s)] 암호화 전 id: %s pass : %s  @debug \n", __FILE__, __LINE__, __func__,id,pass);
//test
	printf("=========\n %s\n",purple_account_get_string(account,"lastblist","0"));
	printf(" %s\n",purple_account_get_string(account,"lastgroup","0"));
	printf(" %s\n===============\n",purple_account_get_string(account,"lastbuddy","0"));


	strcpy(test1,purple_account_get_string(account,"lastblist","0"));
	strcat(test1,"/");
	strcat(test1,purple_account_get_string(account,"lastgroup","0"));
	strcat(test1,"/");
	strcat(test1,purple_account_get_string(account,"lastbuddy","0"));

//test1 = "0/0/0";
//	test1 = "1234567891";
	enval1[64]='\0';
//	enval[32]='\0';
	datasize=strlen(test1);
    EVP_CIPHER_CTX_init(&en);
    EVP_EncryptInit_ex(&en,EVP_aes_128_ecb(),NULL,(unsigned char *)key,NULL);
    c_len=datasize+EVP_MAX_BLOCK_LENGTH;
    ciphertext=calloc(c_len,sizeof(char));
    EVP_EncryptUpdate(&en,(unsigned char *)ciphertext,&c_len,(unsigned char *)test1,datasize);
    EVP_EncryptFinal_ex(&en,(unsigned char *)(ciphertext+c_len),&f_len);

	for(i = 0;i<64;i++)
	{
		enval1[i]='\0';
	}

//printf("1:%s\n",ciphertext);

	if(strcmp(test1,"0/0/0")==0)
	{
		for(i = 0; i<16;i++)
		{
			printf("%02x\n",ciphertext[i]);
			sprintf(vval, "%02x",ciphertext[i]);
			if(i == 0)
			{
				strcpy(enval1, vval);
	        }
	        else
	        {
		        strcat(enval1,vval);
	        }
		}
	}
	else
	{
		for(i = 0; i<32;i++)
	    {
		    printf("%02x\n",ciphertext[i]);
		    sprintf(vval, "%02x",ciphertext[i]);
			if(i == 0)
			{
				strcpy(enval1, vval);
	        }
	        else
	        {
		        strcat(enval1,vval);
	        }
		}
	}
	printf("1:%s\n",enval1);
	printf("2:%s\n",decryptbuddy(enval1));

//  
	//ID암호화 시작
	enval[32]='\0';
	datasize=strlen(id);
    EVP_CIPHER_CTX_init(&en);
    EVP_EncryptInit_ex(&en,EVP_aes_128_ecb(),NULL,(unsigned char *)key,NULL);
    c_len=datasize+EVP_MAX_BLOCK_LENGTH;
    ciphertext=calloc(c_len,sizeof(char));
    EVP_EncryptUpdate(&en,(unsigned char *)ciphertext,&c_len,(unsigned char *)id,datasize);
    EVP_EncryptFinal_ex(&en,(unsigned char *)(ciphertext+c_len),&f_len);
	for(i = 0; i<16;i++)
    {
	    sprintf(vval, "%02x",ciphertext[i]);
		if(i == 0)
		{
			strcpy(enval, vval);
        }
        else
        {
	        strcat(enval,vval);
        }
	}
//    printf("%s\n",enval);
    free(ciphertext);
    EVP_CIPHER_CTX_cleanup(&en);

	strcpy(id,enval);//암호화된 ID 넣으면 됨

	//PASS암호화 시작
	enval[32]='\0';
	datasize=strlen(pass);
    EVP_CIPHER_CTX_init(&en);
    EVP_EncryptInit_ex(&en,EVP_aes_128_ecb(),NULL,(unsigned char *)key,NULL);
    c_len=datasize+EVP_MAX_BLOCK_LENGTH;
    ciphertext=calloc(c_len,sizeof(char));
    EVP_EncryptUpdate(&en,(unsigned char *)ciphertext,&c_len,(unsigned char *)pass,datasize);
    EVP_EncryptFinal_ex(&en,(unsigned char *)(ciphertext+c_len),&f_len);
	for(i = 0; i<16;i++)
    {
	    sprintf(vval, "%02x",ciphertext[i]);
		if(i == 0)
		{
			strcpy(enval, vval);
        }
        else
        {
	        strcat(enval,vval);
        }
	}
//    printf("%s\n",enval);
    free(ciphertext);
    EVP_CIPHER_CTX_cleanup(&en);

	strcpy(pass,enval);//암호화된 패스워드 넣으면됨
	
	purple_debug_warning("anhh", "[%s:%d(%s)] 암호화 후 id : %s pass : %s @debug \n", __FILE__, __LINE__, __func__,id,pass);

	strcat(para,id);
	strcat(para,"&pass=");
	strcat(para,pass);
	strcat(para,"&uuid=");
	strcat(para,pass);

//		re = jsonparser(data);

	purple_debug_warning("anhh", "[%s:%d(%s)] parameter : %s  @debug \n", __FILE__, __LINE__, __func__,para);

//	printf("%s\n",para);
										
	data = handle_url(url,para);
    printf("--- http 접속 ---\n\n");	
    if(data) {
        printf("%s\n", data);
    }
/*
	data2 = handle_url(url2,test);
    printf("--- http11 접속 ---\n\n");	
    if(data2) {
        printf(" data2 : \n%s\n", data2);
    }
*/

	re = jsonparser(data);

	if(re.code == 100)
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug json 접속 !!!\n", __FILE__, __LINE__, __func__);
		///////////////////////////////
/*
		data1 = handle_url(url1, NULL);
		printf("--- http 접속 ---\n\n");
		if(data1) {
			printf("%s\n", data1);
		}

		printf("--- count ---\n");
		ptr1 = data1;
		while(1)
		{
			ptr1 = strstr(ptr1,"},");
		    if(ptr == NULL)
		    {
		        break;
	        }
	        count++;
			ptr1++;
		}
		count++;
		printf("%d 명\n",count);

		printf("--- jsonparser ---\n");	
		printf("JSON string: %s \n", data1);
		json_object * jobj = json_tokener_parse(data1);     
		json_parsej(jobj, account);
*/
	//새로 추가

//	char *url2 = "http://27.1.48.153/api/newOrgChart.do";
//	char *test="usrGrpIdx=e615309652fadb7e471603bf6870be91&checkUpdateTime=ba1fc00a180c98056e900a481eed23d2";
	char *data2;

//	char *test="usrGrpIdx=e615309652fadb7e471603bf6870be91&checkUpdateTime=92742ad2ef70575a5db9f440a86a2b248bd16bac1c28e713a7535d7a0a3ddf63";
//	printf("=========\n %s\n",purple_account_get_string(account,"lastblist","0"));
//	printf(" %s\n",purple_account_get_string(account,"lastgroup","0"));
//	printf(" %s\n===============\n",purple_account_get_string(account,"lastbuddy","0"));
	strcpy(test,"usrGrpIdx=");
	strcat(test,re.usrGrpIdx);
	strcat(test,"&checkUpdateTime=");
	strcat(test,enval1);

//				cJSON *c=json->child; 
//				blistaddcount = 1;
//			}

//			purple_debug_warning("anhh", "[%s:%d(%s)] @debug \n", __FILE__, __LINE__, __func__);
//			//와일문 에러 
//			while (c && cJSON_strcasecmp(c->string,"list")) 
//			{
//				c=c->next;
//				data2=c;				
//				break;
//			}

//
//
//			int dataLength = cJSON_GetArraySize(data2);
//			g = purple_group_new("buddy");
//		
//			for (j = 0; j < dataLength; j++) {
//				cJSON * dataAD = cJSON_GetArrayItem(data2, j);

	data2 = handle_url(url2,test);
	printf("--- http11 접속 ---\n\n");
	if(data2) {
		printf(" data2 : \n%s\n", data2);
	}

	json_object * jobj = json_tokener_parse(data2);
	json_parsek(jobj,account);
//	purple_blist_load();
								

//	prpl = purple_find_prpl(purple_account_get_protocol_id(account));

//	if (prpl != NULL)
//		prpl_info = PURPLE_PLUGIN_PROTOCOL_INFO(prpl);
//	else {
//		gchar *message;

	////////////////////////////////////////////////////////
	}
	else if(re.code == 401)
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug 복호화 실패 \n", __FILE__, __LINE__, __func__);
		strcpy(account->password,"");
	}
	else if(re.code == 402)
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug 암호화 실패 \n", __FILE__, __LINE__, __func__);
		strcpy(account->password,"");
	}
	else if(re.code == 403)
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug TCP 통신 실패 \n", __FILE__, __LINE__, __func__);
		strcpy(account->password,"");
	}
	else if(re.code == 404)
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug db query 실패 \n", __FILE__, __LINE__, __func__);
		strcpy(account->password,"");
	}
	else if(re.code == 400)
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug 사용자 정보 없음 \n", __FILE__, __LINE__, __func__);
	}
	else
	{
		purple_debug_warning("anhh", "[%s:%d(%s)] @debug json 접속 실패 !!! \n", __FILE__, __LINE__, __func__);
	}

	g_return_if_fail(account != NULL);

	if (!purple_account_is_disconnected(account))
		return;

	prpl = purple_find_prpl(purple_account_get_protocol_id(account));

	if (prpl != NULL)
		prpl_info = PURPLE_PLUGIN_PROTOCOL_INFO(prpl);
	else {
		gchar *message;

		message = g_strdup_printf(_("Missing protocol plugin for %s"),
			purple_account_get_username(account));
		purple_notify_error(NULL, regist ? _("Registration Error") :
						  _("Connection Error"), message, NULL);
		g_free(message);
		return;
	}

	if (regist)
	{
		if (prpl_info->register_user == NULL)
			return;
	}
	else
	{
		if (((password == NULL) || (*password == '\0')) &&
		!(prpl_info->options & OPT_PROTO_NO_PASSWORD) &&
		!(prpl_info->options & OPT_PROTO_PASSWORD_OPTIONAL))
		{
			purple_debug_error("connection", "Cannot connect to account %s without "
							 "a password.\n", purple_account_get_username(account));
			return;
		}
	}
	
	gc = g_new0(PurpleConnection, 1);
	PURPLE_DBUS_REGISTER_POINTER(gc, PurpleConnection);

	gc->prpl = prpl;
	if ((password != NULL) && (*password != '\0'))
		gc->password = g_strdup(password);
	purple_connection_set_account(gc, account);
	purple_connection_set_state(gc, PURPLE_CONNECTING);
	connections = g_list_append(connections, gc);
	purple_account_set_connection(account, gc);

	purple_signal_emit(purple_connections_get_handle(), "signing-on", gc);

	if (regist)
	{
		purple_debug_info("connection", "Registering.  gc = %p\n", gc);

		/* set this so we don't auto-reconnect after registering */
		gc->wants_to_die = TRUE;

		prpl_info->register_user(account);
	}
	else
	{
		purple_debug_info("connection", "Connecting. gc = %p\n", gc);

		purple_signal_emit(purple_accounts_get_handle(), "account-connecting", account);
		prpl_info->login(account);
	}
	
}
void
purple_connection_new_unregister(PurpleAccount *account, const char *password, PurpleAccountUnregistrationCb cb, void *user_data)
{
	_purple_connection_new_unregister(account, password, cb, user_data);
}

void
_purple_connection_new_unregister(PurpleAccount *account, const char *password, PurpleAccountUnregistrationCb cb, void *user_data)
{
	/* Lots of copy/pasted code to avoid API changes. You might want to integrate that into the previous function when posssible. */
	PurpleConnection *gc;
	PurplePlugin *prpl;
	PurplePluginProtocolInfo *prpl_info;

	g_return_if_fail(account != NULL);

	prpl = purple_find_prpl(purple_account_get_protocol_id(account));

	if (prpl != NULL)
		prpl_info = PURPLE_PLUGIN_PROTOCOL_INFO(prpl);
	else {
		gchar *message;

		message = g_strdup_printf(_("Missing protocol plugin for %s"),
								  purple_account_get_username(account));
		purple_notify_error(NULL, _("Unregistration Error"), message, NULL);
		g_free(message);
		return;
	}

	if (!purple_account_is_disconnected(account)) {
		prpl_info->unregister_user(account, cb, user_data);
		return;
	}

	if (((password == NULL) || (*password == '\0')) &&
		!(prpl_info->options & OPT_PROTO_NO_PASSWORD) &&
		!(prpl_info->options & OPT_PROTO_PASSWORD_OPTIONAL))
	{
		purple_debug_error("connection", "Cannot connect to account %s without "
						   "a password.\n", purple_account_get_username(account));
		return;
	}

	gc = g_new0(PurpleConnection, 1);
	PURPLE_DBUS_REGISTER_POINTER(gc, PurpleConnection);

	gc->prpl = prpl;
	if ((password != NULL) && (*password != '\0'))
		gc->password = g_strdup(password);
	purple_connection_set_account(gc, account);
	purple_connection_set_state(gc, PURPLE_CONNECTING);
	connections = g_list_append(connections, gc);
	purple_account_set_connection(account, gc);

	purple_signal_emit(purple_connections_get_handle(), "signing-on", gc);

	purple_debug_info("connection", "Unregistering.  gc = %p\n", gc);

	prpl_info->unregister_user(account, cb, user_data);
}

void
purple_connection_destroy(PurpleConnection *gc)
{
	_purple_connection_destroy(gc);
}

void
_purple_connection_destroy(PurpleConnection *gc)
{
	PurpleAccount *account;
	GSList *buddies;
	PurplePluginProtocolInfo *prpl_info = NULL;
	gboolean remove = FALSE;

	g_return_if_fail(gc != NULL);

	account = purple_connection_get_account(gc);

	purple_debug_info("connection", "Disconnecting connection %p\n", gc);

	if (purple_connection_get_state(gc) != PURPLE_CONNECTING)
		remove = TRUE;

	purple_signal_emit(purple_connections_get_handle(), "signing-off", gc);

	while (gc->buddy_chats)
	{
		PurpleConversation *b = gc->buddy_chats->data;

		gc->buddy_chats = g_slist_remove(gc->buddy_chats, b);
		purple_conv_chat_left(PURPLE_CONV_CHAT(b));
	}

	update_keepalive(gc, FALSE);

	purple_proxy_connect_cancel_with_handle(gc);

	prpl_info = PURPLE_PLUGIN_PROTOCOL_INFO(gc->prpl);
	if (prpl_info->close)
		(prpl_info->close)(gc);

	/* Clear out the proto data that was freed in the prpl close method*/
	buddies = purple_find_buddies(account, NULL);
	while (buddies != NULL) {
		PurpleBuddy *buddy = buddies->data;
		purple_buddy_set_protocol_data(buddy, NULL);
		buddies = g_slist_delete_link(buddies, buddies);
	}

	connections = g_list_remove(connections, gc);

	purple_connection_set_state(gc, PURPLE_DISCONNECTED);

	if (remove)
		purple_blist_remove_account(account);

	purple_signal_emit(purple_connections_get_handle(), "signed-off", gc);

	purple_account_request_close_with_account(account);
	purple_request_close_with_handle(gc);
	purple_notify_close_with_handle(gc);

	purple_debug_info("connection", "Destroying connection %p\n", gc);

	purple_account_set_connection(account, NULL);

	g_free(gc->password);
	g_free(gc->display_name);

	if (gc->disconnect_timeout > 0)
		purple_timeout_remove(gc->disconnect_timeout);

	PURPLE_DBUS_UNREGISTER_POINTER(gc);
	g_free(gc);
}

/*
 * d:)->-<
 *
 * d:O-\-<
 *
 * d:D-/-<
 *
 * d8D->-< DANCE!
 */

void
purple_connection_set_state(PurpleConnection *gc, PurpleConnectionState state)
{
	PurpleConnectionUiOps *ops;

	g_return_if_fail(gc != NULL);

	if (gc->state == state)
		return;

	gc->state = state;

	ops = purple_connections_get_ui_ops();

	if (gc->state == PURPLE_CONNECTING) {
		connections_connecting = g_list_append(connections_connecting, gc);
	}
	else {
		connections_connecting = g_list_remove(connections_connecting, gc);
	}

	if (gc->state == PURPLE_CONNECTED) {
		PurpleAccount *account;
		PurplePresence *presence;

		account = purple_connection_get_account(gc);
		presence = purple_account_get_presence(account);

		/* Set the time the account came online */
		purple_presence_set_login_time(presence, time(NULL));

		if (purple_prefs_get_bool("/purple/logging/log_system"))
		{
			PurpleLog *log = purple_account_get_log(account, TRUE);

			if (log != NULL)
			{
				char *msg = g_strdup_printf(_("+++ %s signed on"),
											purple_account_get_username(account));
				purple_log_write(log, PURPLE_MESSAGE_SYSTEM,
							   purple_account_get_username(account),
							   purple_presence_get_login_time(presence),
							   msg);
				g_free(msg);
			}
		}

		if (ops != NULL && ops->connected != NULL)
			ops->connected(gc);

		purple_blist_add_account(account);

		purple_signal_emit(purple_connections_get_handle(), "signed-on", gc);
		purple_signal_emit_return_1(purple_connections_get_handle(), "autojoin", gc);

		serv_set_permit_deny(gc);

		update_keepalive(gc, TRUE);
	}
	else if (gc->state == PURPLE_DISCONNECTED) {
		PurpleAccount *account = purple_connection_get_account(gc);

		if (purple_prefs_get_bool("/purple/logging/log_system"))
		{
			PurpleLog *log = purple_account_get_log(account, FALSE);

			if (log != NULL)
			{
				char *msg = g_strdup_printf(_("+++ %s signed off"),
											purple_account_get_username(account));
				purple_log_write(log, PURPLE_MESSAGE_SYSTEM,
							   purple_account_get_username(account), time(NULL),
							   msg);
				g_free(msg);
			}
		}

		purple_account_destroy_log(account);

		if (ops != NULL && ops->disconnected != NULL)
			ops->disconnected(gc);
	}
}

void
purple_connection_set_account(PurpleConnection *gc, PurpleAccount *account)
{
	g_return_if_fail(gc != NULL);
	g_return_if_fail(account != NULL);

	gc->account = account;
}

void
purple_connection_set_display_name(PurpleConnection *gc, const char *name)
{
	g_return_if_fail(gc != NULL);

	g_free(gc->display_name);
	gc->display_name = g_strdup(name);
}

void
purple_connection_set_protocol_data(PurpleConnection *connection, void *proto_data) {
	g_return_if_fail(connection != NULL);

	connection->proto_data = proto_data;
}

PurpleConnectionState
purple_connection_get_state(const PurpleConnection *gc)
{
	g_return_val_if_fail(gc != NULL, PURPLE_DISCONNECTED);

	return gc->state;
}

PurpleAccount *
purple_connection_get_account(const PurpleConnection *gc)
{
	g_return_val_if_fail(gc != NULL, NULL);

	return gc->account;
}

PurplePlugin *
purple_connection_get_prpl(const PurpleConnection *gc)
{
	g_return_val_if_fail(gc != NULL, NULL);

	return gc->prpl;
}

const char *
purple_connection_get_password(const PurpleConnection *gc)
{
	g_return_val_if_fail(gc != NULL, NULL);

	return gc->password ? gc->password : gc->account->password;
}

const char *
purple_connection_get_display_name(const PurpleConnection *gc)
{
	g_return_val_if_fail(gc != NULL, NULL);

	return gc->display_name;
}

void *
purple_connection_get_protocol_data(const PurpleConnection *connection) {
	g_return_val_if_fail(connection != NULL, NULL);

	return connection->proto_data;
}

void
purple_connection_update_progress(PurpleConnection *gc, const char *text,
								size_t step, size_t count)
{
	PurpleConnectionUiOps *ops;

	g_return_if_fail(gc   != NULL);
	g_return_if_fail(text != NULL);
	g_return_if_fail(step < count);
	g_return_if_fail(count > 1);

	ops = purple_connections_get_ui_ops();

	if (ops != NULL && ops->connect_progress != NULL)
		ops->connect_progress(gc, text, step, count);
}

void
purple_connection_notice(PurpleConnection *gc, const char *text)
{
	PurpleConnectionUiOps *ops;

	g_return_if_fail(gc   != NULL);
	g_return_if_fail(text != NULL);

	ops = purple_connections_get_ui_ops();

	if (ops != NULL && ops->notice != NULL)
		ops->notice(gc, text);
}

static gboolean
purple_connection_disconnect_cb(gpointer data)
{
	PurpleAccount *account;
	PurpleConnection *gc;
	char *password;

	account = data;
	gc = purple_account_get_connection(account);

	if (gc != NULL)
		gc->disconnect_timeout = 0;

	password = g_strdup(purple_account_get_password(account));
	purple_account_disconnect(account);
	purple_account_set_password(account, password);
	g_free(password);

	return FALSE;
}

void
purple_connection_error(PurpleConnection *gc, const char *text)
{
	/* prpls that have not been updated to use disconnection reasons will
	 * be setting wants_to_die before calling this function, so choose
	 * PURPLE_CONNECTION_ERROR_OTHER_ERROR (which is fatal) if it's true,
	 * and PURPLE_CONNECTION_ERROR_NETWORK_ERROR (which isn't) if not.  See
	 * the documentation in connection.h.
	 */
	PurpleConnectionError reason = gc->wants_to_die
	                             ? PURPLE_CONNECTION_ERROR_OTHER_ERROR
	                             : PURPLE_CONNECTION_ERROR_NETWORK_ERROR;
	purple_connection_error_reason (gc, reason, text);
}

void
purple_connection_error_reason (PurpleConnection *gc,
                                PurpleConnectionError reason,
                                const char *description)
{
	PurpleConnectionUiOps *ops;

	g_return_if_fail(gc   != NULL);
	/* This sanity check relies on PURPLE_CONNECTION_ERROR_OTHER_ERROR
	 * being the last member of the PurpleConnectionError enum in
	 * connection.h; if other reasons are added after it, this check should
	 * be updated.
	 */
	if (reason > PURPLE_CONNECTION_ERROR_OTHER_ERROR) {
		purple_debug_error("connection",
			"purple_connection_error_reason: reason %u isn't a "
			"valid reason\n", reason);
		reason = PURPLE_CONNECTION_ERROR_OTHER_ERROR;
	}

	if (description == NULL) {
		purple_debug_error("connection", "purple_connection_error_reason called with NULL description\n");
		description = _("Unknown error");
	}

	/* If we've already got one error, we don't need any more */
	if (gc->disconnect_timeout > 0)
		return;

	gc->wants_to_die = purple_connection_error_is_fatal (reason);

	purple_debug_info("connection", "Connection error on %p (reason: %u description: %s)\n",
	                  gc, reason, description);

	ops = purple_connections_get_ui_ops();

	if (ops != NULL)
	{
		if (ops->report_disconnect_reason != NULL)
			ops->report_disconnect_reason (gc, reason, description);
		if (ops->report_disconnect != NULL)
			ops->report_disconnect (gc, description);
	}

	purple_signal_emit(purple_connections_get_handle(), "connection-error",
		gc, reason, description);

	gc->disconnect_timeout = purple_timeout_add(0, purple_connection_disconnect_cb,
			purple_connection_get_account(gc));
}

void
purple_connection_ssl_error (PurpleConnection *gc,
                             PurpleSslErrorType ssl_error)
{
	PurpleConnectionError reason;

	switch (ssl_error) {
		case PURPLE_SSL_HANDSHAKE_FAILED:
			reason = PURPLE_CONNECTION_ERROR_ENCRYPTION_ERROR;
			break;
		case PURPLE_SSL_CONNECT_FAILED:
			reason = PURPLE_CONNECTION_ERROR_NETWORK_ERROR;
			break;
		case PURPLE_SSL_CERTIFICATE_INVALID:
			/* TODO: maybe PURPLE_SSL_* should be more specific? */
			reason = PURPLE_CONNECTION_ERROR_CERT_OTHER_ERROR;
			break;
		default:
			g_assert_not_reached ();
			reason = PURPLE_CONNECTION_ERROR_CERT_OTHER_ERROR;
	}

	purple_connection_error_reason (gc, reason,
		purple_ssl_strerror(ssl_error));
}

gboolean
purple_connection_error_is_fatal (PurpleConnectionError reason)
{
	switch (reason)
	{
		case PURPLE_CONNECTION_ERROR_NETWORK_ERROR:
		case PURPLE_CONNECTION_ERROR_ENCRYPTION_ERROR:
			return FALSE;
		case PURPLE_CONNECTION_ERROR_INVALID_USERNAME:
		case PURPLE_CONNECTION_ERROR_AUTHENTICATION_FAILED:
		case PURPLE_CONNECTION_ERROR_AUTHENTICATION_IMPOSSIBLE:
		case PURPLE_CONNECTION_ERROR_NO_SSL_SUPPORT:
		case PURPLE_CONNECTION_ERROR_NAME_IN_USE:
		case PURPLE_CONNECTION_ERROR_INVALID_SETTINGS:
		case PURPLE_CONNECTION_ERROR_OTHER_ERROR:
		case PURPLE_CONNECTION_ERROR_CERT_NOT_PROVIDED:
		case PURPLE_CONNECTION_ERROR_CERT_UNTRUSTED:
		case PURPLE_CONNECTION_ERROR_CERT_EXPIRED:
		case PURPLE_CONNECTION_ERROR_CERT_NOT_ACTIVATED:
		case PURPLE_CONNECTION_ERROR_CERT_HOSTNAME_MISMATCH:
		case PURPLE_CONNECTION_ERROR_CERT_FINGERPRINT_MISMATCH:
		case PURPLE_CONNECTION_ERROR_CERT_SELF_SIGNED:
		case PURPLE_CONNECTION_ERROR_CERT_OTHER_ERROR:
			return TRUE;
		default:
			g_return_val_if_reached(TRUE);
	}
}

void
purple_connections_disconnect_all(void)
{
	GList *l;
	PurpleConnection *gc;

	while ((l = purple_connections_get_all()) != NULL) {
		gc = l->data;
		gc->wants_to_die = TRUE;
		purple_account_disconnect(gc->account);
	}
}

GList *
purple_connections_get_all(void)
{
	return connections;
}

GList *
purple_connections_get_connecting(void)
{
	return connections_connecting;
}

void
purple_connections_set_ui_ops(PurpleConnectionUiOps *ops)
{
	connection_ui_ops = ops;
}

PurpleConnectionUiOps *
purple_connections_get_ui_ops(void)
{
	return connection_ui_ops;
}

void
purple_connections_init(void)
{
	void *handle = purple_connections_get_handle();

	purple_signal_register(handle, "signing-on",
						 purple_marshal_VOID__POINTER, NULL, 1,
						 purple_value_new(PURPLE_TYPE_SUBTYPE,
										PURPLE_SUBTYPE_CONNECTION));

	purple_signal_register(handle, "signed-on",
						 purple_marshal_VOID__POINTER, NULL, 1,
						 purple_value_new(PURPLE_TYPE_SUBTYPE,
										PURPLE_SUBTYPE_CONNECTION));

	purple_signal_register(handle, "signing-off",
						 purple_marshal_VOID__POINTER, NULL, 1,
						 purple_value_new(PURPLE_TYPE_SUBTYPE,
										PURPLE_SUBTYPE_CONNECTION));

	purple_signal_register(handle, "signed-off",
						 purple_marshal_VOID__POINTER, NULL, 1,
						 purple_value_new(PURPLE_TYPE_SUBTYPE,
										PURPLE_SUBTYPE_CONNECTION));

	purple_signal_register(handle, "connection-error",
	                       purple_marshal_VOID__POINTER_INT_POINTER, NULL, 3,
	                       purple_value_new(PURPLE_TYPE_SUBTYPE,
	                                        PURPLE_SUBTYPE_CONNECTION),
	                       purple_value_new(PURPLE_TYPE_ENUM),
	                       purple_value_new(PURPLE_TYPE_STRING));

	purple_signal_register(handle, "autojoin",
	                       purple_marshal_BOOLEAN__POINTER, NULL, 1,
	                       purple_value_new(PURPLE_TYPE_SUBTYPE,
	                                        PURPLE_SUBTYPE_CONNECTION));

}

void
purple_connections_uninit(void)
{
	purple_signals_unregister_by_instance(purple_connections_get_handle());
}

void *
purple_connections_get_handle(void)
{
	return &connections_handle;
}
