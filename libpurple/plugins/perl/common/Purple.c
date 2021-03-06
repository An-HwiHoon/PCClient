/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of Purple.xs. Do not edit this file, edit Purple.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Purple.xs"
#include "module.h"
#include "../perl-handlers.h"

/* Prototypes for the BOOT section below. */
PURPLE_PERL_BOOT_PROTO(Account);
PURPLE_PERL_BOOT_PROTO(Account__Option);
PURPLE_PERL_BOOT_PROTO(Buddy__Icon);
PURPLE_PERL_BOOT_PROTO(BuddyList);
PURPLE_PERL_BOOT_PROTO(Certificate);
PURPLE_PERL_BOOT_PROTO(Cipher);
PURPLE_PERL_BOOT_PROTO(Cmd);
PURPLE_PERL_BOOT_PROTO(Connection);
PURPLE_PERL_BOOT_PROTO(Conversation);
PURPLE_PERL_BOOT_PROTO(Core);
PURPLE_PERL_BOOT_PROTO(Debug);
PURPLE_PERL_BOOT_PROTO(Xfer);
PURPLE_PERL_BOOT_PROTO(Idle);
PURPLE_PERL_BOOT_PROTO(ImgStore);
PURPLE_PERL_BOOT_PROTO(Log);
PURPLE_PERL_BOOT_PROTO(Network);
PURPLE_PERL_BOOT_PROTO(Notify);
PURPLE_PERL_BOOT_PROTO(Plugin);
PURPLE_PERL_BOOT_PROTO(PluginPref);
PURPLE_PERL_BOOT_PROTO(Pounce);
PURPLE_PERL_BOOT_PROTO(Prefs);
PURPLE_PERL_BOOT_PROTO(Privacy);
PURPLE_PERL_BOOT_PROTO(Proxy);
PURPLE_PERL_BOOT_PROTO(Prpl);
PURPLE_PERL_BOOT_PROTO(Request);
PURPLE_PERL_BOOT_PROTO(Roomlist);
PURPLE_PERL_BOOT_PROTO(SSL);
PURPLE_PERL_BOOT_PROTO(SavedStatus);
PURPLE_PERL_BOOT_PROTO(Serv);
PURPLE_PERL_BOOT_PROTO(Signal);
PURPLE_PERL_BOOT_PROTO(Smiley);
PURPLE_PERL_BOOT_PROTO(Sound);
PURPLE_PERL_BOOT_PROTO(Status);
PURPLE_PERL_BOOT_PROTO(Stringref);
PURPLE_PERL_BOOT_PROTO(Util);
PURPLE_PERL_BOOT_PROTO(Whiteboard);
PURPLE_PERL_BOOT_PROTO(XMLNode);

#line 53 "Purple.c"
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

#line 195 "Purple.c"

XS_EUPXS(XS_Purple_timeout_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple_timeout_add)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "plugin, seconds, callback, data = 0");
    {
	Purple__Plugin	plugin = purple_perl_ref_object(ST(0))
;
	int	seconds = (int)SvIV(ST(1))
;
	SV *	callback = ST(2)
;
	SV *	data;
	guint	RETVAL;
	dXSTARG;

	if (items < 4)
	    data = 0;
	else {
	    data = ST(3)
;
	}
#line 92 "Purple.xs"
	RETVAL = purple_perl_timeout_add(plugin, seconds, callback, data);
#line 222 "Purple.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple_timeout_remove); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple_timeout_remove)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "handle");
    {
	guint	handle = (guint)SvIV(ST(0))
;
	gboolean	RETVAL;
#line 100 "Purple.xs"
	RETVAL = purple_perl_timeout_remove(handle);
#line 241 "Purple.c"
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple_deinit); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple_deinit)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 107 "Purple.xs"
	purple_perl_timeout_clear();
#line 258 "Purple.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple_get_core); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple_get_core)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Core	RETVAL;

	RETVAL = purple_get_core();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Core");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple)
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

        (void)newXSproto_portable("Purple::timeout_add", XS_Purple_timeout_add, file, "$$$;$");
        (void)newXSproto_portable("Purple::timeout_remove", XS_Purple_timeout_remove, file, "$");
        (void)newXSproto_portable("Purple::deinit", XS_Purple_deinit, file, "");
        (void)newXSproto_portable("Purple::get_core", XS_Purple_get_core, file, "");

    /* Initialisation Section */

#line 47 "Purple.xs"
	PURPLE_PERL_BOOT(Account);
	PURPLE_PERL_BOOT(Account__Option);
	PURPLE_PERL_BOOT(Buddy__Icon);
	PURPLE_PERL_BOOT(BuddyList);
	PURPLE_PERL_BOOT(Certificate);
	PURPLE_PERL_BOOT(Cipher);
	PURPLE_PERL_BOOT(Cmd);
	PURPLE_PERL_BOOT(Connection);
	PURPLE_PERL_BOOT(Conversation);
	PURPLE_PERL_BOOT(Core);
	PURPLE_PERL_BOOT(Debug);
	PURPLE_PERL_BOOT(Xfer);
	PURPLE_PERL_BOOT(Idle);
	PURPLE_PERL_BOOT(ImgStore);
	PURPLE_PERL_BOOT(Log);
	PURPLE_PERL_BOOT(Network);
	PURPLE_PERL_BOOT(Notify);
	PURPLE_PERL_BOOT(Plugin);
	PURPLE_PERL_BOOT(PluginPref);
	PURPLE_PERL_BOOT(Pounce);
	PURPLE_PERL_BOOT(Prefs);
	PURPLE_PERL_BOOT(Privacy);
	PURPLE_PERL_BOOT(Proxy);
	PURPLE_PERL_BOOT(Prpl);
	PURPLE_PERL_BOOT(Request);
	PURPLE_PERL_BOOT(Roomlist);
	PURPLE_PERL_BOOT(SSL);
	PURPLE_PERL_BOOT(SavedStatus);
	PURPLE_PERL_BOOT(Serv);
	PURPLE_PERL_BOOT(Signal);
	PURPLE_PERL_BOOT(Smiley);
	PURPLE_PERL_BOOT(Sound);
	PURPLE_PERL_BOOT(Status);
	PURPLE_PERL_BOOT(Stringref);
	PURPLE_PERL_BOOT(Util);
	PURPLE_PERL_BOOT(Whiteboard);
	PURPLE_PERL_BOOT(XMLNode);

#line 346 "Purple.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

