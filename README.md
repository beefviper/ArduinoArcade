# Arcade3
Simple Arduino hardware and software framework for games.

The basic layout is:

- Arcade
  - Hardware
    - Screen
    - Joystick
    - Speaker
    - RanNumGen
  - Software
    - Game
      - Snake
      - Missile
      - Breakout
      
      
Arcade contains Hardware and Software. It also contains four main functions:
  init(), draw(), input(), and logic() which it cascades down.
  
Hardware contains Screen, Joystick, Speaker, and RanNumGen. It calls all the init() functions
  for all the hardware define with HardwareParams.
  
Screen is an U8G2 object. Library: https://github.com/olikraus/u8g2

Joystick reads from a standard analog module.

Speaker supports both Active and Passive speakers.

RanNumGen does an analog read from a floating pin.

Software contains Game, and Game contains the actual games.
  (TODO: One of them needs to handle a menu)

And Snake, Missle, and Breakout are simple proofs of concept.
  With the basic idea being that they have a draw() and logic() functions
  that get called each time through the loop. Plus whatever functions
  they need to work.
  
  
  
  
  
