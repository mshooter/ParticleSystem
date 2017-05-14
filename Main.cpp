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

int main()
{
    // create our SDLWindow called window
    DisplayWindow win("Particle System demo", 0,0, WIDTH, HEIGHT);
    // if you have multiple windows open make the window the current window
    win.makeCurrent();
    // sets background colour
    win.setBackground();

    int _keypressed =0;
    // handle keys for the camera, and the animation
    float speed = 10;
    float look_vertical=0;
    float look_horizontal=0;
    float cameraPositionZ=300;
    float cameraPositionY=0;

    // initiate the timer
    Timer timer;

    // initiate a Camera
    Camera camera;

    // init emitters
    Snow snow(800,glm::vec3(0,0,0));
    Fire fire(1500,glm::vec3(0,-100,0));

    // starts the game loop
    bool quit=false;
    while(!quit)
    {
      // create an event
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
            case SDLK_ESCAPE :  { quit = true; break; }
            case SDLK_UP:   {   look_vertical += speed * timer.CameraTime();      break;}
            case SDLK_DOWN: {   look_vertical -= speed * timer.CameraTime();      break;}
            case SDLK_LEFT: {   look_horizontal -= speed * timer.CameraTime();    break;}
            case SDLK_RIGHT:{   look_horizontal += speed * timer.CameraTime();    break;}
            case SDLK_w:    {   cameraPositionZ -= 5 * speed * timer.CameraTime();   break;}
            case SDLK_s:    {   cameraPositionZ += 5 * speed * timer.CameraTime();   break;}
            case SDLK_a:    {   cameraPositionY -= 5 * speed * timer.CameraTime();   break;}
            case SDLK_d:    {   cameraPositionY += 5 * speed * timer.CameraTime();   break;}
            case SDLK_p:    {   timer.pauseTimer();                                 break;}
            case SDLK_u:    {   timer.unPauseTimer();                               break;}
            case SDLK_r:    {   timer.setDeltaTime(timer.ReverseTime());            break;}
            case SDLK_0:    {   _keypressed=2;                                      break; }
            case SDLK_1:    {   _keypressed =1;                                     break;}
            case SDLK_3:    {   look_vertical=0;    look_horizontal=0;  cameraPositionZ=300;    cameraPositionY=0;  break;}

          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      // setup the scene
      win.setScene();

      // setup the camera
      glViewport(0,0,WIDTH,HEIGHT);
      camera.camPerspective(45.0f,float(WIDTH/HEIGHT),0.0f,100.0f);
      camera.lookAtTarget(glm::vec3(cameraPositionY,-25,cameraPositionZ),glm::vec3(look_horizontal,look_vertical,0));

      // apply wind
      if(_keypressed==1)
      {
         snow.applyWind();   ; fire.applyWind();
      }
      if(_keypressed==2)
      {
          fire.BlowOnFire();
          _keypressed=0;

      }
      else
      {
          fire.resetAcceleration();
      }

      // run the two emitters
      snow.run(timer.DeltaTime());
      fire.run(timer.DeltaTime());

      // set the end time of your animation
      timer.setEndTime(SDL_GetTicks());

     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
