CC=gcc
CFLAGS=-Wall `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

joke_generator: joke_generator.c
	$(CC) $(CFLAGS) joke_generator.c -o joke_generator $(LDFLAGS)

clean:
	del joke_generator.exe
