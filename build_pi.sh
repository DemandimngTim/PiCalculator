#!/data/data/com.termux/files/usr/bin/bash

echo "Building π calculator 🔥"
echo

SOURCES=(
    main.cpp
    $(find src -name "*.cpp")
)

FLAGS="
-I./include
-I./src/help
-std=c++17
-O3
-flto
-march=native
-mtune=native
-funroll-loops
-pipe
"

LIBS="
-lgmp
-lmpfr
-pthread
"

spin='|/-\'

echo "Compiling files:"
for file in "${SOURCES[@]}"
do
    echo "  $file"
done

echo
echo "Compiling... 🔥"

(
    clang++ \
    "${SOURCES[@]}" \
    $FLAGS \
    $LIBS \
    -o pi
) &

PID=$!

i=0

while kill -0 $PID 2>/dev/null
do
    printf "\r[%c] Compiling..." "${spin:i++%4:1}"
    sleep 1
done

wait $PID

if [ $? -eq 0 ]; then
    printf "\rBuild finished ✅          \n"
else
    printf "\rBuild failed ❌            \n"
    exit 1
fi
