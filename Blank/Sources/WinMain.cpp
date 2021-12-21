#include "pch.h"
/*---------------------------------------------------------------------------*/
/* File name: WinMain.cpp                                                    */
/* Autor: cocojumbo                                                          */
/* Licence: as is                                                            */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Global variables                                                          */
/*---------------------------------------------------------------------------*/
#pragma region GlobalVariables
	WCHAR	g_class_name[MAX_NAME_STRING];
	WCHAR	g_window_title[MAX_NAME_STRING];
	int		g_window_width;
	int		g_window_height;
	HICON	g_icon;
#pragma endregion
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Predefined functions                                                      */
/*---------------------------------------------------------------------------*/
#pragma region PredefinedFunctions
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	void InitializeVariables();
	void CreateWindowClass();
	void InitializeWindow();
	void MessageLoop();
#pragma endregion
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Operations                                                                */
/*---------------------------------------------------------------------------*/
#pragma region Operations
/*
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR commandLine, INT nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(commandLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	//initialize global variables
	InitializeVariables();

	// create window class
	CreateWindowClass();

	//create window
	InitializeWindow();

	//listen for messages
	MessageLoop();
	return 0;
}
*/
#pragma endregion
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Functions                                                                 */
/*---------------------------------------------------------------------------*/
#pragma region Functions

LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		PAINTSTRUCT paint;
		BeginPaint(hWnd, &paint);
		EndPaint(hWnd, &paint);
		break;
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

void InitializeVariables()
{
	g_icon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
	LoadString(HInstance(), IDS_CLASSNAME, g_class_name, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOW_TITLE, g_window_title, MAX_NAME_STRING);
	g_window_width = 640;
	g_window_height = 480;
}

void CreateWindowClass()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.hIcon = g_icon;
	wcex.hIconSm = g_icon;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = g_class_name;
	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WindowProc;
	RegisterClassEx(&wcex);
}

void InitializeWindow()
{
	HWND h_wnd = CreateWindow(g_class_name, g_window_title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, g_window_width, g_window_height, nullptr, nullptr, HInstance(), nullptr);

	if (!h_wnd)
	{
		MessageBox(0, L"Failed to create window.", 0, 0);
		PostQuitMessage(0);
	}
	ShowWindow(h_wnd, SW_SHOW);
}

void MessageLoop()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#pragma endregion
/*---------------------------------------------------------------------------*/
