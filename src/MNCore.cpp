#include "MNCore.h"


namespace MNL {
	MNCore::MNCore()
	{
	}

	MNCore::~MNCore()
	{
	}

	MNCore* MNCore::GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new MNCore();
		return m_pInstance;
	}

	SDL_Renderer* MNCore::GetRenderer()
	{
		return m_pRenderer;
	}

	void MNCore::FreeInstnace()
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
			m_bInit = false;
		}
	}

	MNCore*			MNCore::m_pInstance = nullptr;
	SDL_Renderer*	MNCore::m_pRenderer = nullptr;
	bool			MNCore::m_bInit = false;


	bool MNL_INIT(SDL_Renderer* pRenderer)
	{
		if (MNCore::m_bInit)
		{
			SDL_Log("MNL is already initialized\n");
			return false;
		}
		if (nullptr == pRenderer)
		{
			SDL_Log("MNL initialize failed. pRenderer is null\n");
			return false;
		}
		MNCore* pCore = MNCore::GetInstance();
		pCore->m_pRenderer = pRenderer;
		MNCore::m_bInit = true;
		return true;
	}

	void MNL_QUIT()
	{
		MNCore::FreeInstnace();
	}
}
