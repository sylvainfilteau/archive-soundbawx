/*! \file Delay.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.1
 *
 * \brief Corp de la classe CDelay
 */
#include "delay.h"
#include "Tools.h"
#include "Math.h"

// Constructeur de la classe
CDelay::CDelay(CWAVE *son) : CEffet(son){}

// Méthode qui applique l'effet au son.
int CDelay::AppliquerDelais(int ms, float feedback, float mix)
{
	int ret = 0;
	short *tmpCanalGauche;
	short *tmpCanalDroite;
	int nbRepetition = 1;
	int samples = (m_son->Entete().SampleRate/1000) * ms;
	CTools tools;

	// Vérification des paramètres
	if (ms > 0 && feedback >= 0 && feedback <= 1 && mix <= 0 && mix >= 1)
	{
		// Création des vecteurs de copie du son original.
		tmpCanalGauche = new short[m_son->getNbEchantillon()];
		tools.SoundCopier(m_son->getCanalGauche(), tmpCanalGauche, m_son->getNbEchantillon() - 1);
		if (m_son->Stereo())
		{
			tmpCanalDroite = new short[m_son->getNbEchantillon()];
			tools.SoundCopier(m_son->getCanalDroite(), tmpCanalDroite, m_son->getNbEchantillon());
		}

		// Backup du son
		m_son->Backup();

		// On applique l'effet
		while (nbRepetition * samples < m_son->getNbEchantillon())
		{
			for (int i = ((nbRepetition * samples) - 1); i < m_son->getNbEchantillon() - 1; i++)
			{
				m_son->getCanalGauche()[i] =
					tools.Mixer(m_son->getCanalGauche()[i], tmpCanalGauche[i]*(pow(nbRepetition, feedback)), mix);
				if (m_son->Stereo())
				{
					m_son->getCanalDroite()[i] =
						tools.Mixer(m_son->getCanalDroite()[i], tmpCanalDroite[i]*(pow(nbRepetition, feedback)), mix);
				}
			}
		}

		delete [] tmpCanalGauche;
		if (m_son->Stereo()) delete [] tmpCanalDroite;
	}

	return ret;
}