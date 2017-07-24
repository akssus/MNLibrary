#ifndef _H_INCLUDE_MNFILELOADER_
#define _H_INCLUDE_MNFILELOADER_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace MNL {

	/* helper functions here */

	SDL_Surface* LoadSurface(std::string path);
	SDL_Texture* LoadTexture(std::string path);
}

#endif