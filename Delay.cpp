/*! \file Delay.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.1
 *
 * \brief Corp de la classe CDelay
 */
#include "delay.h"

// Constructeur de la classe
CDelay::CDelay(CWAVE *son) : CEffet(son){}

// Méthode qui applique l'effet au son.
int CDelay::AppliquerDelais(int ms, float feedback, float mix)
{
	int ret = 0;
	short tmpCanalGauche;
	short tmpCanalDroite;
	int nbRepetition = 1;

	// Vérification des paramètres
	if (ms > 0 && feedback >= 0 && feedback <= 1 && mix <= 0 && mix >= 1)
	{
		tmpCanalGauche = new short[m_son->getNbEchantillon()];
		if (m_son->Stereo())
			tmpCanalDroite = new short[m_son->getNbEchantillon()];

		m_son->Backup();
	}

	return ret;
}