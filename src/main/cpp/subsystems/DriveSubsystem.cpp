#include "subsystems/DriveSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <units/length.h>

#include "Constants.h"
#include <iostream>

DriveSubsystem::DriveSubsystem()
    : frontLeft{constants::drive::kFrontLeft},
      frontRight{constants::drive::kFrontRight},
      backLeft{constants::drive::kBackLeft},
      backRight{constants::drive::kBackRight}, odom{gyro.GetRotation2d(), 0_m, 0_m} {
    backLeft.Follow(frontLeft);
    backRight.Follow(frontRight);
    frontRight.SetInverted(true);
    curSpeed = constants::drive::kDriveSpeed;
    backRight.SetInverted(
        ctre::phoenix::motorcontrol::InvertType::FollowMaster);

    std::cout << backLeft.GetSelectedSensorPosition(0);
    ResetEncoders();
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
    diffDrive.ArcadeDrive(fwd * curSpeed, rot * curSpeed);
}

void DriveSubsystem::TankDrive(double l, double r) {
    diffDrive.TankDrive(
        l * constants::drive::kDriveSpeed, r * constants::drive::kDriveSpeed);
}

void DriveSubsystem::ResetEncoders() {
    frontLeft.SetSelectedSensorPosition(0);
    frontRight.SetSelectedSensorPosition(0);
    backLeft.SetSelectedSensorPosition(0);
    backRight.SetSelectedSensorPosition(0);
}

double DriveSubsystem::GetAverageEncoderDistance() {
    return (GetLeftEncoderDistance() + GetRightEncoderDistance()) / 2;
}

double DriveSubsystem::GetLeftEncoderDistance() {
    double avg = frontLeft.GetSelectedSensorPosition(0);
    avg += backLeft.GetSelectedSensorPosition(0);
    avg *= constants::drive::kDistancePerTick;
    return avg / 2;
}

double DriveSubsystem::GetRightEncoderDistance() {
    double avg = frontRight.GetSelectedSensorPosition(0);
    avg += backRight.GetSelectedSensorPosition(0);
    avg *= constants::drive::kDistancePerTick;
    return avg / 2;
}

void DriveSubsystem::ToggleSpeed() {
    if (curSpeed == constants::drive::kDriveSpeed) {
        curSpeed = constants::drive::kDriveSlow;
    } else {
        curSpeed = constants::drive::kDriveSpeed;
    }
}

void DriveSubsystem::ToggleBrake() {
    if (brake) {
        frontLeft.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Coast);
        frontRight.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Coast);
        backLeft.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Coast);
        backRight.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Coast);
    } else {
        frontLeft.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Brake);
        frontRight.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Brake);
        backLeft.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Brake);
        backRight.SetNeutralMode(
            ctre::phoenix::motorcontrol::NeutralMode::Brake);
    }

    brake = !brake;
}

void DriveSubsystem::Periodic() {
    frc::SmartDashboard::PutBoolean("GREEN IF BRAKING", brake);
    odom.Update(gyro.GetRotation2d(), units::meter_t{GetLeftEncoderDistance()},
        units::meter_t{GetRightEncoderDistance()});
}