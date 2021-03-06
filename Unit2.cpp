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
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma hdrstop
#include "Unit2.h"
#include <string>
#pragma hdrstop
#pragma package(smart_init)
#include <iostream>
#include <stdio.h>
#include <sstream>




liaison::liaison(){
	this->buffer = new char[500];
}

bool liaison::ouvrirport(char *buffer){

	this->hcom = CreateFileA(buffer,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL);

	if(hcom == INVALID_HANDLE_VALUE){
		return false;
	}

	GetCommState(this->hcom,&this->dcb);   //On configure les param�tres du port s�rie

	this->dcb.BaudRate = CBR_4800;    //9600 de baud rate
	this->dcb.ByteSize = 8;            //8 de Data size
	this->dcb.Parity = NOPARITY;
	this->dcb.StopBits = ONESTOPBIT;

	SetCommState(this->hcom,&this->dcb);


	COMMTIMEOUTS comm;
	comm.ReadIntervalTimeout = MAXDWORD;
	comm.ReadTotalTimeoutMultiplier=0;
	comm.ReadTotalTimeoutConstant=0;
	comm.WriteTotalTimeoutMultiplier=0;
	comm.WriteTotalTimeoutConstant=0;

	SetCommTimeouts(this->hcom,&comm);

	return true;
}

void liaison::ecrireport(char *buffer){

	unsigned long sendLenght;
	WriteFile(this->hcom,buffer, strlen(buffer),&sendLenght,NULL);

}

void liaison::fermerport(){
	CloseHandle(this->hcom);
}

void liaison::recep(char *buffer){

	unsigned long sendLenght;
	ReadFile(this->hcom,buffer, 800,&sendLenght,NULL);
}







//---------------------------------------------------------------------------

