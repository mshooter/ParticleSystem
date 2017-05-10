#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "displaywindow.h"
#include "fireworks.h"
#include "fire.h"
#include "camera.h"

const int WIDTH = 720;
const int HEIGHT = 576;

/// fix the camera 7 May
/// make the particle system move

int main()
{



    // create our SDLWindow called window
    DisplayWindow win("Particle System demo", 0,0, WIDTH, HEIGHT);
    // if you have multiple windows open make the window the current window
    win.makeCurrent();
    // sets background colour
    win.setBackground();

    double currentTime = SDL_GetTicks();
    float lastTime=0;
    float deltaTime = (currentTime-lastTime);
    lastTime = currentTime;
    float speed = 0.001f;
    float translateZ=300;
    float translatX=0;

    //Create main Camera
    Camera camera;
    // init emitter
    Fireworks blab(100,glm::vec3(0,-100,0));



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
            // translate
            case SDLK_UP: translateZ -= speed * 4 *deltaTime; break;
            case SDLK_DOWN: translateZ += speed * 4 * deltaTime; break;
          case SDLK_0 : translatX += speed * 4 *deltaTime; break;


          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      //setup the camera
      glViewport(0,0,WIDTH,HEIGHT);
      camera.camPerspective(45.0f,float(WIDTH/HEIGHT),0.0f,100.0f);
      camera.lookAtTgt(glm::vec3(translateZ,200,0),glm::vec3(0,0,0), glm::vec3(0,0,0));
      /// cube file
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

      // load the previous matrix
      glPopMatrix();

      //glMatrixMode(GL_MODELVIEW);
      // draw a particle; this is a test you have to generate particles in the emitter class
      blab.run();

     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
