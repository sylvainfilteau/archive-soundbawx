#include "distorsion.h"

CDistorsion::CDistorsion(CWAVE *son): CEffet(son)
{
}

void CDistorsion::Distorsionner(int valmultiplie)
{
	int maxgauche = 0;
	int maxdroite = 0;
	
	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		if (m_son->getCanalGauche()[i] > maxgauche)
			maxgauche = m_son->getCanalGauche()[i];

		if (m_son->Entete().NumChannels == 2 && m_son->getCanalDroite()[i] > maxdroite)
			maxdroite = m_son->getCanalDroite()[i];
	}

	for (int i = 0; i < m_son->getNbEchantillon(); i++)
	{
		if ((m_son->getCanalGauche()[i] * valmultiplie) > maxgauche)
			m_son->getCanalGauche()[i] = maxgauche;
		else
			m_son->getCanalGauche()[i] = m_son->getCanalGauche()[i] * valmultiplie;

		if (m_son->Entete().NumChannels == 2 && (m_son->getCanalDroite()[i] * valmultiplie) > maxdroite)
			m_son->getCanalDroite()[i] = maxdroite;
		else
			m_son->getCanalDroite()[i] = m_son->getCanalDroite()[i] * valmultiplie;
	}

}