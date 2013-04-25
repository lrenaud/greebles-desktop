#include "../inc/Settings.h"

Settings::Settings(void)
{

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
