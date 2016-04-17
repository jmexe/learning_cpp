CXX = g++
CXFLAGS = -std=c++11

all : buddy.o main.o
	$(CXX) $(CXFLAGS) buddy.o main.o -o main
main.0 : main.cpp buddy.h
	$(CXX) $(CXFLAGS) -Wall -c main.cpp
buddy.o: buddy.h
	$(CXX) $(CXFLAGS) -Wall -c buddy.cpp
clean:
	rm -r main *.o