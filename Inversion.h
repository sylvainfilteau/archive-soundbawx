#pragma once
#include "wave.h"
#include "effet.h"


/*! \brief Classe d'effet d'inversion
 *
 * @see CWAVE
 *
 * Classe qui inverse un son wave contenu dans
 * la classe CWAVE.
 */
class CInversion :
	public CEffet
{
public:
	/*! \brief Constructeur de la classe
	 *
	 * @param son Le son à appliquer l'effet
	 */
	CInversion(CWAVE *son);
	/*! \brief Méthode qui applique l'inversion au son.
	 *
	 * Pour chaque valeur du son, on inverse sa valeur avec
	 * sa correspondante inverse après la moitié du son.
	 */
	void Inverser();
};
