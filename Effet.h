#pragma once
#include "WAVE.h"

/*! \brief Classe de base de tout les effets.
 *
 * Cette classe est h�rit� par toutes les classes
 * d'effets. Elle ne prend en charge que le son lui m�me.
 */
class CEffet
{
public:
	/*! \brief Constructeur de la classe.
	 *
	 * @param son Le son o� sera appliqu� l'effet.
	 */
	CEffet(CWAVE *son);
	/*! \brief Destructeur de la classe */
	~CEffet(void);
protected:
	CWAVE *m_son;
};
