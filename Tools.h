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
	//! \brief Convertit des millisecondes en Nombre de samples.
	int MsToNbSamples(int, int);
	//! \brief Retourne un nombre d'échantillon par cycle par rapport à la vitesse du son et la frequence.
	int NbEchantillonsParCycle(float vitesse, float frequence);
};
