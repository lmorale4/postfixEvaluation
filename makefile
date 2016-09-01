postfixProg.exe: Queue.o Stack.o postfixFile.o
	g++ Queue.o Stack.o postfixFile.o -o postfixProg.exe

Queue.o: Queue.cpp Queue.h
	g++ -c -std=c++11 Queue.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c -std=c++11 Stack.cpp

postfixFile.o: postfixFile.cpp
	g++ -c -std=c++11 postfixFile.cpp

clean:
	rm *.o postfixProg.exe
