#include <SDL2/SDL.h>		// for SDL2
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>

 int 
main (int argc, char *argv[]) 
{
  
 
 
if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0)
    
 
    {
      
 
 
SDL_Log ("Failed to initialize SDL: %s", SDL_GetError ());
      
 
 
return 1;
    
 
 
}
  
 
 
 
SDL_Window * window =
    
 
SDL_CreateWindow ("Video Player", SDL_WINDOWPOS_CENTERED,
			 
 
SDL_WINDOWPOS_CENTERED, 640, 480, 0);
  
 
 
if (!window)
    
 
    {
      
 
 
SDL_Log ("Failed to create window: %s", SDL_GetError ());
      
 
 
return 1;
    
 
 
}
  
 
 
 
SDL_Renderer * renderer =
    
 
SDL_CreateRenderer (window, -1,
			   
 
SDL_RENDERER_ACCELERATED |
			   
SDL_RENDERER_PRESENTVSYNC);
  
 
 
if (!renderer)
    
 
    {
      
 
 
SDL_Log ("Failed to create renderer: %s", SDL_GetError ());
      
 
 
return 1;
    
 
 
}
  
 
 
 
Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 2048);
  
 
 
Mix_Music * music = Mix_LoadMUS ("C:\video");
  
 
 
if (!music)
    
 
    {
      
 
 
SDL_Log ("Failed to load video: %s", Mix_GetError ());
      
 
 
return 1;
    
 
 
}
  
 
 
 
int x = 0, y = 0;
  
 
 
int x_step = 1, y_step = 1;
  
 
 
 
int done = 0;
  
 
 
SDL_Event event;
  
 
 
while (!done)
    
 
    {
      
 
 
while (SDL_PollEvent (&event))
	
 
	{
	  
 
 
if (event.type == SDL_QUIT)
	    
 
	    {
	      
 
 
done = 1;
	    
 
 
}
	
 
 
}
      
 
 
 
x += x_step;
      
 
 
if (x + 640 >= SDL_GetWindowSurface (window)->w || x <= 0)
	
 
	{
	  
 
 
x_step = -x_step;
	
 
 
}
      
 
 
 
y += y_step;
      
 
 
if (y + 480 >= SDL_GetWindowSurface (window)->h || y <= 0)
	
 
	{
	  
 
 
y_step = -y_step;
	
 
 
}
      
 
 
 
SDL_SetWindowPosition (window, x, y);
      
 
 
SDL_RenderClear (renderer);
      
 
 
SDL_RenderPresent (renderer);
      
 
 
 
Mix_PlayMusic (music, 1);
    
 
 
}
  
 
 
 
Mix_FreeMusic (music);
  
 
 
Mix_CloseAudio ();
  
 
 
SDL_DestroyRenderer (renderer);
  
 
 
SDL_DestroyWindow (window);
  
 
 
SDL_Quit ();
  
 
 
 
return 0;

 
 
}


 
 
 
 
