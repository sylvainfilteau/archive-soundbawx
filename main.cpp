/*! \file main.cpp
 * @author Sylvain Filteau <admin@cidsphere.com>
 * @author Philippe Tremblay <pht@infodev.ca>
 * @date avril 2004
 * @version 0.6
 *
 * \brief Fichier du main du programme.
 *
 * Ce fichier est pour accueillir la fonction main qui sert
 * à tester les classes pour le logiciel SoundBawx
 */
#include <stdio.h>
#include "WAVE.h"
#include "LFO.h"
#include "Inversion.h"
#include "Vibrato.h"
#include "Effet.h"
#include "Distorsion.h"
#include "Delay.h"

void main () 
{
	// c:\Program Files\Messenger\newemail.wav
	printf("Début des tests\n");
	printf("---------------------------------------\n");
	printf("Test de CWAVE\n");
	printf("---------------------------------------\n");

	CWAVE *son = new CWAVE("c:\\testson\\drum.wav", "drum.wav.tmp");
	if (!son->Ouvrir())
	{
		printf("Erreur durant la lecture du son");
		return;
	}

	if (son != 0) // Je crois que cette vérification est inutile car elle est toujours vrai.
	{
		printf("OK\n");
		printf("Canaux:		%d\n", son->Entete().NumChannels);
		printf("BitsPerSample:	%d\n", son->Entete().BitsPerSample);
		printf("Subchunk2Size:	%d\n", son->Entete().Subchunk2Size);
		printf("SampleRate:	%d\n", son->Entete().SampleRate);
		printf("ByteRate:	%d\n", son->Entete().ByteRate);

		if (son->Enregistrer("c:\\drum2.wav"))
		{
			printf("Écriture du fichier réussi\n");
		}
		else
		{
			printf("Écriture du fichier échoué\n");
		}
	}
	else
	{
		printf("DOH!");
	}

	/*printf("---------------------------------------\n");
	printf("Test d'inversion\n");
	printf("---------------------------------------\n");

	CInversion *inv = new CInversion(son);
	inv->Inverser();

	if (son->Enregistrer("c:\\druminv.wav"))
	{
		printf("Écriture du fichier réussi\n");
	}
	else
	{
		printf("Écriture du fichier échoué\n");
	}

	delete inv;

	printf("---------------------------------------\n");
	printf("Test de vibrato\n");
	printf("---------------------------------------\n");

	CVibrato *vib = new CVibrato(son);
	
	if (vib->Vibrer(50, 0.5))
	{
		printf("La vibration a réussi!\n");

		if (son->Enregistrer("c:\\drumvib.wav"))
		{
			printf("Écriture du fichier réussi\n");
		}
		else
		{
			printf("Écriture du fichier échoué\n");
		}
	}
	else
	{
		printf("La vibration a échoué!\n");
	}

	delete vib;

	printf("---------------------------------------\n");
	printf("Test de Rollback #1\n");
	printf("---------------------------------------\n");
	
	if (son->Rollback())
	{
		if (son->Enregistrer("c:\\drumroll1.wav"))
		{
			printf("Écriture du fichier réussi\n");
		}
		else
		{
			printf("Écriture du fichier échoué\n");
		}
	}

	printf("---------------------------------------\n");
	printf("Test de Rollback #2\n");
	printf("---------------------------------------\n");
	
	if (son->Rollback())
	{
		if (son->Enregistrer("c:\\drumroll2.wav"))
		{
			printf("Écriture du fichier réussi\n");
		}
		else
		{
			printf("Écriture du fichier échoué\n");
		}
	}

	printf("---------------------------------------\n");
	printf("Test de distorision\n");
	printf("---------------------------------------\n");

	CDistorsion *dis = new CDistorsion(son);
	dis->Distorsionner(20);

	if (son->Enregistrer("c:\\drumdis.wav"))
	{
		printf("Écriture du fichier réussi\n");
	}
	else
	{
		printf("Écriture du fichier échoué\n");
	}

	delete dis;*/

	printf("---------------------------------------\n");
	printf("Test de Delay\n");
	printf("---------------------------------------\n");

	CDelay *delay = new CDelay(son);
	if (delay->AppliquerDelais(100, 0.90, 0.50))
	{
		if (son->Enregistrer("c:\\drumdelay.wav"))
		{
			printf("Écriture du fichier réussi\n");
		}
		else
		{
			printf("Écriture du fichier échoué\n");
		}
	}
	else
	{
		printf("Effet échoué\n");
	}

	delete delay;

	/*printf("---------------------------------------\n");
	printf("Test de CLFO\n");

	CLFO *lfo = new CLFO(LFOSIN, 100);

	for (int i = 0; i < 150; i++)
	{
		printf("%d : %.6f\n", i, lfo->getNextValeur());
	}
	delete lfo;*/

	delete son;

}