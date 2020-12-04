#pragma once
#include "CL_map_STATS.h"

using namespace System::Data;
using namespace System::Data::SqlClient;		//(pour SQL SERVER)
using namespace System::Xml;
using namespace System;
using namespace NS_Composants;

namespace NS_Svc
{
	ref class CL_svc_STATS
	{
	private:
		CL_CAD^ dataAccess;
		CL_map_STATS^ mapTabl;
		DataSet^ dataset;
	public:
		CL_svc_STATS(void);
		float valeurstock(float, float, float, float);
		DataSet^ afficherReq(int, String^, String^, String^, String^);
	};
}


