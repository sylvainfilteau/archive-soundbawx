/*! \file Vibrato.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Entête de la classe CVibrato
 */
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
	/*! \brief Constructeur de la classe
	 *
	 * @param son Le son à appliquer l'effet
	 */
	CVibrato(CWAVE *son);
	/*! \brief Méthode qui exécute l'effet sur le son.
	 *
	 * @param frequence Vitesse du cycle d'une vibration.
	 * @param mix Pourcentage du mix de l'effet avec le son original.
	 * @return Vrai si la méthode a réussi
	 */
	int Vibrer(float frequence, float mix);
};
