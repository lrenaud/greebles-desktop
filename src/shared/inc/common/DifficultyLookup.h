#ifndef DIFFICULTY_LOOKUP_H
#define DIFFICULTY_LOOKUP_H 

#include "StaticLookup.h"

#define DL DifficultyLookup::GetInstance()

class DifficultyLookup : public StaticLookup
{
private:

    DifficultyLookup();

public:

    ~DifficultyLookup();

    static DifficultyLookup* GetInstance();
};

#endif