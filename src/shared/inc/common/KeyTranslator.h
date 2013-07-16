#ifndef KEY_TRANSALATOR_H
#define KEY_TRANSALATOR_H

#include <map>

using namespace std;

#define KEY_WX_STR(k)   KeyTranslator::GetInstance().KeyToWxString(k)

class KeyTranslator
{
private:

    /**
     * Maps GLFW_KEY_* values to WXK_* values
     */
    map<int, int>         glfwToWxKeys;

private:

    /**
     * Initializes the translation map
     */
    KeyTranslator();

public:

    ~KeyTranslator();

    /**
     * Returns pointer to singleton instance
     */
    static KeyTranslator& GetInstance();

    /**
     * This method will return the corresponding WXK_* value
     * for a given GLFW_KEY_* value
     * @param  glfwKey The GLFW_KEY_* value to translate
     * @return         The corresponding WXK_* value
     */
    int TranslateGLFWToWXK(int glfwKey);

    /**
     * This method returns a string representation of a key,
     * but as a wxString rather than a std::string. This makes
     * using strings in the forms much easier.
     * @param  glfwKey The GLFW_KEY_* value to get a string for
     * @return         a wxString representation of glfwKey
     */
    wxString KeyToWxString(int glfwKey);

private:

    /**
     * This method initializes the translation map
     */
    void populateTranslationMap();

};

#endif