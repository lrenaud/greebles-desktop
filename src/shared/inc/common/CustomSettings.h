#ifndef CUSTOM_SETTINGS_H
#define CUSTOM_SETTINGS_H

#include <string>

using namespace std;

#define CS CustomSettings::GetInstance()

class CustomSettings
{
public:

    /**
     * Constants
     */
    const static int        MIN_START_LEVEL                 = 1;
    const static int        MAX_START_LEVEL                 = 70;

    const static int        DISABLED_TIME_LIMIT             = 0;
    const static int        MIN_TIME_LIMIT                  = 1;
    const static int        MAX_TIME_LIMIT                  = 60;

    const static int        DISABLED_REMAINING_PLAYERS      = 0;
    const static int        MIN_REMAINING_PLAYERS           = 1;
    const static int        MAX_REMAINING_PLAYERS           = 31;

private:

    enum DBColumnIndex
    {
        COL_UNLIMITED_LIVES=1,
        COL_START_LEVEL,
        COL_TIME_LIMIT,
        COL_PLAYERS_REMAINING,
        COL_ADVERTISE
    };

    /**
     * Unlimited lives, yes or no?
     */
    bool unlimitedLives;

    /**
     * Starting level
     */
    int startLevel;

    /**
     * Time limit in minutes. If 0, then no time limit is enforced.
     */
    int timeLimit;

    /**
     * The game ends when this number of players are left. 
     */
    int playersRemaining;

    /**
     * The name used to advertise this game over the network
     */
    string advertiseName;

private:
    
    /**
     * Private constructor, singleton
     */
    CustomSettings();

public:

    /**
     * Destructor
     */
    ~CustomSettings();

    /**
     * Singleton access method
     */
    static CustomSettings& GetInstance();
    
    /**
     * Saves the member data to the database.
     * @return true if save was successful, false otherwise.
     */
    bool Save();

    /**
     * Reloads all member data from the database
     * @return true if successful, false otherwise.
     */
    bool Refresh();

    /**
     * Lives are unlimited?
     */
    bool LivesAreUnlimited()const;

    /**
     * Get the current start level
     */
    int StartLevel()const;

    /**
     * Get the current time limit
     */
    int TimeLimit()const;

    /**
     * Get the current players remaining value
     */
    int RemainingPlayers()const;

    /**
     * Get the advertising name
     */
    const string& AdvertiseName()const;

    /**
     * Enable Unlimited Lives
     */
    void EnableUnlimitedLives();

    /**
     * Disable Unlimited Lives
     */
    void DisableUnlimitedLives();

    /**
     * Change the start level
     */
    void ChangeStartLevel(int newStartLevel);

    /**
     * Set Time Limit
     */
    void SetTimeLimit(int newTimeLimit);

    /**
     * Set Players Remaining
     */
    void SetRemainingPlayers(int newRemainingPlayers);

    /**
     * Set Advertising Name
     */
    void SetAdvertiseName(string newAdvertiseName);

private:

    /**
     * Sets the default values for these settings
     */
    void setDefaults();

};

#endif