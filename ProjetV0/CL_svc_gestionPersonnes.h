#pragma once
#include "CL_CAD.h"
#include "CL_map_TBPERSONNE.h"
//Couche service
//classe service de gestion des processus Personne
using namespace System::Data;
using namespace System::Data::SqlClient;		//(pour SQL SERVER)
using namespace System::Xml;
using namespace System;
using namespace NS_Composants;


namespace NS_Svc
{
	ref class CL_svc_gestionPersonnes
	{
	private:
		CL_CAD^ dataAccess;
		CL_map_TBPERSONNE^ mapTabl;
		DataSet^ dataset;
	public:
		CL_svc_gestionPersonnes(void);
		DataSet^ listePersonnes(String^);
		int ajouter(String^, String^, String^, int, String^, String^, int);
		void modifier(int, String^, String^, String^, int, String^, String^, int);
		void supprimer(int);
	};
}



