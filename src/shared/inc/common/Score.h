#ifndef SCORE_H
#define SCORE_H

#include <string>

using namespace std;

/**
 * This class represents a single score, comprising
 * a db id, name, player count, level reached, and
 * total points earned.
 */
class Score
{
private:

    enum DBColumnIndex
    {
        COL_ID=0,
        COL_NAME,
        COL_PLAYERS,
        COL_LEVEL,
        COL_POINTS
    };

    /**
     * This score's database id
     */
    int             id;

    /**
     * The name of the player who earned this score. Length
     * is limited by Constants::MAX_NAME_LENGTH
     */
    string          name;

    /**
     * The number of players in the game where this score was won.
     * (Including remote players in a network game?)
     */
    unsigned int             players;

    /**
     * The level reached when this score was achieved
     * (Highest level, or level at when game over? Since
     * some levels send you back to a previous level)
     */
    unsigned int             level;

    /**
     * The points earned.
     */
    unsigned long            points;

public:

    /**
     * Constructor
     */
    Score();

    /**
     * Destructor
     */
    ~Score();

    /**
     * Saves this score to the database.
     * @return The id of the inserted row on success, -1 on error.
     */
    int Save();

    /**
     * Loads the score with id from the database.
     * @param  id The id of the score to load
     * @return    True if the load was successful, false otherwise.
     */
    bool Load(int id);

    /**
     * Resets this score object to hold empty data
     */
    void Reset();

    /**
     * This method fills this score object with the given score data.
     * @param id      The id of this score entry, -1 if it's not in the db yet
     * @param name    The name associated with this entry. Limited by Constants::MAX_NAME_LENGTH
     * @param players The number of players in the associated game
     * @param level   The level reached in the associated game
     * @param points  The points earned
     */
    void Initialize(int id, string& name, unsigned int players, unsigned int level, unsigned long points);

};

#endif