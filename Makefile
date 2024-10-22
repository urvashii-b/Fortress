CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = src/main.cpp src/encryption.cpp src/access_control.cpp src/file_manager.cpp src/logger.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = bin/fortress

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) -lssl -lcrypto

clean:
	rm -f $(OBJ) $(TARGET)
