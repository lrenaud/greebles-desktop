#include "Settings.h"

Settings::Settings(void)
{
	if (!load())
		; // Error
}

Settings::~Settings(void)
{

}

Settings *Settings::GetInstance()
{
	static Settings instance;

	return &instance;
}

bool Settings::Save()
{

}

bool Settings::load()
{

}
