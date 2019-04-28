CXXFLAGS += -std=c++11

output: mainfinal.o Forrest.o Mountain.o Graveyard.o Underworld.o Afterworld.o Purgatory.o Space2.o Fighter.o
	g++ mainfinal.o Forrest.o Mountain.o Graveyard.o Underworld.o Afterworld.o Purgatory.o Space2.o Fighter.o -o output
mainfinal.o: mainfinal.cpp
	g++ -ggdb -std=c++11 -c mainfinal.cpp
Space2.o: Space2.cpp Space2.hpp
	g++ -ggdb -std=c++11 -c Space2.cpp
Fighter.o: Fighter.cpp Fighter.hpp
	g++ -ggdb -std=c++11 -c Fighter.cpp
Forrest.o: Forrest.cpp Forrest.hpp
	g++ -ggdb -std=c++11 -c Forrest.cpp
Mountain.o: Mountain.cpp Mountain.hpp
	g++ -ggdb -std=c++11 -c Mountain.cpp
Graveyard.o: Graveyard.cpp Graveyard.hpp
	g++ -ggdb -std=c++11 -c Graveyard.cpp
Purgatory.o: Purgatory.cpp Purgatory.hpp
	g++ -ggdb -std=c++11 -c Purgatory.cpp
Underworld.o: Underworld.cpp Underworld.hpp
	g++ -ggdb -std=c++11 -c Underworld.cpp
Afterworld.o: Afterworld.cpp Afterworld.hpp
	g++ -ggdb -std=c++11 -c Afterworld.cpp
clean:
	rm *.o output
