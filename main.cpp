#include <stdio.h>
#include "WAVE.h"
#include "LFO.h"
#include "Inversion.h"
#include "Vibrato.h"

void main () 
{
	// c:\Program Files\Messenger\newemail.wav
	printf("D�but des tests\n");
	printf("---------------------------------------\n");
	printf("Test de CWAVE\n");
	printf("---------------------------------------\n");

	CWAVE *son = new CWAVE("c:\\testson\\tada.wav");

	if (son != 0)
	{
		printf("OK\n");
		printf("Canaux:		%d\n", son->Entete().NumChannels);
		printf("BitsPerSample:	%d\n", son->Entete().BitsPerSample);
		printf("Subchunk2Size:	%d\n", son->Entete().Subchunk2Size);
		printf("SampleRate:	%d\n", son->Entete().SampleRate);
		printf("ByteRate:	%d\n", son->Entete().ByteRate);

		if (son->Enregistrer("c:\\tada2.wav"))
		{
			printf("�criture du fichier r�ussi\n");
		}
		else
		{
			printf("�criture du fichier �chou�\n");
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

	//if (son->Enregistrer("c:\\tadainv.wav"))
	//{
	//	printf("�criture du fichier r�ussi\n");
	//}
	//else
	//{
	//	printf("�criture du fichier �chou�\n");
	//}

	//delete inv;

	printf("---------------------------------------\n");
	printf("Test de vibrato\n");
	printf("---------------------------------------\n");

	CVibrato *vib = new CVibrato(son);
	vib->Vibrer(50, 0.8);

	if (son->Enregistrer("c:\\tadavib.wav"))
	{
		printf("�criture du fichier r�ussi\n");
	}
	else
	{
		printf("�criture du fichier �chou�\n");
	}

	delete vib;


	/*printf("---------------------------------------\n");
	printf("Test de CLFO\n");

	CLFO *lfo = new CLFO(LFOSIN, 1102);

	for (int i = 0; i < 1102; i++)
	{
		printf("%d : %.6f\n", i, lfo->getNextValeur());
	}*/
}