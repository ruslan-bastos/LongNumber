all: windows

windows:
	g++ -c LongNumberClass.cpp DefinitionOfOperation.c
	g++ -shared -o LongNumberClass.dll LongNumberClass.o DefinitionOfOperation.o
	g++ main.cpp LongNumberClass.dll -I. -Wl,-rpath,. -L. -o Lab_2.exe
	rm -rf *.o

linux:
	g++ -c -fPIC LongNumberClass.cpp -o LN_Class.o
	g++ -c -fPIC DefinitionOfOperation.c -o DefinitionOfOperation.o
	g++ -shared -o libLongNumberClass.so LongNumberClass.o DefinitionOfOperation.o
	g++ -c main.cpp
	g++  main.o -L. -lLongNumberClass -o Lab_2
