#include "MNFileLoader.h"
#include "MNCore.h"

namespace MNL {

	/* helper functions here */

	bool LoadSurface(std::string path, SDL_Surface* pSurface)
	{
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		return loadedSurface;
	}

	bool LoadTexture(std::string path, SDL_Texture* pTexture)
	{
		if (!MNCore::m_bInit)
		{
			return false;
		}
		SDL_Texture* newTexture = nullptr;
		SDL_Surface* loadedSurface = nullptr; 

		if ( LoadSurface(path, loadedSurface) == false ) return false;

		newTexture = SDL_CreateTextureFromSurface(MNCore::GetRenderer(), loadedSurface);
		if (newTexture == nullptr) return false;

		SDL_FreeSurface(loadedSurface);
		pTexture = newTexture;

		return true;
	}

}