#include "CRobotArm.h"

CRobotArm::CRobotArm() {
    this->clampSV.attach(CLAMP);
    this->upDownSV.attach(UP_DOWN);
    this->forBackSV.attach(FOR_BACKWARD);
    this->rotSV.attach(ROT);
    this->speed = 2;
    this->clampPos = 90jk;
    this->upDownPos = 90;
    this->forBackPos = 90;
    this->rotPos = 90;
    this->move();
}

void CRobotArm::move() {
    this->clampSV.write(this->clampPos); 
    this->upDownSV.write(this->upDownPos);
    this->forBackSV.write(this->forBackPos);
    this->rotSV.write(this->rotPos);
    delay(15); // Wait for Servo to reach desired position
}

void CRobotArm::release() {
    if (this->clampPos >= speed)
        this->clampPos -= speed;
}

void CRobotArm::grip() {
    if (this->clampPos < 180 - speed)
        this->clampPos += speed;
}

void CRobotArm::moveUp() {
    if (this->upDownPos < 180 - speed)
        this->upDownPos += speed;  
}

void CRobotArm::moveDown() {
    if (this->upDownPos >= speed)
        this->upDownPos -= speed;  
}

void CRobotArm::forward() {
    if (this->forBackPos < 180 - speed)
        this->forBackPos += speed;  
}

void CRobotArm::backward() {
    if (this->forBackPos >= speed)
        this->forBackPos -= speed;  
}

void CRobotArm::rotateRight() {
    if (this->rotPos < 180 - speed)
        this->rotPos += speed;
}

void CRobotArm::rotateLeft() {
    if (this->rotPos >= speed)
        this->rotPos -= speed;
}
