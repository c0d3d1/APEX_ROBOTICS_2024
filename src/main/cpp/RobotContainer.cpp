// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Commands.h>

#include <units/time.h>

#include "commands/AutonCommand.h"
#include "commands/DriveCommand.h"
#include "commands/ShootCommand.h"
#include "commands/IntakeCommand.h"
#include <iostream>

RobotContainer::RobotContainer() {
    ConfigureBindings();
    frc::SmartDashboard::PutData(&chooser);
}

void RobotContainer::ConfigureBindings() {
    std::function<double()> ly;
    std::function<double()> rx;
    std::function<double()> ry;
    std::function<double()> throttle;
    ly = [this] { return generic.GetRawAxis(1); };
    rx = [this] {
        return -generic.GetRawAxis(2) * constants::drive::kTurnSpeed;
    };
    ry = [this] { return -generic.GetRawAxis(3); };
    throttle = [this] { return generic.GetRawAxis(4); };
    drive.SetDefaultCommand(DriveCommand(&drive, ly, rx, ry));

    generic.Button(6).OnTrue(
        frc2::InstantCommand([&] {
            if(intake.intakeOut=true) {
             intake.IntakeSpin(1000); 
            }
            else {
             intake.IntakeSpin(-1000); 
            } }, {&intake}).ToPtr());
    generic.Button(7).OnTrue(
        frc2::InstantCommand([&] { intake.IntakeSpin(0); }, {&intake}).ToPtr());
    generic.Button(8).OnTrue(
        frc2::InstantCommand([&] { intake.IntakeRotationAngle(90); intake.intakeOut = true;}, {&intake}).ToPtr());

    generic.Button(9).OnTrue(
        frc2::InstantCommand([&] { intake.IntakeRotationAngle(-90); intake.intakeOut = false;}, {&intake}).ToPtr());

    generic.Button(10).OnTrue(
        frc2::InstantCommand([&] { shooter.Shooter(2000); }, {&shooter}).ToPtr());
    generic.Button(11).OnTrue(
        frc2::InstantCommand([&] { shooter.Shooter(5700); }, {&shooter}).ToPtr());
    generic.Button(12).OnTrue(
        frc2::InstantCommand([&] { shooter.StopShooter(); }, {&shooter}).ToPtr());
    
}

frc2::Command *RobotContainer::GetAutonomousCommand() {
    return chooser.GetSelected();
}
