ifeq ($(OS),Windows_NT)
    IS_WINDOWS := 1
    SHELL := cmd
    MKDIR := mkdir
    RM_DIR := rmdir /S /Q
	RM_FILE := del /Q
	GENERATOR := "MinGW Makefiles"
	CLEAN_DIR := build
	CLEAN_FILE := arkanoid.exe
else
    IS_WINDOWS := 0
    SHELL := /bin/bash
    MKDIR := mkdir -p
    RM_DIR := rm -rf
	RM_FILE := rm -f
	GENERATOR := "Unix Makefiles"
	CLEAN_DIR := build
	CLEAN_FILE := arkanoid
    CORES := $(shell nproc 2>/dev/null || echo 1)
endif

BUILD_DIR = build
OUTPUT_DIR = $(abspath .)

all: setup
ifeq ($(IS_WINDOWS), 1)
	@cmake -S . -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(OUTPUT_DIR)
	@cmake --build $(BUILD_DIR)
else
	@cmake -S . -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(OUTPUT_DIR)
	@cmake --build $(BUILD_DIR) -- -j$(CORES)
endif

debug: setup
ifeq ($(IS_WINDOWS), 1)
	@cmake -S . -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Debug -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(OUTPUT_DIR)
	@cmake --build $(BUILD_DIR)
else
	@cmake -S . -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Debug -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(OUTPUT_DIR)
	@cmake --build $(BUILD_DIR) -- -j$(CORES)
endif

setup:
	$(MKDIR) $(BUILD_DIR)

clean:
	$(RM_DIR) $(CLEAN_DIR)
	$(RM_FILE) $(CLEAN_FILE)

re: clean all

re_debug: clean debug

.PHONY: all debug clean re re_debug
