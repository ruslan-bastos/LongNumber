all: windows

windows:
	gcc main.c DefinitionOfOperation.c -o Lab_1.exe

linux:
	gcc -c -fPIC DefinitionOfOperation.c -o DefinitionOfOperation.o
	gcc -c main.c
	gcc main.o DefinitionOfOperation.o -o Lab_1
