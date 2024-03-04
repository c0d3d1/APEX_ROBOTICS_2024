#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class AngleSubsystem : public frc2::SubsystemBase {
  public:
    AngleSubsystem();
    void Periodic();
    void ShooterRotationAmount(int SetRotation);

  private:
    void ResetEncoders();
    void SetPid();
    rev::CANSparkMax leftLift;
    rev::CANSparkMax rightLift;
    rev::SparkPIDController leftLiftPID;
    rev::SparkPIDController rightLiftPID;
    //rev::SparkAbsoluteEncoder rotateIntakeEncoder;
};
