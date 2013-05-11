#ifndef GENERAL_SETTINGS_H
#define GENERAL_SETTINGS_H

#include <string>

#include "GreeblesDatabase.h"

using namespace std;

class GeneralSettings
{
private:

    /**
     * Difficulty Level Enum
     */
    enum DifficultyLevel
    {
        DL_EASY = 1,
        DL_NORMAL,
        DL_HARD,
        DL_SUICIDAL
    };

    /**
     * General Game Settings
     */
    bool                soundEnabled;
    bool                musicEnabled;

    DifficultyLevel     difficulty;
    string              difficultyStr;

public:

    GeneralSettings();
    ~GeneralSettings();

private:

    /**
     * Refreshes the general settings by reloading them from the database.
     * @return true if reload was successful, false otherwise.
     */
    bool refresh();

    /**
     * Saves the state of the general settings to the database.
     * @return true if the data was successfully saved, false otherwise.
     */
    bool save();

    /**
     * Sets the state of general settings to be their default values.
     */
    void setDefaults();
};

#endif 