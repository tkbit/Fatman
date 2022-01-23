#include<iostream>

#include<SDL.h>

  SDL_Window* window;
  Uint32 windowID;

int initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

                      // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "FAT MAN",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    Uint32 windowID = SDL_GetWindowID(window);
    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
}

int main(int argc , char* argv[]){
    initSDL();

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_WINDOWEVENT: {
                if (event.window.windowID == windowID) {
                    switch (event.window.event) {

                    case SDL_WINDOWEVENT_CLOSE: {
                        event.type = SDL_QUIT;
                        SDL_PushEvent(&event);
                        break;
                    }
                    }
                }
                break;
            }
            case SDL_QUIT: {
                return 0;
            }
            }
        }
        SDL_Delay(1);
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}