OBJS	= analysis.o main.o AVLTree.o
SOURCE	= analysis.cpp main.cpp AVLTree.cpp
HEADER	= analysis.h AVLTree.h
OUT	= q2
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

analysis.o: analysis.cpp
	$(CC) $(FLAGS) analysis.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

AVLTree.o: AVLTree.cpp
	$(CC) $(FLAGS) AVLTree.cpp 


clean:
	rm -f $(OBJS) $(OUT)