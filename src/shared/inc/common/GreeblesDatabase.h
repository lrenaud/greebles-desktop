#ifndef GREEBLES_DATABASE_H
#define GREEBLES_DATABASE_H

#include <Database.h>

using namespace SOAR;

#define DB 				GreeblesDatabase::GetInstance()

class GreeblesDatabase : public Database
{
private:
    
    const static int        TABLE_COUNT     = 9;

    /**
     * Private Constructor for Singleton
     */
    GreeblesDatabase();

public:

    ~GreeblesDatabase();

    static GreeblesDatabase* GetInstance();

private:

    /**
     * Destroys and recreates the database using the .sql scripts found
     * in the database directory. 
     *
     * /database/create_schema.sql
     * /database/initial_data_insert.sql
     * 
     * @return true if rebuild succeeded, false if errors were encountered.
     */
    bool rebuild();
    
};

#endif 