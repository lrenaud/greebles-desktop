#ifndef PLAYER_SETTINGS_H
#define PLAYER_SETTINGS_H

#include <string>
#include <sstream>

using namespace std;

class PlayerSettings
{
private:

    enum DBColumnIndex
    {
        COL_ID=0,
        COL_PLAYER_TYPE_ID,
        COL_CONTROL_SET_ID,
        COL_ENABLED,
        COL_NAME
    };

    enum PlayerType
    {
        HUMAN=1,
        FRIENDLY_AI,
        NASTY_AI
    };

    int             id;

    PlayerType      playerType;

    int             controlSetId;

    bool            enabled;

    string          name;

public:

    /**
     * Creates a player settings instance for the player with id: id. 
     * Loads data from database on creation.
     */
    PlayerSettings(int id);

    /**
     * Destructor
     */
    ~PlayerSettings();

    /**
     * Get an integer representation of the player type
     * @return integer representation of the player type
     */
    int PlayerTypeId()const;

    /**
     * Determine if this player is human
     * @return playerType == HUMAN
     */
    bool IsHuman()const;

    /**
     * Determin if this player is a Friendly AI
     * @return playerType == FRIENDLY_AI
     */ 
    bool IsFriendlyAI()const;

    /**
     * Determine if this player is a Nasty AI
     * @return playerType == NASTY_AI
     */
    bool IsNastyAI()const;

    /**
     * Determine if this player is enabled
     * @return enabled
     */
    bool Enabled()const;

    /**
     * Get this player's name
     * @return name
     */
    const string& Name()const;

    /**
     * Change the player's type by specifying a new type id
     * @param  typeId An integer corresponding to a player type id
     *                1 = Human
     *                2 = Friendly AI
     *                3 = Nasty AI
     *                Anything else is invalid and will not change the type
     * @return        true if the type was successfully changed
     */
    bool SetTypeById(int typeId);

    /**
     * Disables this player
     */
    void Disable();

    /**
     * Enables this player
     */
    void Enable();

    /**
     * Changes the name of this player
     * @param newName The new name to assign to this player
     */
    void ChangeName(const char* newName);

    /**
     * Save this player's settings to the database
     * @return true if save was successful, false otherwise
     */
    bool Save();

private:

    /**
     * Read in the player settings associated with id from the database
     * @param  id The id of the player to read
     * @return    true if the load was successful, false otherwise
     */
    bool load(int id);
    
    /**
     * Sets default values for this instance. Default values are invalid, Save() will fail.
     */
    void setDefaults();

};

#endif