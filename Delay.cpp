#include "delay.h"

CDelay::CDelay(CWAVE *son) : CEffet(son){}

int CDelay::AppliquerDelais(int ms, float feedback, float mix)
{
	m_son->Backup();
	return 0;
}