﻿#include "IRSnifferCirpark.h"
#include <iostream>
#include <string>
#include <iomanip>


int main(){


	IRSnifferCirpark sniffer;
//	bool correct = sniffer.ParametrerLeServeurCirpark("172.20.21.157",10111);
//	std::cout << correct << std::endl;
//
//	std::cout << "0082: " << sniffer.DetecterUnCapteur(0x0082) << std::endl;
//	std::cout << "0f9e: " << sniffer.DetecterUnCapteur(666) << std::endl;
//	std::cout << "La plage : " << sniffer.DetecterLesCapteurs(0x0f00,0x1000) << std::endl;
//	unsigned short capteur = 0x01ec;
//	std::cout << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << capteur << std::endl;
//	std::cout << "Nb capteur trouv�s : " << sniffer.NombreCapteursTrouves() << std::endl;
//	sniffer.EnregistrerSous("capteurs.txt");
//
//	std::cin.get();
//
	while(1){

		std::cout << "num capteur : " ;
		short Capt;
		std::cin >> Capt;
		bool correct = sniffer.ParametrerLeServeurCirpark("172.20.21.157",10111);
		bool correct2 = sniffer.DetecterUnCapteur(Capt);
		std::cout << correct2 << std::endl;
	}






	return 0;
}



