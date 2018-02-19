/*
 * OuterWindow.cpp
 *
 *  Created on: 2018. 2. 19.
 *      Author: syasyasya
 */

#include <wchar.h>
#include "stdafx.h"
#include "OuterWindow.h"

//namespace test {

OuterWindow::OuterWindow(RECT rect) : Control(rect){
}

OuterWindow::~OuterWindow() {
}

BOOL OuterWindow::init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	//!< 지역변수 선언
	HINSTANCE					hInst;
	HWND						hWnd;
	WNDCLASS					WndClass;
	MSG							Message;
	RECT						Rect;

	//!< 윈도우 설정
	Rect						= this->getBounds();
	hInst						= hInstance;
	WndClass.cbClsExtra			= 0;
	WndClass.cbWndExtra			= 0;
	WndClass.hbrBackground		= (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance			= hInst;
	WndClass.lpfnWndProc		= (WNDPROC)NULL;
	WndClass.lpszClassName		= "HELLO";
	WndClass.lpszMenuName		= NULL;
	WndClass.style				= CS_HREDRAW | CS_VREDRAW;

	//!< 윈도우 설정을 넘겨주는 곳
	RegisterClass(&WndClass);

	//!< 윈도우의 크기를 똑같도록 설정 (이거 안하면 윈도우 크기가 박스 포함한 값으로 됨
	AdjustWindowRect(&Rect, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION, false);

	//!< 윈도우를 메모리에 올림
	hWnd = CreateWindow(D_GAME_NAME, D_GAME_NAME, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION, D_SCREEN_XPOS, D_SCREEN_YPOS, D_SCREEN_WIDTH, D_SCREEN_HEIGHT, NULL, NULL, hInst, 0);

	//!< 초기화 실행 (만약 NULL 값이 들어오면 false)
	if (!hWnd )
		return 0;

	//!< 윈도우를 화면상에 그림
	ShowWindow(hWnd, nCmdShow);

	//!< 메시지 루프
	while (1)
	{
		if (PeekMessage(&Message, 0, 0, 0, PM_REMOVE))		//!< 메시지가 들어왔을 경우
		{
			if (Message.message == WM_QUIT)
				break;

			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
//		else                                                //!< 메시지가 들어오지 않았을 경우
//		{
//			CMain::GetInstance()->Update(0);
//			CMain::GetInstance()->Render();
//		}
	}

	//!< 루프가 끝나면 메모리 해제
//	CMain::GetInstance()->Destroy();

	return 1;
}

//LRESULT Control::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
//	switch (iMessage) {
//		case WM_TIMER:
//			CMain::GetInstance()->Update(0);
//			break;
//		case WM_KEYDOWN:
//			switch (wParam) {
//				case VK_ESCAPE:
//					CMain::GetInstance()->Destroy();
//					PostQuitMessage(0);
//				break;
//			}
//		break;
//		case WM_DESTROY:
//			CMain::GetInstance()->Destroy();
//			PostQuitMessage(0);
//			break;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}

//} /* namespace test */
