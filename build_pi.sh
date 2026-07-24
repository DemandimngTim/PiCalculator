#!/data/data/com.termux/files/usr/bin/bash

echo "Building π calculator 🔥"


clang++ \
main.cpp \
$(find src -name "*.cpp") \
-I./include \
-std=c++17 \
-O3 \
-flto \
-march=native \
-mtune=native \
-funroll-loops \
-pipe \
-lgmp \
-lmpfr \
-pthread \
-o pi
if [ $? -eq 0 ]; then
    echo "Build finished ✅"
else
    echo "Build failed ❌"
fi
