#include "CL_svc_STATS.h"

NS_Svc::CL_svc_STATS::CL_svc_STATS(void)
{
	dataAccess = gcnew CL_CAD;
	mapTabl = gcnew CL_map_STATS;
    dataset = gcnew DataSet;
}

float NS_Svc::CL_svc_STATS::valeurstock(float tva, float marge, float remise, float demarque)
{
	float result = dataAccess->actionRowsFloat(mapTabl->SELECTVALEURSTOCK());
	return (result + (result * (marge / 100)) - (result * (tva / 100)) - (result * (remise / 100)) - (result * (demarque / 100)));
}

DataSet^ NS_Svc::CL_svc_STATS::afficherReq(int indexReq, String^ month, String^ year, String^ _nom, String^ _prenom)
{
    dataset->Clear();
    switch (indexReq)
    {
    case 0:
        dataset = dataAccess->getRows(mapTabl->m_MoyPan(), "Values");
        break;
    case 1:
        dataset = dataAccess->getRows(mapTabl->m_ChAffMois(month, year), "Values");
        break;
    case 2:
        dataset = dataAccess->getRows(mapTabl->m_pdtSsReap(), "Values");
        break;
    case 3:
        dataset = dataAccess->getRows(mapTabl->m_TotComCli(_nom, _prenom), "Values");
        break;
    case 4:
        dataset = dataAccess->getRows(mapTabl->m_Tp10Plus(), "Values");
        break;
    case 5:
        dataset = dataAccess->getRows(mapTabl->m_Tp10Moins(), "Values");
        break;
    case 6:
        dataset = dataAccess->getRows(mapTabl->m_ValComSto(), "Values");
        break;
    case 7:
        dataset = dataAccess->getRows(mapTabl->m_ValAchSto(), "Values");
        break;
    }

    return dataset;
}