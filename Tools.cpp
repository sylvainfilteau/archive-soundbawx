/*! \file Tools.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.5
 *
 * \brief Corp de la classe CTools
 */
#include "tools.h"

// Fonction de comparaison de deux chaînes de caractères
int CTools::StringComparer( char *string1, char *string2, int nbChar )
{
	for( int i = 0; i < nbChar; i++ )
	{
		if( string1[i] != string2[i] )
		{
			return 0;
		}
	}

	return 1;
}

int CTools::MsToNbSamples(int ms, int debit)
{
		return ms / 1000 * debit;
}

int CTools::NbEchantillonsParCycle(float vitesse, float frequence)
{
	return (frequence/((1/vitesse)*1000));
}

short CTools::Mixer(short son1, short son2, float mix)
{
	return ((1-mix) * son1) + (mix * son2);
}