#include "tools.h"

// Fonction de comparaison de deux cha�nes de caract�res
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