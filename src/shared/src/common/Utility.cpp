#include <string>

#include <wx/wx.h>

#include <util/Log.h>

#include "Utility.h"

using namespace std;

wxString Utility::StringToWxString(string str)
{
    return StringToWxString(str.c_str());
}

wxString Utility::StringToWxString(const char* str)
{
    wxString wxStr(str, *wxConvCurrent);

    return wxStr;
}

int Utility::WxStringToInt(wxString wxStr)
{
    try
    {
        return stoi(std::string(wxStr.mb_str()));
    }
    catch (exception& e)
    {
        LOG_RECOVERABLE << "Error Converting '" << wxStr.mb_str() << "' to integer: " << e.what();
        return 0;
    }
}
