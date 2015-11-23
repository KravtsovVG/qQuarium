#include "BeepHelper.h"

BeepHelper* BeepHelper::m_pInstance = NULL;
BeepHelper* BeepHelper::Instance()
{
	if (!m_pInstance)
		m_pInstance = new BeepHelper;

	return m_pInstance;
}

void BeepHelper::beep(int freq, unsigned long duration)
{
	unsigned long start;
	// ���������� ������ ������ ����������
	start = millis();

	// � ������� duration ����������� �����
	while (millis() - start < duration) {
		// ������� ����� ������������ ������� ����� ����������� ��������� ����
		digitalWrite(BeepPinNum, HIGH);
		delay(1000 / freq / 2);
		digitalWrite(BeepPinNum, LOW);
		delay(1000 / freq / 2);
	}

}
void BeepHelper::setup(uint8_t beepPinNum)
{
	BeepPinNum = beepPinNum;
	// ��������� ��� � �����
	pinMode(BeepPinNum, OUTPUT);

}