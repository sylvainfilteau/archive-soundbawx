#pragma once
#include "WAVE.h"
#include "effet.h"

/*! \brief Classe d'effet Vibrato.
 *
 * @see CWAVE
 *
 * La classe génère un effet de type vibrato sur un son. Un
 * effet vibrato est similaire à une personne qui monte et baisse
 * le son de façon très rapide et régulière.
 */
class CVibrato :
	public CEffet
{
public:
	CVibrato(CWAVE *son);
	/*! \brief Méthode qui exécute l'effet sur le son.
	 *
	 * @param frequence Vitesse du cycle d'une vibration.
	 * @param mix Pourcentage du mix de l'effet avec le son original.
	 */
	void Vibrer(float frequence, float mix);
};
