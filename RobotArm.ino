#include "BluetoothSerial.h"
#include "CRobotArm.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Global variables
BluetoothSerial SerialBT;
CRobotArm arm = CRobotArm();
int control = STOP;

void setup() {
    Serial.begin(115200);
    SerialBT.begin("RobotArm v0.1");
    Serial.println("RobotArm ready to use!");
}

void loop() {
    if (SerialBT.available()) {
        control = SerialBT.read() - '0';
    }
    switch (control) {
        case ROT_LEFT:
            arm.rotateLeft();
            break;
        case ROT_RIGHT:
            arm.rotateRight();
            break;
        case UP:
            arm.moveUp();
            break;
        case DOWN:
            arm.moveDown();
            break;
        case FORWARD:
            arm.forward();
            break;
        case BACKWARD:
            arm.backward();
            break;
        case GRIP:
            arm.grip();
            Serial.println("Group");
            break;
        case RELEASE:
            arm.release();
            Serial.println("Release");
            break;
    }
    arm.move();
    delay(20);
}
