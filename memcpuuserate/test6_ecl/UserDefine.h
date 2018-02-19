#pragma once

#include <Windows.h>

/**
	@file		UserDefine.h
	@date		2014/8/25
	@author		Vallista
	@brief		���� ó���ؾ� �� �͵��� ��Ƶ� ��
*/

#define D_GAME_NAME			"API Sample"	///< ���ø����̼��� �̸�

#define D_SCREEN_WIDTH		1024			///< ���ø����̼��� �ִ� ���� ��

#define D_SCREEN_HEIGHT		768				///< ���ø����̼��� �ִ� ���� ��

#define D_WINDOW_WIDTH		GetSystemMetrics(SM_CXSCREEN)		//!< �������� ���� ��

#define D_WINDOW_HEIGHT		GetSystemMetrics(SM_CYSCREEN)		//!< �������� ���� ��

#define D_SCREEN_XPOS		D_WINDOW_WIDTH	/ 2 - D_SCREEN_WIDTH  / 2	//!< �������� ��ġ (����) �� 

#define D_SCREEN_YPOS		D_WINDOW_HEIGHT	/ 2 - D_SCREEN_HEIGHT / 2	//!< �������� ��ġ (����) ��

#define SAFE_DELETE(p)		{ delete p; p = NULL; }

