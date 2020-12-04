#pragma once
#include "CL_CAD.h"
using namespace System;

namespace NS_Composants
{
	ref class CL_map_STATS
	{
	private:
		int id_client;
		String^ nom;
		String^ prenom;
		String^ month;
		String^ year;
	public:
		CL_map_STATS();
		String^ SELECTVALEURSTOCK(void);
		String^ m_Tp10Plus(void);
		String^ m_Tp10Moins(void);
		String^ m_TotComCli(String^, String^);
		String^ m_MoyPan(void);
		String^ m_ValComSto(void);
		String^ m_ValAchSto(void);
		String^ m_pdtSsReap(void);
		String^ m_ChAffMois(String^, String^);
	};
}


