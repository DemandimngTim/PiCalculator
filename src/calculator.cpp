// ======================================================
// calculator.cpp
// Chudnovsky π engine
// ======================================================

#include "pi.h"

#include <gmp.h>
#include <mpfr.h>

#include <thread>
#include <atomic>

using namespace std;


// Chudnovsky constants

const long A = 13591409;
const long B = 545140134;


// Progress counter
extern atomic<long> terms_done;


// Tree settings
extern int MAX_TREE_DEPTH;


// ======================================================
// Binary split structure
// ======================================================

void bs_init(
    BS &x
)
{
    mpz_init(x.P);
    mpz_init(x.Q);
    mpz_init(x.T);
}



void bs_clear(
    BS &x
)
{
    mpz_clear(x.P);
    mpz_clear(x.Q);
    mpz_clear(x.T);
}
// ======================================================
// Binary split engine
// Chudnovsky algorithm
// ======================================================


void binary_split(
    long a,
    long b,
    BS &r,
    int depth
)
{

    // ------------------------------
    // Leaf calculation
    // ------------------------------

    if(b - a == 1)
    {

        // First term

        if(a == 0)
        {

            mpz_set_ui(
                r.P,
                1
            );

            mpz_set_ui(
                r.Q,
                1
            );

            mpz_set_si(
                r.T,
                A
            );

        }

        else
        {

            // P = (6a-5)(2a-1)(6a-1)

            mpz_set_si(
                r.P,
                6*a - 5
            );


            mpz_mul_si(
                r.P,
                r.P,
                2*a - 1
            );


            mpz_mul_si(
                r.P,
                r.P,
                6*a - 1
            );



            // Q = 10939058860032000*a³

            mpz_set_ui(
                r.Q,
                10939058860032000ULL
            );


            mpz_mul_ui(
                r.Q,
                r.Q,
                a
            );


            mpz_mul_ui(
                r.Q,
                r.Q,
                a
            );


            mpz_mul_ui(
                r.Q,
                r.Q,
                a
            );



            // T = P*(A+B*a)

            mpz_set_si(
                r.T,
                A + B*a
            );


            mpz_mul(
                r.T,
                r.T,
                r.P
            );


            // Alternating signs

            if(a % 2)
            {

                mpz_neg(
                    r.T,
                    r.T
                );

            }

        }


        terms_done++;

        return;

    }



    // ------------------------------
    // Split recursively
    // ------------------------------

    long mid =
        (a + b) / 2;



    BS left;
    BS right;


    bs_init(left);
    bs_init(right);



    // ------------------------------
    // Parallel branch
    // ------------------------------

    if(
        depth < MAX_TREE_DEPTH
    )
    {

        thread worker(
            [&]()
            {

                set_core(7);


                binary_split(
                    a,
                    mid,
                    left,
                    depth + 1
                );

            }
        );



        set_core(6);


        binary_split(
            mid,
            b,
            right,
            depth + 1
        );


        worker.join();

    }

    else
    {

        binary_split(
            a,
            mid,
            left,
            depth + 1
        );


        binary_split(
            mid,
            b,
            right,
            depth + 1
        );

    }



    // ------------------------------
    // Combine nodes
    //
    // P = P1*P2
    // Q = Q1*Q2
    // T = T1*Q2 + P1*T2
    // ------------------------------


    mpz_mul(
        r.P,
        left.P,
        right.P
    );


    mpz_mul(
        r.Q,
        left.Q,
        right.Q
    );



    mpz_t temp;

    mpz_init(temp);



    mpz_mul(
        r.T,
        left.T,
        right.Q
    );


    mpz_mul(
        temp,
        left.P,
        right.T
    );


    mpz_add(
        r.T,
        r.T,
        temp
    );



    mpz_clear(temp);



    bs_clear(left);
    bs_clear(right);

}





// ======================================================
// Chudnovsky calculation wrapper
// ======================================================


void calculate_chudnovsky(
    long terms,
    BS &result
)
{

    terms_done = 0;


    set_core(6);


    binary_split(
        0,
        terms,
        result,
        0
    );

}
