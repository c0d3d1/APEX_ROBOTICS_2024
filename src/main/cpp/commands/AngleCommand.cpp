#include "commands/AngleCommand.h"
#include <utility>

AngleCommand::AngleCommand(AngleSubsystem *sub, bool active, int setRotation) : angle{sub}, is_active{active}, chosenAngle{setRotation} {
    AddRequirements(sub);
}

void AngleCommand::Execute() {
        angle->ShooterRotationAmount(chosenAngle);
    
}
