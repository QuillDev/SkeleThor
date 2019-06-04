//Skeleton Crew 2019 v2.1 - Shinobu
#include "Robot.h"
#include "String.h"

//Global Variables

 //Flipping Boolean
  bool flipped = false;



//Drive Straight Functions

void Robot::RobotInit() {

//Setup Drive System
 botDrive = new frc::DifferentialDrive{lDrive, rDrive};
 lDrive.SetInverted(true);

//Create Joystick
 stick = new frc::Joystick{0};
}

//For Any Diagnostics...
void Robot::RobotPeriodic() {}

//Special Functions
//Setup Autonomous Running Period
void Robot::AutonomousInit() {}

//During Autonomous Running Period
void Robot::AutonomousPeriodic() {}


//Setup Player Control Mode.
void Robot::TeleopInit() {}

//Player Controlled Code
void Robot::TeleopPeriodic() {

//Axis
  double lDriveStick = stick->GetRawAxis(1);
  double rDriveStick = stick->GetRawAxis(5);

//Buttons
  bool aButton  = stick->GetRawButton(1);
  bool yButton  = stick->GetRawButton(4);
  bool bButton  = stick->GetRawButton(2);
  bool lBump = stick->GetRawButton(5);
  bool lBumpPressed = stick->GetRawButtonPressed(5);
  
//Bot Functions
  //While A is pressed, Cargo Deployment
  climb.Set(bButton);

  //While Y is pressed, Hatch Deployment
  hatchDeploy.Set(yButton);

  //While Y, Climb!
  cargo.Set(aButton ? frc::DoubleSolenoid::kForward : frc::DoubleSolenoid::kReverse);
  //The Flipper
  if(stick->GetRawButtonPressed(3)){flipped = !flipped;}
  //DriveTrain Set
  flipped ? botDrive->TankDrive(-rDriveStick, -lDriveStick) : botDrive->TankDrive(lDriveStick, rDriveStick);

}
//Test Stuff
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif