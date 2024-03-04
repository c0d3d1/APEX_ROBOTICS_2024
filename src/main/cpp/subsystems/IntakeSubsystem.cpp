#include "subsystems/IntakeSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>

IntakeSubsystem::IntakeSubsystem()
    : spinIntake{constants::shooter::kSpinIntake, rev::CANSparkMax::MotorType::kBrushless},
      rotateIntake{constants::shooter::kRotateIntake, rev::CANSparkMax::MotorType::kBrushless},
      spinIntakeEncoder{spinIntake.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor)},
      //rotateIntakeEncoder{rotateIntake.GetEncoder(rev::SparkAbsoluteEncoder::)},
      spinIntakePID{spinIntake.GetPIDController()},
      rotateIntakePID{rotateIntake.GetPIDController()}
      {

    ResetEncoders();
}

void IntakeSubsystem::ResetEncoders() {
    spinIntakeEncoder.SetPosition(0);
}

void IntakeSubsystem::IntakeSpin(int SetPoint) {
    spinIntakePID.SetReference(SetPoint, rev::CANSparkMax::ControlType::kVelocity);
    }

void IntakeSubsystem::StopIntakeSpin() {
    spinIntakePID.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
}

void IntakeSubsystem::IntakeRotationAngle(int SetRotation) {
    rotateIntakePID.SetReference(SetRotation, rev::CANSparkMax::ControlType::kPosition);
}


void IntakeSubsystem::Periodic() {
    
    float shooterP = constants::shooter::kShooterP;
    float shooterI = constants::shooter::kShooterI;
    float shooterD = constants::shooter::kShooterD;
    float shooterIZ = constants::shooter::kShooterIZ;
    float shooterFF = constants::shooter::kShooterFF;
    float MinOutput = constants::shooter::kMinOutput;
    float MaxOutput = constants::shooter::kMaxOutput;
    float MaxRPM = constants::shooter::kMaxRPM;
  
    // set PID coefficients
    spinIntakePID.SetP(shooterP);
    spinIntakePID.SetI(shooterI);
    spinIntakePID.SetD(shooterD);
    spinIntakePID.SetIZone(shooterIZ);
    spinIntakePID.SetFF(shooterFF);
    spinIntakePID.SetOutputRange(MinOutput, MaxOutput);

    // display PID coefficients on SmartDashboard
    frc::SmartDashboard::PutNumber("P Gain - Intake", shooterP);
    frc::SmartDashboard::PutNumber("I Gain - Intake", shooterI);
    frc::SmartDashboard::PutNumber("D Gain - Intake", shooterD);
    frc::SmartDashboard::PutNumber("I Zone - Intake", shooterIZ);
    frc::SmartDashboard::PutNumber("Feed Forward - Intake", shooterFF);
    frc::SmartDashboard::PutNumber("Max Output - Intake", MaxOutput);
    frc::SmartDashboard::PutNumber("Min Output - Intake", MinOutput);
    frc::SmartDashboard::PutNumber("spinIntakeVelocity - Intake", spinIntakeEncoder.GetVelocity());
    }