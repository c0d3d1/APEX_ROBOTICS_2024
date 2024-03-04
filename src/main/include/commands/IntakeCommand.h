#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class IntakeCommand
    : public frc2::CommandHelper<frc2::Command, IntakeCommand> {
  public:
    IntakeCommand(IntakeSubsystem *sub, bool active, int SetPoint, int setRotation);
    void Execute() override;
    //bool IsFinished() override;

  private:
    IntakeSubsystem *intake;
    bool is_active;
    int rpm;
    int angle;
};