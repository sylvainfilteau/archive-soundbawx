#include "wave.h"
#include "Tools.h"
#include <stdio.h>
#include <windows.h>

CWAVE::CWAVE(char* strnomFichier)
{
	FILE* flux;
	int intnbPass = 0;
	BYTE bytvaleur = 0;
	CTools tools;

	flux = fopen(strnomFichier, "rb");

	if (flux != NULL)
	{
		fread(&m_entete, sizeof(WAVEHEADER), 1, flux);
		
		// vérification de l'entête du wave
		if (tools.StringComparer(m_entete.ChunkID, "RIFF", 4) && 
			tools.StringComparer(m_entete.Format, "WAVE", 4) &&  
			tools.StringComparer(m_entete.Subchunk1ID, "fmt ", 4) && 
			tools.StringComparer(m_entete.Subchunk2ID, "data", 4))
		{
			// initialisation des vecteurs qui contiennent le son
			if (m_entete.NumChannels == 1)
				m_intcanalGauche = new int[m_entete.Subchunk2Size];
			else
			{
				m_intcanalGauche = new int[m_entete.Subchunk2Size/2];
				m_intcanalDroite = new int[m_entete.Subchunk2Size/2];
			}				

			// Lecture du reste du fichier
			/*
			En 8 bits, les données sont stocké sur un unsigned short tandis que
			en 16 bits, c'est un signed int. Il faut donc faire une conversion
			à l'aide de la fonction ByteToInt
			*/
			for (int i = 0; i < m_entete.Subchunk2Size; i++)
			{
				if (m_entete.BitsPerSample == 16)
				{
					fread(&m_intcanalGauche[i], sizeof(int), 1, flux);
				}
				else if (m_entete.BitsPerSample == 8)
				{
					fread(&bytvaleur, sizeof(BYTE), 1, flux);
					m_intcanalGauche[i] = ByteToInt(bytvaleur);
				}
				if (m_entete.NumChannels == 2)
				{
					if (m_entete.BitsPerSample == 16)
					{
						fread(&m_intcanalDroite[i], sizeof(int), 1, flux);
					}
					else if (m_entete.BitsPerSample == 8)
					{
						fread(&bytvaleur, sizeof(BYTE), 1, flux);
						m_intcanalDroite[i] = ByteToInt(bytvaleur);
					}
				}
			}
		}
	}

	fclose(flux);

}

CWAVE::~CWAVE(void)
{
	delete[] m_intcanalDroite;
	delete[] m_intcanalGauche;
}

// Méthode d'enregistrement du son.
// si le paramètre = une chaîne vide, on enregistre le son par dessus l'autre son.
int CWAVE::Enregistrer(char *strnomFichier)
{
	int intcote = 0;
	int intvaleur = 0;
	FILE* flux;
	
	// Vérification du nom pour prendre celui de l'original
	// ou un nouveau nom
	if (strnomFichier == "")
		flux = fopen(m_strnomFichier, "wb");
	else
		flux = fopen(strnomFichier, "wb");

	// Vérification de la création du flux
	if (flux == NULL)
	{
		return 0;
	}
	else
	{
		fwrite(&m_entete, sizeof(WAVEHEADER), 1, flux);
		int intGrandeurVect = m_entete.Subchunk2Size/m_entete.NumChannels;
		for (int i = 0; i < intGrandeurVect; i++)
		{
			if (m_entete.BitsPerSample == 16)
			{
				fwrite(&m_intcanalGauche[i], sizeof(int), 1, flux);
			}
			else if (m_entete.BitsPerSample == 8)
			{
				intvaleur = IntToByte(m_intcanalGauche[i]);
				fwrite(&intvaleur, sizeof(BYTE), 1, flux);
			}
			if (m_entete.NumChannels == 2)
			{
				if (m_entete.BitsPerSample == 16)
				{
					fwrite(&m_intcanalDroite[i], sizeof(int), 1, flux);
				}
				else if (m_entete.BitsPerSample == 8)
				{
					intvaleur = IntToByte(m_intcanalDroite[i]);
					fwrite(&intvaleur, sizeof(BYTE), 1, flux);
				}
			}
		}
	}

	fclose(flux);
	return 1;
}

// Fonction de conversion de Byte à Int
int CWAVE::ByteToInt(BYTE valeur)
{
	return (valeur - 127) * 256;
}

// Fonction de conversion de Int à Byte
BYTE CWAVE::IntToByte(int valeur)
{
	return (valeur / 256) + 127;
}

WAVEHEADER CWAVE::Entete(void)
{
	return m_entete;
}

int* CWAVE::getCanalGauche(void)
{
	return m_intcanalGauche;
}

int* CWAVE::getCanalDroite(void)
{
	return m_intcanalDroite;
}

void CWAVE::setCanalDroite(int* intvaleurs)
{
	m_intcanalDroite = intvaleurs;
}

void CWAVE::setCanalGauche(int* intvaleurs)
{
	m_intcanalGauche = intvaleurs;
}