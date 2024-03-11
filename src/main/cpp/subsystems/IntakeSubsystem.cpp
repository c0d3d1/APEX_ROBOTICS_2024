#include "subsystems/IntakeSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>

IntakeSubsystem::IntakeSubsystem()
    : spinIntake{constants::intake::kSpinIntake, rev::CANSparkMax::MotorType::kBrushless},
      rotateIntake{constants::intake::kRotateIntake, rev::CANSparkMax::MotorType::kBrushless},
      rotateIntakeEncoder{rotateIntake.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor)},
      //rotateIntakeEncoder{rotateIntake.GetEncoder(rev::SparkAbsoluteEncoder::)},
      spinIntakePID{spinIntake.GetPIDController()},
      rotateIntakePID{rotateIntake.GetPIDController()}
      {

    ResetEncoders();
}

void IntakeSubsystem::ResetEncoders() {
    rotateIntakeEncoder.SetPosition(0);
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
    // FIX shooter P etc to be for shooter pid
    // set PID coefficients
    spinIntakePID.SetP(constants::shooter::kShooterP);
    spinIntakePID.SetI(constants::shooter::kShooterI);
    spinIntakePID.SetD(constants::shooter::kShooterD);
    spinIntakePID.SetIZone(constants::shooter::kShooterIZ);
    spinIntakePID.SetFF(constants::shooter::kShooterFF);
    spinIntakePID.SetOutputRange(constants::shooter::kMinOutput, constants::shooter::kMaxOutput);

    rotateIntakePID.SetP(constants::intake::kIntakeP);
    rotateIntakePID.SetI(constants::intake::kIntakeI);
    rotateIntakePID.SetD(constants::intake::kIntakeD);
    rotateIntakePID.SetIZone(constants::intake::kIntakeIZ);
    rotateIntakePID.SetFF(constants::intake::kIntakeFF);
    rotateIntakePID.SetOutputRange(constants::intake::kIntakeMinOutput, constants::intake::kIntakeMaxOutput);

    frc::SmartDashboard::PutNumber("spinIntakeVelocity - Intake", rotateIntakeEncoder.GetVelocity());
    }