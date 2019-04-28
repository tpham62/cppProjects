CXXFLAGS += -std=c++11

output: mainproject2.o zoo.o animal.o Tiger.o Penguin.o Turtle.o
	g++ mainproject2.o zoo.o animal.o Tiger.o Penguin.o Turtle.o -o output

mainproject2.o: mainproject2.cpp
	g++ -std=c++11 -c mainproject2.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -std=c++11 -c zoo.cpp

animal.o: animal.cpp animal.hpp
	g++ -std=c++11 -c animal.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -std=c++11 -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -std=c++11 -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -std=c++11 -c Turtle.cpp

clean:
	rm *.o output
