#pragma once
#include <windows.h>

struct WAVEHEADER
{
	// Riff chunk
	char ChunkID[4];		// doit contenir le mot "RIFF"
	DWORD ChunkSize;
	char Format[4];			// doit contenir le mot "WAVE"
	// fmt sub-chunk
	char Subchunk1ID[4];	// doit contenir le mot "fmt "
	DWORD Subchunk1Size;	
	WORD AudioFormat;
	WORD NumChannels;		// 1 = mono, 2 = st�r�o
	DWORD SampleRate;
	DWORD ByteRate;
	WORD BlockAlign;
	WORD BitsPerSample;		// 8 pour 8bits, 16 pour 16 bits
	// data sub-chunk
	char Subchunk2ID[4];		// doit contenir le mot "data"
	DWORD Subchunk2Size;
};

/*! \brief Classe qui stocke le son de type Wave.
 *
 * Cette classe ouvre et enregistre un son de type Wave. Elle fournit
 * toutes les informations n�cessaires sur le son afin de le tra�ter.
 * elle supporte les sons 8 et 16 bits.
 */
class CWAVE
{
public:
	/*! \brief Constructeur de la classe.
	 *
	 * @param strnomFichier Le nom du fichier wave � ouvrir.
	 *
	 * Le constructeur ouvre le fichier et stocke chacun des
	 * �chantillons dans un vecteur de type short. Si c'est un son
	 * 8 bits, il convertit chacun des �chantillons de BYTE � short.
	 */
	CWAVE(char* strnomFichier);
	//! \brief Destructeur de la classe.
	~CWAVE(void);
	/*! \brief M�thode d'enregistrement du fichier.
	 *
	 * @param strnomFichier Endroit o� le son doit �tre �crit.
	 * @return Vrai si la fonction s'est ex�cut� avec succ�s.
	 */
	int Enregistrer(char* strnomFichier);
	/*! \brief Propri�t� qui retourne les informations sur le fichier wave
	 *
	 * @return Une structure de donn�es qui contient l'ent�te du fichier wave.
	 */
	WAVEHEADER Entete(void);
	/*! \brief Propri�t� qui retourne un pointeur vers le vecteur de son du canal gauche.
	 *
	 * @return Pointeur vers le vecteur de son du canal gauche.
	 */
    short* getCanalGauche(void);
	/*! \brief Propri�t� qui retourne un pointeur vers le vecteur de son du canal droite.
	 *
	 * @return Pointeur vers le vecteur de son du canal droite.
	 */
	short* getCanalDroite(void);
	/*! \brief Propri�t� qui retourne le nombre d'�chantillons du son.
	 *
	 * @return Nombre d'�chantillons du son.
	 */
	int getNbEchantillon(void);

private:
	/*! \brief M�thode qui converti un Byte en short
	 *
	 * @param valeur Le byte � convertir
	 * @return La valeur converti en short
	 * 
	 * Cette m�thode est utile pour convertir les sons 8bits en 16bits
	 * pour le lire.
	 */
	short ByteToShort(BYTE valeur);
	/*! \brief M�thode qui converti un short en Byte
	 *
	 * @param valeur Le short � convertir
	 * @return La valeur converti en Byte
	 * 
	 * Cette m�thode est utile pour convertir les sons 16bits en 8bits
	 * pour l'�crire.
	 */
	BYTE ShortToByte(short valeur);
	char* m_strnomFichier; //!< Nom du fichier wave ouvert
	short* m_intcanalGauche; //!< Vecteur qui contient le son du canal de gauche
    short* m_intcanalDroite; //!< Vecteur qui contient le son du canal de droite quand le son a deux canal
	int m_intnbEchantillons; //!< Nombre d'�chantillon du son
	WAVEHEADER m_entete; //!< Entete du fichier wave
};
