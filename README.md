# ParticleSystem

This a project for my second assignment for Principles and Practice of Programming. (Bournemouth University, 2017)
I chose to make a particle system where a reset the values of the particle, everytime they die. 
I made three different emitters: A snow emitter, a fire emitter and a "waterfall emitter with splash effects". 
I generated all those emitters in a box, the box is a boundary for the particles. We have the x-,y- and z-axes in the scene, to help navigate
through the scene with the camera we made. 

# Usage : Keys
**ESC**: escape the program

**UP arrow**: change your view to look up 

**DOWN arrow**: change your view to look down

**LEFT arrow**: change your view to look left

**RIGHT arrow**: change your view to look right 


**w**: move position of the camera (moves negative direction of the z-axis)

**s** : move position of the camera (moves positive direction of the z-axis)

**a**: move position of the camera (moves negative direction of the x-axis)

**d** : move position of the camera (moves positive direction of thex-axis)


**r** : resets the view to its default setting 

**p** : pause and unpause the timer (animation)

**m** : makes the animation slowmotion (looks well when the scene is set to the WATERFALL setting)


**SPACE** : makes you blow on the fire ( direction z-axis )

**f** : applies a force, for example wind ( you can change the setting in the applyWind function (emitter) ) 


### your default scene as the campfire/snow scene so if you want to change scene press number:

**1** : WATERFALL scene 

**2**: back to default scene 

# Built with 
- OpenGL
- GLM (OpenGL Mathematics) 
- SDL2 
- C++11




