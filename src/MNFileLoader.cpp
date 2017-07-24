#include "MNFileLoader.h"
#include "MNCore.h"

namespace MNL {

	/* helper functions here */

	SDL_Surface* LoadSurface(std::string path)
	{
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == nullptr)
		{
			SDL_Log("Image load failure. SDL_Error: %s", SDL_GetError());
		}

		return loadedSurface;
	}

	SDL_Texture* LoadTexture(std::string path)
	{
		if (!MNCore::m_bInit)
		{
			SDL_Log("Initilaize MNL before calling:%s\n", __FUNCDNAME__);
			return nullptr;
		}
		SDL_Texture* newTexture = nullptr;
		SDL_Surface* loadedSurface = LoadSurface(path);
		if (nullptr != loadedSurface)
		{
			newTexture = SDL_CreateTextureFromSurface(MNCore::GetRenderer(), loadedSurface);
			if (newTexture == nullptr)
			{
				SDL_Log("Unable to create texture. SDL_Error:%s\n", SDL_GetError());
			}
			SDL_FreeSurface(loadedSurface);
		}
		return newTexture;
	}

}