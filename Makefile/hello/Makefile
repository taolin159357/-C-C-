# version1
hello: main.cpp printhello.cpp factorial.cpp 
	g++ -o hello main.cpp printhello.cpp factorial.cpp

# version2
CXX = g++
TARGET = hello
OBJ = main.o printhello.o factorial.o

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)
	
main.o: main.cpp
	$(CXX) -c main.cpp
	
printhello.o: printhello.cpp
	$(CXX) -c printhello.cpp
	
factorial.o: factorial.cpp
	$(CXX) -c factorial.cpp

# version3
CXX = g++
TARGET = hello
OBJ = main.o printhello.o factorial.o

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	
.PHONY: clean
clean:
	rm -f *.o $(TARGET)

# version4
CXX = g++
TARGET = hello
SRC = $(wildcard *.cpp)#获取当前录下所有的.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))#将$(SRC)中所有的.cpp替换成.o文件

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	
.PHONY: clean
clean:
	rm -f *.o $(TARGET)