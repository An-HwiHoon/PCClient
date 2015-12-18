/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of Account.xs. Do not edit this file, edit Account.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Account.xs"
#include "module.h"

#line 13 "Account.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 155 "Account.c"

XS_EUPXS(XS_Purple__Account_get_presence); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_presence)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__Presence	RETVAL;

	RETVAL = purple_account_get_presence(account);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Presence");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_new)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "class, username, protocol_id");
    {
	const char *	username = (const char *)SvPV_nolen(ST(1))
;
	const char *	protocol_id = (const char *)SvPV_nolen(ST(2))
;
	Purple__Account	RETVAL;

	RETVAL = purple_account_new(username, protocol_id);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_destroy(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_connect); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_connect)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_connect(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_register); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_register)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_register(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_disconnect); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_disconnect)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_disconnect(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_request_change_password); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_request_change_password)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_request_change_password(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_request_change_user_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_request_change_user_info)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_request_change_user_info(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_username); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_username)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, username");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	username = (const char *)SvPV_nolen(ST(1))
;

	purple_account_set_username(account, username);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_password); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_password)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, password");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	password = (const char *)SvPV_nolen(ST(1))
;

	purple_account_set_password(account, password);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_alias); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_alias)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, alias");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	alias = (const char *)SvPV_nolen(ST(1))
;

	purple_account_set_alias(account, alias);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_user_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_user_info)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, user_info");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	user_info = (const char *)SvPV_nolen(ST(1))
;

	purple_account_set_user_info(account, user_info);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_buddy_icon_path); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_buddy_icon_path)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, icon");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	icon = (const char *)SvPV_nolen(ST(1))
;

	purple_account_set_buddy_icon_path(account, icon);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_connection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_connection)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, gc");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__Connection	gc = purple_perl_ref_object(ST(1))
;

	purple_account_set_connection(account, gc);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_remember_password); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_remember_password)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, value");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	gboolean	value = (bool)SvTRUE(ST(1))
;

	purple_account_set_remember_password(account, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_check_mail); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_check_mail)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, value");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	gboolean	value = (bool)SvTRUE(ST(1))
;

	purple_account_set_check_mail(account, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_enabled); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_enabled)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, ui, value");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	ui = (const char *)SvPV_nolen(ST(1))
;
	gboolean	value = (bool)SvTRUE(ST(2))
;

	purple_account_set_enabled(account, ui, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_proxy_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_proxy_info)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, info");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__ProxyInfo	info = purple_perl_ref_object(ST(1))
;

	purple_account_set_proxy_info(account, info);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_status); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_status)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, status_id, active");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	status_id = (const char *)SvPV_nolen(ST(1))
;
	gboolean	active = (bool)SvTRUE(ST(2))
;
#line 97 "Account.xs"
    purple_account_set_status(account, status_id, active, NULL);
#line 490 "Account.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_status_types); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_status_types)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, status_types");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	SV *	status_types = ST(1)
;
#line 104 "Account.xs"
    GList *t_GL;
    int i, t_len;
#line 512 "Account.c"
#line 107 "Account.xs"
    t_GL = NULL;
    t_len = av_len((AV *)SvRV(status_types));

    for (i = 0; i <= t_len; i++)
        t_GL = g_list_append(t_GL, SvPVutf8_nolen(*av_fetch((AV *)SvRV(status_types), i, 0)));

    purple_account_set_status_types(account, t_GL);
#line 521 "Account.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Account_clear_settings); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_clear_settings)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_clear_settings(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_set_int); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_set_int)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, name, value");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	name = (const char *)SvPV_nolen(ST(1))
;
	int	value = (int)SvIV(ST(2))
;

	purple_account_set_int(account, name, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_is_connected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_is_connected)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_account_is_connected(account);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_username); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_username)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_username(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_password); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_password)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_password(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_alias); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_alias)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_alias(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_user_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_user_info)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_user_info(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_buddy_icon_path); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_buddy_icon_path)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_buddy_icon_path(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_protocol_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_protocol_id)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_protocol_id(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_protocol_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_protocol_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_get_protocol_name(account);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_connection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_connection)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__Connection	RETVAL;

	RETVAL = purple_account_get_connection(account);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Connection");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_remember_password); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_remember_password)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_account_get_remember_password(account);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_check_mail); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_check_mail)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_account_get_check_mail(account);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_enabled); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_enabled)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, ui");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	ui = (const char *)SvPV_nolen(ST(1))
;
	gboolean	RETVAL;

	RETVAL = purple_account_get_enabled(account, ui);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_proxy_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_proxy_info)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__ProxyInfo	RETVAL;

	RETVAL = purple_account_get_proxy_info(account);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::ProxyInfo");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_active_status); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_active_status)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__Status	RETVAL;

	RETVAL = purple_account_get_active_status(account);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Status");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_get_status_types); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_status_types)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
#line 186 "Account.xs"
    GList *l;
#line 845 "Account.c"
#line 188 "Account.xs"
    for (l = purple_account_get_status_types(account); l != NULL; l = l->next) {
        XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::StatusType")));
    }
#line 850 "Account.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Account_get_log); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_get_log)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, create");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	gboolean	create = (bool)SvTRUE(ST(1))
;
	Purple__Log	RETVAL;

	RETVAL = purple_account_get_log(account, create);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Log");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account_destroy_log); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_destroy_log)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_account_destroy_log(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_add_buddies); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_add_buddies)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, list");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	SV *	list = ST(1)
;
#line 206 "Account.xs"
    GList *t_GL;
    int i, t_len;
#line 910 "Account.c"
#line 209 "Account.xs"
    t_GL = NULL;
    t_len = av_len((AV *)SvRV(list));

    for (i = 0; i <= t_len; i++)
        t_GL = g_list_append(t_GL, SvPVutf8_nolen(*av_fetch((AV *)SvRV(list), i, 0)));

    purple_account_add_buddies(account, t_GL);
    g_list_free(t_GL);
#line 920 "Account.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Account_add_buddy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_add_buddy)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, buddy");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__BuddyList__Buddy	buddy = purple_perl_ref_object(ST(1))
;

	purple_account_add_buddy(account, buddy);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_change_password); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_change_password)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, a, b");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	a = (const char *)SvPV_nolen(ST(1))
;
	const char *	b = (const char *)SvPV_nolen(ST(2))
;

	purple_account_change_password(account, a, b);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_remove_buddies); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_remove_buddies)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, A, B");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	SV *	A = ST(1)
;
	SV *	B = ST(2)
;
#line 235 "Account.xs"
    GList *t_GL1, *t_GL2;
    int i, t_len;
#line 983 "Account.c"
#line 238 "Account.xs"
    t_GL1 = NULL;
    t_len = av_len((AV *)SvRV(A));

    for (i = 0; i <= t_len; i++)
        t_GL1 = g_list_append(t_GL1, SvPVutf8_nolen(*av_fetch((AV *)SvRV(A), i, 0)));

    t_GL2 = NULL;
    t_len = av_len((AV *)SvRV(B));

    for (i = 0; i <= t_len; i++)
        t_GL2 = g_list_append(t_GL2, SvPVutf8_nolen(*av_fetch((AV *)SvRV(B), i, 0)));

    purple_account_remove_buddies(account, t_GL1, t_GL2);
    g_list_free(t_GL1);
    g_list_free(t_GL2);
#line 1000 "Account.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Account_remove_buddy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_remove_buddy)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, buddy, group");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__BuddyList__Buddy	buddy = purple_perl_ref_object(ST(1))
;
	Purple__BuddyList__Group	group = purple_perl_ref_object(ST(2))
;

	purple_account_remove_buddy(account, buddy, group);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account_remove_group); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account_remove_group)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, group");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	Purple__BuddyList__Group	group = purple_perl_ref_object(ST(1))
;

	purple_account_remove_group(account, group);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Accounts_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_add)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_accounts_add(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Accounts_remove); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_remove)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_accounts_remove(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Accounts_delete); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_delete)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "account");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;

	purple_accounts_delete(account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Accounts_reorder); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_reorder)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, new_index");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	size_t	new_index = (size_t)SvUV(ST(1))
;

	purple_accounts_reorder(account, new_index);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Accounts_get_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_get_all)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 288 "Account.xs"
    GList *l;
#line 1122 "Account.c"
#line 290 "Account.xs"
    for (l = purple_accounts_get_all(); l != NULL; l = l->next) {
        XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Account")));
    }
#line 1127 "Account.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Accounts_get_all_active); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_get_all_active)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 297 "Account.xs"
    GList *list, *iter;
#line 1145 "Account.c"
#line 299 "Account.xs"
    list = purple_accounts_get_all_active();
    for (iter = list; iter != NULL; iter = iter->next) {
        XPUSHs(sv_2mortal(purple_perl_bless_object(iter->data, "Purple::Account")));
    }
    g_list_free(list);
#line 1152 "Account.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Accounts_restore_current_statuses); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_restore_current_statuses)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	purple_accounts_restore_current_statuses();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Accounts_find); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_find)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "name, protocol");
    {
	const char *	name = (const char *)SvPV_nolen(ST(0))
;
	const char *	protocol = (const char *)SvPV_nolen(ST(1))
;
	Purple__Account	RETVAL;

	RETVAL = purple_accounts_find(name, protocol);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Accounts_get_handle); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Accounts_get_handle)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Handle	RETVAL;

	RETVAL = purple_accounts_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple__Account); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple__Account)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        (void)newXSproto_portable("Purple::Account::get_presence", XS_Purple__Account_get_presence, file, "$");
        (void)newXSproto_portable("Purple::Account::new", XS_Purple__Account_new, file, "$$$");
        (void)newXSproto_portable("Purple::Account::destroy", XS_Purple__Account_destroy, file, "$");
        (void)newXSproto_portable("Purple::Account::connect", XS_Purple__Account_connect, file, "$");
        (void)newXSproto_portable("Purple::Account::register", XS_Purple__Account_register, file, "$");
        (void)newXSproto_portable("Purple::Account::disconnect", XS_Purple__Account_disconnect, file, "$");
        (void)newXSproto_portable("Purple::Account::request_change_password", XS_Purple__Account_request_change_password, file, "$");
        (void)newXSproto_portable("Purple::Account::request_change_user_info", XS_Purple__Account_request_change_user_info, file, "$");
        (void)newXSproto_portable("Purple::Account::set_username", XS_Purple__Account_set_username, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_password", XS_Purple__Account_set_password, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_alias", XS_Purple__Account_set_alias, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_user_info", XS_Purple__Account_set_user_info, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_buddy_icon_path", XS_Purple__Account_set_buddy_icon_path, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_connection", XS_Purple__Account_set_connection, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_remember_password", XS_Purple__Account_set_remember_password, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_check_mail", XS_Purple__Account_set_check_mail, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_enabled", XS_Purple__Account_set_enabled, file, "$$$");
        (void)newXSproto_portable("Purple::Account::set_proxy_info", XS_Purple__Account_set_proxy_info, file, "$$");
        (void)newXSproto_portable("Purple::Account::set_status", XS_Purple__Account_set_status, file, "$$$");
        (void)newXSproto_portable("Purple::Account::set_status_types", XS_Purple__Account_set_status_types, file, "$$");
        (void)newXSproto_portable("Purple::Account::clear_settings", XS_Purple__Account_clear_settings, file, "$");
        (void)newXSproto_portable("Purple::Account::set_int", XS_Purple__Account_set_int, file, "$$$");
        (void)newXSproto_portable("Purple::Account::is_connected", XS_Purple__Account_is_connected, file, "$");
        (void)newXSproto_portable("Purple::Account::get_username", XS_Purple__Account_get_username, file, "$");
        (void)newXSproto_portable("Purple::Account::get_password", XS_Purple__Account_get_password, file, "$");
        (void)newXSproto_portable("Purple::Account::get_alias", XS_Purple__Account_get_alias, file, "$");
        (void)newXSproto_portable("Purple::Account::get_user_info", XS_Purple__Account_get_user_info, file, "$");
        (void)newXSproto_portable("Purple::Account::get_buddy_icon_path", XS_Purple__Account_get_buddy_icon_path, file, "$");
        (void)newXSproto_portable("Purple::Account::get_protocol_id", XS_Purple__Account_get_protocol_id, file, "$");
        (void)newXSproto_portable("Purple::Account::get_protocol_name", XS_Purple__Account_get_protocol_name, file, "$");
        (void)newXSproto_portable("Purple::Account::get_connection", XS_Purple__Account_get_connection, file, "$");
        (void)newXSproto_portable("Purple::Account::get_remember_password", XS_Purple__Account_get_remember_password, file, "$");
        (void)newXSproto_portable("Purple::Account::get_check_mail", XS_Purple__Account_get_check_mail, file, "$");
        (void)newXSproto_portable("Purple::Account::get_enabled", XS_Purple__Account_get_enabled, file, "$$");
        (void)newXSproto_portable("Purple::Account::get_proxy_info", XS_Purple__Account_get_proxy_info, file, "$");
        (void)newXSproto_portable("Purple::Account::get_active_status", XS_Purple__Account_get_active_status, file, "$");
        (void)newXSproto_portable("Purple::Account::get_status_types", XS_Purple__Account_get_status_types, file, "$");
        (void)newXSproto_portable("Purple::Account::get_log", XS_Purple__Account_get_log, file, "$$");
        (void)newXSproto_portable("Purple::Account::destroy_log", XS_Purple__Account_destroy_log, file, "$");
        (void)newXSproto_portable("Purple::Account::add_buddies", XS_Purple__Account_add_buddies, file, "$$");
        (void)newXSproto_portable("Purple::Account::add_buddy", XS_Purple__Account_add_buddy, file, "$$");
        (void)newXSproto_portable("Purple::Account::change_password", XS_Purple__Account_change_password, file, "$$$");
        (void)newXSproto_portable("Purple::Account::remove_buddies", XS_Purple__Account_remove_buddies, file, "$$$");
        (void)newXSproto_portable("Purple::Account::remove_buddy", XS_Purple__Account_remove_buddy, file, "$$$");
        (void)newXSproto_portable("Purple::Account::remove_group", XS_Purple__Account_remove_group, file, "$$");
        (void)newXSproto_portable("Purple::Accounts::add", XS_Purple__Accounts_add, file, "$");
        (void)newXSproto_portable("Purple::Accounts::remove", XS_Purple__Accounts_remove, file, "$");
        (void)newXSproto_portable("Purple::Accounts::delete", XS_Purple__Accounts_delete, file, "$");
        (void)newXSproto_portable("Purple::Accounts::reorder", XS_Purple__Accounts_reorder, file, "$$");
        (void)newXSproto_portable("Purple::Accounts::get_all", XS_Purple__Accounts_get_all, file, "");
        (void)newXSproto_portable("Purple::Accounts::get_all_active", XS_Purple__Accounts_get_all_active, file, "");
        (void)newXSproto_portable("Purple::Accounts::restore_current_statuses", XS_Purple__Accounts_restore_current_statuses, file, "");
        (void)newXSproto_portable("Purple::Accounts::find", XS_Purple__Accounts_find, file, "$$");
        (void)newXSproto_portable("Purple::Accounts::get_handle", XS_Purple__Accounts_get_handle, file, "");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

