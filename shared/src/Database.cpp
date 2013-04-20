#include "Database.h"

Database::Database()
{
	if (!openConnection("dbname.db"))
	{
		// Log error message using sqlite3_errmsg(db);
	}
}

Database::~Database()
{
	closeConnection();
}

/**
 * GetInstance() -  Returns a pointer to the only instance of the
 *					database class.
 */
Database* Database::GetInstance()
{
	static Database instance;

	return &instance;
}

/**
 * openConnection -	Opens a connection to the database given. Returns
 *					true if connection was successful, false otherwise.
 */
bool Database::openConnection(const char *dbFilename)
{
	return sqlite3_open(dbFilename, db) == SQLITE_OK;
}

/**
 * closeConnection -	Closes the current connection. Returns true
 *						if close was successful.
 */
bool Database::closeConnection()
{
	return sqlite3_close(db) == SQLITE_OK;
}