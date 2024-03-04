#include "commands/DriveCommand.h"
#include <utility>

DriveCommand::DriveCommand(DriveSubsystem *sub, std::function<double()> ly,
    std::function<double()> rx, std::function<double()> ry)
    : drive{sub}, ly{ly}, rx{rx}, ry{ry} {
    AddRequirements(sub);
}

void DriveCommand::Execute() {
    if (constants::drive::kIsArcadeDrive) {
        drive->ArcadeDrive(ly(), rx());
    } else {
        drive->TankDrive(ly(), ry());
    }
}