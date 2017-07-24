#ifndef _H_INCLUDE_MNFILELOADER_
#define _H_INCLUDE_MNFILELOADER_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace MNL {

	/* helper functions here */

	bool LoadSurface(std::string path, SDL_Surface* pSurface);
	bool LoadTexture(std::string path, SDL_Texture* pTexture);
}

#endif