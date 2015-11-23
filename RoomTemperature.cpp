#include "RoomTemperature.h"
#include "ClockHelper.h"
#include "LedRgbHelper.h"

RoomTemperature* RoomTemperature::m_pInstance = NULL;
RoomTemperature* RoomTemperature::Instance()
{
	if (!m_pInstance)
		m_pInstance = new RoomTemperature;

	return m_pInstance;
}

void RoomTemperature::setup(uint8_t sensorPinNum)
{
	SensorPinNum = sensorPinNum;
}

void RoomTemperature::loop()
{
	if (!ClockHelper::Instance()->isUpdatedByTimer)
	{
		ReadTemperature();
	}
}

void RoomTemperature::ReadTemperature()
{
	int chk;

	// ���������� ������
	chk = DHT.read(SensorPinNum);    // ������ ������
	switch (chk){
	case DHTLIB_OK:
		break;
	case DHTLIB_ERROR_CHECKSUM:
		Serial.println("Checksum error, \t");
		break;
	case DHTLIB_ERROR_TIMEOUT:
		Serial.println("Time out error, \t");
		break;
	default:
		Serial.println("Unknown error, \t");
		break;
	}

	// ������� ��������� ��������� � �����������
	TempAnalog = DHT.temperature;
	HumidityAnalog = DHT.humidity;
	
}

String RoomTemperature::GetTemperatureText()
{
	String retVal = String(TempAnalog);

	return retVal;
};


String RoomTemperature::GetHumidityText()
{
	String retVal = String(HumidityAnalog);

	return retVal;
};