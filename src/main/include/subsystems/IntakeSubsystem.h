#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase {
  public:
    IntakeSubsystem();
    void Periodic();
    void IntakeSpin(int rotationPoint);
    void StopIntakeSpin();
    void IntakeRotationAngle(int SetRotation);
    bool intakeOut = false;

  private:
    void ResetEncoders();
    void SetPid();
    rev::CANSparkMax rotateIntake;
    rev::CANSparkMax spinIntake;
    rev::SparkPIDController spinIntakePID;
    rev::SparkPIDController rotateIntakePID;
    //rev::SparkAbsoluteEncoder rotateIntakeEncoder;
    rev::SparkRelativeEncoder rotateIntakeEncoder;
};
