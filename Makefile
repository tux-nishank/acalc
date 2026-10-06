
CXX = g++
CXXFLAGS  = -Wall -Wextra -std=c++23

conv: main.o
	$(CXX) $(CXXFLAGS) -o acalc main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
