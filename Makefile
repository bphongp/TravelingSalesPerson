#Bamphiane Annie Phongphouthai
#bp8qg
#Makefile
# November 28, 2017

CXX = clang++

CXXFLAGS = -Wall -g -O2

OFILES = traveling.o middleearth.o

.SUFFIXES: .o .cpp

main: 	$(OFILES)
	$(CXX) $(OFILES)
	doxygen

traveling.o: traveling.cpp
middleearth.o: middleearth.h middleearth.cpp

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out
