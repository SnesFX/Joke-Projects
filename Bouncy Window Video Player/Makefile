CC = gcc
CFLAGS = -Wall -Wextra -g -I/usr/local/include/SDL2
LDFLAGS = -lSDL2 -lSDL2_mixer

video_player: video_player.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f video_player
