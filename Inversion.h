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
	CInversion(CWAVE *son);
	/*! \brief M�thode qui applique l'inversion au son.
	 *
	 * Pour chaque valeur du son, on inverse sa valeur avec
	 * sa correspondante inverse apr�s la moiti� du son.
	 */
	void Inverser();
};
