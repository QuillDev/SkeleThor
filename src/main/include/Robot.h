#pragma once

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/VictorSP.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>
#include <adi/ADIS16470_IMU.h>
#include <frc/SerialPort.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
 /*
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  */

//Drive Systems
 //Set Drive Train Type
 frc::DifferentialDrive* botDrive;

 //Get Joystick...
 frc::Joystick *stick;

//Motors
 frc::VictorSP lDrive{0};
 frc::VictorSP rDrive{1};

 //Control Through SpeedController
 frc::SpeedControllerGroup *lDriveT;
 frc::SpeedControllerGroup *rDriveT;

//Pneumatic Systems
 //Hatch Deploy
 frc::Solenoid hatchDeploy{3};

 //Climb
 frc::Solenoid climb{0};

 //CargoShooter
 frc::DoubleSolenoid cargo{1, 2};
 
 //GyroScope
 frc::ADIS16470_IMU *gyro;
};
