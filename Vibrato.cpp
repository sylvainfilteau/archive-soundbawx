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
		if (tmpLfo != 1)
		{
			intCanalG[i] = (short)((1-mix)*intCanalG[i]) + (short)(intCanalG[i] * tmpLfo * mix);
			
			if (m_son->Entete().NumChannels == 2)
			{
				intCanalD[i] = (short)((1-mix)*intCanalD[i]) + (short)(intCanalD[i] * tmpLfo * mix);
			}
		}
	}

	//delete lfo;
}
