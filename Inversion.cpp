#include "inversion.h"

CInversion::CInversion(CWAVE *son) : CEffet(son)
{
}

void CInversion::Inverser()
{
	short *shtCanalGauche = m_son->getCanalGauche();
	short *shtCanalDroite = m_son->getCanalDroite();
	short shttmp = 0;
	
    for (int i = 0; i < m_son->getNbEchantillon() / 2; i++)
	{
		shttmp = shtCanalGauche[i];
		shtCanalGauche[i] = shtCanalGauche[m_son->getNbEchantillon() - i];
		shtCanalGauche[m_son->getNbEchantillon() - i] = shttmp;

		if (m_son->Entete().NumChannels == 2)
		{
			shttmp = shtCanalDroite[i];
			shtCanalDroite[i] = shtCanalDroite[m_son->getNbEchantillon() - i];
			shtCanalDroite[m_son->getNbEchantillon() - i] = shttmp;
		}
	}
}