#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/AngleSubsystem.h"

class AngleCommand
    : public frc2::CommandHelper<frc2::Command, AngleCommand> {
  public:
    AngleCommand(AngleSubsystem *sub, bool active, int setRotation);
    void Execute() override;
    //bool IsFinished() override;

  private:
    AngleSubsystem *angle;
    bool is_active;
    int chosenAngle;
    
};