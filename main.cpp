#include <stdio.h>
#include "WAVE.h"
#include "LFO.h"
#include "Inversion.h"
#include "Vibrato.h"

void main () 
{
	// c:\Program Files\Messenger\newemail.wav
	printf("Début des tests\n");
	printf("---------------------------------------\n");
	printf("Test de CWAVE\n");
	printf("---------------------------------------\n");

	CWAVE *son = new CWAVE("c:\\testson\\drum.wav");

	if (son != 0)
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

	//printf("---------------------------------------\n");
	//printf("Test d'inversion\n");
	//printf("---------------------------------------\n");

	//CInversion *inv = new CInversion(son);
	//inv->Inverser();

	//if (son->Enregistrer("c:\\druminv.wav"))
	//{
	//	printf("Écriture du fichier réussi\n");
	//}
	//else
	//{
	//	printf("Écriture du fichier échoué\n");
	//}

	//delete inv;

	printf("---------------------------------------\n");
	printf("Test de vibrato\n");
	printf("---------------------------------------\n");

	CVibrato *vib = new CVibrato(son);
	vib->Vibrer(son->getNbEchantillon(), 0.80);

	if (son->Enregistrer("c:\\drumvib.wav"))
	{
		printf("Écriture du fichier réussi\n");
	}
	else
	{
		printf("Écriture du fichier échoué\n");
	}

	delete vib;


	/*printf("---------------------------------------\n");
	printf("Test de CLFO\n");

	CLFO *lfo = new CLFO(LFOSIN, 44100 / 250);

	for (int i = 0; i < 44100 / 250; i++)
	{
		printf("%d : %.6f\n", i, lfo->getNextValeur());
	}*/
}