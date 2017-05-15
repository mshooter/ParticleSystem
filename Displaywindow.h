#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include "SDL2/SDL.h"
#include <iostream>
#include <string>

/// \author Jon Macey modified: Moira Shooter
/// \version
/// \date Last Revision

/// \class Display Window
/// \brief Creates a SDL Window and sets the background colour
/// \todo

class DisplayWindow
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the default constructor
    /// @param[in] _name the name of the window
    /// @param[in] _x the x position of the window
    /// @param[in] _y the y position of the winodw
    /// @param[in] _width the width of the window
    /// @param[in] _height the height of the window
    //--------------------------------------------------------------------------------------------------------------------
    DisplayWindow(const std::string &_name, int _x, int _y, int _width, int _height);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that makes the window the current window
    //--------------------------------------------------------------------------------------------------------------------
    void makeCurrent() { SDL_GL_MakeCurrent(m_window, m_glContext); }
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that enable to swap windows
    //--------------------------------------------------------------------------------------------------------------------
    void swapWindow() { SDL_GL_SwapWindow(m_window); }
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the background colour
    //--------------------------------------------------------------------------------------------------------------------
    void setBackground();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that polls for currently pending events
    /// @param[in] _event the SDL_Event structure to be filled with the next event from the queue, or NULL
    //--------------------------------------------------------------------------------------------------------------------
    void pollEvent(SDL_Event &_event);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the scene, it draws the cube and the axis
    void setScene();

private:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief width of screen
    //--------------------------------------------------------------------------------------------------------------------
    int m_width;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief height of screen
    //--------------------------------------------------------------------------------------------------------------------
    int m_height;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the x position of the window
    //--------------------------------------------------------------------------------------------------------------------
    int m_x;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the y position of the window
    //--------------------------------------------------------------------------------------------------------------------
    int m_y;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the name of the window
    //--------------------------------------------------------------------------------------------------------------------
    std::string m_name;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief Creates an OpenGL context associated with the window
    //--------------------------------------------------------------------------------------------------------------------
    SDL_GLContext m_glContext;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief Declares a pointer to the window
    //--------------------------------------------------------------------------------------------------------------------
    SDL_Window *m_window;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief initiates the SDL Window
    //--------------------------------------------------------------------------------------------------------------------
    void init();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief creates an OpenGL context for use with an OpenGL window, and makes it current
    //--------------------------------------------------------------------------------------------------------------------
    void createGLContext();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief Retrieves a message about the last error that occured
    //--------------------------------------------------------------------------------------------------------------------
    void ErrorExit(const std::string &_msg) const;

};

#endif // DISPLAYWINDOW_H
