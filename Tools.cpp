/*! \file Tools.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
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

void SoundCopier( short *orig, short *copie, int longueur)
{
	for (int i = 0; i < longueur; i++)
	{
		copie[i] = orig[i];
	}
}

int CTools::MsToNbSamples(int ms, int debit)
{
		return ms / 1000 * debit;
}

int CTools::NbEchantillonsParCycle(float vitesse, float frequence)
{
	return (int)(frequence/((1/vitesse)*1000));
}

short CTools::Mixer(short son1, short son2, float mix)
{
	return (short)((1-mix) * son1) + (mix * son2);
}