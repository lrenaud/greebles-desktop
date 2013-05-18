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

private:

    GeneralSettings();

public:

    ~GeneralSettings();

    static GeneralSettings* GetInstance();

    /**
     * Saves the state of the general settings to the database.
     * @return true if the data was successfully saved, false otherwise.
     */
    bool Save();

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

    /**
     * Returns true if sound is currently enabled
     * @return soundEnabled == true
     */
    bool SoundEnabled()const{return soundEnabled;}

    /**
     * Returns true if music is currently enabled
     * @return musicEnabled == true
     */
    bool MusicEnabled()const{return musicEnabled;}

    /**
     * Sets the difficulty level based on the string representation given.
     * If the string isn't recognized, the default is set. (Normal)
     * @param difficulty The string representation of the desired difficulty level
     */
    void ChooseDifficulty(const char* difficulty);

private:

    /**
     * Refreshes the general settings by reloading them from the database.
     * @return true if reload was successful, false otherwise.
     */
    bool refresh();

    /**
     * Sets the state of general settings to be their default values.
     */
    void setDefaults();
};

#endif 