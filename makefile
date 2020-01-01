BIN_DIR := bin
DEBUG_DIR := $(BIN_DIR)/debug
RELEASE_DIR := $(BIN_DIR)/release
SOURCE_DIR := source
HEADER_DIR := header

SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.c)
SOURCES_FILE_NAME := $(patsubst $(SOURCE_DIR)/%.c,%.c,$(SOURCE_FILES))
OBJS_FILE_NAME := $(patsubst %.c,%.o,$(SOURCES_FILE_NAME))
DEBUG_OBJ_FILES := $(patsubst %.o,$(DEBUG_DIR)/%.o,$(OBJS_FILE_NAME))
RELEASE_OBJ_FILES := $(patsubst %.o,$(RELEASE_DIR)/%.o,$(OBJS_FILE_NAME))

.PHONY: all clean

all : debug release

debug : $(DEBUG_OBJ_FILES)

release : $(RELEASE_OBJ_FILES)

clean :
	rm $(DEBUG_OBJ_FILES)
	rm $(RELEASE_OBJ_FILES)

$(DEBUG_DIR)%.o: $(SOURCE_DIR)%.c
	gcc -Iheader -g -c $< -o $@

$(RELEASE_DIR)%.o: $(SOURCE_DIR)%.c
	gcc -Iheader -c $< -o $@
