#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[]) {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  // Create a window
  window = SDL_CreateWindow("Just Monika", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
  if (!window) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return 1;
  }

  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return 1;
  }

  // Load the image of Monika
  surface = IMG_Load("monika.png");
  if (!surface) {
    SDL_Log("Failed to load image: %s", IMG_GetError());
    return 1;
  }

  // Convert the surface to a texture
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture) {
    SDL_Log("Failed to create texture: %s", SDL_GetError());
    return 1;
  }

  // Free the surface
  SDL_FreeSurface(surface);

  // Clear the renderer
  SDL_RenderClear(renderer);

  // Render the texture
  SDL_RenderCopy(renderer, texture, NULL, NULL);

  // Update the screen
  SDL_RenderPresent(renderer);

  // Wait for the user to close the window
  SDL_Event event;
  while (SDL_WaitEvent(&event) && event.type != SDL_QUIT) {
  }

  // Clean up
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
