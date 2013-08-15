#ifndef PLAYER_SETTINGS_H
#define PLAYER_SETTINGS_H

#include <string>
#include <sstream>

#include "ControlSet.h"

using namespace std;

class PlayerSettings
{
public:

    /**
     * Constant to limit name length
     */
    static const int    MAX_NAME_LENGTH     = 10;
    
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

    ControlSet*     controlSet;

    bool            enabled;

    string          name;

public:

    /**
     * Creates a player settings instance for the player with id: id. 
     * Loads data from database on creation.
     */
    PlayerSettings(int id);

    PlayerSettings(const PlayerSettings& other)=delete;
    PlayerSettings& operator=(const PlayerSettings& rhs)=delete;    

    /**
     * Destructor
     */
    ~PlayerSettings();

    /**
     * Get the id of this player
     * @return id
     */
    int Id()const;

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
     * Get this player's control set
     * @return a pointer to this player's current controls
     */
    ControlSet* Controls();

    /**
     * Change the player's id. This is a bit dangerous as
     * far as data integrity goes. It should ONLY be used 
     * when player's are swapped on the Setup GUI.
     * @param newId The new id for this settings group. It
     *              must be either 1, 2, 3, or 4. All others
     *              will cause the assignment to fail.
     * @return true if newId was >=1 && <= 4
     */
    bool SetId(int newId);

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
     * Frees associated resources
     */
    void free();

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