#include "CL_svc_gestionPersonnes.h"

NS_Svc::CL_svc_gestionPersonnes::CL_svc_gestionPersonnes(void)
{
	dataAccess = gcnew CL_CAD;
	mapTabl = gcnew CL_map_TBPERSONNE;
	dataset = gcnew DataSet;
}

DataSet^ NS_Svc::CL_svc_gestionPersonnes::listePersonnes(String^ dataTableName)
{
	dataset->Clear();
	dataset = dataAccess->getRows(mapTabl->SELECT(), dataTableName);
	return dataset;
}

int NS_Svc::CL_svc_gestionPersonnes::ajouter(String^ nom, String^ prenom, String^ dateembauche, int norue, String^ adr, String^ ville, int cp)
{
	int id_personne;

	mapTabl->setNom(nom);
	mapTabl->setPrenom(prenom);
	mapTabl->setDate(dateembauche);
	mapTabl->setNoRue(norue);
	mapTabl->setAdress(adr);
	mapTabl->setVille(ville);
	mapTabl->setCp(cp);
	id_personne = dataAccess->actionRowsID(mapTabl->INSERT());

	return id_personne;
}
void NS_Svc::CL_svc_gestionPersonnes::modifier(int id, String^ nom, String^ prenom, String^ date, int norue, String^ adr, String^ ville, int cp)
{
	mapTabl->setId(id);
	mapTabl->setNom(nom);
	mapTabl->setPrenom(prenom);
	mapTabl->setDate(date);
	mapTabl->setNoRue(norue);
	mapTabl->setAdress(adr);
	mapTabl->setVille(ville);
	mapTabl->setCp(cp);
	dataAccess->actionRows(mapTabl->UPDATE());
}

void NS_Svc::CL_svc_gestionPersonnes::supprimer(int id)
{
	mapTabl->setId(id);
	dataAccess->actionRows(mapTabl->DELETE());
}