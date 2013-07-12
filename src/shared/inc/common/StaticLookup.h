#ifndef STATIC_LOOKUP_H
#define STATIC_LOOKUP_H 

#include <map>
#include <string>

#include "GreeblesDatabase.h"

using namespace std;

class StaticLookup
{
private:

    /**
     * A Key-Value map containing id-text pairs from the specified table.
     */
    map<unsigned int, string>       pairs;

    const static int                DEFAULT_KEY_IDX = 0;
    const static int                DEFAULT_VALUE_IDX = 1;

public:
    StaticLookup(const char* tableName, int keyIdx=DEFAULT_KEY_IDX, int valueIdx=DEFAULT_VALUE_IDX);
    ~StaticLookup();

    /**
     * Returns the string associated with key in pairs
     * @param  key The integer key
     * @return     The associated string in pairs
     */ 
    string& GetValue(int key);

    /**
     * Discover if a static lookup contains a key and an associated value
     * @param  key The key in question
     * @return     true if key has an entry in pairs
     */
    bool KeyExists(int key);

private:

    void initialize(const char* tableName, int keyIdx=DEFAULT_KEY_IDX, int valueIdx=DEFAULT_VALUE_IDX);
};

#endif