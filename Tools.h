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
	//! \brief Convertit des millisecondes en Nombre de samples.
	int MsToNbSamples(int, int);
	//! \brief Retourne un nombre d'�chantillon par cycle par rapport � la vitesse du son et la frequence.
	int NbEchantillonsParCycle(float vitesse, float frequence);
};
