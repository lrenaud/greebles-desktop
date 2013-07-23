#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

#include <wx/wx.h>

/**
 * This class is designed to hold NO member data.
 * It encapsulates only public static utililty methods.
 */
class Utility
{
public:

    /**
     * This method takes a standard string and converts it
     * to a wxString to use with wxWidgets.
     * @param  std::string The string to convert
     * @return             A matching wxString
     */
    static wxString     StringToWxString(std::string& str);

    /**
     * This method takes a standard string and converts it
     * to a wxString to use with wxWidgets.     
     * @param  str The string to convert
     * @return     A matching wxString
     */
    static wxString     StringToWxString(const char* str);

};

#endif