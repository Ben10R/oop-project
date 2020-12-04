#pragma once
#include "CL_CAD.h"
#include "Stock.h"
//Couche service
//classe service de gestion des processus Personne
using namespace System::Data;
using namespace System::Data::SqlClient;		//(pour SQL SERVER)
using namespace System::Xml;
using namespace System;
using namespace NS_Composants;


namespace NS_Svc
{
	ref class Services_Stocks
	{
	private:
		CL_CAD^ dataAccess;
		DataSet^ dataset;
	public:
		Services_Stocks(void);

		void modifierArticle(int, String^, String^, int, int, int, String^, int, int);

		void supprimer(int, int, int);

		void ajouterArticle(String^, String^, int, int, String^, int);
		void ajouterArticle(Stock^ p);

		void checkNature(String^);
		void checkTVA(int);

		Stock^ selectPremierArticle(String^);
		Stock^ selectDernierArticle(String^);
		Stock^ selectPrecedentArticle(int, int, int , String^);
		Stock^ selectSuivantArticle(int, int, int, String^);
	};
}