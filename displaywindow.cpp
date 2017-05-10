#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif
#include "displaywindow.h"
#include "SDL2/SDL.h"
#include <iostream>

DisplayWindow::DisplayWindow(const std::string &_name, int _x, int _y, int _width, int _height)
{
      m_name=_name;
      m_x=_x;
      m_y=_y;
      m_width=_width;
      m_height=_height;
      init();
}

void DisplayWindow::init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_TIMER) < 0)
  {
    ErrorExit("Could Not Init Everything");
  }

  m_window=SDL_CreateWindow(m_name.c_str(),m_x,m_y,
                            m_width,m_height,
                            SDL_WINDOW_OPENGL );
  if(!m_window)
  {
    ErrorExit("Could not create Window");
  }

  createGLContext();

}

void DisplayWindow::createGLContext()
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);

  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);

  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

  m_glContext=SDL_GL_CreateContext(m_window);
}

void DisplayWindow::setBackground()
{
    glClearColor(0,0,0.1,1);
}


void DisplayWindow::pollEvent(SDL_Event &_event)
{
  makeCurrent();
  SDL_PollEvent(&_event);
}


void DisplayWindow::ErrorExit(const std::string &_msg) const
{
  std::cerr<<_msg<<std::endl;
  std::cerr<<SDL_GetError()<<std::endl;
  SDL_Quit();
  exit(EXIT_FAILURE);
}
