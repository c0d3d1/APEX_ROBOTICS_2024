#pragma once
#include <ctre/Phoenix.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
  public:
    DriveSubsystem();
    void ResetEncoders();
    void ArcadeDrive(double fwd, double rot);
    void TankDrive(double l, double r);
    void Periodic() override;
    void ToggleSpeed();
    void ToggleBrake();
    double GetAverageEncoderDistance();

  private:
    WPI_TalonFX frontLeft;
    WPI_TalonFX frontRight;
    WPI_TalonFX backLeft;
    WPI_TalonFX backRight;

    float curSpeed;
    bool brake = false;

    double GetLeftEncoderDistance();
    double GetRightEncoderDistance();

    frc::DifferentialDrive diffDrive{frontLeft, frontRight};
    frc::DifferentialDriveOdometry odom;
    frc::ADXRS450_Gyro gyro;
};