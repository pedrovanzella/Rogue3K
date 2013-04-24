CXX = clang++
CXXFLAGS = -Wall
OBJECTS = bin/main.o
BINARY = bin/Rogue3k

all: prepare $(BINARY)

prepare:
	mkdir -p bin

$(BINARY): prepare $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BINARY)

bin/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o bin/main.o -c

clean:
	rm -rf bin/*
