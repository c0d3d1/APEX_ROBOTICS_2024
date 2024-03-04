// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/button/CommandGenericHID.h>
#include <frc2/command/button/CommandJoystick.h>
#include <frc2/command/button/CommandXboxController.h>

#include "commands/AutonCommand.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/IntakeSubsystem.h"

class RobotContainer {
  public:
    RobotContainer();

    frc2::Command *GetAutonomousCommand();

    frc2::CommandGenericHID generic{0};

    frc::SendableChooser<frc2::Command *> chooser;

    DriveSubsystem drive;

    ShooterSubsystem shooter;

    IntakeSubsystem intake;

  private:
    void ConfigureBindings();
};
