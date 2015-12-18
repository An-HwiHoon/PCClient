/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of GtkConv.xs. Do not edit this file, edit GtkConv.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "GtkConv.xs"
#include "gtkmodule.h"

#line 13 "GtkConv.c"
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

#line 155 "GtkConv.c"

XS_EUPXS(XS_Pidgin__Conversation_update_buddy_icon); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_update_buddy_icon)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0))
;

	pidgin_conv_update_buddy_icon(conv);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__Conversation_switch_active_conversation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_switch_active_conversation)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0))
;

	pidgin_conv_switch_active_conversation(conv);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__Conversation_update_buttons_by_protocol); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_update_buttons_by_protocol)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0))
;

	pidgin_conv_update_buttons_by_protocol(conv);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__Conversation_present_conversation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_present_conversation)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0))
;

	pidgin_conv_present_conversation(conv);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__Conversation_get_window); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_get_window)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    {
	Pidgin__Conversation	conv = purple_perl_ref_object(ST(0))
;
	Pidgin__Conversation__Window	RETVAL;

	RETVAL = pidgin_conv_get_window(conv);
	ST(0) = purple_perl_bless_object(RETVAL, "Pidgin::Conversation::Window");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Pidgin__Conversation_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_new)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, conv");
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(1))
;

	pidgin_conv_new(conv);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__Conversation_is_hidden); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_is_hidden)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "gtkconv");
    {
	Pidgin__Conversation	gtkconv = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = pidgin_conv_is_hidden(gtkconv);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Pidgin__Conversation_get_gtkconv); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversation_get_gtkconv)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "conv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Conversation	conv = purple_perl_ref_object(ST(0))
;
#line 40 "GtkConv.xs"
	if (conv != NULL && PIDGIN_IS_PIDGIN_CONVERSATION(conv))
		XPUSHs(sv_2mortal(purple_perl_bless_object(
				PIDGIN_CONVERSATION(conv),
				"Pidgin::Conversation")));
#line 291 "GtkConv.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Pidgin__Conversations_find_unseen_list); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversations_find_unseen_list)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "type, min_state, hidden_only, max_count");
    {
	Purple__ConversationType	type = (Purple__ConversationType)SvIV(ST(0))
;
	Pidgin__UnseenState	min_state = (Pidgin__UnseenState)SvIV(ST(1))
;
	gboolean	hidden_only = (bool)SvTRUE(ST(2))
;
	guint	max_count = (guint)SvIV(ST(3))
;

	pidgin_conversations_find_unseen_list(type, min_state, hidden_only, max_count);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Pidgin__Conversations_get_handle); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Pidgin__Conversations_get_handle)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Handle	RETVAL;

	RETVAL = pidgin_conversations_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Pidgin__Conversation); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Pidgin__Conversation)
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

        (void)newXSproto_portable("Pidgin::Conversation::update_buddy_icon", XS_Pidgin__Conversation_update_buddy_icon, file, "$");
        (void)newXSproto_portable("Pidgin::Conversation::switch_active_conversation", XS_Pidgin__Conversation_switch_active_conversation, file, "$");
        (void)newXSproto_portable("Pidgin::Conversation::update_buttons_by_protocol", XS_Pidgin__Conversation_update_buttons_by_protocol, file, "$");
        (void)newXSproto_portable("Pidgin::Conversation::present_conversation", XS_Pidgin__Conversation_present_conversation, file, "$");
        (void)newXSproto_portable("Pidgin::Conversation::get_window", XS_Pidgin__Conversation_get_window, file, "$");
        (void)newXSproto_portable("Pidgin::Conversation::new", XS_Pidgin__Conversation_new, file, "$$");
        (void)newXSproto_portable("Pidgin::Conversation::is_hidden", XS_Pidgin__Conversation_is_hidden, file, "$");
        (void)newXSproto_portable("Pidgin::Conversation::get_gtkconv", XS_Pidgin__Conversation_get_gtkconv, file, "$");
        (void)newXSproto_portable("Pidgin::Conversations::find_unseen_list", XS_Pidgin__Conversations_find_unseen_list, file, "$$$$");
        (void)newXSproto_portable("Pidgin::Conversations::get_handle", XS_Pidgin__Conversations_get_handle, file, "");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

