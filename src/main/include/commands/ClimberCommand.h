#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimberSubsystem.h"

class ClimberCommand
    : public frc2::CommandHelper<frc2::Command, ClimberCommand> {
  public:
    ClimberCommand(ClimberSubsystem *sub, bool active, int degreeAmount);
    void Execute() override;
    //bool IsFinished() override;

  private:
    ClimberSubsystem *intake;
    bool is_active;
    int angle;
};