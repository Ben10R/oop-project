#include "CL_svc_gestionClients.h"

NS_Svc::CL_svc_gestionClients::CL_svc_gestionClients(void)
{
	dataAccess = gcnew CL_CAD;
	mapTabl = gcnew CL_map_TBCLIENT;
	datasetAdress = gcnew DataSet;
	datasetClient = gcnew DataSet;
}

DataSet^ NS_Svc::CL_svc_gestionClients::listeClients(String^ dataTableName)
{
	datasetClient->Clear();
	datasetClient = dataAccess->getRows(mapTabl->SELECTCLIENT(), dataTableName);
	return datasetClient;
}

DataSet^ NS_Svc::CL_svc_gestionClients::listeAdressesFacturation(String^ dataTableName, int id)
{
	datasetAdress->Clear();

	mapTabl->setIdClient(id);
	datasetAdress = dataAccess->getRows(mapTabl->SELECTADRRESSEFACTURATION(), dataTableName);

	return datasetAdress;
}
DataSet^ NS_Svc::CL_svc_gestionClients::listeAdressesLivraison(String^ dataTableName, int id)
{
	datasetAdress->Clear();

	mapTabl->setIdClient(id);
	datasetAdress = dataAccess->getRows(mapTabl->SELECTADRRESSELIVRAISON(), dataTableName);

	return datasetAdress;
}

//	INSERT
int NS_Svc::CL_svc_gestionClients::ajouterClient(String^ nomCli, String^ prenomCli, String^ dateNaissance, String^ datePremierAchat)
{
	mapTabl->setNom(nomCli);
	mapTabl->setPrenom(prenomCli);
	mapTabl->setDateNaissance(dateNaissance);
	mapTabl->setDatePremAchat(datePremierAchat);

	return (dataAccess->actionRowsID(mapTabl->INSERTCLIENT()));
}
void NS_Svc::CL_svc_gestionClients::ajouterAdresseFacturation(int id, int norue, String^ adr, String^ ville, int cp)
{
	mapTabl->setIdClient(id);
	mapTabl->setNoRue(norue);
	mapTabl->setAdress(adr);
	mapTabl->setVille(ville);
	mapTabl->setCp(cp);
	
	dataAccess->actionRows(mapTabl->INSERTADRESSFACT());
}
void NS_Svc::CL_svc_gestionClients::ajouterAdresseLivraison(int id, int norue, String^ adr, String^ ville, int cp)
{
	mapTabl->setIdClient(id);
	mapTabl->setNoRue(norue);
	mapTabl->setAdress(adr);
	mapTabl->setVille(ville);
	mapTabl->setCp(cp);

	dataAccess->actionRows(mapTabl->INSERTADRESSLIVR());
}

//	UPDATE
void NS_Svc::CL_svc_gestionClients::modifierClient(int idClient, String^ nom, String^ prenom, String^ datenaissance, String^ datePremAchat)
{
	mapTabl->setIdClient(idClient);
	mapTabl->setNom(nom);
	mapTabl->setPrenom(prenom);
	mapTabl->setDateNaissance(datenaissance);
	mapTabl->setAdress(datePremAchat);
	dataAccess->actionRows(mapTabl->UPDATECLIENT());
}
void NS_Svc::CL_svc_gestionClients::modifierAdresseLivraison(int idAdresse, int noRue, String^ adress, String^ ville, int cp)
{
	mapTabl->setIdAdresseLivraison(idAdresse);
	mapTabl->setNoRue(noRue);
	mapTabl->setAdress(adress);
	mapTabl->setVille(ville);
	mapTabl->setCp(cp);
	dataAccess->actionRows(mapTabl->UPDATEADRESSELIVR());
}
void NS_Svc::CL_svc_gestionClients::modifierAdresseFacturation(int idAdresse, int noRue, String^ adress, String^ ville, int cp)
{
	mapTabl->setIdAdresseFacturation(idAdresse);
	mapTabl->setNoRue(noRue);
	mapTabl->setAdress(adress);
	mapTabl->setVille(ville);
	mapTabl->setCp(cp);
	dataAccess->actionRows(mapTabl->UPDATEADRESSEFACT());
}

void NS_Svc::CL_svc_gestionClients::supprimer(int id)
{
	mapTabl->setIdClient(id);
	dataAccess->actionRows(mapTabl->DELETE());
}
