#include <sstream>
#include "CTREMagEncoder.h"
#include <WPILib.h>
#include <iostream>

CTREMagEncoder::CTREMagEncoder(can::WPI_TalonSRX* talon) : m_talon(talon) {
}

CTREMagEncoder::~CTREMagEncoder() {
	// TODO Auto-generated destructor stub
}

Rotation2D CTREMagEncoder::GetRawAngle() const {
	return Rotation2D::fromRadians(GetEncoderTicks(false) / 4096.0 * 2 * M_PI);

}

Rotation2D CTREMagEncoder::GetAngle() const {
	return m_offset.rotateBy(GetRawAngle());
}

int CTREMagEncoder::GetRotations() const {
	return GetEncoderTicks(true) / 4096;
}

int CTREMagEncoder::GetEncoderTicks(bool overflow) const {
	int ticks = m_talon->GetSensorCollection().GetQuadraturePosition();
	ticks = ticks * -1; //negative b/c Pulse Width Position doesn't
				 //take sensor direction into account
	if (!overflow) {
		ticks = ticks & 0xFFF;
	}
	return ticks;
}

void CTREMagEncoder::Calibrate() {
	m_offset = GetRawAngle().inverse();
	Preferences::GetInstance()->PutDouble(m_calibrationKey, m_offset.getDegrees());
}

int CTREMagEncoder::ConvertAngleToSetpoint(Rotation2D targetAngle) {
	Rotation2D angle = targetAngle.rotateBy(m_offset);
	int ticks = ConvertAngleToEncoderTicks(angle); // 0 - 4096

	int encoderTicks = GetEncoderTicks(true);
	ticks = ticks + (encoderTicks/4096)*4096; //Add ticks equivalent to full rotations on encoder.

	int error = encoderTicks - ticks;

	// Ensure the movement is <= 180 deg (2048 encoder ticks)
	if (error < -2048) {
		ticks = ticks - 4096;
	}
	else if (error > 2048) {
		ticks = ticks + 4096;
	}

	return ticks;
}

int CTREMagEncoder::ConvertAngleToEncoderTicks(Rotation2D angle) {
	double degrees = angle.getDegrees();
	int ticks = degrees / 360.0 * 4096;
	return ticks;
}

void CTREMagEncoder::SetEncoderRaw(int ticks) {
	m_talon->GetSensorCollection().SetPulseWidthPosition(ticks, 0);
}
