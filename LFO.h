#pragma once

const int LFOSIN = 1;
const int LFOTRIANGLE = 2;

class CLFO
{
public:
	CLFO(int intlfoType, int intphase);
	~CLFO(void);
	int getPhase();
	int getLfoType();
	float getNextValeur();
private:
	void Sinus(void);
	void Triangle(void);
	int m_intlfoType;
	int m_intphase;
	float* m_fltvaleurs;
};
