#include <IL/il.h>
#include <IL/ilut.h>

#include <util/Log.h>

#include "GreeblesGame.h"

int main(int argc, char* argv[])
{
    // Setup DevIL to use OpenGL
    ilInit();
    iluInit();
    ilutRenderer(ILUT_OPENGL);

    SOAR::Util::Log::GetInstance()->SetFilterLevel(SOAR::Util::Log::LOG_ALL);

    GreeblesGame::GetInstance().Run();
    
    return 0;
}