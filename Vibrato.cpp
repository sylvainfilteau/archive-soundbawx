#include "vibrato.h"
#include "LFO.h"

CVibrato::CVibrato(CWAVE *son)
{
	m_son = son;
}

CVibrato::~CVibrato(void)
{
}

void CVibrato::Vibrer(float frequence, float mix)
{
	CLFO *lfo = new CLFO(LFOSIN, (int)frequence);
	int *intCanalG = m_son->getCanalGauche();
	int *intCanalD = m_son->getCanalDroite();
	float tmpLfo;

	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		tmpLfo = lfo->getNextValeur();
		intCanalG[i] = (int)((intCanalG[i] * ((float)1.00 - mix)) + (intCanalG[i] * mix * tmpLfo));
		
		if (m_son->Entete().NumChannels == 2)
		{
			intCanalD[i] = (int)((intCanalD[i] * ((float)1.00 - mix)) + (intCanalD[i] * mix * tmpLfo));
		}
	}

	delete lfo;
}
