#include "subsystems/ClimberSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>

ClimberSubsystem::ClimberSubsystem()
    : leftClimber{constants::shooter::kLeftClimber, rev::CANSparkMax::MotorType::kBrushless},
      rightClimber{constants::shooter::kRightClimber, rev::CANSparkMax::MotorType::kBrushless},
      //rotateIntakeEncoder{rotateIntake.GetEncoder(rev::SparkAbsoluteEncoder::)},
      leftClimberPID{leftClimber.GetPIDController()},
      rightClimberPID{rightClimber.GetPIDController()}
      {
}


void ClimberSubsystem::RetractArm() {
    leftClimberPID.SetReference(0, rev::CANSparkMax::ControlType::kPosition);
    rightClimberPID.SetReference(0, rev::CANSparkMax::ControlType::kPosition);
    }

void ClimberSubsystem::ExtendArm(int degreeAmount) {
    leftClimberPID.SetReference(degreeAmount, rev::CANSparkMax::ControlType::kPosition);
    rightClimberPID.SetReference(degreeAmount, rev::CANSparkMax::ControlType::kPosition);
}



void ClimberSubsystem::Periodic() {
    
    float shooterP = constants::shooter::kShooterP;
    float shooterI = constants::shooter::kShooterI;
    float shooterD = constants::shooter::kShooterD;
    float shooterIZ = constants::shooter::kShooterIZ;
    float shooterFF = constants::shooter::kShooterFF;
    float MinOutput = constants::shooter::kMinOutput;
    float MaxOutput = constants::shooter::kMaxOutput;
    float MaxRPM = constants::shooter::kMaxRPM;
  
    // set PID coefficients
    leftClimberPID.SetP(shooterP);
    leftClimberPID.SetI(shooterI);
    leftClimberPID.SetD(shooterD);
    leftClimberPID.SetIZone(shooterIZ);
    leftClimberPID.SetFF(shooterFF);
    leftClimberPID.SetOutputRange(MinOutput, MaxOutput);

    // set PID coefficients
    rightClimberPID.SetP(shooterP);
    rightClimberPID.SetI(shooterI);
    rightClimberPID.SetD(shooterD);
    rightClimberPID.SetIZone(shooterIZ);
    rightClimberPID.SetFF(shooterFF);
    rightClimberPID.SetOutputRange(MinOutput, MaxOutput);

    // display PID coefficients on SmartDashboard
    }