#pragma once
#include "effet.h"

/*! \brief Classe d'effet de distorsion
 *
 * Cette classe applique un effet de distorsion � un son CWAVE.
 */
class CDistorsion :
	public CEffet
{
public:
	/*! \brief Constructeur de la classe
	 *
	 * @param son Le son o� sera apploqu� l'effet de distorsion
	 */
	CDistorsion(CWAVE *son);
	/*! \brief M�thode qui appliquera l'effet au son
	 *
	 * @param valmultiplie Valeur de multiplication du chacunes des valeurs du son.
	 *
	 * On multiplie chacunes des valeurs du son et on coupe le son � la
	 * valeur maximum du son initiale.
	 */
	void Distorsionner(int valmultiplie);
};
