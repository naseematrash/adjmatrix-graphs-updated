# Compiler and compiler flags
CXX = clang++
CXXFLAGS = -Wall -g

# Define the executable output names
TARGET = DemoApp
TEST_TARGET = GraphTests

# Object files
OBJS = Graph.o TEST.o Algorithms.o
TEST_OBJS = Graph.o GraphTests.o

# Header dependencies
DEPS = Algorithms.hpp Graph.hpp

# Default target
all: $(TARGET) $(TEST_TARGET)

# Link the object files into the DemoApp binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the object files into the GraphTests binary
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each cpp file to an object file
Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c $<

Test.o: TEST.cpp Graph.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c $<

GraphTests.o: GraphTests.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c $<

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean the build
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)

# Phony targets
.PHONY: all clean
