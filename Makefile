UNAME_S := $(shell uname -s)

BUILD_DIR = ./build/
OUTPUT_DIR = ./
EXECUTABLE_NAME = arkanoid
CORES = $(shell nproc 2>/dev/null || echo 1)

all: setup
ifeq ($(UNAME_S),Linux)
	@cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@cmake --build $(BUILD_DIR) -- -j$(CORES)
else
	@cmake -G "MinGW Makefiles" -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@cmake --build $(BUILD_DIR) -- -j$(CORES)
endif

debug: setup
ifeq ($(UNAME_S),Linux)
	@cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@cmake --build $(BUILD_DIR) -- -j$(CORES)
else
	@cmake -G "MinGW Makefiles" -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@cmake --build $(BUILD_DIR) -- -j$(CORES)
endif

setup:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OUTPUT_DIR)

clean:
	@rm -rf $(BUILD_DIR) arkanoid

re: clean all

re_debug: clean debug

.PHONY: all debug clean re re_debug
