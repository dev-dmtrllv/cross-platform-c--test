INCLUDE_DIR = ./include
SOURCE_DIR = ./src
SOURCES := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS := $(patsubst ./src/%.cpp,./out/%.o,$(SOURCES))

all: libnova-engine

./out/%.o: ./src/%.cpp
	@mkdir -p out
	g++ -c -o $@ $^ -DV8_COMPRESS_POINTERS -Wall -Werror -fpic -std=c++2a -DNOVAENGINE_EXPORTS -I$(V8_INCLUDE_DIR) -I$(INCLUDE_DIR) -L$(V8_LINK_DIR) $(LIBS)

libnova-engine: $(OBJS)
	@mkdir -p out
	gcc -shared -o out/$@.so $^ -DV8_COMPRESS_POINTERS -Wall -Werror -fpic -std=c++2a -DNOVAENGINE_EXPORTS -I$(V8_INCLUDE_DIR) -I$(INCLUDE_DIR) -L$(V8_LINK_DIR) $(LIBS)

clean:
	@rm -rf Debug
	@rm -rf Release
	@rm -rf x64
	@rm -rf out
