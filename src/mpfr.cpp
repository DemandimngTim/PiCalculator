// ======================================================
// mpfr.cpp
// MPFR π conversion
// ======================================================


#include "pi.h"

#include <mpfr.h>




// ======================================================
// Convert GMP binary split result into π
// ======================================================


void calculate_pi_mpfr(
    BS &result,
    mpfr_t pi,
    long digits
)
{

    // MPFR precision
    // ~3.322 bits per decimal digit

    mpfr_prec_t precision =
        (digits * 3322) / 1000 + 16;



    mpfr_set_prec(
        pi,
        precision
    );



    mpfr_t sqrtC;
    mpfr_t q;
    mpfr_t t;



    mpfr_init2(
        sqrtC,
        precision
    );


    mpfr_init2(
        q,
        precision
    );


    mpfr_init2(
        t,
        precision
    );




    // 426880 * sqrt(10005)

    mpfr_sqrt_ui(
        sqrtC,
        10005,
        MPFR_RNDN
    );


    mpfr_mul_ui(
        sqrtC,
        sqrtC,
        426880,
        MPFR_RNDN
    );




    // GMP -> MPFR conversion

    mpfr_set_z(
        q,
        result.Q,
        MPFR_RNDN
    );


    mpfr_set_z(
        t,
        result.T,
        MPFR_RNDN
    );




    // π = 426880*sqrt(10005)*Q/T

    mpfr_div(
        pi,
        q,
        t,
        MPFR_RNDN
    );


    mpfr_mul(
        pi,
        pi,
        sqrtC,
        MPFR_RNDN
    );




    mpfr_clear(
        sqrtC
    );


    mpfr_clear(
        q
    );


    mpfr_clear(
        t
    );

}
