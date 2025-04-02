CXX = g++
CXXFLAGS = -Wall -std=c++17
OBJ = main.o product.o database.o
TARGET = inventory

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp product.h database.h
	$(CXX) $(CXXFLAGS) -c main.cpp

product.o: product.cpp product.h
	$(CXX) $(CXXFLAGS) -c product.cpp

database.o: database.cpp database.h product.h
	$(CXX) $(CXXFLAGS) -c database.cpp

clean:
	rm -f $(TARGET) $(OBJ)
