all:test magic_square

test: media_number.o test.o
	g++ -o test media_number.o test.o -std=c++11

media_number.o: media_number.cpp media_number.h debug.h
	g++ -c media_number.cpp -o media_number.o -std=c++11

test.o:test.cpp permutations.hpp debug.h
	g++ -c test.cpp -o test.o -std=c++11

magic_square: media_number.o magic_square.o
	g++ -o magic_square media_number.o magic_square.o -std=c++11

magic_square.o:magic_square.cpp permutations.hpp debug.h
	g++ -c magic_square.cpp -o magic_square.o -std=c++11

clean:
	del *.o test.exe