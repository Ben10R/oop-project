#include "CL_map_STATS.h"

NS_Composants::CL_map_STATS::CL_map_STATS()
{

}

String^ NS_Composants::CL_map_STATS::SELECTVALEURSTOCK(void)
{
	return "SELECT SUM(Catalogue.QuantiteStockArticle * Prix.PrixHT) AS VALEURSTOCKHT FROM Catalogue JOIN Etre " +
			"ON Catalogue.IdArticle = Etre.IdArticle " +
			"JOIN Prix " +
			"ON Etre.IdPrix = Prix.IdPrix;";
}
String^ NS_Composants::CL_map_STATS::m_Tp10Plus(void)
{
	return "SELECT TOP 10 Catalogue.NomArticle, SUM (Contenir.Quantite) Qte FROM Catalogue INNER JOIN Contenir ON Catalogue.IdArticle = Contenir.IdArticle GROUP BY Catalogue.NomArticle ORDER BY Qte DESC";
}

String^ NS_Composants::CL_map_STATS::m_Tp10Moins(void)
{
	return "SELECT TOP 10 Catalogue.NomArticle, SUM (Contenir.Quantite) Qte FROM Catalogue INNER JOIN Contenir ON Catalogue.IdArticle = Contenir.IdArticle GROUP BY Catalogue.NomArticle ORDER BY Qte ASC";
}

String^ NS_Composants::CL_map_STATS::m_TotComCli(String^ nom, String^ prenom)
{
	return "SELECT Client.PrenomClient, Client.NomClient, SUM (Commande.MontantTotalTTC) AS Total_Commandes FROM Client INNER JOIN Commande ON Client.IdClient = Commande.IdClient WHERE Client.NomClient ='" + nom + "'AND Client.PrenomClient ='" + prenom + "'GROUP BY Client.PrenomClient, Client.NomClient";
}

String^ NS_Composants::CL_map_STATS::m_MoyPan(void)
{
	return "SELECT AVG(Commande.MontantTotalHT) AS Pannier_Moyen FROM Commande";
}

String^ NS_Composants::CL_map_STATS::m_ValComSto(void)
{
	return "SELECT SUM(Catalogue.QuantiteStockArticle * (Prix.PrixHT + (Prix.PrixHT * TVA.TauxTVA))) As val_Com_Stock FROM Catalogue INNER JOIN TVA ON Catalogue.IdTVA = TVA.IdTVA INNER JOIN Etre ON Catalogue.IdArticle = Etre.IdArticle INNER JOIN Prix ON Etre.IdPrix = Prix.IdPrix";
}

String^ NS_Composants::CL_map_STATS::m_ValAchSto(void)
{
	return "SELECT SUM(Catalogue.QuantiteStockArticle * Prix.PrixHT) As val_Ach_Stock FROM Catalogue INNER JOIN TVA ON Catalogue.IdTVA = TVA.IdTVA INNER JOIN Etre ON Catalogue.IdArticle = Etre.IdArticle INNER JOIN Prix ON Etre.IdPrix = Prix.IdPrix";
}

String^ NS_Composants::CL_map_STATS::m_ChAffMois(String^ month, String^ year)
{
	return "SELECT MONTH(Date.Date) AS Mois, SUM(Commande.MontantTotalTTC) AS Chiffre_affaire FROM Commande INNER JOIN Date ON Commande.IdDate = Date.IdDate WHERE MONTH(Date.Date) ='" + month + "'AND YEAR(Date.Date) ='" + year + "'GROUP BY MONTH(Date.Date)";
}

String^ NS_Composants::CL_map_STATS::m_pdtSsReap(void)
{
	return "SELECT Catalogue.IdArticle, Catalogue.NomArticle, Catalogue.QuantiteStockArticle, Catalogue.SeuilReapro FROM Catalogue WHERE Catalogue.QuantiteStockArticle <= Catalogue.SeuilReapro GROUP BY Catalogue.IdArticle, Catalogue.NomArticle, Catalogue.QuantiteStockArticle, Catalogue.SeuilReapro";
}