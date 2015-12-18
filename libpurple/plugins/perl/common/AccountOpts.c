/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of AccountOpts.xs. Do not edit this file, edit AccountOpts.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "AccountOpts.xs"
#include "module.h"

#line 13 "AccountOpts.c"
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

#line 155 "AccountOpts.c"

XS_EUPXS(XS_Purple__Account__Option_destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;

	purple_account_option_destroy(option);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account__Option_get_default_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_default_string)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_option_get_default_string(option);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_add_list_item); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_add_list_item)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "option, key, value");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	const char *	key = (const char *)SvPV_nolen(ST(1))
;
	const char *	value = (const char *)SvPV_nolen(ST(2))
;

	purple_account_option_add_list_item(option, key, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account__Option_set_default_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_set_default_string)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "option, value");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	const char *	value = (const char *)SvPV_nolen(ST(1))
;

	purple_account_option_set_default_string(option, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account__Option_set_default_int); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_set_default_int)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "option, value");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	int	value = (int)SvIV(ST(1))
;

	purple_account_option_set_default_int(option, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account__Option_set_default_bool); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_set_default_bool)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "option, value");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	gboolean	value = (bool)SvTRUE(ST(1))
;

	purple_account_option_set_default_bool(option, value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account__Option_list_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_list_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, text, pref_name, values");
    {
	const char *	text = (const char *)SvPV_nolen(ST(1))
;
	const char *	pref_name = (const char *)SvPV_nolen(ST(2))
;
	SV *	values = ST(3)
;
#line 41 "AccountOpts.xs"
	GList *t_GL;
	int i, t_len;
#line 282 "AccountOpts.c"
	Purple__Account__Option	RETVAL;
#line 44 "AccountOpts.xs"
	t_GL = NULL;
	t_len = av_len((AV *)SvRV(values));

	for (i = 0; i <= t_len; i++)
		t_GL = g_list_append(t_GL, SvPVutf8_nolen(*av_fetch((AV *)SvRV(values), i, 0)));

	RETVAL  = purple_account_option_list_new(text, pref_name, t_GL);
#line 292 "AccountOpts.c"
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account::Option");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_string_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_string_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, text, pref_name, default_value");
    {
	const char *	text = (const char *)SvPV_nolen(ST(1))
;
	const char *	pref_name = (const char *)SvPV_nolen(ST(2))
;
	const char *	default_value = (const char *)SvPV_nolen(ST(3))
;
	Purple__Account__Option	RETVAL;

	RETVAL = purple_account_option_string_new(text, pref_name, default_value);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account::Option");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_int_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_int_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, text, pref_name, default_value");
    {
	const char *	text = (const char *)SvPV_nolen(ST(1))
;
	const char *	pref_name = (const char *)SvPV_nolen(ST(2))
;
	gboolean	default_value = (bool)SvTRUE(ST(3))
;
	Purple__Account__Option	RETVAL;

	RETVAL = purple_account_option_int_new(text, pref_name, default_value);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account::Option");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_bool_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_bool_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, text, pref_name, default_value");
    {
	const char *	text = (const char *)SvPV_nolen(ST(1))
;
	const char *	pref_name = (const char *)SvPV_nolen(ST(2))
;
	gboolean	default_value = (bool)SvTRUE(ST(3))
;
	Purple__Account__Option	RETVAL;

	RETVAL = purple_account_option_bool_new(text, pref_name, default_value);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account::Option");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, type, text, pref_name");
    {
	Purple__PrefType	type = (Purple__PrefType)SvIV(ST(1))
;
	const char *	text = (const char *)SvPV_nolen(ST(2))
;
	const char *	pref_name = (const char *)SvPV_nolen(ST(3))
;
	Purple__Account__Option	RETVAL;

	RETVAL = purple_account_option_new(type, text, pref_name);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account::Option");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_get_list); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_list)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
#line 90 "AccountOpts.xs"
	GList *l;
#line 405 "AccountOpts.c"
#line 92 "AccountOpts.xs"
	for (l = purple_account_option_get_list(option); l != NULL; l = l->next) {
		/* XXX These are actually PurpleKeyValuePairs but we don't have a
		 * type for that and even if we did I don't think there's
		 * anything perl could do with them, so I'm just going to
		 * leave this as a Purple::ListEntry for now. */
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::ListEntry")));
	}
#line 414 "AccountOpts.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Account__Option_get_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	Purple__PrefType	RETVAL;
	dXSTARG;

	RETVAL = purple_account_option_get_type(option);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_get_masked); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_masked)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_account_option_get_masked(option);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_get_default_int); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_default_int)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	int	RETVAL;
	dXSTARG;

	RETVAL = purple_account_option_get_default_int(option);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_get_default_bool); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_default_bool)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_account_option_get_default_bool(option);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_get_setting); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_setting)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_option_get_setting(option);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_get_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_get_text)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "option");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_option_get_text(option);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__Option_set_list); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_set_list)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "option, values");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	SV *	values = ST(1)
;
#line 129 "AccountOpts.xs"
	GList *t_GL;
	int i, t_len;
#line 551 "AccountOpts.c"
#line 132 "AccountOpts.xs"
	t_GL = NULL;
	t_len = av_len((AV *)SvRV(values));

	for (i = 0; i <= t_len; i++)
		t_GL = g_list_append(t_GL, SvPVutf8_nolen(*av_fetch((AV *)SvRV(values), i, 0)));

	purple_account_option_set_list(option, t_GL);
#line 560 "AccountOpts.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Account__Option_set_masked); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__Option_set_masked)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "option, masked");
    {
	Purple__Account__Option	option = purple_perl_ref_object(ST(0))
;
	gboolean	masked = (bool)SvTRUE(ST(1))
;

	purple_account_option_set_masked(option, masked);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Account__UserSplit_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__UserSplit_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, text, default_value, sep");
    {
	const char *	text = (const char *)SvPV_nolen(ST(1))
;
	const char *	default_value = (const char *)SvPV_nolen(ST(2))
;
	char	sep = (char)*SvPV_nolen(ST(3))
;
	Purple__Account__UserSplit	RETVAL;

	RETVAL = purple_account_user_split_new(text, default_value, sep);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account::UserSplit");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__UserSplit_get_separator); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__UserSplit_get_separator)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "split");
    {
	Purple__Account__UserSplit	split = purple_perl_ref_object(ST(0))
;
	char	RETVAL;
	dXSTARG;

	RETVAL = purple_account_user_split_get_separator(split);
	XSprePUSH; PUSHp((char *)&RETVAL, 1);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__UserSplit_get_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__UserSplit_get_text)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "split");
    {
	Purple__Account__UserSplit	split = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_account_user_split_get_text(split);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Account__UserSplit_destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Account__UserSplit_destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "split");
    {
	Purple__Account__UserSplit	split = purple_perl_ref_object(ST(0))
;

	purple_account_user_split_destroy(split);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple__Account__Option); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple__Account__Option)
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

        (void)newXSproto_portable("Purple::Account::Option::destroy", XS_Purple__Account__Option_destroy, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_default_string", XS_Purple__Account__Option_get_default_string, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::add_list_item", XS_Purple__Account__Option_add_list_item, file, "$$$");
        (void)newXSproto_portable("Purple::Account::Option::set_default_string", XS_Purple__Account__Option_set_default_string, file, "$$");
        (void)newXSproto_portable("Purple::Account::Option::set_default_int", XS_Purple__Account__Option_set_default_int, file, "$$");
        (void)newXSproto_portable("Purple::Account::Option::set_default_bool", XS_Purple__Account__Option_set_default_bool, file, "$$");
        (void)newXSproto_portable("Purple::Account::Option::list_new", XS_Purple__Account__Option_list_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Account::Option::string_new", XS_Purple__Account__Option_string_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Account::Option::int_new", XS_Purple__Account__Option_int_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Account::Option::bool_new", XS_Purple__Account__Option_bool_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Account::Option::new", XS_Purple__Account__Option_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Account::Option::get_list", XS_Purple__Account__Option_get_list, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_type", XS_Purple__Account__Option_get_type, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_masked", XS_Purple__Account__Option_get_masked, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_default_int", XS_Purple__Account__Option_get_default_int, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_default_bool", XS_Purple__Account__Option_get_default_bool, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_setting", XS_Purple__Account__Option_get_setting, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::get_text", XS_Purple__Account__Option_get_text, file, "$");
        (void)newXSproto_portable("Purple::Account::Option::set_list", XS_Purple__Account__Option_set_list, file, "$$");
        (void)newXSproto_portable("Purple::Account::Option::set_masked", XS_Purple__Account__Option_set_masked, file, "$$");
        (void)newXSproto_portable("Purple::Account::UserSplit::new", XS_Purple__Account__UserSplit_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Account::UserSplit::get_separator", XS_Purple__Account__UserSplit_get_separator, file, "$");
        (void)newXSproto_portable("Purple::Account::UserSplit::get_text", XS_Purple__Account__UserSplit_get_text, file, "$");
        (void)newXSproto_portable("Purple::Account::UserSplit::destroy", XS_Purple__Account__UserSplit_destroy, file, "$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

