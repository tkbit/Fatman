#include<iostream>

#include<SDL.h>

  SDL_Window* window;
  SDL_Renderer* renderMain;
  Uint32 windowID = NULL;
  int status = 0;
  bool programRunning = true;

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        status = 1;
        programRunning = false;
    }

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Fatman",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        status = 1;
        programRunning = false;
    }
    else {
        windowID = SDL_GetWindowID(window);
    }
}

void checkInput() {
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
            status = 0;
            programRunning = false;
        }
        }
    }
}

int main(int argc, char* argv[]){

    initSDL();

    while (programRunning) {
        checkInput();
        SDL_Delay(1);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return status;
}