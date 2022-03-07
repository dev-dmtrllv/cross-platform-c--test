PROJ_DIR = $(shell pwd)

OS = linux
PLATFORM = x64
TARGET = Debug

V8_INCLUDE_DIR = $(PROJ_DIR)/packages/includes/v8
V8_LINK_DIR = $(PROJ_DIR)/packages/libs/$(OS)/$(PLATFORM)/$(TARGET)
V8_LIBS = v8_monolith
DEFAULT_LIBS = rt dl pthread

V8_COPY_LIBS = $(patsubst %,lib%.a,$(V8_LIBS))

LIBS = $(patsubst %,-l%,$(V8_LIBS) $(DEFAULT_LIBS))

export

V8_OUT_LIBS = $(shell find $(V8_LINK_DIR) -name "*.a")

test: 
	echo $(V8_OUT_LIBS)

copy-libs: $(V8_COPIED_LIBS)
	for so in $(V8_COPY_LIBS) ; do \
		cp $(V8_LINK_DIR)/$$so out/$$so ; \
	done

nova-engine:
	@$(MAKE) -C NovaEngine all

test-game:
	@$(MAKE) -C NovaEngine all
	@$(MAKE) -C TestGame all
	@mkdir -p out
	cp TestGame/out/test-game.app out/test-game.app
	cp NovaEngine/out/libnova-engine.so out/libnova-engine.so
# cp $(V8_LINK_DIR)/snapshot_blob.bin out/snapshot_blob.bin
	$(foreach so,$(V8_COPY_LIBS),cp $(V8_LINK_DIR)/$(so) out/$(so);)
	cd ./out && LD_LIBRARY_PATH=. ./test-game.app

clean:
	@rm -rf Debug
	@rm -rf Release
	@rm -rf x64
	@rm -rf out
	@$(MAKE) -C NovaEngine clean
	@$(MAKE) -C TestGame clean

build-v8:
	node scripts/build-v8


