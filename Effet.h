/*! \file Effet.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Ent�te de la classe CEffet
 */
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
	CWAVE *m_son; //!< Source du son o� sera appliqu� l'effet
};
