#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * A class encapsulating all global constants
 */
class Constants
{
private:

    /**
     * Should never be instantiated
     */
    Constants();
    ~Constants();

public:

    /**
     * The maximum length a name is allowed to be in the game.
     */
    static const int        MAX_NAME_LENGTH         = 10;

};

#endif
