INCLUDE_DIR = ./include
SOURCE_DIR = ./src
SOURCES := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS := $(patsubst ./src/%.cpp,./out/%.o,$(SOURCES))

all: test-game

clean:
	@rm -rf Debug
	@rm -rf Release
	@rm -rf x64
	@rm -rf out
	
test-game: src/TestGame.cpp
	@mkdir -p out
	g++ -o out/test-game.app -DV8_COMPRESS_POINTERS $^ -Wall -Werror -fpic -std=c++2a -lrt -ldl -pthread -I$(INCLUDE_DIR) -I../NovaEngine/include -L/home/dmtrllv/Code/c++/NovaEngine/NovaEngine/out -lnova-engine -L$(V8_LINK_DIR) -I$(V8_INCLUDE_DIR) $(LIBS)
