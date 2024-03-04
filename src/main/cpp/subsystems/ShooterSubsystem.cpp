#include "subsystems/ShooterSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>

ShooterSubsystem::ShooterSubsystem()
    : shooterLeft{constants::shooter::kLeftShooter, rev::CANSparkMax::MotorType::kBrushless},
      shooterRight{constants::shooter::kRightShooter, rev::CANSparkMax::MotorType::kBrushless},
      shooterLeftEncoder{shooterLeft.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor)},
      shooterRightEncoder{shooterRight.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor)},
      shooterLeftPID{shooterLeft.GetPIDController()},
      shooterRightPID{shooterRight.GetPIDController()}
      {

    ResetEncoders();
}

void ShooterSubsystem::ResetEncoders() {
    shooterLeftEncoder.SetPosition(0);
    shooterRightEncoder.SetPosition(0);
}

void ShooterSubsystem::Shooter(int SetPoint) {
    shooterLeftPID.SetReference(SetPoint, rev::CANSparkMax::ControlType::kVelocity);
    shooterRightPID.SetReference(-SetPoint, rev::CANSparkMax::ControlType::kVelocity);
    }

void ShooterSubsystem::StopShooter() {
    shooterLeftPID.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
    shooterRightPID.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
}


void ShooterSubsystem::Periodic() {
    // read PID coefficients from SmartDashboard
    /*
    double p = frc::SmartDashboard::GetNumber("P Gain", 0);
    double i = frc::SmartDashboard::GetNumber("I Gain", 0);
    double d = frc::SmartDashboard::GetNumber("D Gain", 0);
    double iz = frc::SmartDashboard::GetNumber("I Zone", 0);
    double ff = frc::SmartDashboard::GetNumber("Feed Forward", 0);
    double max = frc::SmartDashboard::GetNumber("Max Output", 0);
    double min = frc::SmartDashboard::GetNumber("Min Output", 0);*/

    
    float shooterP = constants::shooter::kShooterP;
    float shooterI = constants::shooter::kShooterI;
    float shooterD = constants::shooter::kShooterD;
    float shooterIZ = constants::shooter::kShooterIZ;
    float shooterFF = constants::shooter::kShooterFF;
    float MinOutput = constants::shooter::kMinOutput;
    float MaxOutput = constants::shooter::kMaxOutput;
    float MaxRPM = constants::shooter::kMaxRPM;

  
    // set PID coefficients
    shooterLeftPID.SetP(shooterP);
    shooterLeftPID.SetI(shooterI);
    shooterLeftPID.SetD(shooterD);
    shooterLeftPID.SetIZone(shooterIZ);
    shooterLeftPID.SetFF(shooterFF);
    shooterLeftPID.SetOutputRange(MinOutput, MaxOutput);

    shooterRightPID.SetP(shooterP);
    shooterRightPID.SetI(shooterI);
    shooterRightPID.SetD(shooterD);
    shooterRightPID.SetIZone(shooterIZ);
    shooterRightPID.SetFF(shooterFF);
    shooterRightPID.SetOutputRange(MinOutput, MaxOutput);


    // display PID coefficients on SmartDashboard
    frc::SmartDashboard::PutNumber("P Gain", shooterP);
    frc::SmartDashboard::PutNumber("I Gain", shooterI);
    frc::SmartDashboard::PutNumber("D Gain", shooterD);
    frc::SmartDashboard::PutNumber("I Zone", shooterIZ);
    frc::SmartDashboard::PutNumber("Feed Forward", shooterFF);
    frc::SmartDashboard::PutNumber("Max Output", MaxOutput);
    frc::SmartDashboard::PutNumber("Min Output", MinOutput);
    frc::SmartDashboard::PutNumber("ShooterVelocityLeft", shooterLeftEncoder.GetVelocity());
    frc::SmartDashboard::PutNumber("ShooterVelocityRight", shooterRightEncoder.GetVelocity());
    }