# SDL
SDL_FLAGS=`sdl-config --cflags`
SDL_LIBS=`sdl-config --libs`

CXX = clang++
OBJECTS = bin/main.o bin/application_main.o
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

clean:
	rm -rf bin/*
