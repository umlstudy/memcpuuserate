#pragma once

#include <Windows.h>

/**
	@file		UserDefine.h
	@date		2014/8/25
	@author		Vallista
	@brief		선행 처리해야 할 것들을 모아둔 곳
*/

#define D_GAME_NAME			"API Sample"	///< 어플리케이션의 이름

#define D_SCREEN_WIDTH		1024			///< 어플리케이션의 최대 가로 값

#define D_SCREEN_HEIGHT		768				///< 어플리케이션의 최대 세로 값

#define D_WINDOW_WIDTH		GetSystemMetrics(SM_CXSCREEN)		//!< 윈도우의 가로 값

#define D_WINDOW_HEIGHT		GetSystemMetrics(SM_CYSCREEN)		//!< 윈도우의 세로 값

#define D_SCREEN_XPOS		D_WINDOW_WIDTH	/ 2 - D_SCREEN_WIDTH  / 2	//!< 윈도우의 위치 (가로) 값 

#define D_SCREEN_YPOS		D_WINDOW_HEIGHT	/ 2 - D_SCREEN_HEIGHT / 2	//!< 윈도우의 위치 (세로) 값

#define SAFE_DELETE(p)		{ delete p; p = NULL; }

