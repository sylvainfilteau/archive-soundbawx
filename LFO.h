#pragma once

const int LFOSIN = 1;
const int LFOTRIANGLE = 2;

/*! \brief Classe qui génère un signal LFO (Low Frequency Oscillator)
 *
 * la classe génère une courbe soit triangulaire ou
 * sinusoïdale avec comme minimum 0 et maximum 1 avec
 * une grandeur de cycle donnée par l'utilisateur.
 */
class CLFO
{
public:
	/*! \brief Constructeur de la classe.
	 * 
	 * @param intlfoType Type de la courbe du LFO (LFOTRIANGLE, LFOSIN).
	 * @param intphase   La grandeur d'un cycle.
	 *
	 * La classe génère toutes les valeurs de la courbe et les
	 * stock dans un vecteur. Pour accèder aux valeurs, il faut utiliser
	 * la méthode getNextValeur().
	 */
	CLFO(int intlfoType, int intphase);
	//! \brief Destructeur de la classe.
	~CLFO(void);
	/*! \brief Propriété qui fournit la phase.
	 *
	 * @return Retourne la grandeur du cycle.
	 */
	int getPhase();
	/*! \brief Propriété qui fournit le type du LFO.
	 *
	 * @return Retourne LFOTRIANGLE ou LFOSIN.
	 */
	int getLfoType();
	/*! \brief Propriété qui retourne la prochaine valeur du LFO.
	 *
	 * @return La valeur du LFO à la poisition du pointeur.
	 */
	float getNextValeur();
private:
	//! \brief Méthode qui génère la courbe de forme Sinusoïdale.
	void Sinus(void);
	//! \brief Méthode qui génère la courbe de forme Triangulaire.
	void Triangle(void);
	int m_intlfoType; //!< Donnée membre qui donne le type du LFO.
	int m_intphase; //!< Donnée membre qui donne la grandeur du cycle.
	float* m_fltvaleurs; //!< Vecteur de la longueur de la phase qui stock la courbe.
};
