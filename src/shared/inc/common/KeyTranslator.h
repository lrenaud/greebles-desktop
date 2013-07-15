#ifndef KEY_TRANSALATOR_H
#define KEY_TRANSALATOR_H

#include <map>

using namespace std;

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

private:

    /**
     * This method initializes the translation map
     */
    void populateTranslationMap();

};

#endif