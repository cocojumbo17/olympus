#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication(){return new x;}

class OLYMPUS_API IApplication
{
public:
	IApplication();
	virtual ~IApplication();
	virtual void Initialize() = 0;
	virtual void Update() = 0;
};

