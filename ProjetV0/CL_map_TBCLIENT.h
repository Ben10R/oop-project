#pragma once
#include "CL_CAD.h"
using namespace System;

namespace NS_Composants
{
	ref class CL_map_TBCLIENT
	{
	private:
		int id_client;
		int id_adresse;
		int IdAdressLivraison;
		int IdAdressFacturation;
		int _noRue;
		int _cp;
		String^ _adress;
		String^ _ville;
		String^ _nom;
		String^ _prenom;
		String^ _dateNaissance;
		String^ _datePremAchat;

		CL_CAD^ dataAccess;
	public:
		CL_map_TBCLIENT(void);
		//SELECT
		String^ SELECTCLIENT(void);
		String^ SELECTADRRESSEFACTURATION(void);
		String^ SELECTADRRESSELIVRAISON(void);
		//INSERT
		String^ INSERTCLIENT(void);
		String^ INSERTADRESSFACT(void);
		String^ INSERTADRESSLIVR(void);
		//UPDATE
		String^ UPDATECLIENT(void);
		String^ UPDATEADRESSELIVR(void);
		String^ UPDATEADRESSEFACT(void);
		//DELETE
		String^ DELETE(void);
		

		//Partie Client
		int getIdClient(void);
		void setIdClient(int);
		String^ getDateNaissance(void);
		void setDateNaissance(String^);
		String^ getDatePremAchat(void);
		void setDatePremAchat(String^);
		String^ getNom(void);
		void setNom(String^);
		String^ getPrenom(void);
		void setPrenom(String^);
		//Partie Adresse Client
		void setIdAdresseLivraison(int);
		int getIdAdresseLivraison(void);
		void setIdAdresseFacturation(int);
		int getIdAdresseFacturation(void);
		void setNoRue(int);
		int getNoRue(void);
		void setAdress(String^);
		String^ getAdress(void);
		void setVille(String^);
		String^ getVille(void);
		void setCp(int);
		int getCp(void);
	};
}


