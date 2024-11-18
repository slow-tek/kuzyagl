SRC_DIR = ./src
BUILD_DIR = ./build
INC_DIR = ./include
RES_DIR = ./res
CFLAGS = $(shell pkg-config --cflags glew sdl2)
LDFLAGS = $(shell pkg-config --libs glew sdl2)
CXXFLAGS = -std=c++11 
OBJ_DIR = $(BUILD_DIR)/obj
OBJS = $(wildcard $(OBJ_DIR)/*.o)

kuzya: main.o mesh.o texture.o shader.o display.o
	g++ $(OBJS) -o $(BUILD_DIR)/kuzya -I$(INC_DIR) $(CFLAGS) $(LDFLAGS)

main.o:
	g++ -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o -I$(INC_DIR)
	
mesh.o:
	g++ -c $(SRC_DIR)/mesh.cpp -o $(OBJ_DIR)/mesh.o -I$(INC_DIR)

texture.o:
	g++ -c $(SRC_DIR)/texture.cpp -o $(OBJ_DIR)/texture.o -I$(INC_DIR)

shader.o:
	g++ -c $(SRC_DIR)/shader.cpp -o $(OBJ_DIR)/shader.o -I$(INC_DIR)

display.o:
	g++ -c $(SRC_DIR)/display.cpp -o $(OBJ_DIR)/display.o -I$(INC_DIR)
	
clean:
	rm $(OBJ_DIR)/*.o
	echo Clean done.