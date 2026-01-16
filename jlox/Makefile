# ---- config ----
SRC_DIR := src
BUILD_DIR := build
MAIN_CLASS := com.craftinginterpreters.lox.Lox

SOURCES := $(shell find $(SRC_DIR) -name "*.java")

# ---- targets ----
.PHONY: all run clean

all: compile

compile:
	mkdir -p $(BUILD_DIR)
	javac -d $(BUILD_DIR) $(SOURCES)

run: compile
	java -cp $(BUILD_DIR) $(MAIN_CLASS)

clean:
	rm -rf $(BUILD_DIR)
