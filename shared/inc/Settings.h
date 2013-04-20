#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
private:

	// Data members



private:

	Settings(void);

public:
	
	~Settings(void);

	static Settings *GetInstance();

	bool Save();

private:

	bool load();
};

#endif
