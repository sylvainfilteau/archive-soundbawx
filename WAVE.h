/*! \file WAVE.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Ent�te de la classe CWAVE et la structure d'une ent�te de fichier wave
 */
#pragma once
#include <windows.h>

/*! \brief Structure qui contient l'ent�te d'un fichier Wave.
 *
 * Chacune des valeurs sers � d�finir comment est compos� le
 * son et les sp�cifications du wave. L'ent�te se divise en trois partie:
 * 1 (RIFF)  : Partie qui d�crit tout l'ent�te,
 * 2 (Format): Partie qui d�crit le format du son,
 * 3 (Data)  : Partie qui d�crit la grosseur du son et le son lui m�me.
 */
struct WAVEHEADER
{
	// Riff chunk
	char ChunkID[4];		//!< doit contenir le mot "RIFF"
	DWORD ChunkSize;		//!< Grosseur de l'ent�te
	char Format[4];			//!< doit contenir le mot "WAVE"
	// fmt sub-chunk
	char Subchunk1ID[4];	//!< doit contenir le mot "fmt "
	DWORD Subchunk1Size;	//!< Grosseur de la deuxi�me partie de l'ent�te
	WORD AudioFormat;		//!< ?
	WORD NumChannels;		//!< Nombre de canaux du son: 1 = mono, 2 = st�r�o
	DWORD SampleRate;		//!< ?
	DWORD ByteRate;			//!< ?
	WORD BlockAlign;		//!< ?
	WORD BitsPerSample;		//!< Nombre de d'octet par �chantillon: 8 pour 8bits, 16 pour 16 bits
	// data sub-chunk
	char Subchunk2ID[4];	//!< doit contenir le mot "data"
	DWORD Subchunk2Size;	//!< La grosseur du son
};

/*! \brief Classe qui stocke le son de type Wave.
 *
 * Cette classe ouvre et enregistre un son de type Wave. Elle fournit
 * toutes les informations n�cessaires sur le son afin de le tra�ter.
 * elle supporte les sons 8 et 16 bits. Depuis le 18-04-2004, il est
 * possible de faire des rollback d'une action faite. Pour ce faire, il
 * est n�cessaire d'appeler la m�thode Backup() avant tout changement
 * au vecteurs de sons. Ensuite, il faut appeler la m�thode Rollback()
 * pour revenir en arri�re.
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
	CWAVE(char* strnomFichier, char* strnomFichierBackup);
	//! \brief Destructeur de la classe.
	~CWAVE(void);
	/*! \brief M�thode qui ouvre le son et le stock dans des vecteurs.
	 *
	 * La m�thode ouvre le fichier donn�e au constructeur et stocke chacun des
	 * �chantillons dans un vecteur de type short. Si c'est un son
	 * 8 bits, il convertit chacun des �chantillons de BYTE � short. Pour que
	 * l'ouverture se fasse avec succ�s, il est n�cessaire que l'ent�te du son
	 * fournisse les valeurs suivantes: ChunkID=RIFF, Format=WAVE, Subchunk1ID="fmt "
	 * et Subchunk2ID=data.
	 *
	 * @return Vrai si l'ouverture s'est fait avec succ�s.
	 */
	int Ouvrir();
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

	/*! \brief M�thode qui prend une sauvegarde des donn�es.
	 *
	 * Cette m�thode prend une sauvegarde des donn�es afin de pouvoir revenir
	 * en arri�re quand un effet sera appliqu� au son.
	 *
	 * @see Rollback() qui permet de r�tablir les donn�es prises en sauvegarde.
	 * @see HaveBackup() qui permet de savoir si un backup a d�j� �t� pris.
	 *
	 * @return Vrai si la sauvegarde a r�ussi.
	 */
	int Backup(void);
	/*! \brief M�thode qui reprend les donn�es temporaire
	 *
	 * M�thode qui reprend les donn�es temporaire stock� dans le fichiers de
	 * backup et les remet dans les vecteurs de son. Elle en profite pour faire
	 * un backup des donn�es d�j� existente pour refaire un autre rollback.
	 *
	 * @see Backup() qui permet de sauvegarder les donn�es afin de pouvoir faire un rollback.
	 * @see HaveBackup() qui permet de savoir si un backup a d�j� �t� pris.
	 *
	 * @return Vrai si la m�thode a r�ussi
	 */
	int Rollback(void);
	//! \brief Propri�t� qui retourne si le programme a un backup d'une ancienne valeur.
	int HaveBackup(void);

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
	char* m_strnomFichier; //!< Nom du fichier wave ouvert.
	char* m_strNomFichierBackup; //!< Nom du fichier ou sera pris la sauvegarde.
	short* m_intcanalGauche; //!< Vecteur qui contient le son du canal de gauche.
    short* m_intcanalDroite; //!< Vecteur qui contient le son du canal de droite quand le son a deux canal.
	int m_intnbEchantillons; //!< Nombre d'�chantillon du son.
	WAVEHEADER m_entete; //!< Entete du fichier wave.
	int m_intHaveBackup; //!< Valeur qui indique si le son poss�de un backup.
};
