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

    /**
     * The maximum number of scores in the high scores list.
     */
    static const int        MAX_HIGH_SCORE_COUNT    = 7;

    /**
     * The number of scores in the last scores list
     */
    static const int        LAST_SCORES_COUNT       = 4;
};

#endif
