#pragma once

class CTools
{
public:
	CTools(void);
	~CTools(void);
	int StringComparer(char*, char*, int);
	int MsToNbSamples(int, int);
	int NbEchantillonsParCycle(float vitesse, float frequence);
};
