/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of FT.xs. Do not edit this file, edit FT.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "FT.xs"
#include "module.h"

#line 13 "FT.c"
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

#line 155 "FT.c"

XS_EUPXS(XS_Purple__Xfer_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_new)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, account, type, who");
    {
	Purple__Account	account = purple_perl_ref_object(ST(1))
;
	Purple__XferType	type = (Purple__XferType)SvIV(ST(2))
;
	const char *	who = (const char *)SvPV_nolen(ST(3))
;
	Purple__Xfer	RETVAL;

	RETVAL = purple_xfer_new(account, type, who);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Xfer");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_add)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_add(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_cancel_local); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_cancel_local)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_cancel_local(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_cancel_remote); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_cancel_remote)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_cancel_remote(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_end); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_end)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_end(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_error); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_error)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "type, account, who, msg");
    {
	Purple__XferType	type = (Purple__XferType)SvIV(ST(0))
;
	Purple__Account	account = purple_perl_ref_object(ST(1))
;
	const char *	who = (const char *)SvPV_nolen(ST(2))
;
	const char *	msg = (const char *)SvPV_nolen(ST(3))
;

	purple_xfer_error(type, account, who, msg);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_get_account); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_account)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	Purple__Account	RETVAL;

	RETVAL = purple_xfer_get_account(xfer);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Account");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_bytes_remaining); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_bytes_remaining)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	size_t	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_bytes_remaining(xfer);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_bytes_sent); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_bytes_sent)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	size_t	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_bytes_sent(xfer);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_filename); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_filename)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_filename(xfer);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_local_filename); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_local_filename)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_local_filename(xfer);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_local_port); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_local_port)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	unsigned int	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_local_port(xfer);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_progress); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_progress)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	double	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_progress(xfer);
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_remote_ip); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_remote_ip)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_remote_ip(xfer);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_remote_port); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_remote_port)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	unsigned int	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_remote_port(xfer);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_size)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	size_t	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_size(xfer);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_status); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_status)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	Purple__XferStatusType	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_status(xfer);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_get_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_get_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	Purple__XferType	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_get_type(xfer);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_is_canceled); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_is_canceled)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_xfer_is_canceled(xfer);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_is_completed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_is_completed)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_xfer_is_completed(xfer);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_read); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_read)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, buffer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	guchar **	buffer = INT2PTR(guchar **,SvIV(ST(1)))
;
	ssize_t	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_read(xfer, buffer);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Xfer_ref); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_ref)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_ref(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_request); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_request)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_request(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_request_accepted); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_request_accepted)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, filename");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	filename = (const char *)SvPV_nolen(ST(1))
;

	purple_xfer_request_accepted(xfer, filename);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_request_denied); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_request_denied)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_request_denied(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_set_completed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_set_completed)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, completed");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	gboolean	completed = (bool)SvTRUE(ST(1))
;

	purple_xfer_set_completed(xfer, completed);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_set_filename); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_set_filename)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, filename");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	filename = (const char *)SvPV_nolen(ST(1))
;

	purple_xfer_set_filename(xfer, filename);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_set_local_filename); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_set_local_filename)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, filename");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	filename = (const char *)SvPV_nolen(ST(1))
;

	purple_xfer_set_local_filename(xfer, filename);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_set_message); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_set_message)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, message");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const char *	message = (const char *)SvPV_nolen(ST(1))
;

	purple_xfer_set_message(xfer, message);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_set_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_set_size)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "xfer, size");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	size_t	size = (size_t)SvUV(ST(1))
;

	purple_xfer_set_size(xfer, size);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_unref); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_unref)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_unref(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_update_progress); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_update_progress)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "xfer");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;

	purple_xfer_update_progress(xfer);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Xfer_write); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Xfer_write)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "xfer, buffer, size");
    {
	Purple__Xfer	xfer = purple_perl_ref_object(ST(0))
;
	const guchar *	buffer = (const guchar *)SvPV_nolen(ST(1))
;
	size_t	size = (size_t)SvUV(ST(2))
;
	ssize_t	RETVAL;
	dXSTARG;

	RETVAL = purple_xfer_write(xfer, buffer, size);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple__Xfer); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple__Xfer)
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

        (void)newXSproto_portable("Purple::Xfer::new", XS_Purple__Xfer_new, file, "$$$$");
        (void)newXSproto_portable("Purple::Xfer::add", XS_Purple__Xfer_add, file, "$");
        (void)newXSproto_portable("Purple::Xfer::cancel_local", XS_Purple__Xfer_cancel_local, file, "$");
        (void)newXSproto_portable("Purple::Xfer::cancel_remote", XS_Purple__Xfer_cancel_remote, file, "$");
        (void)newXSproto_portable("Purple::Xfer::end", XS_Purple__Xfer_end, file, "$");
        (void)newXSproto_portable("Purple::Xfer::error", XS_Purple__Xfer_error, file, "$$$$");
        (void)newXSproto_portable("Purple::Xfer::get_account", XS_Purple__Xfer_get_account, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_bytes_remaining", XS_Purple__Xfer_get_bytes_remaining, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_bytes_sent", XS_Purple__Xfer_get_bytes_sent, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_filename", XS_Purple__Xfer_get_filename, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_local_filename", XS_Purple__Xfer_get_local_filename, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_local_port", XS_Purple__Xfer_get_local_port, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_progress", XS_Purple__Xfer_get_progress, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_remote_ip", XS_Purple__Xfer_get_remote_ip, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_remote_port", XS_Purple__Xfer_get_remote_port, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_size", XS_Purple__Xfer_get_size, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_status", XS_Purple__Xfer_get_status, file, "$");
        (void)newXSproto_portable("Purple::Xfer::get_type", XS_Purple__Xfer_get_type, file, "$");
        (void)newXSproto_portable("Purple::Xfer::is_canceled", XS_Purple__Xfer_is_canceled, file, "$");
        (void)newXSproto_portable("Purple::Xfer::is_completed", XS_Purple__Xfer_is_completed, file, "$");
        (void)newXSproto_portable("Purple::Xfer::read", XS_Purple__Xfer_read, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::ref", XS_Purple__Xfer_ref, file, "$");
        (void)newXSproto_portable("Purple::Xfer::request", XS_Purple__Xfer_request, file, "$");
        (void)newXSproto_portable("Purple::Xfer::request_accepted", XS_Purple__Xfer_request_accepted, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::request_denied", XS_Purple__Xfer_request_denied, file, "$");
        (void)newXSproto_portable("Purple::Xfer::set_completed", XS_Purple__Xfer_set_completed, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::set_filename", XS_Purple__Xfer_set_filename, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::set_local_filename", XS_Purple__Xfer_set_local_filename, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::set_message", XS_Purple__Xfer_set_message, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::set_size", XS_Purple__Xfer_set_size, file, "$$");
        (void)newXSproto_portable("Purple::Xfer::unref", XS_Purple__Xfer_unref, file, "$");
        (void)newXSproto_portable("Purple::Xfer::update_progress", XS_Purple__Xfer_update_progress, file, "$");
        (void)newXSproto_portable("Purple::Xfer::write", XS_Purple__Xfer_write, file, "$$$");

    /* Initialisation Section */

#line 7 "FT.xs"
{
	HV *type_stash = gv_stashpv("Purple::Xfer::Type", 1);
	HV *status_stash = gv_stashpv("Purple::Xfer::Status", 1);

	static const constiv *civ, type_const_iv[] = {
#define const_iv(name) {#name, (IV)PURPLE_XFER_##name}
		const_iv(UNKNOWN),
		const_iv(SEND),
		const_iv(RECEIVE),
	};
	static const constiv status_const_iv[] = {
#undef const_iv
#define const_iv(name) {#name, (IV)PURPLE_XFER_STATUS_##name}
		const_iv(UNKNOWN),
		const_iv(NOT_STARTED),
		const_iv(ACCEPTED),
		const_iv(STARTED),
		const_iv(DONE),
		const_iv(CANCEL_LOCAL),
		const_iv(CANCEL_REMOTE),
	};

	for (civ = type_const_iv + sizeof(type_const_iv) / sizeof(type_const_iv[0]); civ-- > type_const_iv; )
		newCONSTSUB(type_stash, (char *)civ->name, newSViv(civ->iv));

	for (civ = status_const_iv + sizeof(status_const_iv) / sizeof(status_const_iv[0]); civ-- > status_const_iv; )
		newCONSTSUB(status_stash, (char *)civ->name, newSViv(civ->iv));
}

#line 849 "FT.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

