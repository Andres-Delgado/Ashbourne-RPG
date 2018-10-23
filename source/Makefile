CXX = g++
CXXFLAGS = -Wall -c

all: Ashbourne

Ashbourne: Ashbourne.o dungeon.o player.o monster.o
	$(CXX) Ashbourne.o dungeon.o player.o monster.o -o Ashbourne

Ashbourne.o: Ashbourne.cpp player.h monster.h
	$(CXX) $(CXXFLAGS) Ashbourne.cpp

dungeon.o: dungeon.cpp player.h monster.h
	$(CXX) $(CXXFLAGS) dungeon.cpp

player.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) player.cpp

monster.o: monster.cpp monster.h
	$(CXX) $(CXXFLAGS) monster.cpp

clean:
	rm *.o Ashbourne