#include "CL_map_TBCLIENT.h"

NS_Composants::CL_map_TBCLIENT::CL_map_TBCLIENT(void)
{

}

String^ NS_Composants::CL_map_TBCLIENT::SELECTCLIENT(void)
{
	return "SELECT IdClient, NomClient, PrenomClient, FORMAT(D1.Date, 'yyyy/MM/dd'), FORMAT(D2.Date, 'yyyy/MM/dd') FROM Client C1 INNER JOIN Date D1 " +
		"ON D1.IdDate = C1.IdDate_PremierAchat " +
		"INNER JOIN Date D2 " +
		"ON D2.IdDate = C1.IdDate";
}
String^ NS_Composants::CL_map_TBCLIENT::SELECTADRRESSEFACTURATION(void)
{
	return "SELECT IdAdresse, NoRue, Addresse, Ville, CP FROM Adresse WHERE Adresse.IdClient_AdresserFacturer = " + getIdClient() + ";";
}
String^ NS_Composants::CL_map_TBCLIENT::SELECTADRRESSELIVRAISON(void)
{
	return "SELECT IdAdresse, NoRue, Addresse, Ville, CP FROM Adresse WHERE Adresse.IdClient_AdresserLivrer = " + getIdClient() + ";";
}

String^ NS_Composants::CL_map_TBCLIENT::INSERTCLIENT(void)
{
	dataAccess = gcnew CL_CAD;
	int id_date = dataAccess->actionRowsID("SELECT * FROM Date WHERE Date IN ('" + getDatePremAchat() + "')");
	if (id_date == 0)
	{
		return "INSERT INTO Date (Date) VALUES ('" + getDateNaissance() + "');" +
			"DECLARE @Id1 AS int = @@identity;" +
			"INSERT INTO Date(Date) VALUES('" + getDatePremAchat() + "');" +
			"DECLARE @Id2 AS int = @@identity;" +
			"INSERT INTO Client(NomClient, PrenomClient, IdDate, IdDate_PremierAchat) " +
			"VALUES('" + getNom() + "', '" + getPrenom() + "', @Id1, @Id2);" +
			"SELECT @@IDENTITY; ";
	}
	else 
	{
		return "INSERT INTO Date (Date) VALUES ('" + getDateNaissance() + "');" +
			"DECLARE @Id1 AS int = @@identity;" +
			"INSERT INTO Client(NomClient, PrenomClient, IdDate, IdDate_PremierAchat) " +
			"VALUES('" + getNom() + "', '" + getPrenom() + "', @Id1," + getDatePremAchat() + ");" +
			"SELECT @@IDENTITY; ";;
	}
}
String^ NS_Composants::CL_map_TBCLIENT::INSERTADRESSFACT(void)
{
	return "INSERT INTO Adresse (NoRue, Addresse, Ville, CP, IdClient_AdresserFacturer)" +
				"VALUES (" + getNoRue() + ",'" + getAdress() + "','" + getVille() + "'," + getCp() + "," + getIdClient() + ");";
}
String^ NS_Composants::CL_map_TBCLIENT::INSERTADRESSLIVR(void)
{
	return "INSERT INTO Adresse (NoRue, Addresse, Ville, CP, IdClient_AdresserLivrer)" +
		"VALUES (" + getNoRue() + ",'" + getAdress() + "','" + getVille() + "'," + getCp() + "," + getIdClient() + ");";
}

//UPDATE
String^ NS_Composants::CL_map_TBCLIENT::UPDATECLIENT(void)
{
	dataAccess = gcnew CL_CAD;
	int id_Birthdate = dataAccess->actionRowsID("SELECT * FROM Date WHERE Date IN ('" + getDateNaissance() + "')");
	int id_datePrem = dataAccess->actionRowsID("SELECT * FROM Date WHERE Date IN ('" + getDatePremAchat() + "')");
	if (id_Birthdate == 0 && id_datePrem == 0)
	{
		return "INSERT INTO Date(Date) VALUES('" + getDatePremAchat() + "');" +
			"DECLARE @Id1 AS int = @@identity;" +
			"INSERT INTO Date(Date) VALUES('" + getDateNaissance() + "');" +
			"DECLARE @Id2 AS int = @@identity;" +
			"UPDATE Client " +
			"SET NomClient = '" + getNom() + "', PrenomClient = '" + getPrenom() + "', idDate = @Id2," + 
			"IdDate_PremierAchat = @Id1 " +
			"WHERE IdClient = " + getIdClient() + ";";
	}
	else if (id_Birthdate != 0 && id_datePrem == 0)
	{
		return "INSERT INTO Date(Date) VALUES('" + getDatePremAchat() + "');" +
				"DECLARE @Id1 AS int = @@identity;"
				"UPDATE Client " +
				"SET NomClient = '" + getNom() + "', PrenomClient = '" + getPrenom() + "', idDate = " + id_Birthdate + ", IdDate_PremierAchat = @Id1" + 
				" WHERE IdClient = " + getIdClient() + ";";
	}
	else if (id_Birthdate == 0 && id_datePrem != 0)
	{
		return "INSERT INTO Date(Date) VALUES('" + getDateNaissance() + "');" +
			"DECLARE @Id1 AS int = @@identity;"
			"UPDATE Client " +
			"SET NomClient = '" + getNom() + "', PrenomClient = '" + getPrenom() + "', idDate = @Id1, IdDate_PremierAchat =" + id_datePrem +
			" WHERE IdClient = " + getIdClient() + ";";
	}
	else if (id_Birthdate != 0 && id_datePrem != 0)
	{
		return "UPDATE Client " +
				"SET NomClient = '" + getNom() + "', PrenomClient = '" + getPrenom() + "', idDate = " + id_Birthdate + 
				",IdDate_PremierAchat =" + id_datePrem +
				" WHERE IdClient = " + getIdClient() + ";";
	}
}
String^ NS_Composants::CL_map_TBCLIENT::UPDATEADRESSELIVR(void)
{
	return "UPDATE Adresse SET NoRue= " + getNoRue() + ", Addresse = '" + getAdress() + "', Ville = '" + getVille() + "', CP =" + getCp() + " WHERE (idAdresse = " + getIdAdresseLivraison() + ");";
}
String^ NS_Composants::CL_map_TBCLIENT::UPDATEADRESSEFACT(void)
{
	return "UPDATE Adresse SET NoRue= " + getNoRue() + ", Addresse = '" + getAdress() + "', Ville = '" + getVille() + "', CP =" + getCp() + " WHERE (idAdresse = " + getIdAdresseFacturation() + ");";
}

String^ NS_Composants::CL_map_TBCLIENT::DELETE(void)
{
	return "DELETE FROM Adresse WHERE IdClient_AdresserFacturer =" + getIdClient() + ";" +
			"DELETE FROM Adresse WHERE IdClient_AdresserLivrer =" + getIdClient() + ";" +
			"DELETE FROM Client WHERE IdClient =" + getIdClient() + ";";
}		

int NS_Composants::CL_map_TBCLIENT::getIdClient(void)
{
	return id_client;
}

void NS_Composants::CL_map_TBCLIENT::setIdClient(int id)
{
	this->id_client = id;
}

String^ NS_Composants::CL_map_TBCLIENT::getDateNaissance(void)
{
	return _dateNaissance;;
}

void NS_Composants::CL_map_TBCLIENT::setDateNaissance(String^ date)
{
	this->_dateNaissance = date;
}

String^ NS_Composants::CL_map_TBCLIENT::getDatePremAchat(void)
{
	return _datePremAchat;
}

void NS_Composants::CL_map_TBCLIENT::setDatePremAchat(String^ DatePremAchat)
{
	this->_datePremAchat = DatePremAchat;;
}

String^ NS_Composants::CL_map_TBCLIENT::getNom(void)
{
	return _nom;
}

void NS_Composants::CL_map_TBCLIENT::setNom(String^ nom)
{
	this->_nom = nom;
}

String^ NS_Composants::CL_map_TBCLIENT::getPrenom(void)
{
	return _prenom;
}

void NS_Composants::CL_map_TBCLIENT::setPrenom(String^ prenom)
{
	this->_prenom = prenom;
}

void NS_Composants::CL_map_TBCLIENT::setIdAdresseLivraison(int id)
{
	this->IdAdressLivraison = id;
}

int NS_Composants::CL_map_TBCLIENT::getIdAdresseLivraison(void)
{
	return IdAdressLivraison;
}

void NS_Composants::CL_map_TBCLIENT::setIdAdresseFacturation(int id)
{
	this->IdAdressFacturation = id;
}

int NS_Composants::CL_map_TBCLIENT::getIdAdresseFacturation(void)
{
	return IdAdressFacturation;
}

void NS_Composants::CL_map_TBCLIENT::setNoRue(int norue)
{
	this->_noRue = norue;
}
int NS_Composants::CL_map_TBCLIENT::getNoRue(void)
{
	return _noRue;
}

void NS_Composants::CL_map_TBCLIENT::setAdress(String^ adr)
{
	this->_adress = adr;
}

String^ NS_Composants::CL_map_TBCLIENT::getAdress(void)
{
	return _adress;
}

void NS_Composants::CL_map_TBCLIENT::setVille(String^ ville)
{
	this->_ville = ville;
}

String^ NS_Composants::CL_map_TBCLIENT::getVille(void)
{
	return _ville;
}

void NS_Composants::CL_map_TBCLIENT::setCp(int cp)
{
	this->_cp = cp;
}

int NS_Composants::CL_map_TBCLIENT::getCp(void)
{
	return _cp;
}
