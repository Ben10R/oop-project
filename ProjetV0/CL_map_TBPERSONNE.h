#pragma once
#include "CL_CAD.h"
// classe composant de mappage de la table « TB_PERSONNE »
using namespace System;

namespace NS_Composants
{
	ref class CL_map_TBPERSONNE
	{
	private:
		int id_personne;
		String^ _nom;
		String^ _prenom;
		String^ _date;
		int _noRue;
		String^ _adress;
		String^ _ville;
		int _cp;
		CL_CAD^ dataAccess;
	public:
		CL_map_TBPERSONNE(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);

		// Seters Geters ---------------
		int getId(void);
		void setId(int);
		//Info personnel
		String^ getNom(void);
		void setNom(String^);
		String^ getPrenom(void);
		void setPrenom(String^);
		//Date
		String^ getDate(void);
		void setDate(String^);
		//Adresse
		int getNoRue(void);
		void setNoRue(int);
		String^ getAdress(void);
		void setAdress(String^);
		String^ getVille(void);
		void setVille(String^);
		int getCp(void);
		void setCp(int);

	};
}




