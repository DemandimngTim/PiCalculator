// ======================================================
// pi.h
// Shared declarations
// ======================================================

#pragma once


#include <gmp.h>
#include <mpfr.h>

#include <atomic>
#include <chrono>
#include <string>

// ======================================================
// Main program
// ======================================================


int run_program(
    int argc,
    char **argv
);




// ======================================================
// Settings
// ======================================================


extern long DIGITS;

extern int MAX_TREE_DEPTH;

extern bool NO_SAVE;




// ======================================================
// Progress system
// ======================================================


extern std::atomic<long> terms_done;




// ======================================================
// Binary split structure
// ======================================================


struct BS
{

    mpz_t P;

    mpz_t Q;

    mpz_t T;

};




void bs_init(
    BS &x
);


void bs_clear(
    BS &x
);




// ======================================================
// π calculation engine
// ======================================================


void calculate_chudnovsky(
    long terms,
    BS &result
);



void calculate_pi_mpfr(
    BS &result,
    mpfr_t pi,
    long digits
);

void save_pi(
    mpfr_t pi,
    long digits
);


// ======================================================
// Utilities
// ======================================================


void set_core(
    int core
);


double elapsed(
    std::chrono::high_resolution_clock::time_point start,
    std::chrono::high_resolution_clock::time_point end
);
// ======================================================
// Verify++ system
// ======================================================

void run_verify_plus(
    int argc,
    char **argv
);


bool reference_exists(
    long digits
);


bool prepare_reference(
    long digits
);


bool validate_reference(
    std::string file
);


bool install_reference(
    long digits
);


bool compare_files(
    std::string generated,
    std::string reference
);
// ======================================================
// Benchmark system
// ======================================================

double run_single_benchmark(
    long digits,
    int depth
);


void run_benchmark(
    long digits
);


void run_benchmark_plus(
    long digits
);
void verify_random(
    long digits
);


void verify_middle(
    long digits
);


void verify_end(
    long digits
);


void verify_full(
    long digits
);
