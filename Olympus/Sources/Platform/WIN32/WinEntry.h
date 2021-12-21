#pragma once
#include "olympus.h"
#include "IApplication.h"

extern IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE , HINSTANCE , LPSTR , INT )
{
	auto app = EntryApplication();

	app->Initialize();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			app->Update();
	}
	return 0;
}
