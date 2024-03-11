#include "subsystems/AngleSubsystem.h"
#include "Constants.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include <iostream>
#include <string>
#include <frc/SmartDashboard/SendableChooser.h>

AngleSubsystem::AngleSubsystem()
    : leftLift{constants::angle::kLeftAngle, rev::CANSparkMax::MotorType::kBrushless},
      rightLift{constants::angle::kRightAngle, rev::CANSparkMax::MotorType::kBrushless},
      //rotateIntakeEncoder{rotateIntake.GetEncoder(rev::SparkAbsoluteEncoder::)},
      leftLiftPID{leftLift.GetPIDController()},
      rightLiftPID{rightLift.GetPIDController()}
      {
}

void AngleSubsystem::ShooterRotationAmount(int SetRotation) {
    leftLiftPID.SetReference(SetRotation, rev::CANSparkMax::ControlType::kPosition);
    rightLiftPID.SetReference(SetRotation, rev::CANSparkMax::ControlType::kPosition);
}

float AngleSubsystem::GetDistance() {
    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");  
    double targetOffsetAngle_Vertical = table->GetNumber("ty",0.0);

    // how many degrees back is your limelight rotated from perfectly vertical?
    double limelightMountAngleDegrees = 0.0; 

    // distance from the center of the Limelight lens to the floor
    double limelightLensHeightInches = 20.0; 

    // distance from the target to the floor
    double goalHeightInches = 60.0; 

    double angleToGoalDegrees = limelightMountAngleDegrees + targetOffsetAngle_Vertical;
    double angleToGoalRadians = angleToGoalDegrees * (3.14159 / 180.0);

    //calculate distance
    double distanceFromLimelightToGoalInches = (goalHeightInches - limelightLensHeightInches)/tan(angleToGoalRadians);

    return distanceFromLimelightToGoalInches;
}

void AngleSubsystem::Periodic() {
    
    float shooterP = constants::angle::kAngleP;
    float shooterI = constants::angle::kAngleI;
    float shooterD = constants::angle::kAngleD;
    float shooterIZ = constants::angle::kAngleIZ;
    float shooterFF = constants::angle::kAngleFF;
    float MinOutput = constants::angle::kAngleMinOutput;
    float MaxOutput = constants::angle::kAngleMaxOutput;
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


    /*if(GetDistance() >= 20 && GetDistance() <= 300) {
        ShooterRotationAmount(30 - GetDistance()*10);
    }*/
    // display PID coefficients on SmartDashboard
    }