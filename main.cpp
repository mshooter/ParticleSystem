#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif
#include <iostream>
#include <cstdlib>
#include "glm/glm.hpp"
#include "DisplayWindow.h"
#include "emitter.h"

// constants
const int WIDTH = 720;
const int HEIGHT = 576;





int main()
{
    // create our SDLWindow called window
    DisplayWindow win("Particle System demo", 0,0, WIDTH, HEIGHT);
    // if you have multiple windows open make the window the current window
    win.makeCurrent();
    // sets background colour
    win.setBackground();

    // set the perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // scaling the enviornment to 100
    glScalef(0.01,0.01,0.01);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.8,0.8,0.8);

    // init a emitter
    Emitter blab(100, glm::vec3(0,0,0));
    // starts the game loop
    bool quit=false;
    while(!quit)
    {
     // create a camera
      SDL_Event event;
      // grab the event from the window (note this explicitly calls make current)
      win.pollEvent(event);
      switch (event.type)
      {
        // this is the window x being clicked.
        case SDL_QUIT : quit = true; break;
        // now we look for a keydown event
        case SDL_KEYDOWN:
        {
          switch( event.key.keysym.sym )
          {
            // if it's the escape key quit
            case SDLK_ESCAPE :  quit = true; break;
            // make OpenGL draw wireframe
            case SDLK_w : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
            // make OpenGL draw solid
            case SDLK_s : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);   break;
          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      // draw a particle; this is a test you have to generate particles in the emitter class
      blab.update();
      blab.draw();



     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
