GXX = gcc

GXX_FLAGS = -g
LINKED_LIBS = -lWs2_32
INCLUDE =

BUILD = build
OBJ = $(BUILD)/obj

SRC = $(wildcard src/*.c)

all: compile

compile: clean
	$(GXX) $(GXX_FLAGS) $(SRC) -o $(BUILD)/network $(LINKED_LIBS)

.PHONY: clean
.SILENT: clean
clean: mkbuild
	del /Q /S $(BUILD)\*

mkbuild:
	if not exist "$(BUILD)" mkdir "$(BUILD)"