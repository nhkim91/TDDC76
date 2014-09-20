

CCC = g++	#C++ kompilator(g++)
CCFLAGS = -g -std=c++11 #Kompilerar 
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++ 


lab1-5: lab1-5.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) lab1-5.o -o lab1-5
lab1-5.o: lab1-5.cc
	$(CCC) $(CCFLAGS) -c lab1-5.cc
	
list: list.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) list.o -o list	

list.o: list.cc
		$(CCC) $(CCFLAGS) -c list.cc
		

clean: #städa arbetsmappen
	@\rm -f *.o
		
		