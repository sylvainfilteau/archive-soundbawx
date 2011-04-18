/*! \file Tools.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Entête de la classe CTools
 */
#pragma once

/*! \brief Classe utilitaire
 *
 * Classe qui contient des méthodes utilitaires pour obtenir des valeurs
 * à partir d'un travail de conversion.
 */
class CTools
{
public:
	//! \brief Méthode qui compare deux strings pour retourner vrai si elles sont pareil.
	int StringComparer(char*, char*, int);
	//! \brief Convertit des millisecondes en nombre d'échantillons.
	int MsToNbSamples(int, int);
	//! \brief Retourne un nombre d'échantillon par cycle par rapport à la vitesse du son et la frequence.
	int NbEchantillonsParCycle(float vitesse, float frequence);
	//! \brief Retourne le résultat d'un son mixer à un pourcentage donnée avec un autre son.
	short Mixer(short son1, short son2, float mix);
	//! \brief Copie le son dans un autre vecteur.
	void SoundCopier(short *orig, short *copie, int longueur);
};
