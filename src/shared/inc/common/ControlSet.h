#ifndef CONTROL_SET_H
#define CONTROL_SET_H

class ControlSet
{
private:

    enum DBColumnIndex
    {
        COL_ID=0,
        COL_LEFT,
        COL_RIGHT,
        COL_UP,
        COL_DOWN,
        COL_PUSH
    };

    const static int DIR_COUNT = 4;

    enum Direction
    {
        LEFT = 0,
        RIGHT,
        UP,
        DOWN
    };

    int id;

    int directions[DIR_COUNT];

    int push;

public:
    ControlSet(int controlSetId);
    ~ControlSet();

    ControlSet(const ControlSet& other)=delete;
    ControlSet& operator=(const ControlSet& rhs)=delete;

    /**
     * Get the GLFW_KEY_* value for this key
     * @return An int corresponding to the GLFW_KEY_* value for this key
     */
    int LeftKey()const;

    /**
     * Get the GLFW_KEY_* value for this key
     * @return An int corresponding to the GLFW_KEY_* value for this key
     */
    int RightKey()const;

    /**
     * Get the GLFW_KEY_* value for this key
     * @return An int corresponding to the GLFW_KEY_* value for this key
     */
    int UpKey()const;
    
    /**
     * Get the GLFW_KEY_* value for this key
     * @return An int corresponding to the GLFW_KEY_* value for this key
     */
    int DownKey()const;

    /**
     * Get the GLFW_KEY_* value for this key
     * @return An int corresponding to the GLFW_KEY_* value for this key
     */
    int PushKey()const;

    /**
     * Change the key for this action
     * @param  newKey The GLFW_KEY_* value of the new key
     * @return        True if successful, false if the key given is not allowed
     */
    bool SetLeftKey(int newKey);

    /**
     * Change the key for this action
     * @param  newKey The GLFW_KEY_* value of the new key
     * @return        True if successful, false if the key given is not allowed
     */
    bool SetRightKey(int newKey);

    /**
     * Change the key for this action
     * @param  newKey The GLFW_KEY_* value of the new key
     * @return        True if successful, false if the key given is not allowed
     */
    bool SetUpKey(int newKey);

    /**
     * Change the key for this action
     * @param  newKey The GLFW_KEY_* value of the new key
     * @return        True if successful, false if the key given is not allowed
     */
    bool SetDownKey(int newKey);

    /**
     * Change the key for this action
     * @param  newKey The GLFW_KEY_* value of the new key
     * @return        True if successful, false if the key given is not allowed
     */
    bool SetPushKey(int newKey);

    /**
     * Save this control set data to the database
     * @return true if the save succeeded, false otherwise
     */
    bool Save(); 

private:

    /**
     * The the key for the specified direction in this control set
     * @param  dir The desired direction
     * @return     An int corresponding to the GLFW_KEY_* value for this direction
     */
    int getKey(Direction dir)const;

    /**
     * Changes the specified direction key
     * @param dir The direction to change
     * @return True if the change was successful, false if the key is invalid.
     * @see AllowedKeys.h
     */
    bool setKey(Direction dir, int newKey);

    /**
     * Loads the control set data with the given id
     * into this instance of the class
     * @param id The control set id to load
     * @return true if the load succeeded, false otherwise.
     */
    bool load(int id);

    /**
     * Sets the defaults for this class in case of error
     */
    void setDefaults();

};

#endif