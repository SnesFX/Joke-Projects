# Define the target file
TARGET = shut_down.exe

# Define the compiler to use
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall

# Define the source files
SOURCES = shut_down.c

# Define the object files
OBJECTS = $(SOURCES:.c=.o)

# Define the build rule for the target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Define the build rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Define the clean rule
.PHONY: clean
clean:
	del $(TARGET) $(OBJECTS)
