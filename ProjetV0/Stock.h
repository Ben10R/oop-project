#pragma once
#include "CL_CAD.h"

using namespace System;

namespace NS_Composants
{
	ref class Stock
	{
	private:
		int IdArticle;
		String^ nomArticle;
		String^ designationArticle;
		int seuilReapro;
		int quantiteStockArticle;
		int idNature;
		String^ nature;
		int idTVA;
		int tauxTVA;

	public:

		Stock();
		Stock(int, String^);
		Stock(int, int);
		Stock(String^, String^, int, int, String^, int);
		Stock(int, String^, String^, int, int, int, String^, int, int);
		Stock(String^, String^, int, int, int, String^, int, int);

		void setIdArticle(int);
		int getIdArticle(void);
		void setNomArticle(String^);
		String^ getNomArticle(void);
		void setDesignationArticle(String^);
		String^ getDesignationArticle(void);
		void setSeuilReapro(int);
		int getSeuilReapro(void);
		void setQuantiteStockArticle(int);
		int getQuantiteStockArticle(void);
		void setIdNature(int);
		int getIdNature(void);
		void setNature(String^);
		String^ getNature(void);		
		void setIdTVA(int);
		int getIdTVA(void);
		void setTauxTVA(int);
		int getTauxTVA(void);
	};
}
