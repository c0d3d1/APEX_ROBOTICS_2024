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
constexpr int kLeftShooter = 11;
constexpr int kRightShooter = 12;
constexpr int kSpinIntake = 7;
constexpr int kRotateIntake = 8;

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
} // namespace constants