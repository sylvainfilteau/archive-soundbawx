#pragma once
#include "WAVE.h"

/*! \brief Classe de base de tout les effets.
 *
 * Cette classe est hérité par toutes les classes
 * d'effets. Elle ne prend en charge que le son lui même.
 */
class CEffet
{
public:
	/*! \brief Constructeur de la classe.
	 *
	 * @param son Le son où sera appliqué l'effet.
	 */
	CEffet(CWAVE *son);
	/*! \brief Destructeur de la classe */
	~CEffet(void);
protected:
	CWAVE *m_son;
};
