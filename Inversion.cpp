#include "inversion.h"

CInversion::CInversion(CWAVE* son)
{
	m_son = son;
}

void CInversion::Inverser()
{
	int *intCanalGauche = m_son->getCanalGauche();
	int *intCanalDroite = m_son->getCanalDroite();
	int inttmp = 0;
	
    for (int i = 0; i < m_son->getNbEchantillon() / 2; i++)
	{
		inttmp = intCanalGauche[i];
		intCanalGauche[i] = intCanalGauche[m_son->getNbEchantillon() - i];
		intCanalGauche[m_son->getNbEchantillon() - i] = inttmp;
	}

	if (m_son->Entete().NumChannels == 2)
	{	
		for (int i = 0; i < m_son->getNbEchantillon() / 2; i++)
		{
			inttmp = intCanalDroite[i];
			intCanalDroite[i] = intCanalDroite[m_son->getNbEchantillon() - i];
			intCanalDroite[m_son->getNbEchantillon() - i] = inttmp;
		}
	}
}

CInversion::~CInversion(void)
{
}
