#include "inversion.h"

CInversion::CInversion(CWAVE* son)
{
	m_son = son;
}

void CInversion::Inverser()
{
	int intGrandeurVec = m_son->Entete().Subchunk2Size/m_son->Entete().NumChannels;
	int *intCanalDroite = new int[intGrandeurVec];
	int *intCanalGauche;
	
    for (int i = 0; i < intGrandeurVec; i++)
	{
		intCanalDroite[i] = m_son->getCanalDroite()[intGrandeurVec - i];
	}
	m_son->setCanalDroite(intCanalDroite);
	//delete[] intCanalDroite;

	if (m_son->Entete().NumChannels == 2)
	{
		intCanalGauche = new int[intGrandeurVec];
	
		for (int i = 0; i < intGrandeurVec; i++)
		{
			intCanalGauche[i] = m_son->getCanalGauche()[intGrandeurVec - i];
		}
		m_son->setCanalGauche(intCanalGauche);
		//delete[] intCanalGauche;
	}
}

CInversion::~CInversion(void)
{
}
