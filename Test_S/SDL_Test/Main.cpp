#include <stdio.h>
#include <stdexcept>

// ATTENTION
// This file is only to check if
// SDL is correctly installed and linked against
// If everything works, an application is launched showing
// an image.
// However the application is "buggy" as it leaks memory
// and violates some other rules

#ifdef WINDOWSOS
  #include <SDL.h>
  #include <SDL_image.h>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#endif


int main(int argc, char* argv[])
{
  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw std::runtime_error(std::string(SDL_GetError()));

  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("SDL_image could not initialize! "
                             "SDL_image Error: " + std::string(IMG_GetError()));


  auto window = SDL_CreateWindow("SDL2 Window",
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
 				     900, 900,SDL_WINDOW_RESIZABLE); //AGRANDIR LA TAILLE de L'IMAGE
 
  
  SDL_Surface *screen = SDL_GetWindowSurface(window);

 
 // window_surface_ptr = SDL_CreateRGBSurface(0, 600,600, 32, 0, 0, 0, 0);
  Uint32 green = SDL_MapRGB(screen->format, 0, 255, 0);

  SDL_FillRect(screen, NULL,green);
  SDL_UpdateWindowSurface(window);
  SDL_Event event;
  bool run = true;
  while(run){
	  while(SDL_PollEvent(&event)){
			  if(event.type == SDL_QUIT)
			  {
			  	run = false;
				break;
			  }
	}
}
  
  
  //if (SDL_BlitSurface(surf, NULL, window_surface_ptr, &rect))
    //  throw std::runtime_error("Could not apply texture.");



/* 
  auto start = SDL_GetTicks();

  SDL_Event e;
  bool quit = false;
  while (!quit && (SDL_GetTicks() - start < 10000)) {
      while (SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT) {
              quit = true;
              break;
          }
      }
  }
*/
  return 0;
}
