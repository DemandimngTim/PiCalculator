# PiCalculator 🔥

A high-performance π calculator written in C++ using GMP, MPFR, and the Chudnovsky algorithm.

## Features

- ⚡ Fast π generation
- 🧮 GMP + MPFR high precision calculations
- 🌲 Parallel binary splitting engine
- 👤 Profile system for custom configurations
- ✅ π verification tools
- 📊 Benchmark system
- 💾 Optimized output handling
- 🛠️ CMake build support

## Requirements

- C++ compiler
- CMake
- GMP
- MPFR

## Build

Clone the repository:

```bash
git clone https://github.com/DemandimngTim/PiCalculator
cd PiCalculator
```

Create a build folder:

```bash
mkdir build
cd build
```

Generate build files:

```bash
cmake ..
```

Compile:

```bash
cmake --build .
```

The executable will be created as:

```bash
./pi
```

## Usage

Generate π digits:

```bash
./pi 1000
```

Generate 1 million digits:

```bash
./pi 1m
```

Disable saving output:

```bash
./pi --no-save 100m
```

Change binary split tree depth:

```bash
./pi 1m 3
```

Use a profile:

```bash
./pi --profile-use profile_name 1000
```

Estimate requirements:

```bash
./pi --estimate 100m
```

Verify generated digits:

```bash
./pi --verify 1000
```

## Profiles

Profiles allow saving custom calculation settings.

Create and manage profiles:

```bash
./pi --profile
```

Example settings:

```txt
tree_depth=3
parallel=true
save_output=true
algorithm=chudnovsky
precision_mode=mpfr
```

## Output

Generated π files are saved in:

```txt
generated pi/
```

Example:

```txt
generated pi/pi_1000000.txt
```

## Performance Example

Example benchmark:

```txt
Digits: 1000000

Calculation time: 0.59s
MPFR time: 0.21s
Save time: 0.30s

Total time: 1.11s
```

## Project Structure

```text
PiCalculator/
├── include/
│   └── pi.h
├── src/
│   ├── calculator.cpp
│   ├── output.cpp
│   ├── program.cpp
│   ├── profiles/
│   ├── benchmark/
│   └── verify/
├── CMakeLists.txt
└── README.md
```

## License

MIT License
