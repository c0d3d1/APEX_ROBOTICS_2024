#include "subsystems/AngleSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>

AngleSubsystem::AngleSubsystem()
    : leftLift{constants::shooter::kSpinIntake, rev::CANSparkMax::MotorType::kBrushless},
      rightLift{constants::shooter::kRotateIntake, rev::CANSparkMax::MotorType::kBrushless},
      //rotateIntakeEncoder{rotateIntake.GetEncoder(rev::SparkAbsoluteEncoder::)},
      leftLiftPID{leftLift.GetPIDController()},
      rightLiftPID{rightLift.GetPIDController()}
      {

    ResetEncoders();
}

void AngleSubsystem::ShooterRotationAmount(int SetRotation) {
    leftLiftPID.SetReference(SetRotation, rev::CANSparkMax::ControlType::kPosition);
    rightLiftPID.SetReference(SetRotation, rev::CANSparkMax::ControlType::kPosition);
}


void AngleSubsystem::Periodic() {
    
    float shooterP = constants::shooter::kShooterP;
    float shooterI = constants::shooter::kShooterI;
    float shooterD = constants::shooter::kShooterD;
    float shooterIZ = constants::shooter::kShooterIZ;
    float shooterFF = constants::shooter::kShooterFF;
    float MinOutput = constants::shooter::kMinOutput;
    float MaxOutput = constants::shooter::kMaxOutput;
    float MaxRPM = constants::shooter::kMaxRPM;
  
    // set PID coefficients
    leftLiftPID.SetP(shooterP);
    leftLiftPID.SetI(shooterI);
    leftLiftPID.SetD(shooterD);
    leftLiftPID.SetIZone(shooterIZ);
    leftLiftPID.SetFF(shooterFF);
    leftLiftPID.SetOutputRange(MinOutput, MaxOutput);

    rightLiftPID.SetP(shooterP);
    rightLiftPID.SetI(shooterI);
    rightLiftPID.SetD(shooterD);
    rightLiftPID.SetIZone(shooterIZ);
    rightLiftPID.SetFF(shooterFF);
    rightLiftPID.SetOutputRange(MinOutput, MaxOutput);

    // display PID coefficients on SmartDashboard
    }