#include <iostream>
#include "IRClientTCP.h"
#include <fstream>
#include <string>

IRClientTCP client;
std::string ip;
std::string port;


void RecupereNomCapteur(std::string Liste){

	unsigned int idDeb=0, idFin=0;
	std::string idTot;
	std::string TableauRep[100];
	int i = 0;
	while (1){

			std::size_t found = Liste.find("<id>", idDeb+1);
			if (found == std::string::npos){
				break;
			}
			idDeb = Liste.find("<id>", idDeb+1);
			idFin = Liste.find("</id>",idDeb+1);
			idTot = Liste.substr(idDeb+4,idFin-idDeb-4);
			std::cout << "Voici id tot : " << idTot << std::endl;



	}
}


void RecupInfo(std::string Nom){

	char Reponse[1000];
	client.SeConnecterAUnServeur(ip,std::atoi(port.c_str()));
	client.Envoyer("GET services/user/deviceInfo.xml?id=SP HTTP/1.1 /\r\n\r\n");
	client.Recevoir(Reponse,500);

}


void RecupEtat(std::string Nom){


}

int main(){


	ifstream Ifs;                            //Cr�ation des objets






	Ifs.open("config.txt");

	std::getline(Ifs,ip) ;                     // ouverture du fichier config.txt et
	std::getline(Ifs,port);					   // stockage des donn�es extraites dans variables
	Ifs.close();


	std::string ReponseFinale;


	char Reponse[1000];

	client.SeConnecterAUnServeur(ip,std::atoi(port.c_str()));
	client.Envoyer("GET services/user/devices.xml HTTP/1.1 /\r\n\r\n");
	client.Recevoir(Reponse,500);

	std::cout  << Reponse;

	ReponseFinale += Reponse;
	memset(Reponse, 0, 1000*sizeof(char));    // vider Reponse


	client.Recevoir(Reponse, 500);
	ReponseFinale += Reponse;

	std::cout << ReponseFinale;

	client.SeDeconnecter();


//	int idDeb = ReponseFinale.find("<id>",400);
//	int idFin = ReponseFinale.find("</id>",450);
//	std::string IdTot = ReponseFinale.substr(idDeb+4,(idFin-idDeb)-4);
//
//	std::cout << IdTot;
//
//	std::cout << idDeb << " " << idFin;
//



	RecupereNomCapteur(ReponseFinale);


	std::cin.get();

}



