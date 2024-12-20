.PHONY: all fonts clean objclean

BUILD_DIR = build
OBJ = $(BUILD_DIR)/nyna.a

BIN_DIR = bin
INC_DIR = include
SRC_DIR = src

#GRAPHICS_REL_DIR = nyna/graphics
#FONTS_REL_DIR = $(GRAPHICS_REL_DIR)/fonts
#
#FONT_BMP_DIR = fonts
#FONT_CPP_GEN_CMD = $(BIN_DIR)/gen_font_array.py
#
#FONT_HPP_LIST = \
#	$(INC_DIR)/$(FONTS_REL_DIR)/shaposans22b.hpp \
#	$(INC_DIR)/$(FONTS_REL_DIR)/shaposans44b.hpp
#
#FONT_CPP_LIST = \
#	$(SRC_DIR)/$(FONTS_REL_DIR)/shaposans22b.cpp \
#	$(SRC_DIR)/$(FONTS_REL_DIR)/shaposans44b.cpp

EXTRA_DEPENDENCIES = \
	Makefile

all: $(OBJ)

#fonts: $(FONT_HPP_LIST)

$(OBJ):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) \
		&& cmake .. \
		&& make -j

#$(INC_DIR)/$(FONTS_REL_DIR)/%.hpp: $(SRC_DIR)/$(FONTS_REL_DIR)/%.cpp
#	@echo -n ""
#
#$(SRC_DIR)/$(FONTS_REL_DIR)/%.cpp: $(FONT_BMP_DIR)/%.png $(EXTRA_DEPENDENCIES) $(FONT_CPP_GEN_CMD)
#	@mkdir -p $(SRC_DIR)/$(FONTS_REL_DIR)
#	@mkdir -p $(INC_DIR)/$(FONTS_REL_DIR)
#	$(FONT_CPP_GEN_CMD) \
#		--src $< \
#		--name $(patsubst $(FONT_BMP_DIR)/%.png,%,$<) \
#		--cpp_outdir $(SRC_DIR)/$(FONTS_REL_DIR) \
#		--hpp_outdir $(INC_DIR)/$(FONTS_REL_DIR) \
#		--out_namespace nyna::graphics::fonts \
#		$(shell cat $(patsubst %.png,%.args.txt,$<))

clean:
	rm -rf $(BUILD_DIR)

objclean:
	rm -f $(BUILD_DIR)/*.a $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/examples/*/CMakeFiles
