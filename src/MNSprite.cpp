#include "MNSprite.h"
#include "MNFileLoader.h"
#include "assetsID.h"
#include <string>


namespace MNL {

	MNSprite::MNSprite():	m_pTexture(nullptr),
							x(0),y(0),w(0),h(0)
	{
		m_pRenderer = MNCore::GetRenderer();
		LoadTextureFromFile(AID_DEFAULT_TEXTURE);
	}


	MNSprite::MNSprite(std::string imageFilePath) : x(0), y(0), w(0), h(0)
	{
		m_pRenderer = MNCore::GetRenderer();
		LoadTextureFromFile(imageFilePath);
	}

	MNSprite::MNSprite(SDL_Texture* pTexture) : x(0), y(0), w(0), h(0)
	{
		m_pRenderer = MNCore::GetRenderer();
		if (!SetTexture(pTexture))
		{
			LoadTextureFromFile(AID_DEFAULT_TEXTURE);
		}
	}

	MNSprite::~MNSprite()
	{
		SDL_DestroyTexture(m_pTexture);
		m_pTexture = nullptr;
	}

	bool MNSprite::LoadTextureFromFile(std::string imageFilePath)
	{
		m_pTexture = MNL::LoadTexture(imageFilePath);
		if (nullptr == m_pTexture)
		{
			m_pTexture = LoadTexture(AID_DEFAULT_TEXTURE);
			return false;
		}
		int tw, th;
		SDL_QueryTexture(m_pTexture, nullptr, nullptr, &tw, &th);
		w = tw;
		h = th;
		return true;
	}
	bool MNSprite::SetTexture(SDL_Texture* pTexture)
	{
		if (nullptr == pTexture)
		{
			SDL_Log("%s : null texture has set\n", __FUNCDNAME__);
			return false;
		}
		else
			m_pTexture = pTexture;

		int tw, th;
		SDL_QueryTexture(m_pTexture, nullptr, nullptr, &tw, &th);
		w = tw;
		h = th;
		return true;
	}

	const SDL_Point	MNSprite::Position()
	{
		SDL_Point pt;
		pt.x = x;
		pt.y = y;
		return pt;
	}
	const SDL_Rect	MNSprite::Rect()
	{
		SDL_Rect rt;
		rt.x = x;
		rt.y = y;
		rt.w = w;
		rt.h = h;
		return rt;
	}

	void MNSprite::Render()
	{
		if (nullptr == m_pRenderer || nullptr == m_pTexture) return;
		//render at 0,0 for test
		SDL_Rect dst = Rect();
		SDL_RenderCopy(m_pRenderer, m_pTexture, nullptr, &dst);
	}

};