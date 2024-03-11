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
#include "commands/AngleCommand.h"
#include "commands/ClimberCommand.h"
#include <iostream>

RobotContainer::RobotContainer() {
    intake.intakeOut = false;
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
    


 generic.Button(5).OnTrue(
        frc2::InstantCommand([&] { 
        float Kp = -0.1f;
        float min_command = 0.05f;
        std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
        float tx = table->GetNumber("tx",0.0);

        float heading_error = -tx;
        float steering_adjust = 0.0f;
        if (tx > 1.0)
        {
                steering_adjust = Kp*heading_error - min_command;
        }
        else if (tx < 1.0)
        {
                steering_adjust = Kp*heading_error + min_command;
        }
        // TODO: FIX RX AND TY ADD
        //rx = rx + steering_adjust;
        //ry = ry - steering_adjust;
        drive.SetDefaultCommand(DriveCommand(&drive, ly, rx, ry));
        
        }, {&drive}).ToPtr());


    generic.Button(6).OnTrue(
        frc2::InstantCommand([&] {
            if(intake.intakeOut==true) {
             intake.IntakeSpin(1000); 
            }
            else {
             intake.IntakeSpin(-1000); 
            } 
            }, {&intake}).ToPtr());

    generic.Button(6).OnFalse(
        frc2::InstantCommand([&] { intake.IntakeSpin(0); }, {&intake}).ToPtr());

    generic.Button(7).OnTrue(
        frc2::InstantCommand([&] { intake.IntakeRotationAngle(25.1); intake.intakeOut = true;}, {&intake}).ToPtr());
    generic.Button(8).OnTrue(
        frc2::InstantCommand([&] { intake.IntakeRotationAngle(-5); intake.intakeOut = false;}, {&intake}).ToPtr());

    generic.Button(9).OnTrue(
        frc2::InstantCommand([&] { angle.ShooterRotationAmount(10); }, {&angle}).ToPtr());
    generic.Button(10).OnTrue(
        frc2::InstantCommand([&] { angle.ShooterRotationAmount(-10); }, {&angle}).ToPtr());

    generic.Button(11).OnTrue(
        frc2::InstantCommand([&] { shooter.Shooter(5700); }, {&shooter}).ToPtr());
    generic.Button(11).OnFalse(
        frc2::InstantCommand([&] { shooter.StopShooter(); }, {&shooter}).ToPtr());
}

frc2::Command *RobotContainer::GetAutonomousCommand() {
    return chooser.GetSelected();
}
