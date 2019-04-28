CXXFLAGS += -std=c++11

output: mainproject3.o Characters.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o
	g++ mainproject3.o Characters.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o -o output

mainproject3.o: mainproject3.cpp
	g++ -std=c++11 -c mainproject3.cpp

Characters.o: Characters.cpp Characters.hpp
	g++ -std=c++11 -c Characters.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

clean:
	rm *.o output
