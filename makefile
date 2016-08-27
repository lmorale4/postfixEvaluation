postfixProg.exe: Queue.o Stack.o postfixFile.o
	g++ Queue.o Stack.o postfixFile.o -o postfixProg.exe

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

postfixFile.o: postfixFile.cpp
	g++ -c postfixFile.cpp

clean:
	rm *.o postfixProg.exe
