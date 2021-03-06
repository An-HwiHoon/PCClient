/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of SavedStatuses.xs. Do not edit this file, edit SavedStatuses.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "SavedStatuses.xs"
#include "module.h"

/* I can't get this to work, both with and without the const on the return
 * type I get errors from gcc. One way about ignoring types in a cast, and the
 * other about assigning to read-only variables.
const Purple::StatusType
purple_savedstatus_substatus_get_type(substatus)
	const Purple::SavedStatus::Sub substatus
*/

#line 21 "SavedStatuses.c"
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

#line 163 "SavedStatuses.c"

XS_EUPXS(XS_Purple__SavedStatus_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_new)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "title, type");
    {
	const char *	title = (const char *)SvPV_nolen(ST(0))
;
	Purple__StatusPrimitive	type = (Purple__StatusPrimitive)SvIV(ST(1))
;
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_new(title, type);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_set_title); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_set_title)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "status, title");
    {
	Purple__SavedStatus	status = purple_perl_ref_object(ST(0))
;
	const char *	title = (const char *)SvPV_nolen(ST(1))
;

	purple_savedstatus_set_title(status, title);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_set_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_set_type)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "status, type");
    {
	Purple__SavedStatus	status = purple_perl_ref_object(ST(0))
;
	Purple__StatusPrimitive	type = (Purple__StatusPrimitive)SvIV(ST(1))
;

	purple_savedstatus_set_type(status, type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_set_message); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_set_message)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "status, message");
    {
	Purple__SavedStatus	status = purple_perl_ref_object(ST(0))
;
	const char *	message = (const char *)SvPV_nolen(ST(1))
;

	purple_savedstatus_set_message(status, message);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_set_substatus); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_set_substatus)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "status, account, type, message");
    {
	Purple__SavedStatus	status = purple_perl_ref_object(ST(0))
;
	Purple__Account	account = purple_perl_ref_object(ST(1))
;
	Purple__StatusType	type = purple_perl_ref_object(ST(2))
;
	const char *	message = (const char *)SvPV_nolen(ST(3))
;

	purple_savedstatus_set_substatus(status, account, type, message);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_unset_substatus); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_unset_substatus)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "status, account");
    {
	Purple__SavedStatus	status = purple_perl_ref_object(ST(0))
;
	Purple__Account	account = purple_perl_ref_object(ST(1))
;

	purple_savedstatus_unset_substatus(status, account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_delete); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_delete)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "title");
    {
	const char *	title = (const char *)SvPV_nolen(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_savedstatus_delete(title);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_current); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_current)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_get_current();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_default); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_default)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_get_default();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_idleaway); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_idleaway)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_get_idleaway();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_is_idleaway); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_is_idleaway)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	gboolean	RETVAL;

	RETVAL = purple_savedstatus_is_idleaway();
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_set_idleaway); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_set_idleaway)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "idleaway");
    {
	gboolean	idleaway = (bool)SvTRUE(ST(0))
;

	purple_savedstatus_set_idleaway(idleaway);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_get_startup); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_startup)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_get_startup();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_find); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_find)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "title");
    {
	const char *	title = (const char *)SvPV_nolen(ST(0))
;
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_find(title);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_find_by_creation_time); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_find_by_creation_time)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "creation_time");
    {
	time_t	creation_time = (time_t)SvIV(ST(0))
;
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_find_by_creation_time(creation_time);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_find_transient_by_type_and_message); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_find_transient_by_type_and_message)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "type, message");
    {
	Purple__StatusPrimitive	type = (Purple__StatusPrimitive)SvIV(ST(0))
;
	const char *	message = (const char *)SvPV_nolen(ST(1))
;
	Purple__SavedStatus	RETVAL;

	RETVAL = purple_savedstatus_find_transient_by_type_and_message(type, message);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_is_transient); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_is_transient)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_savedstatus_is_transient(saved_status);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_title); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_title)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_savedstatus_get_title(saved_status);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	Purple__StatusPrimitive	RETVAL;
	dXSTARG;

	RETVAL = purple_savedstatus_get_type(saved_status);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_message); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_message)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_savedstatus_get_message(saved_status);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_creation_time); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_creation_time)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	time_t	RETVAL;
	dXSTARG;

	RETVAL = purple_savedstatus_get_creation_time(saved_status);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_has_substatuses); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_has_substatuses)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_savedstatus_has_substatuses(saved_status);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_get_substatus); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_get_substatus)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "saved_status, account");
    {
	Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	Purple__Account	account = purple_perl_ref_object(ST(1))
;
	Purple__SavedStatus__Sub	RETVAL;

	RETVAL = purple_savedstatus_get_substatus(saved_status, account);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::SavedStatus::Sub");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatus_activate); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_activate)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "saved_status");
    {
	Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;

	purple_savedstatus_activate(saved_status);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus_activate_for_account); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus_activate_for_account)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "saved_status, account");
    {
	const Purple__SavedStatus	saved_status = purple_perl_ref_object(ST(0))
;
	Purple__Account	account = purple_perl_ref_object(ST(1))
;

	purple_savedstatus_activate_for_account(saved_status, account);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__SavedStatus__Sub_get_message); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatus__Sub_get_message)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "substatus");
    {
	const Purple__SavedStatus__Sub	substatus = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_savedstatus_substatus_get_message(substatus);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__SavedStatuses_get_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatuses_get_all)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 133 "SavedStatuses.xs"
	GList *l;
#line 658 "SavedStatuses.c"
#line 135 "SavedStatuses.xs"
	for (l = purple_savedstatuses_get_all(); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::SavedStatus")));
	}
#line 663 "SavedStatuses.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__SavedStatuses_get_popular); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatuses_get_popular)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "how_many");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	unsigned int	how_many = (unsigned int)SvUV(ST(0))
;
#line 143 "SavedStatuses.xs"
	GList *l, *ll;
#line 683 "SavedStatuses.c"
#line 145 "SavedStatuses.xs"
	ll = purple_savedstatuses_get_popular(how_many);
	for (l = ll; l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::SavedStatus")));
	}
	g_list_free(ll);
#line 690 "SavedStatuses.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__SavedStatuses_get_handle); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__SavedStatuses_get_handle)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Handle	RETVAL;

	RETVAL = purple_savedstatuses_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple__SavedStatus); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple__SavedStatus)
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

        (void)newXSproto_portable("Purple::SavedStatus::new", XS_Purple__SavedStatus_new, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::set_title", XS_Purple__SavedStatus_set_title, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::set_type", XS_Purple__SavedStatus_set_type, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::set_message", XS_Purple__SavedStatus_set_message, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::set_substatus", XS_Purple__SavedStatus_set_substatus, file, "$$$$");
        (void)newXSproto_portable("Purple::SavedStatus::unset_substatus", XS_Purple__SavedStatus_unset_substatus, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::delete", XS_Purple__SavedStatus_delete, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_current", XS_Purple__SavedStatus_get_current, file, "");
        (void)newXSproto_portable("Purple::SavedStatus::get_default", XS_Purple__SavedStatus_get_default, file, "");
        (void)newXSproto_portable("Purple::SavedStatus::get_idleaway", XS_Purple__SavedStatus_get_idleaway, file, "");
        (void)newXSproto_portable("Purple::SavedStatus::is_idleaway", XS_Purple__SavedStatus_is_idleaway, file, "");
        (void)newXSproto_portable("Purple::SavedStatus::set_idleaway", XS_Purple__SavedStatus_set_idleaway, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_startup", XS_Purple__SavedStatus_get_startup, file, "");
        (void)newXSproto_portable("Purple::SavedStatus::find", XS_Purple__SavedStatus_find, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::find_by_creation_time", XS_Purple__SavedStatus_find_by_creation_time, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::find_transient_by_type_and_message", XS_Purple__SavedStatus_find_transient_by_type_and_message, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::is_transient", XS_Purple__SavedStatus_is_transient, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_title", XS_Purple__SavedStatus_get_title, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_type", XS_Purple__SavedStatus_get_type, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_message", XS_Purple__SavedStatus_get_message, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_creation_time", XS_Purple__SavedStatus_get_creation_time, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::has_substatuses", XS_Purple__SavedStatus_has_substatuses, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::get_substatus", XS_Purple__SavedStatus_get_substatus, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::activate", XS_Purple__SavedStatus_activate, file, "$");
        (void)newXSproto_portable("Purple::SavedStatus::activate_for_account", XS_Purple__SavedStatus_activate_for_account, file, "$$");
        (void)newXSproto_portable("Purple::SavedStatus::Sub::get_message", XS_Purple__SavedStatus__Sub_get_message, file, "$");
        (void)newXSproto_portable("Purple::SavedStatuses::get_all", XS_Purple__SavedStatuses_get_all, file, "");
        (void)newXSproto_portable("Purple::SavedStatuses::get_popular", XS_Purple__SavedStatuses_get_popular, file, "$");
        (void)newXSproto_portable("Purple::SavedStatuses::get_handle", XS_Purple__SavedStatuses_get_handle, file, "");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

