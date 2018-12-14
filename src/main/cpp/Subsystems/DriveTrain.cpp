/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/DriveTrain.h"

#include "RobotMap.h"
#include "Commands/TankDrive.h"
#include "iostream"
using namespace std;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem"), left(new TalonSRX(kLeftMotor)),
 right(new TalonSRX(kRightMotor)), us(new Ultrasonic(0, 1)) {
  left->SetInverted(true);
  us->SetAutomaticMode(true);
}

void DriveTrain::InitDefaultCommand()
{
  SetDefaultCommand(new TankDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::tankDrive(double leftVal, double rightVal) {
	left->Set(ControlMode::PercentOutput, leftVal);
	right->Set(ControlMode::PercentOutput, rightVal);
}

double DriveTrain::getDistanceUltrasonic() {
	return us->GetRangeInches();
}

