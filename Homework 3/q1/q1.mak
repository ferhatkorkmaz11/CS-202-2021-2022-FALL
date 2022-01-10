OBJS	= main.o MaxHeap.o MinHeap.o MedianHeap.o
SOURCE	= main.cpp MaxHeap.cpp MinHeap.cpp MedianHeap.cpp
HEADER	= MaxHeap.h MinHeap.h MedianHeap.h
OUT	= q1
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

MaxHeap.o: MaxHeap.cpp
	$(CC) $(FLAGS) MaxHeap.cpp 

MinHeap.o: MinHeap.cpp
	$(CC) $(FLAGS) MinHeap.cpp 

MedianHeap.o: MedianHeap.cpp
	$(CC) $(FLAGS) MedianHeap.cpp 


clean:
	rm -f $(OBJS) $(OUT)