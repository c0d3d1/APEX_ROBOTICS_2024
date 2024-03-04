#pragma once

#include "subsystems/DriveSubsystem.h"
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class AutonCommand
    : public frc2::CommandHelper<frc2::Command, AutonCommand> {
  public:
    AutonCommand(DriveSubsystem *sub);
    void Execute() override;
    bool IsFinished() override;

  private:
    DriveSubsystem *drive;
};
