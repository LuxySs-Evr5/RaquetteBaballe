# Directories
BUILD_DIR := ./build
STATIC_BUILD_DIR := ./build-static
OUTPUT_DIR := .

# Detect OS
ifeq ($(OS),Windows_NT)
	CORES := $(NUMBER_OF_PROCESSORS)
	CLEAN_CMD := powershell -Command "if (Test-Path '$(BUILD_DIR)') { Remove-Item '$(BUILD_DIR)' -Recurse -Force }; if (Test-Path '$(STATIC_BUILD_DIR)') { Remove-Item '$(STATIC_BUILD_DIR)' -Recurse -Force }"
	GENERATOR := "Ninja"
	CMAKE := cmake.exe
	CTEST := ctest.exe
	SHELL := cmd
else
	UNAME_S := $(shell uname -s)
	CORES := $(shell sysctl -n hw.ncpu 2>/dev/null || nproc)
	CLEAN_CMD := rm -rf $(BUILD_DIR) $(STATIC_BUILD_DIR)
	GENERATOR := "Unix Makefiles"
	CMAKE := cmake
	CTEST := ctest
endif

# Targets
all: release

debug:
	@$(CMAKE) -S . -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Debug -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@$(CMAKE) --build $(BUILD_DIR) -- -j$(CORES)

release:
	@$(CMAKE) -S . -B $(BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@$(CMAKE) --build $(BUILD_DIR) -- -j$(CORES)

static:
	@$(CMAKE) -S . -B $(STATIC_BUILD_DIR) -G $(GENERATOR) -DCMAKE_BUILD_TYPE=Release -DBUILD_STATIC=ON -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$(abspath $(OUTPUT_DIR))
	@$(CMAKE) --build $(STATIC_BUILD_DIR) -- -j$(CORES)

install:
	@$(CMAKE) --install $(BUILD_DIR)

clean:
	@$(CLEAN_CMD)

re_debug: clean debug

re_release: clean release

help:
	@echo "Available targets:"
	@echo "  make [release|debug|static]   # Build the project"
	@echo "  make install                  # Installation"
	@echo "  make test                     # Launch the tests"
	@echo "  make clean                    # Clean the builds"
	@echo "  make re_debug/re_release      # Clean + build"
	@echo ""
	@echo "Customizable variables:"
	@echo "  OUTPUT_DIR=chemin             # Binary output folder"
	@echo "  PROJECT_NAME=Nom              # Binary name (default: MyProject)"

.PHONY: all debug release static clean re_debug re_release install help