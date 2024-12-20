.PHONY: all clean objclean

BUILD_DIR = build
OBJ = $(BUILD_DIR)/nyna.a

all: $(OBJ)

$(OBJ):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) \
		&& cmake .. \
		&& make -j

clean:
	rm -rf $(BUILD_DIR)

objclean:
	rm -f $(BUILD_DIR)/*.a $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/examples/*/CMakeFiles
