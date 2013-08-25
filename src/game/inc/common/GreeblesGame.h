#ifndef GREEBLES_GAME_H
#define GREEBLES_GAME_H

#include <string>

using namespace std;

class GreeblesGame
{
private:

    const static int    GAME_WINDOW_ID         = 1;

    const static int    WINDOW_WIDTH           = 800;
    const static int    WINDOW_HEIGHT          = 600;

private:  

    /**
     * Private Constructor for Singleton 
     */
    GreeblesGame();

public:

    /**
     * Destructor
     */
    ~GreeblesGame();

    /**
     * Singleton Access Method
     */
    static GreeblesGame& GetInstance();

    /**
     * Run Method. This method initializes the game
     * and kicks off the main loops.
     */
    void Run();

};

#endif
