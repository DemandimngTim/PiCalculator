# PiCalculator 🔥

A high-performance π calculator written in C++ using GMP, MPFR, and the Chudnovsky algorithm.

## Features

- 🚀 Fast Chudnovsky π generation
- 🧮 GMP + MPFR high precision calculations
- 🌳 Binary splitting optimization
- ⚙️ Configurable tree depth
- 👤 Profile system
- ✅ Verification system
- 📊 Benchmark tools
- 📁 Automatic output organization
- 💻 CMake build support

## Requirements

- C++17 compiler
- CMake
- GMP
- MPFR

## Build

mkdir build
cd build
cmake ..
cmake --build .

## Usage

./pi 1000

Generate π digits.

./pi 1000000 3

Generate π with custom tree depth.

./pi --no-save 100000000

Calculate without saving output.

./pi --estimate 100000000

Estimate storage, RAM, and calculation time.

./pi --verify 1000

Verify generated π digits.

./pi --profile-use profile_name 1000

Use a saved profile.

## Output

Generated π files are saved inside:

generated pi/

Example:

generated pi/pi_1000000.txt

## Algorithm

PiCalculator uses the Chudnovsky algorithm with binary splitting for efficient large-scale π calculations.

## Project Structure

PiCalculator/
├── src/
├── include/
├── build/
├── generated pi/
├── profiles/
└── CMakeLists.txt

## License

MIT License
