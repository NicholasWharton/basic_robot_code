#include "WPILib.h"

class Robot : public IterativeRobot{
private:

    CANTalon* frontRight;
    CANTalon* frontLeft;
    CANTalon* backRight;
    CANTalon* backLeft;
    Joystick* joy1;
    RobotDrive* drive;
    DigitalInput* limitSwitch;
    AnalogGyro* gyro;
    Ultrasonic* sonic;
    Compressor* comp;

    void robotinit{
        frontRight = new CANTalon(0);
        frontLeft = new CANTalon(1);
        backRight = new CANTalon(2);
        backLeft = new CANTalon(3);
        lift = new CANTalon(4)
        joy1 = new Joystick(1);
        drive = new RobotDrive(frontRight,frontLeft,backRight,backLeft);
        bool limitSwitch = new DigitalInput(0);
        gyro = new AnalogGyro(3);
        sonic= new Ultrasonic(1,2);
        comp = new Compressor(0)

    }void teleopPeridioc(){
        double leftSide = joy1->GetRawAxis(1);
        double rightSide = joy1->GetRawAxis(5);
        float angle = gyro->GetAngle();
        int range = sonic->GetRangeInches();
        float currentpsi = comp->GetCompressorCurrent();
        limitSwitch->Get();

        drive->TankDrive(leftSide,rightSide);

        if(limitswitch = 1){
        lift->Set(0.5);

        }if(angle = 10){
        leftSide->Set(-0.5)
        rightSide->Set(-0.5)

        }if(range = 20){
        lift->Set(-0.5)

        }if(currentpsi < 100){
        compre->SetClosedLoopControl(true);

        }else{
        compre->SetClosedLoopControl(false);
        }
    }
};
START_ROBOT_CLASS(Robot);
