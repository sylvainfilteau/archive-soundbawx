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
	CVibrato(CWAVE *son);
	/*! \brief M�thode qui ex�cute l'effet sur le son.
	 *
	 * @param frequence Vitesse du cycle d'une vibration.
	 * @param mix Pourcentage du mix de l'effet avec le son original.
	 */
	void Vibrer(float frequence, float mix);
};
