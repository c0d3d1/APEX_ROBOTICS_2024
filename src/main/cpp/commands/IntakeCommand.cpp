#include "commands/IntakeCommand.h"
#include <utility>

IntakeCommand::IntakeCommand(IntakeSubsystem *sub, bool active, int SetPoint, int setRotation) : intake{sub}, is_active{active}, rpm{SetPoint}, angle{setRotation} {
    AddRequirements(sub);
}

void IntakeCommand::Execute() {
        intake->IntakeSpin(rpm);
        intake->IntakeRotationAngle(angle);
    
}
