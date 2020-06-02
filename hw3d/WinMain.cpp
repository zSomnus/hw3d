//#include <Windows.h>
//#include "WindowsMessageMap.h"
#include "Window.h"
#include <sstream>
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static WindowsMessageMap mm;
//	OutputDebugString(mm(msg, lParam, wParam).c_str());
//
//	switch (msg)
//	{
//	case WM_CLOSE:
//		PostQuitMessage(69);
//		break;
//	case WM_KEYDOWN:
//		if (wParam == 'F')
//		{
//			SetWindowText(hWnd, "Show Text");
//		}
//
//		break;
//	case WM_CHAR:
//	{
//		static std::string title;
//		title.push_back((char)wParam);
//		SetWindowText(hWnd, title.c_str());
//	}
//	break;
//	case WM_LBUTTONDOWN:
//	{
//		const POINTS pt = MAKEPOINTS(lParam);
//		std::ostringstream oss;
//		oss << "(" << pt.x << ", " << pt.y << ")";
//		SetWindowText(hWnd, oss.str().c_str());
//	}
//	break;
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//const auto pClassName = "hw3d2333";
	//// register window class
	//WNDCLASSEX wc = { 0 };
	//wc.cbSize = sizeof(wc);
	//wc.style = CS_OWNDC;
	//wc.lpfnWndProc = WndProc;
	//wc.cbClsExtra = 0;
	//wc.cbWndExtra = 0;
	//wc.hInstance = hInstance;
	//wc.hIcon = nullptr;
	//wc.hCursor = nullptr;
	//wc.hbrBackground = nullptr;
	//wc.lpszMenuName = nullptr;
	//wc.lpszClassName = pClassName;
	//wc.hIconSm = nullptr;
	//RegisterClassEx(&wc);
	//HWND hWnd = CreateWindowEx(
	//	0,
	//	pClassName,
	//	"Happy Hard Window",
	//	WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
	//	200, 200, 640, 480,
	//	nullptr,
	//	nullptr,
	//	hInstance,
	//	nullptr
	//);

	//// show the window
	//ShowWindow(hWnd, SW_SHOW);

	try
	{
		// Instantiate an object of type Window that call the constructor and create a window
		Window wnd(800, 300, "First Box");

		// message pump
		MSG msg;
		BOOL gResult;
		while (gResult = GetMessage(&msg, nullptr, 0, 0) > 0)
		{
			TranslateMessage(&msg);	// post a WM_CHAR message to the message queue
			DispatchMessage(&msg);

			// Test code
			static int i = 0;
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("Gone!");
					break;
				case Mouse::Event::Type::Move:
				{
					std::ostringstream oss;
					oss << "Mouse moved to (" << e.GetPosX() << ", " << e.GetPosY() << ")";
					wnd.SetTitle(oss.str());
				}
				break;
				case Mouse::Event::Type::WheelUp:
					i++;
					{
						std::ostringstream oss;
						oss << "Up: " << i;
						wnd.SetTitle(oss.str());
					}
					break;
				case Mouse::Event::Type::WheelDown:
					i--;
					{
						std::ostringstream oss;
						oss << "Down: " << i;
						wnd.SetTitle(oss.str());
					}
					break;
				}
			}

			//if (wnd.kbd.KeyIsPressed(VK_MENU))
			//{
			//	MessageBox(nullptr, "Something happen!", "Space key was pressed", MB_OK | MB_ICONEXCLAMATION);
			//}
		}

		// Check if GetMessage call itself broke
		if (gResult == -1)
		{
			throw CHWND_LAST_EXCEPT();
		}
		// wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}
	catch (const MyException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}

	return -1;
}
