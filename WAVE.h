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
	WORD NumChannels;		// 1 = mono, 2 = stéréo
	DWORD SampleRate;
	DWORD ByteRate;
	WORD BlockAlign;
	WORD BitsPerSample;		// 8 pour 8bits, 16 pour 16 bits
	// data sub-chunk
	char Subchunk2ID[4];		// doit contenir le mot "data"
	DWORD Subchunk2Size;
};

class CWAVE
{
public:
	CWAVE(char* strnomFichier);
	~CWAVE(void);
	int Enregistrer(char* strnomFichier);
	WAVEHEADER Entete(void);
    int* getCanalGauche(void);
	int* getCanalDroite(void);
	void setCanalGauche(int*);
	void setCanalDroite(int*);

private:
	int ByteToInt(BYTE valeur);
	BYTE IntToByte(int valeur);
	char* m_strnomFichier;
	int* m_intcanalGauche;
    int* m_intcanalDroite;
	WAVEHEADER m_entete;
};
