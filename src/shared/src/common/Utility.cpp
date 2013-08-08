#include <string>

#include <wx/wx.h>

#include "Utility.h"

using namespace std;

wxString Utility::StringToWxString(string& str)
{
    return StringToWxString(str.c_str());
}

wxString Utility::StringToWxString(const char* str)
{
    wxString wxStr(str, *wxConvCurrent);

    return wxStr;
}

