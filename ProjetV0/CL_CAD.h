#pragma once
//classe composant d’accès aux données
using namespace System::Data;
using namespace System::Data::SqlClient;	// (pour   SQL SERVER)
using namespace System::Xml;
using namespace System;

namespace NS_Composants
{
	ref class CL_CAD
	{
	private:
		String^ connectionChain; // Data Source=LAPTOP-56S6H8LS;Initial Catalog=CorbeillePR6;Integrated Security=True
		String^ rq_sql;
		SqlConnection^ conn;
		SqlCommand^ comm;
		SqlDataAdapter^ dataAdapter;
		DataSet^ dataset;
		void setSQL(String^);
	public:
		CL_CAD(void);
		int actionRowsID(String^);
		float actionRowsFloat(String^);
		void actionRows(String^);
		DataSet^ getRows(String^, String^);
		String^ recupPersString(String^);
	};
}

