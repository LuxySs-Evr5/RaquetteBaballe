CXX = g++
CXXFLAGS = -std=c++20 -O2 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wnull-dereference -Wformat=2 -Wduplicated-cond -Wduplicated-branches
LIBS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -lallegro_audio -lallegro_acodec
SRC = src/main.cpp src/global_variables.cpp src/figures/point.cpp src/init_allegro/initialize_allegro.cpp src/init_allegro/check_init.cpp src/figures/forme.cpp src/canvas/canvas.cpp src/life/life.cpp src/score/score.cpp src/wall/wall_game.cpp src/game_over/draw_game_over.cpp
TARGET = allegro

# Règle par défaut
all: $(TARGET)

# Compilation
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)