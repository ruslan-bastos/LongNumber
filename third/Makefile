all: windows

windows:
	swig -c++ -python LongNumberClass.i
	g++ -c LongNumberClass.cpp
	g++ -c DefinitionOfOperation.c
	g++ -c LongNumberClass_wrap.cxx -IC:\Python27\include
	g++ LongNumberClass.o DefinitionOfOperation.o LongNumberClass_wrap.o -Ic:\python27\include -Lc:\python27\libs -lpython27 -shared -o _LongNumberClass.pyd
	rm -rf *.o *.cxx

linux:
	swig -c++ -python -o LongNumberClass_wrap.cpp LongNumberClass.i
	g++ -c -fPIC LongNumberClass.cpp -o LongNumberClass.o
	g++ -c -fPIC DefinitionOfOperation.c -o DefinitionOfOperation.o
	g++ -fPIC -c LongNumberClass_wrap.cpp -I/usr/include/python2.7
	g++ -shared LongNumberClass.o DefinitionOfOperation.o LongNumberClass_wrap.o -o _LongNumberClass.so
