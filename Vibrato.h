/*! \file Vibrato.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Ent�te de la classe CVibrato
 */
#pragma once
#include "WAVE.h"
#include "effet.h"

/*! \brief Classe d'effet Vibrato.
 *
 * @see CWAVE
 *
 * La classe g�n�re un effet de type vibrato sur un son. Un
 * effet vibrato est similaire � une personne qui monte et baisse
 * le son de fa�on tr�s rapide et r�guli�re.
 */
class CVibrato :
	public CEffet
{
public:
	/*! \brief Constructeur de la classe
	 *
	 * @param son Le son � appliquer l'effet
	 */
	CVibrato(CWAVE *son);
	/*! \brief M�thode qui ex�cute l'effet sur le son.
	 *
	 * @param frequence Vitesse du cycle d'une vibration.
	 * @param mix Pourcentage du mix de l'effet avec le son original.
	 * @return Vrai si la m�thode a r�ussi
	 */
	int Vibrer(float frequence, float mix);
};
