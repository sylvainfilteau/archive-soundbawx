#include "vibrato.h"
#include "LFO.h"
#include "Tools.h"

CVibrato::CVibrato(CWAVE *son) : CEffet(son)
{
}

void CVibrato::Vibrer(float frequence, float mix)
{
	CTools tool;
	CLFO *lfo = new CLFO(LFOSIN, tool.NbEchantillonsParCycle(frequence, m_son->Entete().SampleRate));
	short *shtCanalG = m_son->getCanalGauche();
	short *shtCanalD = m_son->getCanalDroite();
	float tmpLfo;

	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		tmpLfo = lfo->getNextValeur();
		if (tmpLfo != 1)
		{
			shtCanalG[i] = tool.Mixer(shtCanalG[i], shtCanalG[i] * tmpLfo, mix);
			
			if (m_son->Entete().NumChannels == 2)
			{
				shtCanalD[i] = tool.Mixer(shtCanalD[i], shtCanalD[i] * tmpLfo, mix);
			}
		}
	}

	delete lfo;
}
