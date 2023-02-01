#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        // Handle error
        return 1;
    }

    // Load the video file
    Mix_Music *music = Mix_LoadMUS("fall_guys.mp4");
    if (!music)
    {
        // Handle error
        return 1;
    }

    // Play the video
    Mix_PlayMusic(music, 0);

    // Wait until the video finishes
    while (Mix_PlayingMusic())
    {
        SDL_Delay(100);
    }

    // Clean up
    Mix_FreeMusic(music);
    SDL_Quit();

    return 0;
}
