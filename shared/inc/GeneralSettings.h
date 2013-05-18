#ifndef GENERAL_SETTINGS_H
#define GENERAL_SETTINGS_H

#include <string>
#include <map>

#include "GreeblesDatabase.h"

using namespace std;

class GeneralSettings
{
private:

    enum DBColumnIndex
    {
        COL_DIFFICULTY=1,
        COL_SOUND,
        COL_MUSIC,

        COL_DIFFICULTY_ID=0,
        COL_DIFFICULTY_TEXT=1
    };

    enum DifficultyLevel
    {   
        DL_EASY = 1,
        DL_NORMAL,
        DL_HARD,
        DL_SUICIDAL
    };

    /**
     * General Game Settings Values
     */
    DifficultyLevel                 difficulty;
    bool                            soundEnabled;
    bool                            musicEnabled;

    /**
     * Map containing string representations of difficulty levels
     */
    map<DifficultyLevel, string>    difficultyStrs;

public:

    GeneralSettings();
    ~GeneralSettings();

    /**
     * Returns true if the difficulty level is currently set to easy
     * @return difficulty == DL_EASY
     */
    bool DifficultyIsEasy()const{return difficulty == DL_EASY;}

    /**
     * Returns true if the difficulty level is currently set to normal
     * @return difficulty == DL_NORMAL
     */
    bool DifficultyIsNormal()const{return difficulty == DL_NORMAL;}

    /**
     * Returns true if the difficulty level is currently set to hard
     * @return difficulty == DL_HARD
     */
    bool DifficultyIsHard()const{return difficulty == DL_HARD;}

    /**
     * Returns true if the difficulty level is currently set to suicidal
     * @return difficulty == DL_SUICIDAL
     */
    bool DifficultyIsSuicidal()const{return difficulty == DL_SUICIDAL;}

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