#include "lfo.h"
#include "math.h"
#define _PI 3.141593

CLFO::CLFO(int intlfoType, int intphase)
{
	m_intlfoType = intlfoType;
	m_intphase = intphase;
	m_fltvaleurs = new float[intphase];

	// Selon le type, on calcul la courbe avec la fonction requise
	switch (intlfoType)
	{
		case LFOSIN:
			Sinus();
			break;
		case LFOTRIANGLE:
			Triangle();
			break;
	}
}

CLFO::~CLFO(void)
{
	delete [] m_fltvaleurs;
}

// Crée un Sinus déphasé
void CLFO::Sinus()
{
	for (int i = 0; i < m_intphase; i++)
	{
		m_fltvaleurs[i] = cos(i * 2 * _PI / m_intphase) / 2 + 0.5;
	}
}

// Crée une courbe triangle
void CLFO::Triangle()
{
	float val = 0;
	for (int i = 0; i < m_intphase; i++)
	{
		// si la position du compteur a dépassé la moitié de
		// la phase, on inverse la courbe.
		if (i <= m_intphase/2)
		{
			val = (-1 / ((float) (m_intphase / 2))) * i + 1;
		}
		else
		{
			val = m_fltvaleurs[(m_intphase/2)-(i - (m_intphase/2))];
		}
		m_fltvaleurs[i] = val;
	}
}
int intposition;
float CLFO::getNextValeur()
{
	if (intposition > m_intphase) intposition = 0;
	return m_fltvaleurs[intposition++];
}

int CLFO::getLfoType()
{
	return m_intlfoType;
}

int CLFO::getPhase()
{
	return m_intphase;
}