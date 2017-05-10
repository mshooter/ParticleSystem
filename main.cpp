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
#include "timer.h"

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

    Timer timer;
    float speed = 10;
    float vertical=-50;
    float horizontal=0;
    float translateVertical=100;

    //Create main Camera
    Camera camera;
    // init emitter
    Fire fire(1000,glm::vec3(0,-100,0));


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
            // translate z axis
            case SDLK_UP:   vertical += speed * timer.getCameraTime();  break;
            case SDLK_DOWN: vertical -= speed * timer.getCameraTime();  break;
            case SDLK_LEFT: horizontal -= speed *timer.getCameraTime();  break;
            case SDLK_RIGHT:horizontal += speed * timer.getCameraTime(); break;
            case SDLK_b:    timer.pauseTimer();                         break;
            case SDLK_v:    timer.unPauseTimer();                       break;
            case SDLK_w:    translateVertical -= speed *4*timer.getCameraTime();   break;
            case SDLK_s:    translateVertical += speed *4* timer.getCameraTime();  break;
          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      //setup the camera
      glViewport(0,0,WIDTH,HEIGHT);
      camera.camPerspective(45.0f,float(WIDTH/HEIGHT),0.0f,100.0f);
      camera.lookAtTgt(glm::vec3(0,0,translateVertical),glm::vec3(0,0,0), glm::vec3(horizontal,vertical,0));

      glPushMatrix();
      // clear matrix
      //glLoadIdentity();
      // draw our axes
      glBegin(GL_LINES);
      // draw line for x axis
      glColor3f(1,0, 0.0);
      glVertex3f(-80.0, -100.0, -80.0);
      glVertex3f(-40.0, -100.0, -80.0);
      // draw line for y axis
      glColor3f(0.0, 1, 0.0);
      glVertex3f(-80.0, -100.0,-80.0);
      glVertex3f(-80.0, -50, -80.0);
      // draw line for Z axis
      glColor3f(0.0, 0.0, 1);
      glVertex3f(-80.0, -100.0, -80.0);
      glVertex3f(-80.0, -100.0, -40);
      glEnd();
      // load the previous matrix
      glPopMatrix();

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
      // load previous matrix
      glPopMatrix();

       fire.run(timer.getDeltaTime());
       timer.setEndTime(SDL_GetTicks());



     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
