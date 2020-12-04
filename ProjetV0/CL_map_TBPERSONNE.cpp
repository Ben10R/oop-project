#include "CL_map_TBPERSONNE.h"

NS_Composants::CL_map_TBPERSONNE::CL_map_TBPERSONNE(void) : id_personne(-1), _nom("RIEN"), _prenom("RIEN")
{

}
String^ NS_Composants::CL_map_TBPERSONNE::SELECT(void)
{
	return "SELECT IdPersonnel, NomPersonnel, PrenomPersonnel, FORMAT(Date, 'yyyy/MM/dd'), NoRue, Addresse, Ville, CP FROM Personnel " +
		"INNER JOIN Date ON(Personnel.IdDate = Date.IdDate) " +
		"INNER JOIN Adresse ON(Personnel.IdAdresse = Adresse.IdAdresse)";
}
String^ NS_Composants::CL_map_TBPERSONNE::INSERT(void)
{
	dataAccess = gcnew CL_CAD;
	int id_date = dataAccess->actionRowsID("SELECT * FROM Date WHERE Date IN ('" + getDate() + "')");
	if (id_date == 0 )
	{
		return "INSERT INTO Adresse (NoRue, Addresse, Ville, CP)" +
					"VALUES(" + getNoRue() + ", '" + getAdress() + "', '" + getVille() + "', " + getCp() + ");" +
					"DECLARE @Id1 AS int = @@identity;" +
					"INSERT INTO Date(Date)" +
					"VALUES('" + getDate() + "');" +
					"DECLARE @Id2 AS int = @@identity;" +
					"INSERT INTO Personnel(NomPersonnel, PrenomPersonnel, IdAdresse, IdDate)" +
					"VALUES('" + getNom() + "', '" + getPrenom() + "', @Id1, @Id2);";
	}
	else
	{
		return "INSERT INTO Adresse (NoRue, Addresse, Ville, CP)" +
					"VALUES('420', 'Rue des Iddatepas0', 'Stylax', '75016');" +
					"DECLARE @Id1 AS int = @@identity;" +
					"INSERT INTO Personnel(NomPersonnel, PrenomPersonnel, IdAdresse, IdDate)" +
					"VALUES('" + getNom() + "', '" + getPrenom() + "', @Id1, "+ id_date + ");";
	}	
}
String^ NS_Composants::CL_map_TBPERSONNE::UPDATE(void)
{
	dataAccess = gcnew CL_CAD;
	int id_date = dataAccess->actionRowsID("SELECT * FROM Date WHERE Date IN ('" + getDate() + "')");
	if (id_date == 0)
	{
		return "INSERT INTO Date(Date) VALUES('" + getDate() + "');" +
			"DECLARE @Id1 AS int = @@identity;" +
			"UPDATE Personnel " +
			"SET NomPersonnel = '" + getNom() +"', PrenomPersonnel = '" + getPrenom() + "', IdDate = @Id1 " +
			"FROM Personnel WHERE IdPersonnel = " + getId() + ";" +
			"UPDATE Adresse " +
			"SET NoRue = " + getNoRue() +", Addresse = '" + getAdress() + "', Ville = '" + getVille() + "', CP = " + getCp() +
			" FROM Adresse "
			"INNER JOIN Personnel ON(Adresse.IdAdresse = Personnel.IdAdresse) "
			"WHERE IdPersonnel = " + getId() + ";";
	}
	else
	{
		return "UPDATE Personnel " +
				"SET NomPersonnel = '" + getNom() + "', PrenomPersonnel = '" + getPrenom() + "', IdDate = " + id_date +
				" FROM Personnel WHERE IdPersonnel = " + getId() + ";" +
				"UPDATE Adresse " +
				"SET NoRue = " + getNoRue() + ", Addresse = '" + getAdress() + "', Ville = '" + getVille() + "', CP = " + getCp() +
				" FROM Adresse "
				"INNER JOIN Personnel ON(Adresse.IdAdresse = Personnel.IdAdresse) "
				"WHERE IdPersonnel = " + getId() + ";";
	}
}
String^ NS_Composants::CL_map_TBPERSONNE::DELETE(void)
{
	return "DECLARE @ID int;" +
		"SELECT @ID = IdAdresse " +
		"FROM Personnel " +
		"where IdPersonnel = " + getId() + ";" +
		"DELETE FROM Personnel WHERE IdPersonnel = " + getId() + ";" +
		"DELETE Adresse FROM Adresse " +
		"INNER JOIN Personnel " +
		"ON Adresse.IdAdresse = Personnel.IdAdresse " +
		"WHERE IdPersonnel = " + getId() + ";"
		"SELECT* FROM Adresse INNER JOIN Personnel " +
		"ON Adresse.IdAdresse = Personnel.IdAdresse";
}

int NS_Composants::CL_map_TBPERSONNE::getId(void)
{
	return id_personne;
}
void NS_Composants::CL_map_TBPERSONNE::setId(int id)
{
	if (id > 0)
	{
		id_personne = id;
	}
}
String^ NS_Composants::CL_map_TBPERSONNE::getNom(void)
{
	return _nom;
}
void NS_Composants::CL_map_TBPERSONNE::setNom(String^ nom)
{
	if (_nom != "")
	{
		_nom = nom;
	}
}
String^ NS_Composants::CL_map_TBPERSONNE::getPrenom(void)
{
	return _prenom;
}
void NS_Composants::CL_map_TBPERSONNE::setPrenom(String^ prenom)
{
	if (_nom != "")
	{
		_prenom = prenom;
	}
}
String^ NS_Composants::CL_map_TBPERSONNE::getDate(void)
{
	return _date;
}
void NS_Composants::CL_map_TBPERSONNE::setDate(String^ date)
{
	this->_date = date;
}

int NS_Composants::CL_map_TBPERSONNE::getNoRue(void)
{
	return _noRue;
}

void NS_Composants::CL_map_TBPERSONNE::setNoRue(int norue)
{
	this->_noRue = norue;
}

String^ NS_Composants::CL_map_TBPERSONNE::getAdress(void)
{
	return _adress;
}

void NS_Composants::CL_map_TBPERSONNE::setAdress(String^ adr)
{
	this->_adress = adr;
}

String^ NS_Composants::CL_map_TBPERSONNE::getVille(void)
{
	return _ville;
}

void NS_Composants::CL_map_TBPERSONNE::setVille(String^ ville)
{
	this->_ville = ville;
}

int NS_Composants::CL_map_TBPERSONNE::getCp(void)
{
	return _cp;
}

void NS_Composants::CL_map_TBPERSONNE::setCp(int cp)
{
	this->_cp = cp;
}
