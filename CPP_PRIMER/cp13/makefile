GXX = g++
CXFLAGS = -std=c++11

all: buddy.o main.o
	$(GXX) $(CXFLAGS) buddy.o main.o -o main
main.o: buddy.h main.cpp
	$(GXX) -c main.cpp
buddy.o: buddy.h buddy.cpp
	$(GXX) -c buddy.cpp
