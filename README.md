# Game-Controller
Snake Game controlled by gyroscope, joystick, and has a buzzer.
This lab is to design a game controller for a “Snake” game. The “snake” in the game needs to
eat the apples that randomly appear in the arena. The snake can move in four directions: up,
down, left, right. It grows its length by one unit every time an apple is eaten, and the player
earns 10 points. The snake cannot hit the boundary of the arena. The game ends when the
snake hits onto the boundary.
The game is initially controlled with four keys on the keyboard: “w”, “a”, “s”, “d”. Your task is to
alter the control of the game with the following:
(1) use a joystick to control the movement of the snake
(2) use the gyro sensor (MPU-6050) to control the movement of the snake. For example,
tilting the sensor board to the left will cause the “snake” to move to the left.
(3) beep the buzzer when an apple is eaten
