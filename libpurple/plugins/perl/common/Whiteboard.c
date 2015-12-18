/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of Whiteboard.xs. Do not edit this file, edit Whiteboard.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Whiteboard.xs"
#include "module.h"

#line 13 "Whiteboard.c"
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

#line 155 "Whiteboard.c"

XS_EUPXS(XS_Purple__Whiteboard_clear); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_clear)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wb");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;

	purple_whiteboard_clear(wb);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_create); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_create)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "account, who, state");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char*	who = (const char *)SvPV_nolen(ST(1))
;
	int	state = (int)SvIV(ST(2))
;
	Purple__Whiteboard	RETVAL;

	RETVAL = purple_whiteboard_create(account, who, state);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Whiteboard");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Whiteboard_destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wb");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;

	purple_whiteboard_destroy(wb);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_draw_line); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_draw_line)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "wb, x1, y1, x2, y2, color, size");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	int	x1 = (int)SvIV(ST(1))
;
	int	y1 = (int)SvIV(ST(2))
;
	int	x2 = (int)SvIV(ST(3))
;
	int	y2 = (int)SvIV(ST(4))
;
	int	color = (int)SvIV(ST(5))
;
	int	size = (int)SvIV(ST(6))
;

	purple_whiteboard_draw_line(wb, x1, y1, x2, y2, color, size);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_draw_point); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_draw_point)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "wb, x, y, color, size");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	int	x = (int)SvIV(ST(1))
;
	int	y = (int)SvIV(ST(2))
;
	int	color = (int)SvIV(ST(3))
;
	int	size = (int)SvIV(ST(4))
;

	purple_whiteboard_draw_point(wb, x, y, color, size);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_get_session); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_get_session)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "account, who");
    {
	Purple__Account	account = purple_perl_ref_object(ST(0))
;
	const char*	who = (const char *)SvPV_nolen(ST(1))
;
	Purple__Whiteboard	RETVAL;

	RETVAL = purple_whiteboard_get_session(account, who);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Whiteboard");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Whiteboard_send_brush); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_send_brush)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "wb, size, color");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	int	size = (int)SvIV(ST(1))
;
	int	color = (int)SvIV(ST(2))
;

	purple_whiteboard_send_brush(wb, size, color);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_send_clear); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_send_clear)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wb");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;

	purple_whiteboard_send_clear(wb);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_set_brush); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_set_brush)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "wb, size, color");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	int	size = (int)SvIV(ST(1))
;
	int	color = (int)SvIV(ST(2))
;

	purple_whiteboard_set_brush(wb, size, color);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_set_dimensions); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_set_dimensions)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "wb, width, height");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	int	width = (int)SvIV(ST(1))
;
	int	height = (int)SvIV(ST(2))
;

	purple_whiteboard_set_dimensions(wb, width, height);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Whiteboard_get_brush); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_get_brush)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wb");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;
	int	size;
	int	color;

	RETVAL = purple_whiteboard_get_brush(wb, &size, &color);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)size);
	PUSHs(sv_newmortal());
	sv_setiv(ST(2), (IV)color);
    }
    XSRETURN(3);
}


XS_EUPXS(XS_Purple__Whiteboard_get_dimensions); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_get_dimensions)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wb");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;
	int	width;
	int	height;

	RETVAL = purple_whiteboard_get_dimensions(wb, &width, &height);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)width);
	PUSHs(sv_newmortal());
	sv_setiv(ST(2), (IV)height);
    }
    XSRETURN(3);
}


XS_EUPXS(XS_Purple__Whiteboard_start); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Whiteboard_start)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "wb");
    {
	Purple__Whiteboard	wb = purple_perl_ref_object(ST(0))
;

	purple_whiteboard_start(wb);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple__Whiteboard); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple__Whiteboard)
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

        (void)newXSproto_portable("Purple::Whiteboard::clear", XS_Purple__Whiteboard_clear, file, "$");
        (void)newXSproto_portable("Purple::Whiteboard::create", XS_Purple__Whiteboard_create, file, "$$$");
        (void)newXSproto_portable("Purple::Whiteboard::destroy", XS_Purple__Whiteboard_destroy, file, "$");
        (void)newXSproto_portable("Purple::Whiteboard::draw_line", XS_Purple__Whiteboard_draw_line, file, "$$$$$$$");
        (void)newXSproto_portable("Purple::Whiteboard::draw_point", XS_Purple__Whiteboard_draw_point, file, "$$$$$");
        (void)newXSproto_portable("Purple::Whiteboard::get_session", XS_Purple__Whiteboard_get_session, file, "$$");
        (void)newXSproto_portable("Purple::Whiteboard::send_brush", XS_Purple__Whiteboard_send_brush, file, "$$$");
        (void)newXSproto_portable("Purple::Whiteboard::send_clear", XS_Purple__Whiteboard_send_clear, file, "$");
        (void)newXSproto_portable("Purple::Whiteboard::set_brush", XS_Purple__Whiteboard_set_brush, file, "$$$");
        (void)newXSproto_portable("Purple::Whiteboard::set_dimensions", XS_Purple__Whiteboard_set_dimensions, file, "$$$");
        (void)newXSproto_portable("Purple::Whiteboard::get_brush", XS_Purple__Whiteboard_get_brush, file, "$");
        (void)newXSproto_portable("Purple::Whiteboard::get_dimensions", XS_Purple__Whiteboard_get_dimensions, file, "$");
        (void)newXSproto_portable("Purple::Whiteboard::start", XS_Purple__Whiteboard_start, file, "$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

