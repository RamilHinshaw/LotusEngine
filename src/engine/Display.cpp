#include "Display.hpp"


Display::Display()
{

}

Display::Display(const char *title, int width, int height)
{		
    //Create Window
    Display::createWindow(title, width, height);

    //Setup OpenGL
    Display::setOpenGLAttributes();

    //OPENGL Context
    glContext = SDL_GL_CreateContext(window);

    // glewExperimental = GL_TRUE; //Use Latest Features
    
    // GLenum status = glewInit(); //Finds opengl functions 
    // if (status != GLEW_OK)SDL_GL_CONTEXT_PROFILE_MASK
    //     std::cerr << "Glew failed to initialize!" << std::endl;

        //Use OpenGL 3.1 core
    // SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
    // SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 0 );
    // SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    // SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    // // Also request a depth buffer
    // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
    // SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);

    // INITIALIZE GLAD:
    //#if defined(__arm__)
    //GLAD
        //std::cout << "Init Glad for Desktop Device" << std::endl;
        //if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
          //  throw(std::string("Failed to initialize GLAD"));
    //#else
    
    GLenum status = glewInit(); //Finds opengl functions 

    if (status != GLEW_OK)
    {
        std::cerr << "Glew failed to initialize!" << std::endl;
    }

    //#endif
    

    //std::cout << ("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor) << std::endl;

    //gladLo

    // Use v-sync
    SDL_GL_SetSwapInterval(1);
}

Display::~Display()
{

}	

void Display::dispose()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    std::cout << "Display destroyed!" << std::endl;
}		

void Display::swapBuffers()
{
    SDL_GL_SwapWindow(window);
}

void Display::createWindow(const char *title, int width, int height)
{
    //Create Window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    if (window) //Check if window was created successfully
    {
        std::cout << "Display created!" << std::endl;
    }
}

void Display::setOpenGLAttributes()
{
    // OPENGL SETTING ATTRIBUTES
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); //2**8 = 256 shades of red
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8); //2**8 = 256 shades of green
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8); //2**8 = 256 shades of blue
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); //2**8 = 256 shades of alpha
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //2**8 = data in bits sdl will allocate for a pixel (8*4 =32)
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //Allocate space for a second window to draw on
}

		