#pragma once

#include<SDL.h>

#include "GameEngine/gameEngine.h"

class game : public gameEngine {
public:
    float cameraX, cameraY;

protected:
    bool initGame();
    bool updateGame();

};