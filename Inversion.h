#pragma once
#include "wave.h"

class CInversion
{
public:
	CInversion(CWAVE* son);
	void Inverser();
	~CInversion(void);
private:
	CWAVE* m_son;
};
