#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application);

void Application::Initialize()
{
	MessageBox(0, L"Application::Initialize", 0, 0);
}

void Application::Update()
{
	MessageBox(0, L"Application::Update", 0, 0);
}
