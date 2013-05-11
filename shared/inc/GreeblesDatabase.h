#ifndef GREEBLES_DATABASE_H
#define GREEBLES_DATABASE_H

#include <Database.h>

using namespace SOAR;

class GreeblesDatabase : public Database
{
private:
    
    /**
     * Private Constructor for Singleton
     */
    GreeblesDatabase();

public:

    ~GreeblesDatabase();

    static GreeblesDatabase* GetInstance();
};

#endif 