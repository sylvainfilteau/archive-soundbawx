/*! \file LFO.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Corp de la classe CLFO
 */
#include "lfo.h"
#include "math.h"
#define _PI 3.141593

CLFO::CLFO(int intlfoType, int intphase)
{
	m_intlfoType = intlfoType;
	m_intphase = intphase;
	m_fltvaleurs = new float[intphase];
	Reset();

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

float CLFO::getNextValeur()
{
	if (m_intposition >= m_intphase) m_intposition = 0;
	return m_fltvaleurs[m_intposition++];
}

void CLFO::Reset()
{
	m_intposition = 0;
}

// Mise à jour, la fonction prenait toujours la nouvelle valeur
// qui n'était pas encore sortie.
float CLFO::getCurrentValue()
{
	return m_fltvaleurs[m_intposition - 1];
}

int CLFO::getLfoType()
{
	return m_intlfoType;
}

int CLFO::getPhase()
{
	return m_intphase;
}