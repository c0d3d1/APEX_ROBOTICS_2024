#include "commands/ClimberCommand.h"
#include <utility>

ClimberCommand::ClimberCommand(ClimberSubsystem *sub, bool active, int rotationAmount) : climber{sub}, is_active{active}, angle{rotationAmount} {
    AddRequirements(sub);
}

void ClimberCommand::Execute() {
        //climber->ExtendArm(angle);
        //TODO: Below might cause a bug
        //climber->RetractArm();
}
