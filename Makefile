#Bamphiane Annie Phongphouthai
#bp8qg
#November 27, 2017
#makefile

CXX = clang++

CXXFLAGS = -Wall -g

OFILES= topological.cpp

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(OFILES)
	doxygen

clean:
	/bin/rm -f *.o *~
	/bin/rm -f *.out
