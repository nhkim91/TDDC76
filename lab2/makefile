# FILNAMN:       makefile
# LABORATION:    lab2
#PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
#               Kerstin Soderqvist 911006-0309 Y3.c kerso255
# DATUM:         2014-10-16

CCC = g++	#C++ kompilator(g++)
CCFLAGS = -g -std=c++11 #Kompilerar 
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++ 

lab2: lab2.o monetary.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) lab2.o monetary.o -o lab2

lab2.o: lab2.cc
	$(CCC) $(CCFLAGS) -c lab2.cc

monetary.o: monetary.cc monetary.h
	$(CCC) $(CCFLAGS) -c monetary.cc

clean: #steda arbetsmappen
	@\rm -f *.o

