CXX = g++
CXXFLAGS = -Wall -Wextra -O2
LIBS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image
SRC = src/main.cpp src/global_variables.cpp src/init_allegro/initialize_allegro.cpp src/figures/forme.cpp src/canvas/canvas.cpp
TARGET = allegro

# Règle par défaut
all: $(TARGET)

# Compilation
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
