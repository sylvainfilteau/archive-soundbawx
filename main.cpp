#include <stdio.h>
#include "WAVE.h"
#include "LFO.h"
#include "Inversion.h"

void main () 
{
	// c:\Program Files\Messenger\newemail.wav
	printf("D�but des tests\n");
	printf("---------------------------------------\n");
	printf("Test de CWAVE\n");
	printf("---------------------------------------\n");

	CWAVE *son = new CWAVE("c:\\testson\\ding.wav");

	if (son != 0)
	{
		printf("OK\n");
		printf("Canaux:		%d\n", son->Entete().NumChannels);
		printf("BitsPerSample:	%d\n", son->Entete().BitsPerSample);
		printf("Subchunk2Size:	%d\n", son->Entete().Subchunk2Size);
		printf("SampleRate:	%d\n", son->Entete().SampleRate);
		printf("ByteRate:	%d\n", son->Entete().ByteRate);

		if (son->Enregistrer("c:\\ding2.wav"))
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

	printf("---------------------------------------\n");
	printf("Test d'inversion\n");
	printf("---------------------------------------\n");

	CInversion *inv = new CInversion(son);
	inv->Inverser();

	if (son->Enregistrer("c:\\dinginv.wav"))
	{
		printf("�criture du fichier r�ussi\n");
	}
	else
	{
		printf("�criture du fichier �chou�\n");
	}

	delete inv;

	/*printf("---------------------------------------\n");
	printf("Test de CLFO\n");

	CLFO *lfo = new CLFO(LFOSIN, 44100 / 250);

	for (int i = 0; i < 44100 / 250; i++)
	{
		printf("%d : %.6f\n", i, lfo->getNextValeur());
	}*/
}