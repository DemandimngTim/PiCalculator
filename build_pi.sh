#!/data/data/com.termux/files/usr/bin/bash

echo "Building π calculator 🔥"

START_TIME=$(date +%s.%N)

BUILD_DIR="build"
mkdir -p "$BUILD_DIR"

CXX="clang++"

CXXFLAGS="
-I./include
-I./src
-std=c++17
-O3
-march=native
-mtune=native
-funroll-loops
-pipe
"

LDFLAGS="
-lgmp
-lmpfr
-pthread
-flto
"

FILES="main.cpp $(find src -name '*.cpp')"

OBJECTS=""
changed=0
compiled=0


spinner()
{
    PID=$1
    chars="|/-\\"
    i=0

    while kill -0 $PID 2>/dev/null; do
        printf "\r[%c] Compiling..." "${chars:i++%4:1}"
        sleep 0.12
    done
}


compile_file()
{
    file=$1
    obj=$2

    echo ""
    echo "⚙️ Compiling: $file"

    $CXX $CXXFLAGS -c "$file" -o "$obj" &
    PID=$!

    spinner $PID

    wait $PID
    RESULT=$?

    printf "\r                     \r"

    return $RESULT
}


for file in $FILES; do

    safe_name=$(echo "$file" | tr '/' '_')
    obj="$BUILD_DIR/$safe_name.o"

    OBJECTS="$OBJECTS $obj"

    if [ ! -f "$obj" ] || [ "$file" -nt "$obj" ]; then

        compile_file "$file" "$obj"

        if [ $? -ne 0 ]; then
            echo "❌ Failed: $file"
            exit 1
        fi

        compiled=$((compiled+1))
        changed=1

    fi

done


if [ $changed -eq 0 ] && [ -f pi ]; then

    END_TIME=$(date +%s.%N)
    TIME=$(echo "$END_TIME-$START_TIME" | bc)

    echo ""
    echo "Nothing changed 😎"
    echo "Build skipped ✅"
    echo "Time: ${TIME}s"

    exit 0

fi


echo ""
echo "🔗 Linking..."

$CXX $OBJECTS $LDFLAGS -o pi &
PID=$!

spinner $PID

wait $PID
RESULT=$?

printf "\r                     \r"


END_TIME=$(date +%s.%N)
TIME=$(echo "$END_TIME-$START_TIME" | bc)


if [ $RESULT -eq 0 ]; then

    echo ""
    echo "Build finished ✅"
    echo "Compiled files: $compiled"
    echo "Build time: ${TIME}s"

else

    echo ""
    echo "Build failed ❌"

fi
