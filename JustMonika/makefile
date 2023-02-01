CC=gcc
CFLAGS=-Wall -Werror -I/path/to/sdl2/include
LDFLAGS=-L/path/to/sdl2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

Just_Monika: monika.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f just_monika.exe
