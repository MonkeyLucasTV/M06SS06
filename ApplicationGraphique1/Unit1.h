﻿//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H

#include "ThreadClass.h"
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "IRSnifferCirpark.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TLabel *LabelCapt;
	TEdit *InputIp;
	TButton *BoutonRech;
	TComboBox *ComboCapteur;
	TEdit *EditPlageMin;
	TEdit *EditPlageMax;
	TLabel *Label1;
	TBevel *Bevel1;
	TShape *Shape1;
	TShape *Shape2;
	TButton *BoutonConfig;
	TLabel *Label2;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TTrackBar *TrackBar1;
	TLabel *Label26;
	TTimer *Timer1;
	TButton *Button1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	void __fastcall BoutonRechClick(TObject *Sender);
	void __fastcall BoutonConfigClick(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Shape4ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);


private:	// D�clarations utilisateur

	ThRecherche *maThread;
	unsigned short donnee;
public:		// D�clarations utilisateur
	IRSnifferCirpark sniffer;
	__fastcall TForm1(TComponent* Owner);
	unsigned int ChaineHexaVersInt(char *chaineHexa, int nbCar);
	std::string IntVersChaineHexa(unsigned int nombre, int nbCar);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif