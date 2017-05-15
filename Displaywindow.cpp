/// @file DisplayWindow.cpp
/// @brief Creating a SDL Window

#include "DisplayWindow.h"

DisplayWindow::DisplayWindow(const std::string &_name, int _x, int _y, int _width, int _height)
{
      m_name=_name;
      m_x=_x;
      m_y=_y;
      m_width=_width;
      m_height=_height;
      init();
}
//--------------------------------------------------------------------------------------------------------------------
void DisplayWindow::setBackground()
{
    glClearColor(0,0,0.1,1);
}
//--------------------------------------------------------------------------------------------------------------------
void DisplayWindow::pollEvent(SDL_Event &_event)
{
  makeCurrent();
  SDL_PollEvent(&_event);
}
//--------------------------------------------------------------------------------------------------------------------
void DisplayWindow::setScene()
{
    // clears the buffer to draw after this function
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    // draw the x,y,z axis
    glBegin(GL_LINES);
    // draw line for x axis; colour red
    glColor3f(1,0, 0.0);
    glVertex3f(-80.0, -100.0, -80.0);
    glVertex3f(-40.0, -100.0, -80.0);
    // draw line for y axis; colour green
    glColor3f(0.0, 1, 0.0);
    glVertex3f(-80.0, -100.0,-80.0);
    glVertex3f(-80.0, -50, -80.0);
    // draw line for Z axis; colour blue
    glColor3f(0.0, 0.0, 1);
    glVertex3f(-80.0, -100.0, -80.0);
    glVertex3f(-80.0, -100.0, -40);
    glEnd();
    // load the previous matrix
    glPopMatrix();

    // drawing the cube
    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100,100,100);
    glVertex3f(-100,100,100);
    glVertex3f(-100,-100,100);
    glVertex3f(100,-100,100);

    glVertex3f(100,100,-100);
    glVertex3f(-100,100,-100);
    glVertex3f(-100,-100,-100);
    glVertex3f(100,-100,-100);

    glVertex3f(100,100,100);
    glVertex3f(100,-100,100);
    glVertex3f(100,-100,-100);
    glVertex3f(100,100,-100);

    glVertex3f(-100,100,100);
    glVertex3f(-100,-100,100);
    glVertex3f(-100,-100,-100);
    glVertex3f(-100,100,-100);

    glVertex3f(100,100,100);
    glVertex3f(-100,100,100);
    glVertex3f(-100,100,-100);
    glVertex3f(100,100,-100);

    glVertex3f(100,-100,100);
    glVertex3f(-100,-100,100);
    glVertex3f(-100,-100,-100);
    glVertex3f(100,-100,-100);

    glEnd();
    // load previous matrix
    glPopMatrix();
}
//--------------------------------------------------------------------------------------------------------------------
void DisplayWindow::init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
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
//--------------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------------
void DisplayWindow::ErrorExit(const std::string &_msg) const
{
  std::cerr<<_msg<<std::endl;
  std::cerr<<SDL_GetError()<<std::endl;
  SDL_Quit();
  exit(EXIT_FAILURE);
}
