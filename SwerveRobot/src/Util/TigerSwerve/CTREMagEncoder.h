#ifndef SRC_CTREMAGENCODER_H_
#define SRC_CTREMAGENCODER_H_
#include "../Math/Rotation2D.h"
#include "ctre/Phoenix.h"
#include <string>
#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"

using namespace ctre::phoenix::motorcontrol;

class CTREMagEncoder {
private:
	can::WPI_TalonSRX* m_talon;
	std::string m_name;
	std::string m_calibrationKey;
	Rotation2D m_offset;
public:
	CTREMagEncoder(can::WPI_TalonSRX *talon);
	virtual ~CTREMagEncoder();
	Rotation2D GetRawAngle() const;
	Rotation2D GetAngle() const;
	int GetRotations() const;
	int GetEncoderTicks(bool overflow = false) const;
	void Calibrate();
	int ConvertAngleToSetpoint(Rotation2D targetAngle);
	int ConvertAngleToEncoderTicks(Rotation2D angle);
	void SetEncoderRaw(int ticks);


};

#endif /* SRC_CTREMAGENCODER_H_ */
