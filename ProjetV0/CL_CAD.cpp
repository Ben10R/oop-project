#include "CL_CAD.h"

NS_Composants::CL_CAD::CL_CAD(void) : rq_sql("RIEN"), connectionChain("Data Source=LAPTOP-56S6H8LS;Initial Catalog=ProjetPOO;Integrated Security=True")
{
	conn = gcnew SqlConnection(connectionChain);
	comm = gcnew SqlCommand(rq_sql, conn);
	comm->CommandType = CommandType::Text;
	// Commandtype default is Text
}

int NS_Composants::CL_CAD::actionRowsID(String^ rqsql)
{
	int id;
	setSQL(rqsql);
	comm->CommandText = this->rq_sql;	//comm is SqlCommand object 
	conn->Open();						//conn is the SqlCommand object
	id = Convert::ToInt32(comm->ExecuteScalar());
	conn->Close();
	return id;
}
float NS_Composants::CL_CAD::actionRowsFloat(String^ rqsql)
{
	float id;
	setSQL(rqsql);
	comm->CommandText = this->rq_sql;	//comm is SqlCommand object 
	conn->Open();						//conn is the SqlCommand object
	id = Convert::ToSingle(comm->ExecuteScalar());
	conn->Close();
	return id;
}
void NS_Composants::CL_CAD::actionRows(String^ rqsql)
{
	conn->Close();
	setSQL(rqsql);
	comm->CommandText = this->rq_sql;
	conn->Open();
	comm->ExecuteNonQuery();		//Executes a Transact-SQL statement against the connection.returns the number of rows affected.
	conn->Close();
}
void NS_Composants::CL_CAD::setSQL(String^ rqsql)
{
	if (rqsql == "" || rqsql == "RIEN")
	{
		rq_sql = "RIEN";
	}
	else
	{
		this->rq_sql = rqsql;
	}
}

DataSet^ NS_Composants::CL_CAD::getRows(String^ rqsql, String^ dataTableName)
{
	setSQL(rqsql);
	dataAdapter = gcnew SqlDataAdapter(comm);
	comm->CommandText = this->rq_sql;
	dataset = gcnew DataSet;
	dataAdapter->Fill(dataset, dataTableName);
	return dataset;
}

String^ NS_Composants::CL_CAD::recupPersString(String^ rqsql)
{
	conn->Close();
	rq_sql = rqsql;
	comm->CommandText = this->rq_sql;
	conn->Open();
	return (Convert::ToString(comm->ExecuteScalar()));
}