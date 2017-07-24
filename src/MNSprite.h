#ifndef _H_INCLUDE_MNSPRITE_
#define _H_INCLUDE_MNSPRITE_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace MNL {

	class MNSprite
	{
	private:
		SDL_Renderer*			m_pRenderer;
		SDL_Texture*			m_pTexture;
	public:
		double					x,y,w,h;
		

	public:
		MNSprite();
		MNSprite(std::string imageFilePath);
		MNSprite(SDL_Texture* pTexture);
		~MNSprite();

	public:
		void Render();
		bool LoadTextureFromFile(std::string imageFilePath);
		bool SetTexture(SDL_Texture* pTexture);

		const SDL_Point	Position();
		const SDL_Rect	Rect();

	};

}

#endif

