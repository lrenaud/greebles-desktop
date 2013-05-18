#ifndef GREEBLES_DATABASE_H
#define GREEBLES_DATABASE_H

#include <Database.h>

using namespace SOAR;

#define DB 				GreeblesDatabase::GetInstance()

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