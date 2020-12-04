#pragma once
#include "CL_map_TBCLIENT.h"

using namespace System::Data;
using namespace System::Data::SqlClient;		//(pour SQL SERVER)
using namespace System::Xml;
using namespace System;
using namespace NS_Composants;

namespace NS_Svc
{
	ref class CL_svc_gestionClients
	{
	private:
		CL_CAD^ dataAccess;
		CL_map_TBCLIENT^ mapTabl;
		DataSet^ datasetAdress;
		DataSet^ datasetClient;
	public:
		CL_svc_gestionClients(void);
		DataSet^ listeClients(String^);
		DataSet^ listeAdressesFacturation(String^, int);
		DataSet^ listeAdressesLivraison(String^, int);
		int ajouterClient(String^, String^, String^, String^);
		void ajouterAdresseFacturation(int, int, String^, String^, int);
		void ajouterAdresseLivraison(int, int, String^, String^, int);
		void modifierAdresseLivraison(int, int, String^, String^, int);
		void modifierAdresseFacturation(int, int, String^, String^, int);
		void modifierClient(int, String^, String^, String^, String^);
		void supprimer(int);
	};
}


