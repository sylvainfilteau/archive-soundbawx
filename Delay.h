/*! \file Delay.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.5
 *
 * \brief Ent�te de la classe CDelay
 */
#pragma once
#include "effet.h"

/*! \brief Classe qui g�n�re un effet de d�lais (echo)
 *
 * Cette classe g�n�re un effet de d�lais (echo) � partir des param�tres
 * suivants: le temps de d�lais (en ms), le nombre de feedback et le
 * pourcentage de mix.
 */
class CDelay :
	public CEffet
{
public:
	/*! \brief Constructeur de la classe.
	 *
	 * @param son Le son � appliquer l'effet.
	 */
	CDelay(CWAVE *son);
	/*! \brief M�thode qui applique un effet de d�lais.
	 *
	 * @param ms Le nombre de milliseconde � attendre avant de r�p�ter le son.
	 * @param feedback Le pourcentage de r�duction du son � chaque r�p�tition.
	 * @param mix Le pourcentage de mix avec le son original.
	 * @return Vrai si la m�thode a r�ussi.
	 *
	 * @todo Commencer et compl�ter l'effet ;)
	 *
	 * Cette m�thode applique au son un effet de d�lais. Un effet de d�lais est
	 * un effet d'�cho. On r�p�te le son apr�s un nombre x de milliseconde et
	 * ce nouveau son est mixer avec le son original. � chaque r�p�tition,
	 * la r�p�tition baisse en volume.
	 */
	int AppliquerDelais(int ms, float feedback, float mix);
};
