#pragma once
#include "WAVE.h"

class CVibrato
{
public:
	CVibrato(CWAVE *son);
	~CVibrato(void);
	void Vibrer(float frequence, float mix);
private:
	CWAVE *m_son;
};
