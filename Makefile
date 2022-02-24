V8_INCLUDE_DIR = /home/dmtrllv/src/v8/v8/include
V8_LINK_DIR = /home/dmtrllv/src/v8/v8/out/x64.release
V8_LIBS = c++ chrome_zlib v8_libplatform icui18n icuuc v8 v8_libbase
DEFAULT_LIBS = rt dl pthread

V8_COPY_LIBS = $(patsubst %,lib%.so,$(V8_LIBS))

LIBS = $(patsubst %,-l%,$(V8_LIBS) $(DEFAULT_LIBS))

export

copy-libs: $(V8_COPIED_LIBS)
	for so in $(V8_COPY_LIBS) ; do \
		cp $(V8_LINK_DIR)/$$so out/$$so ; \
	done

test-game:
	@$(MAKE) -C NovaEngine all
	@$(MAKE) -C TestGame all
	@mkdir -p out
	cp TestGame/out/test-game.app out/test-game.app
	cp NovaEngine/out/libnova-engine.so out/libnova-engine.so
	cp $(V8_LINK_DIR)/snapshot_blob.bin out/snapshot_blob.bin
	$(foreach so,$(V8_COPY_LIBS),cp $(V8_LINK_DIR)/$(so) out/$(so);)
	./out/test-game.app

clean:
	@rm -rf Debug
	@rm -rf Release
	@rm -rf x64
	@rm -rf out
	@$(MAKE) -C NovaEngine clean
	@$(MAKE) -C TestGame clean
