#include "Services_Stocks.h"

NS_Svc::Services_Stocks::Services_Stocks(void)
{
	dataAccess = gcnew CL_CAD;
	dataset = gcnew DataSet;
}

void NS_Svc::Services_Stocks::ajouterArticle(String^ valNomArticle, String^ valDesignationArticle, int valSeuilReapro, int valQuantiteStockArticle, String^ valNature, int valTauxTVA)
{
	ajouterArticle(gcnew Stock(valNomArticle, valDesignationArticle, valSeuilReapro, valQuantiteStockArticle, valNature, valTauxTVA));
}

void NS_Svc::Services_Stocks::checkTVA(int valTauxTVA)
{
	if (dataAccess->recupPersString("SELECT IdTVA FROM TVA WHERE TauxTVA = " + valTauxTVA + " ;") == "")
	{
		dataAccess->actionRows("INSERT INTO TVA (TauxTVA) VALUES (" + valTauxTVA + ");");
	}
}

void NS_Svc::Services_Stocks::checkNature(String^ valNature)
{
	if (dataAccess->recupPersString("SELECT Nature FROM Nature WHERE Nature = '" + valNature + "' ;") == "")
	{
		dataAccess->actionRows("INSERT INTO Nature (Nature) VALUES ('" + valNature + "');");
	}
}

void NS_Svc::Services_Stocks::ajouterArticle(Stock^ p)
{
	if (p->getNomArticle() == dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE NomArticle = '" + p->getNomArticle() + "' ;"))
	{
		int tmpId = Convert::ToInt32(dataAccess->recupPersString("SELECT IdArticle FROM Catalogue WHERE NomArticle = '" + p->getNomArticle() + "' ;"));
		int tmpQuantiteStockArticle = Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + tmpId + " ;"));
		dataAccess->actionRows("UPDATE Catalogue SET QuantiteStockArticle = " + (tmpQuantiteStockArticle + p->getQuantiteStockArticle()) + " WHERE IdArticle= " + tmpId + " ;");
	}

	else
	{
		checkNature(p->getNature());
		checkTVA(p->getTauxTVA());

		dataAccess->actionRows("INSERT INTO Catalogue (NomArticle, DesignationArticle, SeuilReapro, QuantiteStockArticle, IdNature, IdTVA) VALUES ('" + p->getNomArticle() + "','"
			+ p->getDesignationArticle() + "'," + p->getSeuilReapro() + "," + p->getQuantiteStockArticle() + ",(SELECT IdNature FROM Nature WHERE Nature ='"
			+ p->getNature() + "'),(SELECT IdTVA FROM TVA WHERE TauxTVA =" + p->getTauxTVA() + "));");
	}
}

void NS_Svc::Services_Stocks::modifierArticle(int valIdArticle, String^ valNomArticle, String^ valDesignationArticle, int valSeuilReapro, int valQuantiteStockArticle, int valIdNature, String^ valNature, int valIdTVA, int valTauxTVA)
{
	if (Convert::ToString(valIdNature) != "")
	{
		dataAccess->actionRows("UPDATE Nature SET Nature = '" + valNature + "' WHERE IdNature = " + valIdNature + " ;");
	}

	if (Convert::ToString(valIdTVA) != "")
	{
		dataAccess->actionRows("UPDATE TVA SET TauxTVA = " + valTauxTVA + " WHERE IdTVA = " + valIdTVA + " ;");
	}

	if (Convert::ToString(valIdArticle) != "")
	{
		dataAccess->actionRows("UPDATE Catalogue SET NomArticle= '" + valNomArticle + "', DesignationArticle= '" + valDesignationArticle + "',SeuilReapro= " + valSeuilReapro + ", QuantiteStockArticle= "
			+ valQuantiteStockArticle + ", IdNature = (SELECT IdNature FROM Nature WHERE Nature = '" + valNature + "'), IdTVA = (SELECT IdTVA FROM TVA WHERE TauxTVA = " + valTauxTVA + ")"
			+ "WHERE IdArticle =" + valIdArticle + ";");
	}
}

void NS_Svc::Services_Stocks::supprimer(int valIdArticle, int valIdNature, int valIdTVA)
{
	if (Convert::ToString(valIdArticle) != "0")
	{
		dataAccess->actionRows("DELETE FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;");
	}

	if (Convert::ToString(valIdNature) != "0")
	{
		if ((Convert::ToString((dataAccess->recupPersString("SELECT COUNT(*) FROM Catalogue WHERE IdNature = " + valIdNature))) == "0"))
		{
			dataAccess->actionRows("DELETE FROM Nature WHERE IdNature = " + valIdNature + " ;");
		}
	}

	if (Convert::ToString(valIdTVA) != "0")
	{
		if ((Convert::ToString((dataAccess->recupPersString("SELECT COUNT(*) FROM Catalogue WHERE IdTVA =" + valIdNature))) == "0"))
		{
			dataAccess->actionRows("DELETE FROM TVA WHERE IdTVA = " + valIdTVA + " ;");
		}
	}
}

Stock^ NS_Svc::Services_Stocks::selectPremierArticle(String^ tableChoisis)
{
	if (tableChoisis == "Article")
	{
		if (dataAccess->recupPersString("SELECT MIN (IdArticle) FROM Catalogue;") != nullptr)
		{
			int valIdArticle = Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdArticle) FROM Catalogue;"));
			int valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT IdNature FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
			int valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT IdTVA FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
			Stock^ p = gcnew Stock(valIdArticle, dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
				dataAccess->recupPersString("SELECT DesignationArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
				(Convert::ToInt32(dataAccess->recupPersString("SELECT SeuilReapro FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
				(Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
				valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"), valIdTVA,
				(Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))));
			return p;
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}

	else if (tableChoisis == "Nature")
	{
		if ((dataAccess->recupPersString("SELECT MIN(IdNature) FROM Nature;")) != nullptr)
		{
			int valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT MIN(IdNature) FROM Nature;"));
			Stock^ p = gcnew Stock(valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"));
			return p;
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}

	else if (tableChoisis == "TVA")
	{
		if (dataAccess->recupPersString("SELECT MIN (IdTVA) FROM TVA;") != nullptr)
		{
			int valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdTVA) FROM TVA;"));
			Stock^ p = gcnew Stock(valIdTVA, Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;")));
			return p;
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}
}

Stock^ NS_Svc::Services_Stocks::selectDernierArticle(String^ tableChoisis)
{
	if (tableChoisis == "Article")
	{
		if (dataAccess->recupPersString("SELECT MAX (IdArticle) FROM Catalogue;") != nullptr)
		{
			int valIdArticle = Convert::ToInt32(dataAccess->recupPersString("SELECT MAX (IdArticle) FROM Catalogue;"));
			int valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT IdNature FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
			int valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT IdTVA FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
			Stock^ p = gcnew Stock(valIdArticle, dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
				dataAccess->recupPersString("SELECT DesignationArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
				(Convert::ToInt32(dataAccess->recupPersString("SELECT SeuilReapro FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
				(Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
				valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"), valIdTVA,
				(Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))));
			return p;
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}

	else if (tableChoisis == "Nature")
	{
		if ((dataAccess->recupPersString("SELECT MAX(IdNature) FROM Nature;") != nullptr))
		{
			int valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT MAX(IdNature) FROM Nature;"));
			Stock^ p = gcnew Stock(valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"));
			return p;
		}

		else
		{
			Stock^ p = gcnew Stock();
		}
	}

	else if (tableChoisis == "TVA")
	{
		if ((dataAccess->recupPersString("SELECT MAX (IdTVA) FROM TVA;") != nullptr))
		{
			int valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT MAX (IdTVA) FROM TVA;"));
			Stock^ p = gcnew Stock(valIdTVA, Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;")));
			return p;
		}

		else
		{
			Stock^ p = gcnew Stock();
		}

	}
}

Stock^ NS_Svc::Services_Stocks::selectPrecedentArticle(int valIdArticle, int valIdNature, int valIdTVA, String^ tableChoisis)
{
	if (tableChoisis == "Article")
	{
		if ((dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + (valIdArticle - 1) + " ;")) != nullptr)
		{
			if (valIdArticle > Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdArticle) FROM Catalogue;")))
			{
				valIdArticle--;
				while (Convert::ToString((dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))) == "")
				{
					valIdArticle--;
				}
				valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT IdNature FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT IdTVA FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				Stock^ p = gcnew Stock(valIdArticle, dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
					dataAccess->recupPersString("SELECT DesignationArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT SeuilReapro FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"), valIdTVA,
					(Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))));
				return p;
			}

			else if (valIdArticle < Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdArticle) FROM Catalogue;")))
			{
				Stock^ p = gcnew Stock();
				return p;
			}

			else
			{
				valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT IdNature FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT IdTVA FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				Stock^ p = gcnew Stock(valIdArticle, dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
					dataAccess->recupPersString("SELECT DesignationArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT SeuilReapro FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"), valIdTVA,
					(Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))));
				return p;
			}
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}

	else if (tableChoisis == "Nature")
	{

		if ((dataAccess->recupPersString("SELECT MIN (IdNature) FROM Nature;")) != nullptr)
		{
			if (valIdNature > Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdNature) FROM Nature;")))
			{
				valIdNature--;
				while ((dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;")) == nullptr)
				{
					valIdNature--;
				}

				Stock^ p = gcnew Stock(valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"));
				return p;
			}

			else
			{
				Stock^ p = gcnew Stock(valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"));
				return p;
			}
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p = gcnew Stock();
		}
	}

	else if (tableChoisis == "TVA")
	{
		if ((dataAccess->recupPersString("SELECT MIN (IdTVA) FROM TVA;")) != nullptr)
		{
			if (valIdTVA > Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdTVA) FROM TVA;")))
			{
				valIdTVA--;
				while (Convert::ToString((dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))) == "")
				{
					valIdTVA--;
				}

				Stock^ p = gcnew Stock(valIdTVA, Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;")));
				return p;
			}

			else if (valIdTVA < Convert::ToInt32(dataAccess->recupPersString("SELECT MIN (IdTVA) FROM TVA;")))
			{
				Stock^ p = gcnew Stock();
				return p;
			}

			else
			{
				Stock^ p = gcnew Stock(valIdTVA, Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;")));
				return p;
			}
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}
}

Stock^ NS_Svc::Services_Stocks::selectSuivantArticle(int valIdArticle, int valIdNature, int valIdTVA, String^ tableChoisis)
{
	if (tableChoisis == "Article")
	{
		if ((dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;")) != nullptr)
		{
			if (valIdArticle < Convert::ToInt32(dataAccess->recupPersString("SELECT MAX (IdArticle) FROM Catalogue;")))
			{
				valIdArticle++;
				while ((Convert::ToString(dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))) == "")
				{
					valIdArticle++;
				}

				valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT IdNature FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT IdTVA FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				Stock^ p = gcnew Stock(valIdArticle, (dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;")),
					(dataAccess->recupPersString("SELECT DesignationArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;")),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT SeuilReapro FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					valIdNature, (dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;")), valIdTVA,
					(Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))));
				return p;
			}

			else
			{
				valIdNature = Convert::ToInt32(dataAccess->recupPersString("SELECT IdNature FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				valIdTVA = Convert::ToInt32(dataAccess->recupPersString("SELECT IdTVA FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"));
				Stock^ p = gcnew Stock(valIdArticle, dataAccess->recupPersString("SELECT NomArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
					dataAccess->recupPersString("SELECT DesignationArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT SeuilReapro FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					(Convert::ToInt32(dataAccess->recupPersString("SELECT QuantiteStockArticle FROM Catalogue WHERE IdArticle = " + valIdArticle + " ;"))),
					valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"), valIdTVA,
					(Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))));
				return p;
			}
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}

	else if (tableChoisis == "Nature")
	{
		if ((dataAccess->recupPersString("SELECT MAX (IdNature) FROM Nature;")) != nullptr)
		{
			if (valIdNature < Convert::ToInt32(dataAccess->recupPersString("SELECT MAX (IdNature) FROM Nature;")))
			{
				valIdNature++;
				while ((dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;")) == nullptr)
				{
					valIdNature++;
				}

				Stock^ p = gcnew Stock(valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"));
				return p;
			}

			else
			{
				Stock^ p = gcnew Stock(valIdNature, dataAccess->recupPersString("SELECT Nature FROM Nature WHERE IdNature = " + valIdNature + " ;"));
				return p;
			}
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}

	else if (tableChoisis == "TVA")
	{
		if ((dataAccess->recupPersString("SELECT MAX (IdTVA) FROM TVA;")) != nullptr)
		{
			if (valIdTVA < Convert::ToInt32(dataAccess->recupPersString("SELECT MAX (IdTVA) FROM TVA;")))
			{
				valIdTVA++;
				while (Convert::ToString((dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;"))) == "")
				{
					valIdTVA++;
				}

				Stock^ p = gcnew Stock(valIdTVA, Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;")));
				return p;
			}

			else
			{
				Stock^ p = gcnew Stock(valIdTVA, Convert::ToInt32(dataAccess->recupPersString("SELECT TauxTVA FROM TVA WHERE IdTVA = " + valIdTVA + " ;")));
				return p;
			}
		}

		else
		{
			Stock^ p = gcnew Stock();
			return p;
		}
	}
}
