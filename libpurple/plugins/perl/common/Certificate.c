/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of Certificate.xs. Do not edit this file, edit Certificate.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Certificate.xs"
#include "module.h"

struct cb_data {
	SV *cb;
	SV *user_data;
};

static void cb_cert_verify(PurpleCertificateVerificationStatus st, struct cb_data *d) {
	dSP;

	ENTER;
	SAVETMPS;

	PUSHMARK(SP);

	XPUSHs(sv_2mortal(newSViv(st)));
	XPUSHs(d->user_data);

	PUTBACK;

	call_sv(d->cb, G_VOID | G_EVAL);

	if(SvTRUE(ERRSV)) {
		STRLEN l_a;
		purple_debug_warning("perl", "Failed to run 'certificate verify' callback: %s\n", SvPV(ERRSV, l_a));
	}

	FREETMPS;
	LEAVE;

	SvREFCNT_dec(d->cb);
	SvREFCNT_dec(d->user_data);

	g_free(d);
}

#line 47 "Certificate.c"
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

#line 189 "Certificate.c"

XS_EUPXS(XS_Purple__Certificate_add_ca_search_path); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_add_ca_search_path)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "path");
    {
	const char*	path = (const char *)SvPV_nolen(ST(0))
;

	purple_certificate_add_ca_search_path(path);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Certificate_check_subject_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_check_subject_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "crt, name");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	const gchar*	name = (const gchar *)SvPV_nolen(ST(1))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_check_subject_name(crt, name);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_copy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_copy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	Purple__Certificate	RETVAL;

	RETVAL = purple_certificate_copy(crt);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;

	purple_certificate_destroy(crt);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Certificate_display_x509); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_display_x509)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;

	purple_certificate_display_x509(crt);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Certificate_export); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_export)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "crt, filename");
    {
	const gchar*	filename = (const gchar *)SvPV_nolen(ST(1))
;
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_export(filename, crt);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_find_pool); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_find_pool)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scheme_name, pool_name");
    {
	const gchar*	scheme_name = (const gchar *)SvPV_nolen(ST(0))
;
	const gchar*	pool_name = (const gchar *)SvPV_nolen(ST(1))
;
	Purple__Certificate__Pool	RETVAL;

	RETVAL = purple_certificate_find_pool(scheme_name, pool_name);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate::Pool");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_find_scheme); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_find_scheme)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "name");
    {
	const gchar*	name = (const gchar *)SvPV_nolen(ST(0))
;
	Purple__Certificate__Scheme	RETVAL;

	RETVAL = purple_certificate_find_scheme(name);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate::Scheme");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_find_verifier); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_find_verifier)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scheme_name, ver_name");
    {
	const gchar*	scheme_name = (const gchar *)SvPV_nolen(ST(0))
;
	const gchar*	ver_name = (const gchar *)SvPV_nolen(ST(1))
;
	Purple__Certificate__Verifier	RETVAL;

	RETVAL = purple_certificate_find_verifier(scheme_name, ver_name);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate::Verifier");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_get_handle); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_handle)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	Purple__Handle	RETVAL;

	RETVAL = purple_certificate_get_handle();
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Handle");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_get_issuer_unique_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_issuer_unique_id)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	gchar_own *	RETVAL;

	RETVAL = purple_certificate_get_issuer_unique_id(crt);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_get_subject_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_subject_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	gchar_own *	RETVAL;

	RETVAL = purple_certificate_get_subject_name(crt);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_get_unique_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_unique_id)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	gchar_own *	RETVAL;

	RETVAL = purple_certificate_get_unique_id(crt);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_import); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_import)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scheme, filename");
    {
	Purple__Certificate__Scheme	scheme = purple_perl_ref_object(ST(0))
;
	const gchar*	filename = (const gchar *)SvPV_nolen(ST(1))
;
	Purple__Certificate	RETVAL;

	RETVAL = purple_certificate_import(scheme, filename);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_register_pool); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_register_pool)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pool");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_register_pool(pool);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_register_scheme); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_register_scheme)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scheme");
    {
	Purple__Certificate__Scheme	scheme = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_register_scheme(scheme);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_register_verifier); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_register_verifier)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "vr");
    {
	Purple__Certificate__Verifier	vr = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_register_verifier(vr);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_signed_by); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_signed_by)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "crt, issuer");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	Purple__Certificate	issuer = purple_perl_ref_object(ST(1))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_signed_by(crt, issuer);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_unregister_pool); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_unregister_pool)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pool");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_unregister_pool(pool);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_unregister_scheme); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_unregister_scheme)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scheme");
    {
	Purple__Certificate__Scheme	scheme = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_unregister_scheme(scheme);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_unregister_verifier); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_unregister_verifier)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "vr");
    {
	Purple__Certificate__Verifier	vr = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_unregister_verifier(vr);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_verify_complete); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_verify_complete)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "vrq, st");
    {
	Purple__Certificate__VerificationRequest	vrq = purple_perl_ref_object(ST(0))
;
	Purple__Certificate__VerificationStatus	st = (Purple__Certificate__VerificationStatus)SvIV(ST(1))
;

	purple_certificate_verify_complete(vrq, st);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Certificate_get_times); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_times)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;
	time_t	activation;
	time_t	expiration;

	RETVAL = purple_certificate_get_times(crt, &activation, &expiration);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)activation);
	PUSHs(sv_newmortal());
	sv_setiv(ST(2), (IV)expiration);
    }
    XSRETURN(3);
}


XS_EUPXS(XS_Purple__Certificate_destroy_list); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_destroy_list)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    {
#line 159 "Certificate.xs"
	GList* l = NULL;
	int i = 0;
#line 659 "Certificate.c"
#line 162 "Certificate.xs"
		for(i = 0; i < items; i++) { /* PurpleCertificate */
			l = g_list_prepend(l, purple_perl_ref_object(ST(i)));
		}
		purple_certificate_destroy_list(l);
#line 665 "Certificate.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Purple__Certificate_get_pools); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_pools)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 170 "Certificate.xs"
		GList *l;
#line 682 "Certificate.c"
#line 172 "Certificate.xs"
		for(l = purple_certificate_get_pools(); l; l = l->next) {
			XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Certificate::Pool")));
		}
#line 687 "Certificate.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Certificate_get_schemes); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_schemes)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 179 "Certificate.xs"
		GList *l;
#line 705 "Certificate.c"
#line 181 "Certificate.xs"
		for(l = purple_certificate_get_schemes(); l; l = l->next) {
			XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Certificate::Scheme")));
		}
#line 710 "Certificate.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Certificate_get_verifiers); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_verifiers)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 188 "Certificate.xs"
		GList *l;
#line 728 "Certificate.c"
#line 190 "Certificate.xs"
		for(l = purple_certificate_get_verifiers(); l; l = l->next) {
			XPUSHs(sv_2mortal(purple_perl_bless_object(l->data, "Purple::Certificate::Verifier")));
		}
#line 733 "Certificate.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Certificate_check_signature_chain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_check_signature_chain)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 197 "Certificate.xs"
		GList *l = NULL;
		gboolean ret;
		int i;
#line 752 "Certificate.c"
#line 201 "Certificate.xs"
		for(i = 0; i < items; i++) { /* PurpleCertificate */
			l = g_list_prepend(l, purple_perl_ref_object(ST(i)));
		}
		l = g_list_reverse(l);
		ret = purple_certificate_check_signature_chain(l);
		g_list_free(l);
		if(ret) XSRETURN_YES;
		XSRETURN_NO;
#line 762 "Certificate.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Certificate_get_fingerprint_sha1); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_get_fingerprint_sha1)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "crt");
    {
	Purple__Certificate	crt = purple_perl_ref_object(ST(0))
;
#line 214 "Certificate.xs"
		GByteArray *gba = NULL;
#line 780 "Certificate.c"
	SV *	RETVAL;
#line 216 "Certificate.xs"
		gba = purple_certificate_get_fingerprint_sha1(crt);
		RETVAL = newSVpv((gchar *)gba->data, gba->len);
		g_byte_array_free(gba, TRUE);
#line 786 "Certificate.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate_verify); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate_verify)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "verifier, subject_name, cert_chain, cb, cb_data");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Certificate__Verifier	verifier = purple_perl_ref_object(ST(0))
;
	const gchar*	subject_name = (const gchar *)SvPV_nolen(ST(1))
;
	AV*	cert_chain;
	SV *	cb_data = ST(4)
;
#line 229 "Certificate.xs"
		GList *l = NULL;
		int len = 0, i = 0;
		struct cb_data *d = NULL;
#line 814 "Certificate.c"

	STMT_START {
		SV* const xsub_tmp_sv = ST(2);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV){
		    cert_chain = (AV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak(aTHX_ "%s: %s is not an ARRAY reference",
				"Purple::Certificate::verify",
				"cert_chain");
		}
	} STMT_END
;
#line 233 "Certificate.xs"
		len = av_len(cert_chain);
		for(i = 0; i <= len; i++) {
			SV **sv = av_fetch(cert_chain, i, 0);
			if(!sv || !purple_perl_is_ref_object(*sv)) {
				g_list_free(l);
				warn("Purple::Certificate::verify: cert_chain: non-purple object in array...");
				XSRETURN_UNDEF;
			}
			l = g_list_prepend(l, purple_perl_ref_object(*sv));
		}
		l = g_list_reverse(l);

		d = g_new0(struct cb_data, 1);
		d->cb = newSVsv(ST(3));
		d->user_data = newSVsv(cb_data);

		purple_certificate_verify(verifier, subject_name, l, (PurpleCertificateVerifiedCallback) cb_cert_verify, d);

		g_list_free(l);
#line 849 "Certificate.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Certificate__Pool_get_idlist); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_get_idlist)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pool");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
#line 260 "Certificate.xs"
		GList *l, *b;
#line 869 "Certificate.c"
#line 262 "Certificate.xs"
		b = purple_certificate_pool_get_idlist(pool);
		for(l = b; l; l = l->next) {
			XPUSHs(sv_2mortal(newSVpv(l->data, 0)));
		}
		purple_certificate_pool_destroy_idlist(b);
#line 876 "Certificate.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Purple__Certificate__Pool_contains); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_contains)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pool, id");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	const gchar*	id = (const gchar *)SvPV_nolen(ST(1))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_pool_contains(pool, id);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate__Pool_delete); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_delete)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pool, id");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	const gchar*	id = (const gchar *)SvPV_nolen(ST(1))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_pool_delete(pool, id);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate__Pool_get_scheme); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_get_scheme)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pool");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	Purple__Certificate__Scheme	RETVAL;

	RETVAL = purple_certificate_pool_get_scheme(pool);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate::Scheme");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate__Pool_mkpath); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_mkpath)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pool, id");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	const gchar*	id = (const gchar *)SvPV_nolen(ST(1))
;
	gchar_own *	RETVAL;

	RETVAL = purple_certificate_pool_mkpath(pool, id);
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
	 * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
	g_free (RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate__Pool_retrieve); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_retrieve)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pool, id");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	const gchar*	id = (const gchar *)SvPV_nolen(ST(1))
;
	Purple__Certificate	RETVAL;

	RETVAL = purple_certificate_pool_retrieve(pool, id);
	ST(0) = purple_perl_bless_object(RETVAL, "Purple::Certificate");
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate__Pool_store); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_store)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "pool, id, crt");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	const gchar*	id = (const gchar *)SvPV_nolen(ST(1))
;
	Purple__Certificate	crt = purple_perl_ref_object(ST(2))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_pool_store(pool, id, crt);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Purple__Certificate__Pool_usable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Purple__Certificate__Pool_usable)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pool");
    {
	Purple__Certificate__Pool	pool = purple_perl_ref_object(ST(0))
;
	gboolean	RETVAL;

	RETVAL = purple_certificate_pool_usable(pool);
	ST(0) = sv_newmortal();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Purple__Certificate); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Purple__Certificate)
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

        (void)newXSproto_portable("Purple::Certificate::add_ca_search_path", XS_Purple__Certificate_add_ca_search_path, file, "$");
        (void)newXSproto_portable("Purple::Certificate::check_subject_name", XS_Purple__Certificate_check_subject_name, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::copy", XS_Purple__Certificate_copy, file, "$");
        (void)newXSproto_portable("Purple::Certificate::destroy", XS_Purple__Certificate_destroy, file, "$");
        (void)newXSproto_portable("Purple::Certificate::display_x509", XS_Purple__Certificate_display_x509, file, "$");
        (void)newXSproto_portable("Purple::Certificate::export", XS_Purple__Certificate_export, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::find_pool", XS_Purple__Certificate_find_pool, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::find_scheme", XS_Purple__Certificate_find_scheme, file, "$");
        (void)newXSproto_portable("Purple::Certificate::find_verifier", XS_Purple__Certificate_find_verifier, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::get_handle", XS_Purple__Certificate_get_handle, file, "");
        (void)newXSproto_portable("Purple::Certificate::get_issuer_unique_id", XS_Purple__Certificate_get_issuer_unique_id, file, "$");
        (void)newXSproto_portable("Purple::Certificate::get_subject_name", XS_Purple__Certificate_get_subject_name, file, "$");
        (void)newXSproto_portable("Purple::Certificate::get_unique_id", XS_Purple__Certificate_get_unique_id, file, "$");
        (void)newXSproto_portable("Purple::Certificate::import", XS_Purple__Certificate_import, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::register_pool", XS_Purple__Certificate_register_pool, file, "$");
        (void)newXSproto_portable("Purple::Certificate::register_scheme", XS_Purple__Certificate_register_scheme, file, "$");
        (void)newXSproto_portable("Purple::Certificate::register_verifier", XS_Purple__Certificate_register_verifier, file, "$");
        (void)newXSproto_portable("Purple::Certificate::signed_by", XS_Purple__Certificate_signed_by, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::unregister_pool", XS_Purple__Certificate_unregister_pool, file, "$");
        (void)newXSproto_portable("Purple::Certificate::unregister_scheme", XS_Purple__Certificate_unregister_scheme, file, "$");
        (void)newXSproto_portable("Purple::Certificate::unregister_verifier", XS_Purple__Certificate_unregister_verifier, file, "$");
        (void)newXSproto_portable("Purple::Certificate::verify_complete", XS_Purple__Certificate_verify_complete, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::get_times", XS_Purple__Certificate_get_times, file, "$");
        (void)newXSproto_portable("Purple::Certificate::destroy_list", XS_Purple__Certificate_destroy_list, file, ";@");
        (void)newXSproto_portable("Purple::Certificate::get_pools", XS_Purple__Certificate_get_pools, file, "");
        (void)newXSproto_portable("Purple::Certificate::get_schemes", XS_Purple__Certificate_get_schemes, file, "");
        (void)newXSproto_portable("Purple::Certificate::get_verifiers", XS_Purple__Certificate_get_verifiers, file, "");
        (void)newXSproto_portable("Purple::Certificate::check_signature_chain", XS_Purple__Certificate_check_signature_chain, file, ";@");
        (void)newXSproto_portable("Purple::Certificate::get_fingerprint_sha1", XS_Purple__Certificate_get_fingerprint_sha1, file, "$");
        (void)newXSproto_portable("Purple::Certificate::verify", XS_Purple__Certificate_verify, file, "$$$$$");
        (void)newXSproto_portable("Purple::Certificate::Pool::get_idlist", XS_Purple__Certificate__Pool_get_idlist, file, "$");
        (void)newXSproto_portable("Purple::Certificate::Pool::contains", XS_Purple__Certificate__Pool_contains, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::Pool::delete", XS_Purple__Certificate__Pool_delete, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::Pool::get_scheme", XS_Purple__Certificate__Pool_get_scheme, file, "$");
        (void)newXSproto_portable("Purple::Certificate::Pool::mkpath", XS_Purple__Certificate__Pool_mkpath, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::Pool::retrieve", XS_Purple__Certificate__Pool_retrieve, file, "$$");
        (void)newXSproto_portable("Purple::Certificate::Pool::store", XS_Purple__Certificate__Pool_store, file, "$$$");
        (void)newXSproto_portable("Purple::Certificate::Pool::usable", XS_Purple__Certificate__Pool_usable, file, "$");

    /* Initialisation Section */

#line 41 "Certificate.xs"
{
	HV *stash = gv_stashpv("Purple::Certificate", 1);

	static const constiv *civ, const_iv[] = {
#define const_iv(name) {#name, (IV)PURPLE_CERTIFICATE_##name}
		const_iv(INVALID),
		const_iv(VALID),
	};

	for (civ = const_iv + sizeof(const_iv) / sizeof(const_iv[0]); civ-- > const_iv; )
		newCONSTSUB(stash, (char *)civ->name, newSViv(civ->iv));
}

#line 1107 "Certificate.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

