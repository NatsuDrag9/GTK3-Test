The file compiles in UNIX based OS only.

To compile the document execute the following command in the directory containing the .cpp file.

g++ `pkg-config --cflags gtk+-3.0` -o LDMicro.exe LDMicro.cpp `pkg-config --libs gtk+-3.0`

An executable named "LDMicro.exe" will be created in the same directory. To execute it, type the following command in the terminal :
./LDMicro.exe
