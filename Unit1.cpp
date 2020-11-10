//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <windows.h>
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
bool connect;
		unsigned long sendLengh;                     //
		UnicodeString str = Edit1->Text;             //
		wchar_t * text = str.c_str();                //
		char * convert = new char[str.Length() + 1]; //Systeme de conversion de Tchar en char
		wcstombs (convert, text, str.Length());      //
		convert[str.Length()] = 0x00;                //
		connect = port.ouvrirport(convert) //on appel la fonction avec les valeurs récupérés
		;
		if(connect == true){   // Si on est connecté on affiche l'IHM
			Button1->Visible = false;
			Button2->Visible = true;
			Button3->Visible = true;
			Edit1 ->Visible = false;
			Label2->Visible= true;
			Memo1->Visible= true;
			Memo2->Visible= true;
			 Edit3->Visible=true;
             Button4->Visible=true;
		}else if(connect == false){
			Label3 ->Visible = true;
		}
		delete convert;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 unsigned long sendLengh;
	UnicodeString str = Edit2->Text;         		//
	wchar_t * text = str.c_str();            		//
	char * convert = new char[str.Length() + 1]; 	//Systeme de conversion de Tchar en char
	wcstombs (convert, text, str.Length());  		//
	convert[str.Length()] = 0x00;            		//
	port.ecrireport(convert); // On envoie les valeurs grace a la fonction
	delete convert;
	char buf[800];
	port.recep(buf);
	port.ecrireport(buf);
	Memo1->Lines->Append(buf);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form1-> Close();     //On ferme l'IHM
port.fermerport();    //On ferme le port
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   /* char c;
int degre, heure;
float minute, latitude_decimal, latitude_final, longitude_decimal, longitude_final;
bool consumeSomething = true;
	while(buffer.size() > 0 && consumeSomething)
{
consumeSomething = false;
	if(buffer.size() >= 6 && buffer[1] == 'G' && buffer[2] == 'P' && buffer[3] == 'G' && buffer[4] == 'G' && buffer[5] == 'A') //on cherche une trame qui a au minimum 6 carac et qui commence par "GPGGA"
{
	bool complete = false;
		for(int i = 0; i < buffer.size() && !complete; i++)
		{
			if(buffer[i] == '\n') //dans cette boucle on vérifie que la trame finit bien par un \n
		{
			complete = true;
		}
		}

		if(complete)
		{
		UnicodeString str = "";
		while(buffer.front() != '\n') //on crée un unicodestring a partir des caracteres récupérés
		{
		str += buffer.front();
		buffer.pop_front(); //on réduit la taille du deque jusqu'a tomber sur \n
		}
			buffer.pop_front();
			Label2->Caption = str;
			UnicodeString latitude_ = str.SubString(15,9); // latitude
			UnicodeString longitude_ = str.SubString(27,10); // longitude
			char latitude_decimale[11];
			char longitude_decimale[12];
			wcstombs(latitude_decimale ,latitude_.c_str(),11);
			wcstombs(longitude_decimale ,longitude_.c_str(),12);
			degre = (latitude_decimale[0]-48)*10 + latitude_decimale[1]-48;
			heure = (latitude_decimale[2]-48)*10 + latitude_decimale[3]-48;
			minute = (latitude_decimale[5]-48) *10 + (latitude_decimale[6]-48) + (latitude_decimale[7]-48.0)/10 +
			(latitude_decimale[8]-48.00)/100;
			latitude_decimal = (heure + (minute /= 60)) / 60;
			latitude_final = degre + latitude_decimal;

	for (int i=0 ; i<10; i++) {
		if ((latitude_decimale[i] == 'N') || (latitude_decimale[i] =='S')) //Si la localisation est au sud, alors la velur decimale est négative
	{
			if (latitude_decimale[i] == 'N') {

		} else {

		latitude_final = -latitude_final;
		}
	}
}

degre = (longitude_decimale[1]-48)*10 + longitude_decimale[2]-48;
heure = (longitude_decimale[3]-48)*10 + longitude_decimale[4]-48;
minute = (longitude_decimale[5]-48) *10 + (longitude_decimale[6]-48) + (longitude_decimale[7]-48.0)/10 +
(longitude_decimale[8]-48.00)/100;
longitude_decimal = (heure + (minute /= 60)) / 60;
longitude_final = degre + longitude_decimal;
for (int i=0 ; i<10; i++) {
if ((longitude_decimale[i] == 'E') || (latitude_decimale[i] =='W')) //Si la localisation est au sud, alors la velur decimale est négative
{
if (longitude_decimale[i] == 'E') {

} else {

longitude_final = -longitude_final;
}
}
}

Memo2->Caption = latitude_final;
Memo2->Caption = longitude_final;

Memo2->Caption = str.SubString(8,6);
Memo2->Caption = str.SubString(15,11);
Memo2->Caption = str.SubString(27,12);
consumeSomething = true;
}
}
else
{
while(buffer.size() > 0 && buffer.front() != '\n')
{
buffer.pop_front();
}
if(buffer.size() > 0 && buffer.front() == '\n')
{
buffer.pop_front();
consumeSomething = true;
}
}
*/
}

//---------------------------------------------------------------------------



