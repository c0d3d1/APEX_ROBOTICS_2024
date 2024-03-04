#include "commands/AutonCommand.h"
#include "subsystems/DriveSubsystem.h"

AutonCommand::AutonCommand(DriveSubsystem *sub)
    : drive{sub} {
    AddRequirements(sub);
}

constexpr float dist = 5.5;
constexpr float kP = 0.6;
constexpr float CloseEnough = 0.05;

void AutonCommand::Execute() {
    drive->TankDrive(((dist - drive->GetAverageEncoderDistance()) / dist) * kP,
        ((dist - drive->GetAverageEncoderDistance()) / dist) * kP);
}

bool AutonCommand::IsFinished() {
    return std::fabs((dist - drive->GetAverageEncoderDistance())) < CloseEnough;
}