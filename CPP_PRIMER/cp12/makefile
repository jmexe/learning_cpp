GXX = g++
CXFLAGS = -std=c++11

all: main.o strblob.o
	$(GXX) $(CXFLAGS) main.o strblob.o -o main

sp: smartPointer.cpp
	$(GXX) $(CXFLAGS) smartPointer.cpp -o main

strblob.o: StrBlob.h StrBlob.cpp
	$(GXX) $(CXFLAGS) -c StrBlob.cpp

main.o: main.cpp StrBlob.h
	$(GXX) $(CXFLAGS) -c main.cpp
