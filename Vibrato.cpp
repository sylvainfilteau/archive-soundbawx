#include "vibrato.h"
#include "LFO.h"
#include "Tools.h"

CVibrato::CVibrato(CWAVE *son)
{
	m_son = son;
}

CVibrato::~CVibrato(void)
{
}

void CVibrato::Vibrer(float frequence, float mix)
{
	CTools tool;
	CLFO *lfo = new CLFO(LFOSIN, tool.NbEchantillonsParCycle(frequence, m_son->Entete().SampleRate));
	int *intCanalG = m_son->getCanalGauche();
	int *intCanalD = m_son->getCanalDroite();
	float tmpLfo;

	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		tmpLfo = lfo->getNextValeur();
		intCanalG[i] = (int)((1-mix)*intCanalG[i]) + (int)(intCanalG[i] * tmpLfo * mix);
		
		if (m_son->Entete().NumChannels == 2)
		{
			intCanalD[i] = (int)((1-mix)*intCanalD[i]) + (int)(intCanalD[i] * tmpLfo * mix);
		}
	}

	//delete lfo;
}
