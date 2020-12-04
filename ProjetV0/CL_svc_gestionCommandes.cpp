#include "CL_svc_gestionCommandes.h"

NS_Svc::CL_svc_gestionCommandes::CL_svc_gestionCommandes(void)
{
    dataAccessCom = gcnew CL_CAD;
    mapTablCom = gcnew CL_map_Commande;
    datasetCom = gcnew DataSet;
}

DataSet^ NS_Svc::CL_svc_gestionCommandes::afficherParClient(String^ id, String^ prenom, String^ nom)
{
    datasetCom->Clear();

    datasetCom = dataAccessCom->getRows(mapTablCom->SELECTCLI(id, prenom, nom), "Values");

    return datasetCom;
}

DataSet^ NS_Svc::CL_svc_gestionCommandes::afficherParDate(String^ day, String^ month, String^ year)
{
    datasetCom->Clear();

    datasetCom = dataAccessCom->getRows(mapTablCom->SELECTDATE(day, month, year), "Values");

    return datasetCom;
}

DataSet^ NS_Svc::CL_svc_gestionCommandes::afficherParRef(String^ ref)
{
    datasetCom->Clear();

    datasetCom = dataAccessCom->getRows(mapTablCom->SELECTREF(ref), "Values");

    return datasetCom;
}

void NS_Svc::CL_svc_gestionCommandes::ajouter(String^ RefCommande, DateTime^ Date, DateTime^ DateEmission, DateTime^ DatePaiementEnrg, int MontantHT, int MontantTTC, String^ MontantTVA, int IdClient)
{
    //Infos Commmande
    mapTablCom->setRefCommande(RefCommande);
    //Dates
    mapTablCom->setDate(Date);
    mapTablCom->setDateEmission(DateEmission);
    mapTablCom->setDatePaiementEnrg(DatePaiementEnrg);;
    //Infos Montants
    mapTablCom->setMontantHT(MontantHT);
    mapTablCom->setMontantTTC(MontantTTC);
    mapTablCom->setMontantTVA(MontantTVA);

    dataAccessCom->actionRows(mapTablCom->INSERT());
}