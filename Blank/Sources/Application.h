#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
	// Inherited via IApplication
	virtual void Initialize() override;
	virtual void Update() override;
};