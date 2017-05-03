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
#include <glm/gtc/type_ptr.hpp>
#include "displaywindow.h"
#include "particle.h"
#include "fireworks.h"
#include "fire.h"



//void Scene::loadProjection(glm::mat4 _matrix) const
//{
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//  glMultMatrixf((const float*)glm::value_ptr(_matrix));
//  glMatrixMode(GL_MODELVIEW);
//}



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

    float rotationY=0;
    float rotationZ=0;




    // init a emitter
    Fire blab(1000,glm::vec3(0,0,0));

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

          case SDLK_UP: rotationY -= speed * deltaTime; break;
          case SDLK_DOWN: rotationY += speed * deltaTime; break;
          case SDLK_LEFT: rotationZ -= speed * deltaTime; break;
          case SDLK_RIGHT: rotationZ += speed * deltaTime; break;

          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glScalef(0.01f,0.01f,0.01f);
      glRotatef(rotationZ,0,-1,0);
      glRotatef(rotationY,0,0,-1);
      glMatrixMode(GL_MODELVIEW);

      /// should make a class for the axis
      // save previous matrix
      glPushMatrix();
      // clear matrix
      glLoadIdentity();
      // draw our axes
      glBegin(GL_LINES);
      // draw line for x axis
      glColor3f(1.0, 0.0, 0.0);
      glVertex3f(0.0, 0.0, 0);
      glVertex3f(90.0, 0.0, 0);
      // draw line for y axis
      glColor3f(0.0, 1.0, 0.0);
      glVertex3f(0, 0.0, 0);
      glVertex3f(0, 90.0, 0);
      // draw line for Z axis
      glColor3f(0.0, 0.0, 1.0);
      glVertex3f(0, 0.0, 0);
      glVertex3f(0, 0.0, 90.0);
      glEnd();
      // load the previous matrix
      glPopMatrix();

      // draw a particle; this is a test you have to generate particles in the emitter class
      blab.run();


     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
