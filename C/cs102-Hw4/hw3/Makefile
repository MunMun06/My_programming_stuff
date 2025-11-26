CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = grader
OBJS = grader.o bubbleSort.o stats.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

grader.o: grader.c stats.h
	$(CC) $(CFLAGS) -c grader.c

bubbleSort.o: bubbleSort.c stats.h
	$(CC) $(CFLAGS) -c bubbleSort.c

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

clean:
	rm -f $(OBJS) $(TARGET)

