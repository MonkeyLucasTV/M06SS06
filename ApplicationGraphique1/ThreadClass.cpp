﻿//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadClass.h"
#include "Unit1.h"
#pragma package(smart_init)
#include <fstream>




unsigned int ChaineHexaVersInt2(char *chaineHexa, int nbCar)   //("FFFF",4)->65535   ("ffff",4)->65535
{	int nombre=0,j;
	char caractere;
	for(j=0;j<nbCar;j++)
	{ 	caractere=chaineHexa[j];
		if(caractere>='0' && caractere<='9')
		{ 	 nombre=nombre+((caractere-'0')<<(4*(nbCar-j-1)));
		}
		else
		{   char a;
			if(caractere>='a') a='a';
			else a='A';
			nombre=nombre+((caractere-a+10)<<(4*(nbCar-j-1)));
		}
	}
	return nombre;
}
//---------------------------------------------------------------------------

//   Important : Les m�thodes et les propri�t�s des objets de la VCL peuvent seulement �tre
//   utilis�es dans une m�thode appel�e avec Synchronize, par exemple :
//
//      Synchronize(&UpdateCaption);
//
//   o� UpdateCaption pourrait ressembler � :
//
//      void __fastcall ThRecherche::UpdateCaption()
//      {
//        Form1->Caption = "Mis � jour dans un thread";
//      }
//---------------------------------------------------------------------------

__fastcall ThRecherche::ThRecherche(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall ThRecherche::Execute()
{
	//---- Placer le code du thread ici ----
	Form1->sniffer.ParametrerLeServeurCirpark(AnsiString(Form1->InputIp->Text).c_str(),10001);
	Form1->sniffer.DetecterLesCapteurs(ChaineHexaVersInt2(AnsiString(Form1->EditPlageMin->Text).c_str(),4),ChaineHexaVersInt2(AnsiString(Form1->EditPlageMax->Text).c_str(),4));
	Form1->LabelCapt->Caption = (String)Form1->sniffer.NombreCapteursTrouves() + " capteurs trouvés";
	Form1->sniffer.EnregistrerSous("liste.txt");
    Form1->Label19->Caption = "Test";
	ifstream f;
	f.open("liste.txt");
	char adresseC[5];
	for(int i=0;i<Form1->sniffer.NombreCapteursTrouves();i++){

		f>>adresseC;

		Form1->ComboCapteur->AddItem(adresseC,this);
	}
	Form1->ComboCapteur->Text=adresseC;
    Form1->Shape1->Brush->Color = clRed;

	f.close();


}
//---------------------------------------------------------------------------