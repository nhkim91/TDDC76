# FILNAMN:       makefile
# LABORATION:    lab1-5
#PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
#               Kerstin Söderqvist 911006-0309 Y3.c kerso255
# DATUM:         2014-09-29

CCC = g++	#C++ kompilator(g++)
CCFLAGS = -g -std=c++11 #Kompilerar 
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++ 

lab1-5: lab1-5.o list.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) lab1-5.o list.o -o lab1-5

lab1-5.o: lab1-5.cc
	$(CCC) $(CCFLAGS) -c lab1-5.cc

list.o: list.cc
	$(CCC) $(CCFLAGS) -c list.cc

clean: #städa arbetsmappen
	@\rm -f *.o
