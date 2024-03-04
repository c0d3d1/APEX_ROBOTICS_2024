#include "commands/ShootCommand.h"
#include <utility>

ShootCommand::ShootCommand(ShooterSubsystem *sub, bool active, int SetPoint) : shooter{sub}, is_active{active}, rpm{SetPoint} {
    AddRequirements(sub);
}

void ShootCommand::Execute() {
    if (is_active) {
        shooter->Shooter(rpm);
    } else {
        shooter->StopShooter();
    }
}
