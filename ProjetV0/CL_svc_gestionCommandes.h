#pragma once
#include "CL_CAD.h"
#include "CL_map_Commande.h"

//Couche service
//classe service de gestion des processus Personne
using namespace System::Data;
using namespace System::Data::SqlClient;        //(pour SQL SERVER)
using namespace System::Xml;
using namespace System;
using namespace NS_Composants;


namespace NS_Svc
{
    ref class CL_svc_gestionCommandes
    {
    private:
        CL_CAD^ dataAccessCom;
        CL_map_Commande^ mapTablCom;
        DataSet^ datasetCom;
    public:
        CL_svc_gestionCommandes(void);
        DataSet^ afficherParClient(String^, String^, String^);
        DataSet^ afficherParDate(String^, String^, String^);
        DataSet^ afficherParRef(String^);
        void ajouter(String^, DateTime^, DateTime^, DateTime^, int, int, String^, int);
    };
}
