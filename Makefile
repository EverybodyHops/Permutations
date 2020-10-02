all:test

test: media_number.o test.o
	g++ -o test media_number.o test.o -std=c++11

media_number.o: media_number.cpp
	g++ -c media_number.cpp -o media_number.o -std=c++11

test.o:test.cpp
	g++ -c test.cpp -o test.o -std=c++11

clean:
	del *.o test.exe