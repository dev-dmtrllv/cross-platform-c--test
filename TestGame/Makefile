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
	g++ -o out/test-game.app -DV8_COMPRESS_POINTERS $^ -Wall -Werror -fpic -std=c++2a -I$(INCLUDE_DIR) -I../NovaEngine/include -L../NovaEngine/out -L$(V8_LINK_DIR) -I$(V8_INCLUDE_DIR) $(LIBS) -lnova-engine
