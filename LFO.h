/*! \file LFO.h
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 1.0
 *
 * \brief Ent�te de la classe CLFO
 */
#pragma once

const int LFOSIN = 1; //!< Constante qui d�finit un LFO sinuso�dale
const int LFOTRIANGLE = 2; //!< Constante qui d�finit un LFO triangulaire

/*! \brief Classe qui g�n�re un signal LFO (Low Frequency Oscillator)
 *
 * la classe g�n�re une courbe soit triangulaire ou
 * sinuso�dale avec comme minimum 0 et maximum 1 avec
 * une grandeur de cycle donn�e par l'utilisateur.
 */
class CLFO
{
public:
	/*! \brief Constructeur de la classe.
	 * 
	 * @param intlfoType Type de la courbe du LFO (LFOTRIANGLE, LFOSIN).
	 * @param intphase   La grandeur d'un cycle.
	 *
	 * La classe g�n�re toutes les valeurs de la courbe et les
	 * stock dans un vecteur. Pour acc�der aux valeurs, il faut utiliser
	 * la m�thode getNextValeur().
	 */
	CLFO(int intlfoType, int intphase);
	//! \brief Destructeur de la classe.
	~CLFO(void);
	/*! \brief Propri�t� qui fournit la phase.
	 *
	 * @return Retourne la grandeur du cycle.
	 */
	int getPhase();
	/*! \brief Propri�t� qui fournit le type du LFO.
	 *
	 * @return Retourne LFOTRIANGLE ou LFOSIN.
	 */
	int getLfoType();
	/*! \brief Propri�t� qui retourne la prochaine valeur du LFO.
	 *
	 * @return La valeur du LFO � la poisition du pointeur.
	 */
	float getNextValeur();
	//! \brief M�thode qui reset le pointeur de la valeur du LFO.
	void Reset();
	//! \brief M�thode qui retourne la valeur actuelle du LFO.
	float getCurrentValue();
private:
	//! \brief M�thode qui g�n�re la courbe de forme Sinuso�dale.
	void Sinus(void);
	//! \brief M�thode qui g�n�re la courbe de forme Triangulaire.
	void Triangle(void);
	int m_intlfoType; //!< Donn�e membre qui donne le type du LFO.
	int m_intphase; //!< Donn�e membre qui donne la grandeur du cycle.
	float* m_fltvaleurs; //!< Vecteur de la longueur de la phase qui stock la courbe.
	int m_intposition; //!< Compteur qui d�finit o� on est rendu dans la lecture du LFO
};
