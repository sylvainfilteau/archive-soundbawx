/*! \file Tools.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Ent�te de la classe CTools
 */
#pragma once

/*! \brief Classe utilitaire
 *
 * Classe qui contient des m�thodes utilitaires pour obtenir des valeurs
 * � partir d'un travail de conversion.
 */
class CTools
{
public:
	//! \brief M�thode qui compare deux strings pour retourner vrai si elles sont pareil.
	int StringComparer(char*, char*, int);
	//! \brief Convertit des millisecondes en nombre d'�chantillons.
	int MsToNbSamples(int, int);
	//! \brief Retourne un nombre d'�chantillon par cycle par rapport � la vitesse du son et la frequence.
	int NbEchantillonsParCycle(float vitesse, float frequence);
	//! \brief Retourne le r�sultat d'un son mixer � un pourcentage donn�e avec un autre son.
	short Mixer(short son1, short son2, float mix);
	//! \brief Copie le son dans un autre vecteur.
	void SoundCopier(short *orig, short *copie, int longueur);
};
