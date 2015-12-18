/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of GtkBlist.xs. Do not edit this file, edit GtkBlist.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "GtkBlist.xs"
#include "gtkmodule.h"

#line 13 "GtkBlist.c"
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

#line 155 "GtkBlist.c"

XS_EUPXS(XS_Pidgin__BuddyList_get_handle); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_get_handle)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Handle	RETVAL;

	RETVAL = pidgin_blist_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Pidgin__BuddyList_get_default_gtk_blist); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_get_default_gtk_blist)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Pidgin__BuddyList	RETVAL;

	RETVAL = pidgin_blist_get_default_gtk_blist();
	ST(0) = purple_perl_bless_object(RETVAL, "Pidgin::BuddyList");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Pidgin__BuddyList_refresh); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_refresh)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "list");
    {
	Purple__BuddyList	list = purple_perl_ref_object(ST(0))
;

	pidgin_blist_refresh(list);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_update_refresh_timeout); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_update_refresh_timeout)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_update_refresh_timeout();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_node_is_contact_expanded); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_node_is_contact_expanded)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "node");
    {
	Purple__BuddyList__Node	node = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = pidgin_blist_node_is_contact_expanded(node);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Pidgin__BuddyList_toggle_visibility); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_toggle_visibility)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_toggle_visibility();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_visibility_manager_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_visibility_manager_add)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_visibility_manager_add();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_visibility_manager_remove); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_visibility_manager_remove)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_visibility_manager_remove();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_get_sort_methods); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_get_sort_methods)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 35 "GtkBlist.xs"
	GList *l;
#line 293 "GtkBlist.c"
#line 37 "GtkBlist.xs"
	for (l = pidgin_blist_get_sort_methods(); l != NULL; l = l->next) {
		XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Pidgin::BuddyList::SortMethod")));
	}
#line 298 "GtkBlist.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Pidgin__BuddyList_sort_method_reg); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_sort_method_reg)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "id, name, func");
    {
	const char *	id = (const char *)SvPV_nolen(ST(0))
;
	const char *	name = (const char *)SvPV_nolen(ST(1))
;
	Pidgin__BuddyList__SortFunction	func = purple_perl_ref_object(ST(2))
;

	pidgin_blist_sort_method_reg(id, name, func);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_sort_method_unreg); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_sort_method_unreg)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "id");
    {
	const char *	id = (const char *)SvPV_nolen(ST(0))
;

	pidgin_blist_sort_method_unreg(id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_sort_method_set); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_sort_method_set)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "id");
    {
	const char *	id = (const char *)SvPV_nolen(ST(0))
;

	pidgin_blist_sort_method_set(id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_setup_sort_methods); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_setup_sort_methods)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_setup_sort_methods();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_update_accounts_menu); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_update_accounts_menu)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_update_accounts_menu();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_update_plugin_actions); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_update_plugin_actions)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_update_plugin_actions();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_update_sort_methods); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_update_sort_methods)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_update_sort_methods();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_joinchat_is_showable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_joinchat_is_showable)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	gboolean	RETVAL;

	RETVAL = pidgin_blist_joinchat_is_showable();
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Pidgin__BuddyList_joinchat_show); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_joinchat_show)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {

	pidgin_blist_joinchat_show();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__BuddyList_update_account_error_state); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__BuddyList_update_account_error_state)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, message");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char *	message = (const char *)SvPV_nolen(ST(1))
;

	pidgin_blist_update_account_error_state(account, message);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Pidgin__BuddyList); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Pidgin__BuddyList)
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

        (void)newXSproto_portable("Pidgin::BuddyList::get_handle", XS_Pidgin__BuddyList_get_handle, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::get_default_gtk_blist", XS_Pidgin__BuddyList_get_default_gtk_blist, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::refresh", XS_Pidgin__BuddyList_refresh, file, "$");
        (void)newXSproto_portable("Pidgin::BuddyList::update_refresh_timeout", XS_Pidgin__BuddyList_update_refresh_timeout, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::node_is_contact_expanded", XS_Pidgin__BuddyList_node_is_contact_expanded, file, "$");
        (void)newXSproto_portable("Pidgin::BuddyList::toggle_visibility", XS_Pidgin__BuddyList_toggle_visibility, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::visibility_manager_add", XS_Pidgin__BuddyList_visibility_manager_add, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::visibility_manager_remove", XS_Pidgin__BuddyList_visibility_manager_remove, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::get_sort_methods", XS_Pidgin__BuddyList_get_sort_methods, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::sort_method_reg", XS_Pidgin__BuddyList_sort_method_reg, file, "$$$");
        (void)newXSproto_portable("Pidgin::BuddyList::sort_method_unreg", XS_Pidgin__BuddyList_sort_method_unreg, file, "$");
        (void)newXSproto_portable("Pidgin::BuddyList::sort_method_set", XS_Pidgin__BuddyList_sort_method_set, file, "$");
        (void)newXSproto_portable("Pidgin::BuddyList::setup_sort_methods", XS_Pidgin__BuddyList_setup_sort_methods, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::update_accounts_menu", XS_Pidgin__BuddyList_update_accounts_menu, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::update_plugin_actions", XS_Pidgin__BuddyList_update_plugin_actions, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::update_sort_methods", XS_Pidgin__BuddyList_update_sort_methods, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::joinchat_is_showable", XS_Pidgin__BuddyList_joinchat_is_showable, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::joinchat_show", XS_Pidgin__BuddyList_joinchat_show, file, "");
        (void)newXSproto_portable("Pidgin::BuddyList::update_account_error_state", XS_Pidgin__BuddyList_update_account_error_state, file, "$$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
