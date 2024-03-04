#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class ClimberSubsystem : public frc2::SubsystemBase {
  public:
    ClimberSubsystem();
    void Periodic();
    void ExtendArm(int degreeAmount);
    void RetractArm();

  private:
    void ResetEncoders();
    void SetPid();
    rev::CANSparkMax leftClimber;
    rev::CANSparkMax rightClimber;
    rev::SparkPIDController leftClimberPID;
    rev::SparkPIDController rightClimberPID;
};
