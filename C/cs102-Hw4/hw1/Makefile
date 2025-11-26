CC = gcc
CFLAGS = -Wall -Wextra -std=c17

TARGET = grader
OBJS = grader.o get_n_terms.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

grader.o: grader.c get_n_terms.h
	$(CC) $(CFLAGS) -c grader.c

get_n_terms.o: get_n_terms.c get_n_terms.h
	$(CC) $(CFLAGS) -c get_n_terms.c

clean:
	rm -f $(OBJS) $(TARGET)

