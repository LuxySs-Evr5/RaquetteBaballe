CXX = g++
CXXFLAGS = -Wall -Wextra -O2
LIBS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image
SRC = src/main.cpp src/initialize_allegro.cpp
TARGET = allegro

# Règle par défaut
all: $(TARGET)

# Compilation
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
