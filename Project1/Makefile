
output: main.o menu.o Ant.o
	g++ main.o menu.o Ant.o -o output

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

clean:
	rm *.o output
