#include "DifficultyLookup.h"

DifficultyLookup::DifficultyLookup():StaticLookup("difficulty")
{

}

DifficultyLookup::~DifficultyLookup()
{

}

DifficultyLookup* DifficultyLookup::GetInstance()
{
    static DifficultyLookup instance;

    return &instance;
}