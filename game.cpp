#include "game.h"

bool game::initGame() {

	assetSurface = SDL_LoadBMP("assets/spriteSheet.bmp");
	assetTexture = SDL_CreateTextureFromSurface(renderer, assetSurface);
	SDL_FreeSurface(assetSurface);


	return true;
}

bool game::updateGame() {

	drawSprite(0, 1, 1, 3, 10, SDL_FLIP_VERTICAL);

	return true;

}