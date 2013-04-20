#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

class Database
{
private:

	/**
	 * Connection Object
	 */
	sqlite3*				db;

private:

	/**
	 * Private constructor (Singleton)
	 * Establishes a connection to the Database.
	 */
	Database();

public:

	/**
	 * Destructor, closes connection.
	 */
	~Database();

	static Database *GetInstance();

private:

	/**
	 * Other private methods used internally.
	 */
	bool openConnection(const char *dbFilename);
	bool closeConnection();

}

#endif