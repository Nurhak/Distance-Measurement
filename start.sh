#/bin/bash
echo "script started"
g++ -O2 `pkg-config --cflags --libs opencv` Source.cpp -o binary
./binary
