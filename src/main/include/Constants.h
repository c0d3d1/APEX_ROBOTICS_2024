#pragma once
#include <units/length.h>

namespace constants {
constexpr float pi = 3.141592653589793238462653383;
namespace drive {
constexpr int kFrontLeft = 3;
constexpr int kFrontRight = 4;
constexpr int kBackLeft = 1;
constexpr int kBackRight = 2;
constexpr float kDriveSpeed = 1;
constexpr float kDriveSlow = 0.6;
constexpr float kTurnSpeed = 0.8;
constexpr bool kIsArcadeDrive = true;

constexpr units::meter_t kWheelDiameter = 6_in;

constexpr float kDistancePerTick =
    (kWheelDiameter.value() * pi) / (2048.0 * 10.714);
} // namespace drive
namespace shooter { 
constexpr int kLeftShooter =   8;
constexpr int kRightShooter = 14;

constexpr float kShooterP = 6e-5;
constexpr float kShooterI =  1e-6;
constexpr float kShooterD = 0;
constexpr float kShooterFF = 0.000015;
constexpr float kShooterIZ = 0;
constexpr float kMaxOutput = 1.0;
constexpr float kMinOutput = -1.0;


constexpr float kMaxRPM = 5700;
/*constexpr int kArmLeft = 6;
constexpr int kArmRight = 5;
constexpr float kIntakeSpeed = 0.2;
constexpr float kArmSpeed = 0.5;

constexpr float kArmExtPos = -25;
constexpr float kCloseEnough = 5;*/
} // namespace arm
namespace climber { 
    constexpr int kLeftClimber = 16;
    constexpr int kRightClimber = 17;

    constexpr float kClimberP = 0.045999;
    constexpr float kClimberI =  0.0000001;
    constexpr float kClimberD = 0.25;
    constexpr float kClimberFF = 0.0000914999;
    constexpr float kClimberIZ = 0;
    constexpr float kClimberMaxOutput = 0.3;
    constexpr float kClimberMinOutput = -0.3;
}
namespace angle { 
    constexpr int kLeftAngle = 13;
    constexpr int kRightAngle = 15; 

    constexpr float kAngleP = 0.045999;
    constexpr float kAngleI =  0.0000001;
    constexpr float kAngleD = 0.25;
    constexpr float kAngleFF = 0.0000914999;
    constexpr float kAngleIZ = 0;
    constexpr float kAngleMaxOutput = 0.25;
    constexpr float kAngleMinOutput = -0.25;
}
namespace intake { 
    constexpr int kSpinIntake = 12;
    constexpr int kRotateIntake = 11;
    
    constexpr float kIntakeP = 0.045999;
    constexpr float kIntakeI =  0.0000001;
    constexpr float kIntakeD = 0.25;
    constexpr float kIntakeFF = 0.0000914999;
    constexpr float kIntakeIZ = 0;
    constexpr float kIntakeMaxOutput = 0.45;
    constexpr float kIntakeMinOutput = -0.45;
}
} // namespace constants