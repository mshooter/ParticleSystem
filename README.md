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
# problems to be fixed
- the timer is different for different systems: when you calculate deltatime in the timer you need to devide it by a number. 

For linux it would be devided by 1000

For Mac it would be devided by 2500

(check the comments in the code for clarity) 

# References 
[1] WILLIAM T. REEVES (1983). Particle Systems - A Technique for Modeling a Class of Fuzzy Objects. [online] pp.350-375. Available at: https://www.lri.fr/~mbl/ENS/IG2/devoir2/files/docs/fuzzyParticles.pdf [Accessed 2017].

[2] Shiffman, D. (2012). The nature of code: Chapter 4. Particle Systems. [online] Available at: http://natureofcode.com/book/chapter-4-particle-systems/ [Accessed 2017] 

[3] Zhang, J., Angel, E., Alsing, P. and Munich, D. (n.d.). An Object-Oriented Particle System for Simulation and Visualization. [online] Available at: https://pdfs.semanticscholar.org/56a4/1ee99e2cdc4620a919a35a661ed7b1f8eee4.pdf [Accessed 2017].

[4] Macey, J. (2017). Particle System. [online] Available at: https://github.com/NCCA/ParticleSystem [Accessed 2017]

[5] Ginman, V., Malmros, K. (n.d.). Visualization of smoke using particle systems. [online] Available at: http://www.csc.kth.se/utbildning/kth/kurser/DD143X/dkand13/Group9Petter/report/Veronica.Ginman.Kim.Malmros.report.pdf [Accessed 2017] 

[6] Bartek's coding blog, Bartlomiej Filipek. (2014). Flexible Particle System. [online] Available at: http://www.bfilipek.com/2014/04/flexible-particle-system-start.html [Accessed 2017]

# The Video

https://youtu.be/dGAJDXugYKs

...
