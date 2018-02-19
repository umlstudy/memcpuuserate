#include "stdafx.h"
#include "OuterWindow.h"

//using namespace test;

std::string GetLastErrorStdStr()
{
  DWORD error = GetLastError();
  if (error)
  {
    LPVOID lpMsgBuf;
    DWORD bufLen = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        error,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );
    if (bufLen)
    {
      LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
      std::string result(lpMsgStr, lpMsgStr+bufLen);

      LocalFree(lpMsgBuf);

      return result;
    }
  }
  return std::string();
}

	int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

		RECT rect = {0,};
		rect.left = 0;
		rect.top = 0;
		rect.right=200;
		rect.bottom=200;

		//new test::OuterWindow();
		//new test::OuterWindow(rect);
		try {
			OuterWindow win(rect);
			win.init(hInstance, hPrevInstance, lpszCmdParam, nCmdShow);
		}  catch (const std::exception&) {
			MessageBoxW(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		}
//test::OuterWindow *outerWindow =

		MessageBox(NULL, GetLastErrorStdStr().c_str(), "Error!", MB_ICONEXCLAMATION | MB_OK);

		return 1;
	}
