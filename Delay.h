/*! \file Delay.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.5
 *
 * \brief Entête de la classe CDelay
 */
#pragma once
#include "effet.h"

/*! \brief Classe qui génère un effet de délais (echo)
 *
 * Cette classe génère un effet de délais (echo) à partir des paramètres
 * suivants: le temps de délais (en ms), le nombre de feedback et le
 * pourcentage de mix.
 */
class CDelay :
	public CEffet
{
public:
	/*! \brief Constructeur de la classe.
	 *
	 * @param son Le son à appliquer l'effet.
	 */
	CDelay(CWAVE *son);
	/*! \brief Méthode qui applique un effet de délais.
	 *
	 * @param ms Le nombre de milliseconde à attendre avant de répéter le son.
	 * @param feedback Le pourcentage de réduction du son à chaque répétition.
	 * @param mix Le pourcentage de mix avec le son original.
	 * @return Vrai si la méthode a réussi.
	 *
	 * @todo Commencer et compléter l'effet ;)
	 *
	 * Cette méthode applique au son un effet de délais. Un effet de délais est
	 * un effet d'écho. On répète le son après un nombre x de milliseconde et
	 * ce nouveau son est mixer avec le son original. À chaque répétition,
	 * la répétition baisse en volume.
	 */
	int AppliquerDelais(int ms, float feedback, float mix);
};
