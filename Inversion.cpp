/*! \file Inversion.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Corp de la classe CInversion
 */
#include "inversion.h"

CInversion::CInversion(CWAVE *son) : CEffet(son){}

void CInversion::Inverser()
{
	short shttmp = 0;
	
	m_son->Backup();

    for (int i = 0; i < m_son->getNbEchantillon() / 2; i++)
	{
		shttmp = m_son->getCanalGauche()[i];
		m_son->getCanalGauche()[i] = m_son->getCanalGauche()[m_son->getNbEchantillon() - i];
		m_son->getCanalGauche()[m_son->getNbEchantillon() - i] = shttmp;

		if (m_son->Stereo())
		{
			shttmp = m_son->getCanalDroite()[i];
			m_son->getCanalDroite()[i] = m_son->getCanalDroite()[m_son->getNbEchantillon() - i];
			m_son->getCanalDroite()[m_son->getNbEchantillon() - i] = shttmp;
		}
	}
}