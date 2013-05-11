#include <Database.h>
#include <Macros.h>

#include "../inc/GreeblesDatabase.h"

using namespace SOAR;

GreeblesDatabase::GreeblesDatabase():Database("greebles.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE)
{
    // If there is no hash to compare against, build the database and go on
    // 
    // Check to see if the database is intact
    //      Compare a hash of the database file at last close, to now
    //      If the hash is different, rebuild db.
    //      Otherwise continue
}

GreeblesDatabase::~GreeblesDatabase()
{

}

GreeblesDatabase* GreeblesDatabase::GetInstance()
{
    static GreeblesDatabase instance;

    return &instance;
}