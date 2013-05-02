# SDL
SDL_FLAGS=`sdl-config --cflags`
SDL_LIBS=`sdl-config --libs` -lSDL_ttf

CXX = clang++
OBJECTS = bin/main.o bin/application_main.o bin/start_screen.o bin/game_screen.o bin/world_screen.o bin/win_screen.o bin/lose_screen.o bin/tile.o bin/world.o bin/world_builder.o bin/renderer.o
BINARY = bin/Rogue3k
CXXFLAGS = -Wall -std=c++11 -stdlib=libc++ $(SDL_FLAGS)
LDFLAGS = $(SDL_LIBS)

all: prepare $(BINARY)

prepare:
	mkdir -p bin

$(BINARY): prepare $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $(BINARY)

bin/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o bin/main.o -c

bin/application_main.o: src/application_main.h src/application_main.cpp
	$(CXX) $(CXXFLAGS) src/application_main.cpp -o bin/application_main.o -c

bin/start_screen.o: src/start_screen.h src/start_screen.cpp
	$(CXX) $(CXXFLAGS) src/start_screen.cpp -o bin/start_screen.o -c

bin/game_screen.o: src/game_screen.h src/game_screen.cpp
	$(CXX) $(CXXFLAGS) src/game_screen.cpp -o bin/game_screen.o -c

bin/world_screen.o: src/world_screen.h src/world_screen.cpp
	$(CXX) $(CXXFLAGS) src/world_screen.cpp -o bin/world_screen.o -c

bin/win_screen.o: src/win_screen.h src/win_screen.cpp
	$(CXX) $(CXXFLAGS) src/win_screen.cpp -o bin/win_screen.o -c

bin/lose_screen.o: src/lose_screen.h src/lose_screen.cpp
	$(CXX) $(CXXFLAGS) src/lose_screen.cpp -o bin/lose_screen.o -c

bin/tile.o: src/tile.h src/tile.cpp
	$(CXX) $(CXXFLAGS) src/tile.cpp -o bin/tile.o -c

bin/world.o: src/world.h src/world.cpp
	$(CXX) $(CXXFLAGS) src/world.cpp -o bin/world.o -c

bin/world_builder.o: src/world_builder.h src/world_builder.cpp
	$(CXX) $(CXXFLAGS) src/world_builder.cpp -o bin/world_builder.o -c

bin/renderer.o: src/renderer.h src/renderer.cpp
	$(CXX) $(CXXFLAGS) src/renderer.cpp -o bin/renderer.o -c

clean:
	rm -rf bin/*
