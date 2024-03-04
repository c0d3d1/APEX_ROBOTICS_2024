#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class DriveCommand
    : public frc2::CommandHelper<frc2::Command, DriveCommand> {
  public:
    DriveCommand(DriveSubsystem *sub, std::function<double()> ly,
        std::function<double()> rx, std::function<double()> ry);
    void Execute() override;

  private:
    DriveSubsystem *drive;
    std::function<double()> ly;
    std::function<double()> rx;
    std::function<double()> ry;
};