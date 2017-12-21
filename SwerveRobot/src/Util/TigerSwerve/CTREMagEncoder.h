#ifndef SRC_CTREMAGENCODER_H_
#define SRC_CTREMAGENCODER_H_
#include "../Math/Rotation2D.h"
#include "ctrlib/CANTalon.h"
#include <string>

class CTREMagEncoder {
private:
	CANTalon* m_talon;
	std::string m_name;
	std::string m_calibrationKey;
	Rotation2D m_offset;
public:
	CTREMagEncoder(CANTalon *talon);
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
