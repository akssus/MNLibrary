#ifndef _H_INCLUDE_MNCORE_
#define _H_INCLUDE_MNCORE_

#include <SDL.h>

/**** Call MNL_INIT before using MNL 
  and call MNL_QUIT when close the app ****/

namespace MNL {
	class MNCore
	{
	public:
		~MNCore();
		static MNCore*			GetInstance();
		static SDL_Renderer*	GetRenderer();
		static void				FreeInstnace();
		friend bool MNL_INIT(SDL_Renderer* pRenderer);
		friend void MNL_QUIT();

	private:
		MNCore();

	public:
		static bool				m_bInit;

	private:
		static MNCore*			m_pInstance;
		static SDL_Renderer*	m_pRenderer;
	};
	bool MNL_INIT(SDL_Renderer* pRenderer);
	void MNL_QUIT();
}

#endif

