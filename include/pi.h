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
// Global settings
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
// Digit parser
// ======================================================

long long parse_digits(
    const std::string &text
);



// ======================================================
// Verify++
// ======================================================

void run_verify_plus(
    int argc,
    char **argv
);


// Reference system

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



// Comparison engine

bool compare_files(
    std::string generated,
    std::string reference
);


bool compare_range(
    std::string generated,
    std::string reference,
    long start,
    long length
);



// Verification modes

void verify_full(
    long digits
);


void verify_random(
    long digits,
    int checks,
    int chunk_size
);


void verify_middle(
    long digits,
    long check_digits
);


void verify_end(
    long digits,
    long check_digits
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



// ======================================================
// Commands
// ======================================================

int run_command(
    int argc,
    char **argv
);
