
//*********************************************************************************************
//* Programme : GPS : 10/11/2020
//*---------------------------------------------------------------------------------------------------------
//* derni�re mise a jour : 09/11/2020
//*
//*Programmeurs : Colbert Gr�goire,Garcia Florian,Prieux Pierre Louis classe : BTSSN2
//
//*--------------------------------------------------------------------------------------------------------
//* BUT : Afficher, d�couper et convertir une trame de GPS NMEA.
//*Programmes associ�s : AUCUN
//*********************************************************************************************
//---------------------------------------------------------------------------------------------//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <windows.h>

class liaison{
	char *buffer;
	char *port;
	HANDLE hcom;
	DCB dcb;

	public:
		liaison();
		bool ouvrirport(char *buffer); //On appel la fonction en bool�en pour qu'il y'ai que 2 choix possibles
		void ecrireport(char *buffer);
		void fermerport();
		void recep(char *buffer);
		void DMStoDD (char *times,char *lat, char *log,char *buf);
};

//---------------------------------------------------------------------------
#endif
