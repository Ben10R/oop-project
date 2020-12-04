#include "Stock.h"

NS_Composants::Stock::Stock()
{
	setIdArticle(0);
	setNomArticle("");
	setDesignationArticle("");
	setSeuilReapro(0);
	setQuantiteStockArticle(0);
	setIdNature(0);
	setNature("");
	setIdTVA(0);
	setTauxTVA(0);
}

NS_Composants::Stock::Stock(int valIdNature, String^ valNature)
{
	setIdArticle(0);
	setNomArticle("");
	setDesignationArticle("");
	setSeuilReapro(0);
	setQuantiteStockArticle(0);
	setIdNature(valIdNature);
	setNature(valNature);
	setIdTVA(0);
	setTauxTVA(0);
}

NS_Composants::Stock::Stock(int valIdTVA, int valTauxTVA)
{
	setIdArticle(0);
	setNomArticle("");
	setDesignationArticle("");
	setSeuilReapro(0);
	setQuantiteStockArticle(0);
	setIdNature(0);
	setNature("");
	setIdTVA(valIdTVA);
	setTauxTVA(valTauxTVA);
}

NS_Composants::Stock::Stock(int valIdArticle, String^ valNomArticle, String^ valDesignationArticle, int valSeuilReapro, int valQuantiteStockArticle, int valIdNature, String^ valNature, int valIdTVA, int valTauxTVA)
{
	setIdArticle(valIdArticle);
	setNomArticle(valNomArticle);
	setDesignationArticle(valDesignationArticle);
	setSeuilReapro(valSeuilReapro);
	setQuantiteStockArticle(valQuantiteStockArticle);
	setIdNature(valIdNature);
	setNature(valNature);
	setIdTVA(valIdTVA);
	setTauxTVA(valTauxTVA);
}

NS_Composants::Stock::Stock(String^ valNomArticle, String^ valDesignationArticle, int valSeuilReapro, int valQuantiteStockArticle, String^ valNature, int valTauxTVA)
{

	setNomArticle(valNomArticle);
	setDesignationArticle(valDesignationArticle);
	setSeuilReapro(valSeuilReapro);
	setQuantiteStockArticle(valQuantiteStockArticle);
	setNature(valNature);
	setTauxTVA(valTauxTVA);
}

NS_Composants::Stock::Stock(String^ valNomArticle, String^ valDesignationArticle, int valSeuilReapro, int valQuantiteStockArticle, int valIdNature, String^ valNature, int valIdTVA, int valTauxTVA)
{

	setNomArticle(valNomArticle);
	setDesignationArticle(valDesignationArticle);
	setSeuilReapro(valSeuilReapro);
	setQuantiteStockArticle(valQuantiteStockArticle);
	setIdNature(valIdNature);
	setNature(valNature);
	setIdTVA(valIdTVA);
	setTauxTVA(valTauxTVA);
}

void NS_Composants::Stock::setIdArticle(int valIdArticle)
{
	IdArticle = valIdArticle;
}

int NS_Composants::Stock::getIdArticle(void)
{
	return IdArticle;
}

void NS_Composants::Stock::setNomArticle(String^ valNomArticle)
{
	nomArticle = valNomArticle;
}

String^ NS_Composants::Stock::getNomArticle(void)
{
	return nomArticle;
}

void NS_Composants::Stock::setDesignationArticle(String^ valDesignationArticle)
{
	designationArticle = valDesignationArticle;
}

String^ NS_Composants::Stock::getDesignationArticle(void)
{
	return designationArticle;
}

void NS_Composants::Stock::setSeuilReapro(int valSeuilReapro)
{
	seuilReapro = valSeuilReapro;
}

int NS_Composants::Stock::getSeuilReapro(void)
{
	return seuilReapro;
}

void NS_Composants::Stock::setQuantiteStockArticle(int valQuantiteStockArticle)
{
	quantiteStockArticle = valQuantiteStockArticle;
}

int NS_Composants::Stock::getQuantiteStockArticle(void)
{
	return quantiteStockArticle;
}

void NS_Composants::Stock::setIdNature(int valIdNature)
{
	idNature = valIdNature;
}

int NS_Composants::Stock::getIdNature(void)
{
	return idNature;
}

void NS_Composants::Stock::setNature(String^ valNature)
{
	nature = valNature;
}

String^ NS_Composants::Stock::getNature(void)
{
	return nature;
}

void NS_Composants::Stock::setIdTVA(int valIdTVA)
{
	idTVA = valIdTVA;
}

int NS_Composants::Stock::getIdTVA(void)
{
	return idTVA;
}

void NS_Composants::Stock::setTauxTVA(int valTauxTVA)
{
	tauxTVA = valTauxTVA;
}

int NS_Composants::Stock::getTauxTVA(void)
{
	return tauxTVA;
}