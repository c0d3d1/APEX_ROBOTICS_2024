#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ShooterSubsystem.h"

class ShootCommand
    : public frc2::CommandHelper<frc2::Command, ShootCommand> {
  public:
    ShootCommand(ShooterSubsystem *sub, bool active, int SetPoint);
    void Execute() override;
    //bool IsFinished() override;

  private:
    ShooterSubsystem *shooter;
    bool is_active;
    int rpm;
};