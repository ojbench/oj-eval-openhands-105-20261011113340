CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -std=c++17

TARGET = code
SOURCES = main.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

.PHONY: clean

clean:
	rm -f $(TARGET)

