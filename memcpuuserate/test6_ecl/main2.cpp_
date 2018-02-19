//#define _WIN32_WINNT

#define _WIN32_WINNT 0x0602
#include <windows.h>
//#include <wingdi.h>
#include <stdio.h>
#include <stdlib.h>

const char g_szClassName[] = "myWindowClass";


void CreateContextMenu(HWND, LPARAM);
BOOL dragWindow = FALSE;
POINT lastPos = {0};
BOOL MoveWindowToMouse(HWND hWnd);
void WindowCreate(HWND);
void OnPaint(HWND);
void updateInfo();
float GetCPULoad();

int memUsage = 0;
float cpuUsage = 0.0f;


#define ID_POPUP_ID1 100
#define ID_POPUP_ID2 101
#define IDT_TIMER1 200

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //LRESULT ret = 0;
    switch(msg)
    {
    case WM_PAINT :
        //printf("WM_PAINT\n");
        OnPaint(hwnd);
        break;
    case WM_CREATE :
        WindowCreate(hwnd);
        break;
    case WM_TIMER :
        switch (wParam )
        {
        case IDT_TIMER1:
            updateInfo();
            //printf("IDT_TIMER1\n");
//            InvalidateRect(hwnd,NULL,TRUE);
            InvalidateRgn(hwnd, NULL, TRUE);
//            OnPaint(hwnd);
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        break;
    case WM_COMMAND :
        switch ( wParam )
        {
        case ID_POPUP_ID1 :
            wprintf(L"ID_POPUP_ID1\n");
            break;
        case ID_POPUP_ID2 :
            wprintf(L"ID_POPUP_ID2\n");
            DestroyWindow(hwnd);
            break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_RBUTTONDOWN:
        printf("WM_RBUTTONDOWN\n");
        CreateContextMenu(hwnd, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_LBUTTONUP:
        //ReleaseCapture();
        dragWindow = FALSE;
        break;
    case WM_LBUTTONDOWN:
        dragWindow = TRUE;
        lastPos.x = (int)(short) LOWORD(lParam);
        lastPos.y = (int)(short) HIWORD(lParam);
        //SetCapture(hwnd);
        break;
    case WM_NCHITTEST:
        if (GetAsyncKeyState(MK_LBUTTON) < 0 ) {
            //ret = DefWindowProc(hwnd, msg, wParam, lParam);
            DefWindowProc(hwnd, msg, wParam, lParam);
            //printf("WM_NCHITTEST %ld\n", ret);
            return 2;
        } else {
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        /*
        if (GetAsyncKeyState(MK_LBUTTON) < 0 ) {
            return WM_HI
        }
            // When we have no border or title bar, we need to perform our
            // own hit testing to allow resizing and moving.
            if (window.borderless) {
                return window.hit_test(POINT{
                    GET_X_LPARAM(lparam),
                    GET_Y_LPARAM(lparam)
                });
            }
            break;
        }
        */
    case WM_MOUSEMOVE:
        if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
        {
            //MoveWindowToMouse(hwnd);

            /*
            RECT mainWindowRect;
            POINT movedPos = {0};
            POINT curPos = {0};
            curPos.x = (int)(short) LOWORD(lParam);
            curPos.y = (int)(short) HIWORD(lParam);
            movedPos.x = curPos.x - lastPos.x;
            movedPos.y = curPos.y - lastPos.y;
            lastPos.x = (int)(short) LOWORD(lParam);
            lastPos.y = (int)(short) HIWORD(lParam);

            GetWindowRect(hwnd,&mainWindowRect);
            int windowHeight = mainWindowRect.bottom - mainWindowRect.top;
            int windowWidth = mainWindowRect.right - mainWindowRect.left;

//                ClientToScreen(hwnd, &pos);
            MoveWindow(hwnd, mainWindowRect.left + movedPos.x, mainWindowRect.top + movedPos.y, windowWidth, windowHeight, TRUE);
            */
        }
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void WindowCreate(HWND hwnd)
{
    SetTimer(hwnd, // handle of main window
    IDT_TIMER1, // timer identifier
    500, // 10-second interval
    (TIMERPROC) NULL); // no timer callback
}

BOOL MoveWindowToMouse(HWND hWnd)
{
  POINT p;
  RECT  pr;
  BOOL  bRET = FALSE;

  if (GetCursorPos(&p))
    if (GetWindowRect(hWnd, &pr))
      if (MoveWindow(hWnd, p.x, p.y, pr.right - pr.left, pr.bottom - pr.top, TRUE))
        bRET = TRUE;

  return bRET;
}

void CreateContextMenu(HWND hWnd, LPARAM lParam)
{
    RECT rc;
    GetClientRect(hWnd,&rc);
    MapWindowPoints(hWnd,GetParent(hWnd),(LPPOINT)&rc,2);

    int x = LOWORD(lParam);
    int y = HIWORD(lParam);

    printf("CreateContextMenu, %d, %d\n", x, y);

    HMENU hPopupMenu = CreatePopupMenu();
    InsertMenu(hPopupMenu, 0, MF_BYPOSITION | MF_STRING, ID_POPUP_ID1, "menu #1");
    InsertMenu(hPopupMenu, 0, MF_BYPOSITION | MF_STRING, ID_POPUP_ID2, "menu #2");
    SetForegroundWindow(hWnd);
    TrackPopupMenu(hPopupMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN, rc.left+x, rc.top+y, 0, hWnd, NULL);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    //wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    //wc.hbrBackground = (HBRUSH)CreateSolidBrush((COLORREF)RGB(0, 0, 255));
    wc.hbrBackground = (HBRUSH)(COLOR_BTNSHADOW+1);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        0, //  WS_EX_CLIENTEDGE
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW, // WS_POPUP/  WS_OVERLAPPEDWINDOW
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // 타이틀바 없애기
    LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
    lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
    SetWindowLong(hwnd, GWL_STYLE, lStyle);
    //  SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER
    SetWindowPos(hwnd, HWND_TOPMOST, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

void OnPaint(HWND hwnd)
{
    char *textBuf = (char*)malloc(30 * sizeof(char));
    wsprintf(textBuf, "메모리사용율 : %d%%", memUsage);

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint (hwnd, &ps);

    HBRUSH hBrush, oldBrush;
    hBrush=CreateSolidBrush(RGB(255,0,0));
    oldBrush=(HBRUSH)SelectObject(hdc, hBrush);
    TextOut (hdc,
             // Location of the text
             10,
             10,
             // Text to print
             textBuf,
             // Size of the text, my function gets this for us
             strlen (textBuf));

    memset(textBuf, 0, 30);

    //printf("CPU사용율 : %d%%\n", (int)(cpuUsage*100));
    wsprintf(textBuf, "CPU사용율 : %d%%", (int)(cpuUsage*100));
    TextOut (hdc,
             // Location of the text
             10,
             40,
             // Text to print
             textBuf,
             // Size of the text, my function gets this for us
             strlen (textBuf));

    EndPaint (hwnd, &ps);
    Rectangle(hdc,50,50,60,70);
    //printf("In OnPaint....2\n");

    SelectObject(hdc,oldBrush);
    DeleteObject(hBrush);
    free(textBuf);
}

void updateInfo()
{
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx (&statex);
    memUsage = (int)statex.dwMemoryLoad;

    cpuUsage = GetCPULoad();
}

// CPU사용율
static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
   static unsigned long long _previousTotalTicks = 0;
   static unsigned long long _previousIdleTicks = 0;

   unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
   unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;

   float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);

   _previousTotalTicks = totalTicks;
   _previousIdleTicks  = idleTicks;
   return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME & ft)
{
    return (((unsigned long long)(ft.dwHighDateTime))<<32)|((unsigned long long)ft.dwLowDateTime);
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.  Returns -1.0 on error.
//WINBASEAPI BOOL WINAPI GetSystemTimes(LPFILETIME,LPFILETIME,LPFILETIME);

float GetCPULoad()
{
   FILETIME idleTime, kernelTime, userTime;
   BOOL gst = GetSystemTimes(&idleTime, &kernelTime, &userTime);
   return gst ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime)+FileTimeToInt64(userTime)) : -1.0f;
}
