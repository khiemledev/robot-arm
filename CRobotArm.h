#ifndef CROBOT_ARM_H
#define CROBOT_ARM_H

#include <Arduino.h>
#include <analogWrite.h>
#include <ESP32Servo.h>

// Output pins
#define CLAMP 13
#define UP_DOWN 12
#define FOR_BACKWARD 14
#define ROT 27

#define STOP 0
#define UP 1
#define DOWN 2
#define FORWARD 3
#define BACKWARD 4
#define ROT_LEFT 5
#define ROT_RIGHT 6
#define GRIP 7
#define RELEASE 8

class CRobotArm {
public:
    int speed;
    int clampPos;
    int upDownPos;
    int forBackPos;
    int rotPos;
    Servo clampSV;
    Servo upDownSV;
    Servo forBackSV;
    Servo rotSV;

    CRobotArm();

    void move();
    void rotateLeft();
    void rotateRight();
    void moveUp();
    void moveDown();
    void forward();
    void backward();
    void grip();
    void release();
};

#endif // CROTBOT_ARM_H
