SHELL=/bin/bash

# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the compiler based on the operating system
ifeq ($(UNAME_S),Darwin)
	CXX = /usr/bin/clang++
else
	CXX = g++
endif

CXXFLAGS = -std=c++23 -Wall -Wextra -O2
TARGET = newcpp
SRC = main.cpp
BUILD_DIR = build
TARGET_PATH = $(BUILD_DIR)/$(TARGET)
EXAMPLE_PROJECT_NAME = example

.PHONY: all run clean

all: $(TARGET_PATH)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_PATH): $(SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET_PATH) $(SRC)

run: $(TARGET_PATH)
	@pushd $(BUILD_DIR) > /dev/null && \
	./$(TARGET) $(EXAMPLE_PROJECT_NAME) && \
	popd > /dev/null

clean:
	rm $(BUILD_DIR)/$(TARGET)

install: $(TARGET_PATH)
	cp $(TARGET_PATH) /usr/local/bin/$(TARGET)

compile_commands: $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
	ln -sf $(BUILD_DIR)/compile_commands.json .
