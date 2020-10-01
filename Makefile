all:test

test: increase_carry.o test.o
	g++ increase_carry.o test.o -o test -std=c++11

increase_carry.o: increase_carry.cpp
	g++ -c increase_carry.cpp -o increase_carry.o -std=c++11

test.o:test.cpp
	g++ -c test.cpp -o test.o -std=c++11

clean:
	del *.o test.exe