#include "PlayerTypeLookup.h"

PlayerTypeLookup::PlayerTypeLookup():StaticLookup("playertype")
{

}

PlayerTypeLookup::~PlayerTypeLookup()
{

}

PlayerTypeLookup* PlayerTypeLookup::GetInstance()
{
    static PlayerTypeLookup instance;

    return &instance;
}