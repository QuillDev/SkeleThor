//Skeleton Crew 2019 v2.1 - Shinobu
#include "Robot.h"
#include "String.h"

//Global Variables

/*
#if defined(__linux__)
  static void VisionThread() {
    // Get the USB camera from CameraServer
    cs::UsbCamera camera =
        frc::CameraServer::GetInstance()->StartAutomaticCapture();
    // Set the resolution
    camera.SetResolution(160, 120);

    // Get a CvSink. This will capture Mats from the Camera
    cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
    // Setup a CvSource. This will send images back to the Dashboard
    cs::CvSource outputStream =
        frc::CameraServer::GetInstance()->PutVideo("Align", 160, 120);

    // Mats are very memory expensive. Lets reuse this Mat.
    cv::Mat mat;

    while (true) {F
      // Tell the CvSink to grab a frame from the camera and
      // put it
      // in the source mat.  If there is an error notify the
      // output.
      if (cvSink.GrabFrame(mat) == 0) {
        // Send the output the error.
        outputStream.NotifyError(cvSink.GetError());
        // skip the rest of the current iteration
        continue;
      }
      // Put a rectangle on the image
       rectangle(mat, cv::Point(70, 0), cv::Point(90, 120),
                cv::Scalar(0, 255, 255), 2);
      // Give the output stream a new image to display
      outputStream.PutFrame(mat);
    }
  }
#endif
*/

 //Flipping Boolean
  bool flipped = false;



//Drive Straight Functions

void Robot::RobotInit() {

/*
#if defined(__linux__)
    std::thread visionThread(VisionThread);
    visionThread.detach();
#else
    wpi::errs() << "Vision only available on Linux.\n";
    wpi::errs().flush();
#endif
*/

//Setup Drive System
 botDrive = new frc::DifferentialDrive{lDrive, rDrive};
 lDrive.SetInverted(true);

//Create Joystick
 stick = new frc::Joystick{0};
}

//For Any Diagnostics...
void Robot::RobotPeriodic() {
  
}

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
  //Camera Set
  server.SetSource(flipped ? camera2 : camera1);

}
//Test Stuff
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif