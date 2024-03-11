#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "../LimelightHelpers.h"
#include "Constants.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>

class AngleSubsystem : public frc2::SubsystemBase {
  public:
    AngleSubsystem();
    void Periodic();
    void ShooterRotationAmount(int SetRotation);
    float GetDistance();

  private:
    void SetPid();
    rev::CANSparkMax leftLift;
    rev::CANSparkMax rightLift;
    rev::SparkPIDController leftLiftPID;
    rev::SparkPIDController rightLiftPID;
    double tx = LimelightHelpers::getTX("");
    double ty = LimelightHelpers::getTY("");
    //rev::SparkAbsoluteEncoder rotateIntakeEncoder;
};
