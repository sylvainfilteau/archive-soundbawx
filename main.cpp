#include <stdio.h>
#include "WAVE.h"
#include "LFO.h"
#include "Inversion.h"
#include "Vibrato.h"
#include "effet.h"
#include "distorsion.h"

void main () 
{
	// c:\Program Files\Messenger\newemail.wav
	printf("D�but des tests\n");
	printf("---------------------------------------\n");
	printf("Test de CWAVE\n");
	printf("---------------------------------------\n");

	CWAVE *son = new CWAVE("c:\\testson\\drum.wav");
	if (!son->Ouvrir())
	{
		printf("Erreur durant la lecture du son");
		return;
	}

	if (son != 0) // Je crois que cette v�rification est inutile car elle est toujours vrai.
	{
		printf("OK\n");
		printf("Canaux:		%d\n", son->Entete().NumChannels);
		printf("BitsPerSample:	%d\n", son->Entete().BitsPerSample);
		printf("Subchunk2Size:	%d\n", son->Entete().Subchunk2Size);
		printf("SampleRate:	%d\n", son->Entete().SampleRate);
		printf("ByteRate:	%d\n", son->Entete().ByteRate);

		if (son->Enregistrer("c:\\drum2.wav"))
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

	/*printf("---------------------------------------\n");
	printf("Test d'inversion\n");
	printf("---------------------------------------\n");

	CInversion *inv = new CInversion(son);
	inv->Inverser();

	if (son->Enregistrer("c:\\druminv.wav"))
	{
		printf("�criture du fichier r�ussi\n");
	}
	else
	{
		printf("�criture du fichier �chou�\n");
	}

	delete inv;*/

	printf("---------------------------------------\n");
	printf("Test de vibrato\n");
	printf("---------------------------------------\n");

	CVibrato *vib = new CVibrato(son);
	vib->Vibrer(50, 0.5);

	if (son->Enregistrer("c:\\drumvib.wav"))
	{
		printf("�criture du fichier r�ussi\n");
	}
	else
	{
		printf("�criture du fichier �chou�\n");
	}

	delete vib;

	/*printf("---------------------------------------\n");
	printf("Test de distorision\n");
	printf("---------------------------------------\n");

	CDistorsion *dis = new CDistorsion(son);
	dis->Distorsionner(20);

	if (son->Enregistrer("c:\\drumdis.wav"))
	{
		printf("�criture du fichier r�ussi\n");
	}
	else
	{
		printf("�criture du fichier �chou�\n");
	}

	delete dis;

	printf("---------------------------------------\n");
	printf("Test de CLFO\n");

	CLFO *lfo = new CLFO(LFOSIN, 100);

	for (int i = 0; i < 150; i++)
	{
		printf("%d : %.6f\n", i, lfo->getNextValeur());
	}
	delete lfo;*/

}