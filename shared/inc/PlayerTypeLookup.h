#ifndef PLAYER_TYPE_LOOKUP_H
#define PLAYER_TYPE_LOOKUP_H

#include "StaticLookup.h"

#define PTL PlayerTypeLookup::GetInstance()

class PlayerTypeLookup : public StaticLookup
{
private:

    PlayerTypeLookup();

public:

    ~PlayerTypeLookup();

    static PlayerTypeLookup* GetInstance();
};

#endif