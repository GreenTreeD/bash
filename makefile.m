# for compiling: "make -f makefile.m"
# for clear: "make -f makefile.m clean"

T16 : filelib.o T16.c
	c++ -o T16.o -g filelib.o T16.c

filelib.o : filelib.c filelib.o
	c++ -Wall -g -c filelib.c -o filelib.o


clean :
	rm *.o T16