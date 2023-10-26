CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJS =
# Executable name
EXEC = NFA2DFA

# Source file directory
SRC_DIR = src

# Main target
$(EXEC): $(OBJS) $(SRC_DIR)/main.cc
	$(CXX) $(CXXFLAGS) -o $@ $(SRC_DIR)/main.cc

# Clean up compiled files
clean:
	rm -f $(EXEC)

# Run the program with command-line arguments
run: $(EXEC)
	./$(EXEC) input.nfa output.dfa  

.PHONY: run