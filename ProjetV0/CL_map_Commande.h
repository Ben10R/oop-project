#pragma once
#include "CL_CAD.h"

namespace NS_Composants
{
    ref class CL_map_Commande
    {
    private:
        int idCommande;
        String^ refCommande;
        int MontantHT;
        int MontantTTC;
        String^ MontantTVA;
        int IdDate;
        int IdDateEmission;
        int IdDateSoldePaiementEnrg;
        DateTime^ Date;
        DateTime^ DateEmission;
        DateTime^ DatePaiementEnrg;
        int IdClient;
        String^ nomClient;
        String^ prenomClient;
        CL_CAD^ dataAccessCom;


    public:
        CL_map_Commande(void); // Constructeur

        //
        // Geters Seters
        //
        int getIdCommande();
        void setIdCommande(int);
        String^ getRefCommande();
        void setRefCommande(String^);
        int getMontantHT();
        void setMontantHT(int);
        int getMontantTTC();
        void setMontantTTC(int);
        String^ getMontantTVA();
        void setMontantTVA(String^);
        int getIdDate();
        void setIdDate(int);
        int getIdDateEmission();
        void setIdDateEmission(int);
        int getIdDateSoldePaiementEnrg();
        void setIdDateSoldePaiementEnrg(int);
        DateTime^ getDate();
        void setDate(DateTime^);
        DateTime^ getDateEmission();
        void setDateEmission(DateTime^);
        DateTime^ getDatePaiementEnrg();
        void setDatePaiementEnrg(DateTime^);
        int getIdClient();
        void setIdClient(int);
        String^ getNomClient();
        void setNomClient(String^);
        String^ getPrenomClient();
        void setPrenomClient(String^);
        //
        // Methodes
        //
        String^ SELECTCLI(String^, String^, String^);
        String^ SELECTDATE(String^, String^, String^);
        String^ SELECTREF(String^);
        String^ INSERT(void);

    };
}