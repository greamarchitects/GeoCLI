#--------------------
# GeoCLI Makefile
#--------------------

# Trial
# all:
# 	g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/*.cpp -o build/geocli


# Compiler and flags
CXX = g++ 
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
INCLUDES = -Iinclude



# $(TARGET):
#	$(CXX) $(CXXFLAGS) $(INCLUDES) src/*.cpp -o build/geocli
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) src/*.cpp -o $(TARGET)


# Create Directories
BUILD_DIR = build
SRC_DIR = src

# Retrieve and Manage Files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET := $(BUILD_DIR)/geocli

# Create Target
all: $(TARGET)

# Link the program parts (create .s files)
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile the program (create .o files)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Debug build
debug: CXXFLAGS += -g -O0
debug: clean all

# Optimized build
opt: CXXFLAGS += -O2 -DNDEBUG
opt: clean all

# Genereate assembly (create .s files)
asm: | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -S $(SOURCES)
	mv *.s $(BUILD_DIR)/

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean: 
	rm -rf $(BUILD_DIR)

# Phony non-file targets
.PHONY: all debug opt asm run clean


