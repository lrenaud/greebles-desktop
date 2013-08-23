#ifndef JOIN_SETTINGS_H
#define JOIN_SETTINGS_H

#include <string>

using namespace std;

#define JS JoinSettings::GetInstance()

class JoinSettings
{
private:

    enum DBColumnIndex
    {
        COL_HOST=1
    };

    /**
     * The host of the network game you want to join. 
     * (Server host, IP address also acceptable)
     */
    string host;

private:
    
    /**
     * Private constructor, singleton
     */
    JoinSettings();

public:

    /**
     * Destructor
     */
    ~JoinSettings();

    /**
     * Singleton access method
     */
    static JoinSettings& GetInstance();
    
    /**
     * Saves the member data to the database.
     * @return true if save was successful, false otherwise.
     */
    bool Save();

    /**
     * Reloads all member data from the database
     * @return true if successful, false otherwise.
     */
    bool Refresh();

    /**
     * Get the host
     */
    const string& Host()const;

    /**
     * Set Advertising Host
     */
    void SetHost(string newHost);

private:

    /**
     * Sets the default values for these settings
     */
    void setDefaults();

};

#endif