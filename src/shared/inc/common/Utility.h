#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <sstream>

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
    static wxString     StringToWxString(std::string str);

    /**
     * This method takes a standard string and converts it
     * to a wxString to use with wxWidgets.     
     * @param  str The string to convert
     * @return     A matching wxString
     */
    static wxString     StringToWxString(const char* str);

    /**
     * Takes a wxString and returns an integer representation
     * @param  wxStr The wxString to convert
     * @return       An integer representation of wxStr
     */
    static int          WxStringToInt(wxString wxStr);

    /**
     * This method takes a pointer of any kind and returns it's
     * value, (an address of whatever it points to) as a string
     */
    template <typename T>
    static std::string       PointerToString(T* ptr)
    {
        const void* ptrAddress = static_cast<const void*>(ptr);

        std::stringstream addrStream;
        addrStream << ptrAddress;

        return addrStream.str();
    }

    template <typename T>
    static wxString     PointerToWxString(T* ptr)
    {
        std::string intermediate = PointerToString<T>(ptr);

        return StringToWxString(intermediate);
    }

    /**
     * This method takes an address in string form, and returns 
     * a pointer to it.
     */
    template <typename T>
    static T*           StringToPtr(std::string ptrStr)
    {
        return reinterpret_cast<T*>(strtol(ptrStr.c_str(), nullptr, 0));
    }

};

#endif