#include "subsystems/ClimberSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>

ClimberSubsystem::ClimberSubsystem()
    : leftClimber{constants::climber::kLeftClimber, rev::CANSparkMax::MotorType::kBrushless},
      rightClimber{constants::climber::kRightClimber, rev::CANSparkMax::MotorType::kBrushless},
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
  
    // set PID coefficients
    leftClimberPID.SetP(constants::climber::kClimberP);
    leftClimberPID.SetI(constants::climber::kClimberI);
    leftClimberPID.SetD(constants::climber::kClimberD);
    leftClimberPID.SetIZone(constants::climber::kClimberIZ);
    leftClimberPID.SetFF(constants::climber::kClimberFF);
    leftClimberPID.SetOutputRange(constants::climber::kClimberMinOutput, constants::climber::kClimberMaxOutput);

    // set PID coefficients
    rightClimberPID.SetP(constants::climber::kClimberP);
    rightClimberPID.SetI(constants::climber::kClimberI);
    rightClimberPID.SetD(constants::climber::kClimberD);
    rightClimberPID.SetIZone(constants::climber::kClimberIZ);
    rightClimberPID.SetFF(constants::climber::kClimberFF);
    rightClimberPID.SetOutputRange(constants::climber::kClimberMinOutput, constants::climber::kClimberMaxOutput);
    
}