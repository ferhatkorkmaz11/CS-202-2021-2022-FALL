OBJS	= main.o sorting.o
SOURCE	= main.cpp sorting.cpp
HEADER	= sorting.h
OUT	= 
CC	 = g++
FLAGS	 = -std=c++11 -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o hw1 $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

sorting.o: sorting.cpp
	$(CC) $(FLAGS) sorting.cpp 


clean:
	rm -f $(OBJS) $(OUT)