/*! \file WAVE.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Corp de la classe CWAVE
 */
#include "wave.h"
#include "Tools.h"
#include <stdio.h>
#include <windows.h>

CWAVE::CWAVE(char* strnomFichier, char* strNomFichierBackup)
{
	m_strnomFichier = strnomFichier;
	m_strNomFichierBackup = strNomFichierBackup;
	m_intHaveBackup = 0;
}

CWAVE::~CWAVE(void)
{
	remove(m_strNomFichierBackup);
	delete[] m_intcanalDroite;
	delete[] m_intcanalGauche;
}

int CWAVE::Ouvrir()
{
	FILE* flux;
	int intnbPass = 0;
	BYTE bytvaleur = 0;
	CTools tools;
	int ret = 0;

	flux = fopen(m_strnomFichier, "rb");

	if (flux != NULL)
	{
		fread(&m_entete, sizeof(WAVEHEADER), 1, flux);
		
		// v�rification de l'ent�te du wave
		if (tools.StringComparer(m_entete.ChunkID, "RIFF", 4) && 
			tools.StringComparer(m_entete.Format, "WAVE", 4) &&  
			tools.StringComparer(m_entete.Subchunk1ID, "fmt ", 4) && 
			tools.StringComparer(m_entete.Subchunk2ID, "data", 4))
		{

			// initialisation des vecteurs qui contiennent le son
			// initialisation du nombre d'�chantillons
			if (m_entete.NumChannels == 1)
			{
				if (m_entete.BitsPerSample == 8)
					m_intnbEchantillons = (int)m_entete.Subchunk2Size;
				else
					m_intnbEchantillons = (int)m_entete.Subchunk2Size / 2;

				m_intcanalGauche = new short[m_intnbEchantillons];
			}
			else
			{
				if (m_entete.BitsPerSample == 8)
					m_intnbEchantillons = (int)m_entete.Subchunk2Size / 2;
				else
					m_intnbEchantillons = (int)m_entete.Subchunk2Size / 4;

				m_intcanalGauche = new short[m_intnbEchantillons];
				m_intcanalDroite = new short[m_intnbEchantillons];
			}				

			// Lecture du reste du fichier
			/*
			En 8 bits, les donn�es sont stock� sur un unsigned short tandis que
			en 16 bits, c'est un signed int. Il faut donc faire une conversion
			� l'aide de la fonction ByteToInt
			*/
			for (int i = 0; i < m_intnbEchantillons; i++)
			{

				if (m_entete.BitsPerSample == 16)
				{
					fread(&m_intcanalGauche[i], sizeof(short), 1, flux);
				}
				else if (m_entete.BitsPerSample == 8)
				{
					fread(&bytvaleur, sizeof(BYTE), 1, flux);
					m_intcanalGauche[i] = ByteToShort(bytvaleur);
				}
				if (m_entete.NumChannels == 2)
				{
					if (m_entete.BitsPerSample == 16)
					{
						fread(&m_intcanalDroite[i], sizeof(short), 1, flux);
					}
					else if (m_entete.BitsPerSample == 8)
					{
						fread(&bytvaleur, sizeof(BYTE), 1, flux);
						m_intcanalDroite[i] = ByteToShort(bytvaleur);
					}
				}
			}

			ret = 1;
		}
	}

	fclose(flux);
	return ret;
}

// M�thode d'enregistrement du son.
// si le param�tre = une cha�ne vide, on enregistre le son par dessus l'autre son.
int CWAVE::Enregistrer(char *strnomFichier)
{
	int intcote = 0;
	int intvaleur = 0;
	FILE* flux;
	
	// V�rification du nom pour prendre celui de l'original
	// ou un nouveau nom
	if (strnomFichier == "")
		flux = fopen(m_strnomFichier, "wb");
	else
		flux = fopen(strnomFichier, "wb");

	// V�rification de la cr�ation du flux
	if (flux == NULL)
	{
		return 0;
	}
	else
	{
		fwrite(&m_entete, sizeof(WAVEHEADER), 1, flux);
		for (int i = 0; i < m_intnbEchantillons; i++)
		{
			if (m_entete.BitsPerSample == 16)
			{
				fwrite(&m_intcanalGauche[i], sizeof(short), 1, flux);
			}
			else if (m_entete.BitsPerSample == 8)
			{
				intvaleur = ShortToByte(m_intcanalGauche[i]);
				fwrite(&intvaleur, sizeof(BYTE), 1, flux);
			}
			if (m_entete.NumChannels == 2)
			{
				if (m_entete.BitsPerSample == 16)
				{
					fwrite(&m_intcanalDroite[i], sizeof(short), 1, flux);
				}
				else if (m_entete.BitsPerSample == 8)
				{
					intvaleur = ShortToByte(m_intcanalDroite[i]);
					fwrite(&intvaleur, sizeof(BYTE), 1, flux);
				}
			}
		}
	}

	fclose(flux);
	return 1;
}

// M�thode qui prend une sauvegarde dans le fichier de backup du son
int CWAVE::Backup()
{
	FILE* flux;
	int ret = 0;

	flux = fopen(m_strNomFichierBackup, "wb");
	if (flux != NULL)
	{
		fwrite(m_intcanalGauche, getNbEchantillon()*sizeof(short), 1, flux);
		if (m_entete.NumChannels == 2)
			fwrite(m_intcanalDroite, getNbEchantillon()*2, 1, flux);

		ret = 1;
		m_intHaveBackup = 1;
	}

	fclose(flux);
	return ret;
}

// M�thode qui lit le fichier temporaire si il existe.
int CWAVE::Rollback()
{
	short* intCanalGauche;
	short* intCanalDroite;
	FILE *flux;
	int ret = 0;

	if (HaveBackup()) // V�rification de l'existence d'un backup.
	{
		flux = fopen(m_strNomFichierBackup, "rb");
		if (flux != NULL)
		{
			intCanalGauche = new short[m_intnbEchantillons];
			fread(intCanalGauche, m_intnbEchantillons * 2, 1, flux);
			if (m_entete.NumChannels == 2)
			{
				intCanalDroite = new short[m_intnbEchantillons];
				fread(intCanalDroite, m_intnbEchantillons * 2, 1, flux);
			}

			Backup(); // prise du backup avant de mettre les nouvelles valeurs.

			m_intcanalGauche = intCanalGauche;
			if (m_entete.NumChannels == 2)
				m_intcanalDroite = intCanalDroite;

			ret = 1;
		}

		fclose(flux);
	}
	return ret;
}

// Propri�t� qui retourne vrai si le son a un backup
int CWAVE::HaveBackup()
{
	return m_intHaveBackup;
}

// Propri�t� qui retourne vrai si le son est st�r�o
int CWAVE::Stereo()
{
	if (m_entete.NumChannels == 1)
		return 0;
	else
		return 1;
}

// Propri�t� qui retourne le nombre de samples par milliseconde
int CWAVE::NbSamplesParMs()
{
	return m_entete.SampleRate / 1000;
}

// Fonction de conversion de Byte � Int
short CWAVE::ByteToShort(BYTE valeur)
{
	return (valeur - 127) * 256;
}

// Fonction de conversion de Int � Byte
BYTE CWAVE::ShortToByte(short valeur)
{
	return (valeur / 256) + 127;
}

WAVEHEADER CWAVE::Entete(void)
{
	return m_entete;
}

short* CWAVE::getCanalGauche(void)
{
	return m_intcanalGauche;
}

short* CWAVE::getCanalDroite(void)
{
	return m_intcanalDroite;
}

int CWAVE::getNbEchantillon(void)
{
	return m_intnbEchantillons;
}