/// @file Main.cpp
/// @brief initiates what is needed and handles the key for the program

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

#include "DisplayWindow.h"
#include "Snow.h"
#include "Fire.h"
#include "Camera.h"
#include "Timer.h"

const int WIDTH = 720;
const int HEIGHT = 576;

enum TYPES{NOTHING, SNOW, FIRE};

int main()
{
    // create our SDLWindow called window
    DisplayWindow win("Particle System demo", 0,0, WIDTH, HEIGHT);
    // if you have multiple windows open make the window the current window
    win.makeCurrent();
    // sets background colour
    win.setBackground();

    // handle keys for the camera, and the animation
    float speed = 10;
    float look_vertical=-50;
    float look_horizontal=0;
    float cameraPositionZ=150;
    float cameraPositionY=0;

    // initiate the timer
    Timer timer;

    // initiate a Camera
    Camera camera;

    // init emitters
    Snow snow(500,glm::vec3(0,-100,0));
    Fire bob(1000,glm::vec3(0,-100,0));

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
            case SDLK_ESCAPE :  quit = true; break;
            case SDLK_UP:   {   look_vertical+= speed * timer.CameraTime();      break;}
            case SDLK_DOWN: {   look_vertical -= speed * timer.CameraTime();      break;}
            case SDLK_LEFT: {   look_horizontal -= speed *timer.CameraTime();     break;}
            case SDLK_RIGHT:{   look_horizontal += speed * timer.CameraTime();    break;}
            case SDLK_p:    {   timer.pauseTimer();                             break;}
            case SDLK_u:    {   timer.unPauseTimer();                           break;}
            case SDLK_w:    {   cameraPositionZ -= 5*speed *timer.CameraTime();    break;}
            case SDLK_s:    {   cameraPositionZ += 5*speed * timer.CameraTime();   break;}
            case SDLK_a:    {   cameraPositionY -= 5*speed *timer.CameraTime();    break;}
            case SDLK_d:    {   cameraPositionY += 5*speed *timer.CameraTime();    break;}
            case SDLK_0:    {    snow.applyForce(glm::vec3(0,0,0.001)); bob.applyForce(glm::vec3(0,0,0.001));  break;}
            case SDLK_r:    {   timer.setDeltaTime(timer.ReverseTime()); snow.reverse((glm::vec3(0,-((float)rand()/RAND_MAX*0.5+0.05),0)));   break;}
          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      // setup the scene
      win.setScene();

      // setup the camera
      glViewport(0,0,WIDTH,HEIGHT);
      camera.camPerspective(45.0f,float(WIDTH/HEIGHT),0.0f,100.0f);
      camera.lookAtTarget(glm::vec3(cameraPositionY,-50,cameraPositionZ),glm::vec3(look_horizontal,look_vertical,0));


      snow.run(timer.DeltaTime());
      bob.run(timer.DeltaTime());
      timer.setEndTime(SDL_GetTicks());

     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
