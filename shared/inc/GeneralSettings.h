#ifndef GENERAL_SETTINGS_H
#define GENERAL_SETTINGS_H

#include <string>
#include <map>

#include "GreeblesDatabase.h"

using namespace std;

#define GS      GeneralSettings::GetInstance()

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
     * Refreshes the general settings by reloading them from the database.
     * @return true if reload was successful, false otherwise.
     */
    bool Refresh();

    /**
     * Returns true if the difficulty level is currently set to easy
     * @return difficulty == DL_EASY
     */
    bool DifficultyIsEasy()const;

    /**
     * Returns true if the difficulty level is currently set to normal
     * @return difficulty == DL_NORMAL
     */
    bool DifficultyIsNormal()const;

    /**
     * Returns true if the difficulty level is currently set to hard
     * @return difficulty == DL_HARD
     */
    bool DifficultyIsHard()const;

    /**
     * Returns true if the difficulty level is currently set to suicidal
     * @return difficulty == DL_SUICIDAL
     */
    bool DifficultyIsSuicidal()const;

    /**
     * Returns an integer representation of the current difficulty level
     * @return an integer corresponding to DifficultyLevel enum
     */
    int DifficultyLevelInt()const;

    /**
     * Returns true if sound is currently enabled
     * @return soundEnabled == true
     */
    bool SoundEnabled()const;

    /**
     * Returns true if music is currently enabled
     * @return musicEnabled == true
     */
    bool MusicEnabled()const;

    /**
     * Sets the difficulty level based on the integer represntationg given.
     * If difficultyLevel does not match one of the DifficultLevel enumerations,
     * then difficulty will remain unchanged.
     * @param difficulty The integer representation of the desired difficulty level
     */
    void ChooseDifficulty(int difficultyLevel);

    /**
     * Sets soundEnabled to true
     */
    void EnableSound();

    /**
     * Sets musicEnabled to true
     */
    void EnableMusic();

    /**
     * Sets soundEnabled to false
     */
    void DisableSound();

    /**
     * Sets musicEnabled to false
     */
    void DisableMusic();

private:

    /**
     * Sets the state of general settings to be their default values.
     */
    void setDefaults();
};

#endif 