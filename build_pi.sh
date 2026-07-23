#!/data/data/com.termux/files/usr/bin/bash

echo "Building π calculator 🔥"


clang++ \
main.cpp \
$(find src -name "*.cpp") \
-I./include \
-lgmp \
-lmpfr \
-lpthread \
-std=c++17 \
-o pi



if [ $? -eq 0 ]; then
    echo "Build finished ✅"
else
    echo "Build failed ❌"
fi
