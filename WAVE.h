/*! \file WAVE.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Entête de la classe CWAVE et la structure d'une entête de fichier wave
 */
#pragma once
#include <windows.h>

/*! \brief Structure qui contient l'entête d'un fichier Wave.
 *
 * Chacune des valeurs sers à définir comment est composé le
 * son et les spécifications du wave. L'entête se divise en trois partie:
 * 1 (RIFF)  : Partie qui décrit tout l'entête,
 * 2 (Format): Partie qui décrit le format du son,
 * 3 (Data)  : Partie qui décrit la grosseur du son et le son lui même.
 */
struct WAVEHEADER
{
	// Riff chunk
	char ChunkID[4];		//!< doit contenir le mot "RIFF"
	DWORD ChunkSize;		//!< Grosseur de l'entête
	char Format[4];			//!< doit contenir le mot "WAVE"
	// fmt sub-chunk
	char Subchunk1ID[4];	//!< doit contenir le mot "fmt "
	DWORD Subchunk1Size;	//!< Grosseur de la deuxième partie de l'entête
	WORD AudioFormat;		//!< ?
	WORD NumChannels;		//!< Nombre de canaux du son: 1 = mono, 2 = stéréo
	DWORD SampleRate;		//!< ?
	DWORD ByteRate;			//!< ?
	WORD BlockAlign;		//!< ?
	WORD BitsPerSample;		//!< Nombre de d'octet par échantillon: 8 pour 8bits, 16 pour 16 bits
	// data sub-chunk
	char Subchunk2ID[4];	//!< doit contenir le mot "data"
	DWORD Subchunk2Size;	//!< La grosseur du son
};

/*! \brief Classe qui stocke le son de type Wave.
 *
 * Cette classe ouvre et enregistre un son de type Wave. Elle fournit
 * toutes les informations nécessaires sur le son afin de le traîter.
 * elle supporte les sons 8 et 16 bits. Depuis le 18-04-2004, il est
 * possible de faire des rollback d'une action faite. Pour ce faire, il
 * est nécessaire d'appeler la méthode Backup() avant tout changement
 * au vecteurs de sons. Ensuite, il faut appeler la méthode Rollback()
 * pour revenir en arrière.
 */
class CWAVE
{
public:
	/*! \brief Constructeur de la classe.
	 *
	 * @param strnomFichier Le nom du fichier wave à ouvrir.
	 *
	 * Le constructeur ouvre le fichier et stocke chacun des
	 * échantillons dans un vecteur de type short. Si c'est un son
	 * 8 bits, il convertit chacun des échantillons de BYTE à short.
	 */
	CWAVE(char* strnomFichier, char* strnomFichierBackup);
	//! \brief Destructeur de la classe.
	~CWAVE(void);
	/*! \brief Méthode qui ouvre le son et le stock dans des vecteurs.
	 *
	 * La méthode ouvre le fichier donnée au constructeur et stocke chacun des
	 * échantillons dans un vecteur de type short. Si c'est un son
	 * 8 bits, il convertit chacun des échantillons de BYTE à short. Pour que
	 * l'ouverture se fasse avec succès, il est nécessaire que l'entête du son
	 * fournisse les valeurs suivantes: ChunkID=RIFF, Format=WAVE, Subchunk1ID="fmt "
	 * et Subchunk2ID=data.
	 *
	 * @return Vrai si l'ouverture s'est fait avec succès.
	 */
	int Ouvrir();
	/*! \brief Méthode d'enregistrement du fichier.
	 *
	 * @param strnomFichier Endroit où le son doit être écrit.
	 * @return Vrai si la fonction s'est exécuté avec succès.
	 */
	int Enregistrer(char* strnomFichier);
	/*! \brief Propriété qui retourne les informations sur le fichier wave
	 *
	 * @return Une structure de données qui contient l'entête du fichier wave.
	 */
	WAVEHEADER Entete(void);
	/*! \brief Propriété qui retourne un pointeur vers le vecteur de son du canal gauche.
	 *
	 * @return Pointeur vers le vecteur de son du canal gauche.
	 */
    short* getCanalGauche(void);
	/*! \brief Propriété qui retourne un pointeur vers le vecteur de son du canal droite.
	 *
	 * @return Pointeur vers le vecteur de son du canal droite.
	 */
	short* getCanalDroite(void);
	/*! \brief Propriété qui retourne le nombre d'échantillons du son.
	 *
	 * @return Nombre d'échantillons du son.
	 */
	int getNbEchantillon(void);

	/*! \brief Méthode qui prend une sauvegarde des données.
	 *
	 * Cette méthode prend une sauvegarde des données afin de pouvoir revenir
	 * en arrière quand un effet sera appliqué au son.
	 *
	 * @see Rollback() qui permet de rétablir les données prises en sauvegarde.
	 * @see HaveBackup() qui permet de savoir si un backup a déjà été pris.
	 *
	 * @return Vrai si la sauvegarde a réussi.
	 */
	int Backup(void);
	/*! \brief Méthode qui reprend les données temporaire
	 *
	 * Méthode qui reprend les données temporaire stocké dans le fichiers de
	 * backup et les remet dans les vecteurs de son. Elle en profite pour faire
	 * un backup des données déjà existente pour refaire un autre rollback.
	 *
	 * @see Backup() qui permet de sauvegarder les données afin de pouvoir faire un rollback.
	 * @see HaveBackup() qui permet de savoir si un backup a déjà été pris.
	 *
	 * @return Vrai si la méthode a réussi
	 */
	int Rollback(void);
	//! \brief Propriété qui retourne si le programme a un backup d'une ancienne valeur.
	int HaveBackup(void);

private:
	/*! \brief Méthode qui converti un Byte en short
	 *
	 * @param valeur Le byte à convertir
	 * @return La valeur converti en short
	 * 
	 * Cette méthode est utile pour convertir les sons 8bits en 16bits
	 * pour le lire.
	 */
	short ByteToShort(BYTE valeur);
	/*! \brief Méthode qui converti un short en Byte
	 *
	 * @param valeur Le short à convertir
	 * @return La valeur converti en Byte
	 * 
	 * Cette méthode est utile pour convertir les sons 16bits en 8bits
	 * pour l'écrire.
	 */
	BYTE ShortToByte(short valeur);
	char* m_strnomFichier; //!< Nom du fichier wave ouvert.
	char* m_strNomFichierBackup; //!< Nom du fichier ou sera pris la sauvegarde.
	short* m_intcanalGauche; //!< Vecteur qui contient le son du canal de gauche.
    short* m_intcanalDroite; //!< Vecteur qui contient le son du canal de droite quand le son a deux canal.
	int m_intnbEchantillons; //!< Nombre d'échantillon du son.
	WAVEHEADER m_entete; //!< Entete du fichier wave.
	int m_intHaveBackup; //!< Valeur qui indique si le son possède un backup.
};
