#include "CL_map_Commande.h"

NS_Composants::CL_map_Commande::CL_map_Commande()
{

}
String^ NS_Composants::CL_map_Commande::SELECTCLI(String^ id, String^ prenom, String^ nom)
{
	return "SELECT * FROM Commande INNER JOIN Client ON Client.IdClient = Commande.IdClient WHERE Commande.IdCLient = '" + id + "' AND Client.NomCLient = '" + nom + "' AND Client.PrenomClient = '" + prenom + "'";
}

String^ NS_Composants::CL_map_Commande::SELECTDATE(String^ day, String^ month, String^ year)
{
	return "SELECT * FROM Commande INNER JOIN Date ON Date.IdDate = Commande.IdDate WHERE DAY(Date.Date) = '" + day + "' AND MONTH(Date.Date) = '" + month + "' AND YEAR(Date.Date) = '" + year + "'";
}

String^ NS_Composants::CL_map_Commande::SELECTREF(String^ ref)
{
	return "SELECT * FROM Commande WHERE Commande.RefCommande = '" + ref + "'";
}


//	Commande ajouter. A modifier
String^ NS_Composants::CL_map_Commande::INSERT(void)
{
	return "INSERT INTO Date(Date.Date)" + "VALUES('" + getDate() + "')" + "DECLARE @IdDate1 AS int = @@identity;" +
		"INSERT INTO Date(Date.Date)" + "VALUES('" + getDateEmission() + "')" + "DECLARE @IdDate2 AS int = @@identity;" +
		"INSERT INTO Date(Date.Date)" + "VALUES('" + getDatePaiementEnrg() + "')" + "DECLARE @IdDate3 AS int = @@identity;" +
		"INSERT INTO Commande(RefCommande, MontantTotalHT, MontantTotalTTC, MontantTotalTVA, IdDate, IdDate_Emission, IdDate_SoldePaiementEnregistre, IdClient)" +
		"VALUES('" + getRefCommande() + "', " + getMontantHT() + ", " + getMontantTTC() + ", '" + getMontantTVA() + "', @IdDate1, @IdDate2, @IdDate3, " + getIdClient() + ")" + "DECLARE @IdCommande AS int = @@identity;";
}



int NS_Composants::CL_map_Commande::getIdCommande()
{
	return idCommande;
}

void NS_Composants::CL_map_Commande::setIdCommande(int val_idCommande)
{
	idCommande = val_idCommande;
}

String^ NS_Composants::CL_map_Commande::getRefCommande()
{
	return refCommande;
}

void NS_Composants::CL_map_Commande::setRefCommande(String^ val_RefCommande)
{
	refCommande = val_RefCommande;
}

int NS_Composants::CL_map_Commande::getMontantHT()
{
	return MontantHT;
}

void NS_Composants::CL_map_Commande::setMontantHT(int val_MontantHT)
{
	MontantHT = val_MontantHT;
}

int NS_Composants::CL_map_Commande::getMontantTTC()
{
	return MontantTTC;
}

void NS_Composants::CL_map_Commande::setMontantTTC(int val_MontantTTC)
{
	MontantTTC = val_MontantTTC;
}

String^ NS_Composants::CL_map_Commande::getMontantTVA()
{
	return MontantTVA;
}

void NS_Composants::CL_map_Commande::setMontantTVA(String^ val_MontantTVA)
{
	MontantTVA = val_MontantTVA;
}

int NS_Composants::CL_map_Commande::getIdDate()
{
	return IdDate;
}

void NS_Composants::CL_map_Commande::setIdDate(int val_IdDate)
{
	IdDate = val_IdDate;
}

int NS_Composants::CL_map_Commande::getIdDateEmission()
{
	return IdDateEmission;
}

void NS_Composants::CL_map_Commande::setIdDateEmission(int val_IdDateEmission)
{
	IdDateEmission = val_IdDateEmission;
}

int NS_Composants::CL_map_Commande::getIdDateSoldePaiementEnrg()
{
	return IdDateSoldePaiementEnrg;
}

void NS_Composants::CL_map_Commande::setIdDateSoldePaiementEnrg(int val_IdDateSoldePaiementEnrg)
{
	IdDateSoldePaiementEnrg = val_IdDateSoldePaiementEnrg;
}

DateTime^ NS_Composants::CL_map_Commande::getDate()
{
	return Date;
}

void NS_Composants::CL_map_Commande::setDate(DateTime^ val_Date)
{
	Date = val_Date;
}

DateTime^ NS_Composants::CL_map_Commande::getDateEmission()
{
	return DateEmission;
}

void NS_Composants::CL_map_Commande::setDateEmission(DateTime^ val_DateEmission)
{
	DateEmission = val_DateEmission;
}

DateTime^ NS_Composants::CL_map_Commande::getDatePaiementEnrg()
{
	return DatePaiementEnrg;
}

void NS_Composants::CL_map_Commande::setDatePaiementEnrg(DateTime^ val_DatePaiementEnrg)
{
	DatePaiementEnrg = val_DatePaiementEnrg;
}

int NS_Composants::CL_map_Commande::getIdClient()
{
	return IdClient;
}

void NS_Composants::CL_map_Commande::setIdClient(int val_IdClient)
{
	IdClient = val_IdClient;
}

String^ NS_Composants::CL_map_Commande::getNomClient()
{
	return nomClient;
}

void NS_Composants::CL_map_Commande::setNomClient(String^ val_NomClient)
{
	nomClient = val_NomClient;
}

String^ NS_Composants::CL_map_Commande::getPrenomClient()
{
	return prenomClient;
}

void NS_Composants::CL_map_Commande::setPrenomClient(String^ val_PrenomClient)
{
	prenomClient = val_PrenomClient;
}

