CXXFLAGS = -Wall -Werror


main:					main.o
							g++ main.o -o main

main.o:				main.cpp dictionary.h grid.h
							g++ $(CXXFLAGS) -c main.cpp

clean:
							rm *.o main
