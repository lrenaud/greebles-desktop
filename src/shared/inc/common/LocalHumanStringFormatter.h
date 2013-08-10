#ifndef LOCAL_HUMAN_STRING_FORMATTER_H
#define LOCAL_HUMAN_STRING_FORMATTER_H

#include <string>
#include <sstream>

using namespace std;

/**
 * This class encapsulates all functionality for generating
 * Local and Human Player Info strings. 
 *
 * Both the Custom and Join apps present a message showing
 * how many local players there are, and how many of those
 * are human. This class generates these strings.
 */
class LocalHumanStringFormatter
{
private:
    LocalHumanStringFormatter();
    ~LocalHumanStringFormatter();

public:

    /**
     * This method does the gruntwork. You give it the two values, and
     * it will return a std::string that is properly formatted and 
     * grammatically correct.
     * @param  localPlayers The number of local players
     * @param  humanPlayers The number of human players
     * @return              A string formatted as follows:
     *
     * - There are 0 local players (none human) [Where both are 0]
     * - There is 1 local player (all human|none human) [where local is 1]
     * - There are x local players (all human|none human|n human) 
     *
     * Behavior is undefined when:
     * - localPlayers < 0 || humanPlayers < 0
     * - humanPlayers > localPlayers
     */
    static string GetInfoStr(int localPlayers, int humanPlayers);
};

#endif