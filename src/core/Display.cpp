#include "Display.hpp"


Display::Display()
{

}

Display::Display(const char *title, int width, int height)
{		
    //Create Window
    Display::createWindow(title, width, height);
    m_width = width;
    m_height = height;

    //Setup OpenGL
    Display::setOpenGLAttributes();

    //OPENGL Context
    glContext = SDL_GL_CreateContext(window);

    //Use OpenGL 3.1 core
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 0 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

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
    // glewExperimental = GL_TRUE; //Use Latest Features

    if (status != GLEW_OK)
    {
        std::cerr << "Glew failed to initialize!" << std::endl;
    }

    //#endif
    

    //std::cout << ("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor) << std::endl;

    //gladLo

    // Use v-sync
    SDL_GL_SetSwapInterval(0);

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
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    /*SDL_WINDOW_FULLSCREEN	fullscreen window
    SDL_WINDOW_FULLSCREEN_DESKTOP	fullscreen window at the current desktop resolution
    SDL_WINDOW_OPENGL	window usable with OpenGL context
    SDL_WINDOW_SHOWN	window is visible
    SDL_WINDOW_HIDDEN	window is not visible
    SDL_WINDOW_BORDERLESS	no window decoration
    SDL_WINDOW_RESIZABLE	window can be resized
    SDL_WINDOW_MINIMIZED	window is minimized
    SDL_WINDOW_MAXIMIZED	window is maximized
    SDL_WINDOW_INPUT_GRABBED	window has grabbed input focus
    SDL_WINDOW_INPUT_FOCUS	window has input focus
    SDL_WINDOW_MOUSE_FOCUS	window has mouse focus
    SDL_WINDOW_FOREIGN	window not created by SDL
    SDL_WINDOW_ALLOW_HIGHDPI	window should be created in high-DPI mode if supported (>= SDL 2.0.1)
    SDL_WINDOW_MOUSE_CAPTURE	window has mouse captured (unrelated to INPUT_GRABBED, >= SDL 2.0.4)
    SDL_WINDOW_ALWAYS_ON_TOP	window should always be above others (X11 only, >= SDL 2.0.5)
    SDL_WINDOW_SKIP_TASKBAR	window should not be added to the taskbar (X11 only, >= SDL 2.0.5)
    SDL_WINDOW_UTILITY	window should be treated as a utility window (X11 only, >= SDL 2.0.5)
    SDL_WINDOW_TOOLTIP	window should be treated as a tooltip (X11 only, >= SDL 2.0.5)
    SDL_WINDOW_POPUP_MENU	window should be treated as a popup menu (X11 only, >= SDL 2.0.5)*/

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

		