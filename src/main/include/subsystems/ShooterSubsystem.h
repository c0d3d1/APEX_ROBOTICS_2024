#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class ShooterSubsystem : public frc2::SubsystemBase {
  public:
    ShooterSubsystem();
    void Periodic();
    void Shooter(int SetPoint);
    void StopShooter();

  private:
    void ResetEncoders();
    void SetPid();
    rev::CANSparkMax shooterLeft;
    rev::CANSparkMax shooterRight;
    rev::SparkPIDController shooterLeftPID;
    rev::SparkPIDController shooterRightPID;
    rev::SparkRelativeEncoder shooterLeftEncoder;
    rev::SparkRelativeEncoder shooterRightEncoder;
};
