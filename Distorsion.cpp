/*! \file Distorsion.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Corp de la classe CDistorsion
 */
#include "distorsion.h"

CDistorsion::CDistorsion(CWAVE *son): CEffet(son){}

void CDistorsion::Distorsionner(int valmultiplie)
{
	short maxgauche = 0;
	short maxdroite = 0;

	short mingauche = 0;
	short mindroite = 0;
	

	// Vérification des valeurs maximales et minimales pour les deux canaux
	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		if (m_son->getCanalGauche()[i] > maxgauche)
			maxgauche = m_son->getCanalGauche()[i];
		else if (m_son->getCanalGauche()[i] < mingauche)
			mingauche = m_son->getCanalGauche()[i];

		if (m_son->Stereo() && m_son->getCanalDroite()[i] > maxdroite)
			mindroite = m_son->getCanalDroite()[i];
		else if (m_son->getCanalDroite()[i] < mindroite)
			mindroite = m_son->getCanalDroite()[i];
	}

	m_son->Backup();

	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		if ((m_son->getCanalGauche()[i] * valmultiplie) > maxgauche && (m_son->getCanalGauche()[i] * valmultiplie) > 0)
			m_son->getCanalGauche()[i] = maxgauche;
		else if ((m_son->getCanalGauche()[i] * valmultiplie) < mingauche && (m_son->getCanalGauche()[i] * valmultiplie) < 0)
			m_son->getCanalGauche()[i] = mingauche;
		else
			m_son->getCanalGauche()[i] = m_son->getCanalGauche()[i] * valmultiplie;

		if (m_son->Stereo())
		{
			if ((m_son->getCanalDroite()[i] * valmultiplie) > maxdroite && (m_son->getCanalDroite()[i] * valmultiplie) > 0)
				m_son->getCanalDroite()[i] = maxdroite;
			else if ((m_son->getCanalDroite()[i] * valmultiplie) < mindroite && (m_son->getCanalDroite()[i] * valmultiplie) < 0)
				m_son->getCanalGauche()[i] = mingauche;
			else
				m_son->getCanalDroite()[i] = m_son->getCanalDroite()[i] * valmultiplie;
		}
	}

}