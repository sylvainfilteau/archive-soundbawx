#include "vibrato.h"
#include "LFO.h"
#include "Tools.h"

CVibrato::CVibrato(CWAVE *son) : CEffet(son){}

int CVibrato::Vibrer(float frequence, float mix)
{
	CTools tool;
	CLFO *lfo;
	int ret = 0;

	// Vérification de la valeur de mix, elle ne peut pas être plus
	// grande que 1 et plus petite que 0;
	if (mix >= 0 && mix <= 1)
	{
		lfo = new CLFO(LFOSIN, tool.NbEchantillonsParCycle(frequence, m_son->Entete().SampleRate));

		if (m_son->Backup())
		{
			for (int i = 0; i < m_son->getNbEchantillon(); i++)
			{
				m_son->getCanalGauche()[i] = tool.Mixer(m_son->getCanalGauche()[i], 
					m_son->getCanalGauche()[i] * lfo->getNextValeur(), mix);
				
				if (m_son->Entete().NumChannels == 2)
				{
					m_son->getCanalDroite()[i] = tool.Mixer(m_son->getCanalDroite()[i], 
						m_son->getCanalDroite()[i] * lfo->getCurrentValue(), mix);
				}
			}
			ret = 1;
		}

		delete lfo;
	}

	return ret;
}
