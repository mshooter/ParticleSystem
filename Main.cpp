/// @file Main.cpp
/// @brief initiates what is needed to set up the scene and handles the keys for the program

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
#include "WaterFall.h"
#include "Camera.h"
#include "Timer.h"

const int WIDTH = 720;
const int HEIGHT = 576;

enum SCENES {CAMPFIRE, WATERFALL};

int main()
{
    // create our SDLWindow called window
    DisplayWindow win("Particle System demo", 0,0, WIDTH, HEIGHT);
    // if you have multiple windows open make the window the current window
    win.makeCurrent();
    // sets background colour
    win.setBackground();

    // keys to set the scene / change the scene
    int typeOfScene=0;
    int pressedKey=0;
    // handle keys for the camera, and the animation
    float speed = 10;
    float look_vertical=0;
    float look_horizontal=0;
    float cameraPositionZ=300;
    float cameraPositionX=0;

    // initiate the timer
    Timer timer;

    // initiate a Camera
    Camera camera;

    // init emitters
    Snow snow(800,glm::vec3(0,0,0));
    Fire fire(1500,glm::vec3(0,-100,0));
    Waterfall waterfall(9000,glm::vec3(0,0,0));

    // starts the game loop
    bool quit=false;
    while(!quit)
    {
      // setup the camera
      glViewport(0,0,WIDTH,HEIGHT);
      camera.camPerspective(45.0f,float(WIDTH/HEIGHT),0.0f,100.0f);
      camera.lookAtTarget(glm::vec3(cameraPositionX,-25,cameraPositionZ),glm::vec3(look_horizontal,look_vertical,0));

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
            case SDLK_UP:   {   look_vertical += speed * timer.CameraTime();      break;}   // change of camera lens positive y axis
            case SDLK_DOWN: {   look_vertical -= speed * timer.CameraTime();      break;}   // change of camera lens negative y axis
            case SDLK_LEFT: {   look_horizontal -= speed * timer.CameraTime();    break;}   // change of camera lens negative x axis
            case SDLK_RIGHT:{   look_horizontal += speed * timer.CameraTime();    break;}   // change of camera lens positive x axis
            case SDLK_w:    {   cameraPositionZ -= 5 * speed * timer.CameraTime();   break;} // change of camera positive z position
            case SDLK_s:    {   cameraPositionZ += 5 * speed * timer.CameraTime();   break;} // change of camera negative z  position
            case SDLK_a:    {   cameraPositionX -= 5 * speed * timer.CameraTime();   break;} // change of camera negative x position;
            case SDLK_d:    {   cameraPositionX += 5 * speed * timer.CameraTime();   break;} // change of camera positive x position
            case SDLK_r:    {   look_vertical=0;    look_horizontal=0;  cameraPositionZ=300;    cameraPositionX=0;  break;} // reset the view to it's default settings
            case SDLK_p:    {   if(!timer.getPause()) timer.pauseTimer(); else timer.unPauseTimer();  break;} // pause the timer when not pause, and unpause the timer when paused
            case SDLK_m:    {   timer.setDeltaTime(timer.getSlowMow());            break;} // sets to slow motion animation
            case SDLK_SPACE:{   pressedKey = 2;                                    break;} // sets pressedKey to the value of 2: to blow on the fire
            case SDLK_f:    {   pressedKey = 1;                                    break;} // sets pressedKey to the value of 1: to apply wind of fire and snow
            case SDLK_1:    {   typeOfScene = WATERFALL;                           break;} // sets the typeOfScene to type WATERFALL: and changes the animation scene to a waterfall particle system
            case SDLK_2:    {   typeOfScene = CAMPFIRE;                            break;} // sets the typeOfScene to type CAMPFIRE: changes the animation scene to a snow, campfire
          } // end of key process
        } // end of keydown

        default : break;
      } // end of event switch

      // setup the default scene (cube & x,y,z axis)
      win.setScene();

      // sets the type of scene you want
      switch (typeOfScene)
      {
      case CAMPFIRE:
          // apply wind
          if(pressedKey==1)
          {
             snow.applyWind();   ; fire.applyWind();

          }
          if(pressedKey==2)
          {
              fire.blowOnFire();
              pressedKey=0;
          }
          else
          {
              fire.resetAcceleration();
          }
              snow.run(timer.DeltaTime());
              fire.run(timer.DeltaTime());
          break;
      case WATERFALL: {waterfall.run(timer.DeltaTime()); break;}
      }

      // set the end time of your animation
      timer.setEndTime(SDL_GetTicks());

     // update the buffer so we can see what we have drawn.
     win.swapWindow();
    }

    return EXIT_SUCCESS;
}
