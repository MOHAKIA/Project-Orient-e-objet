#include "CAD.h"

 NS_Composants::CAD::CAD(void)
{
    //throw gcnew System::NotImplementedException();
    this->rq_sql = "RIEN";
    this->cnx = "Data Source=(localdb)\MSSQLLocalDB;" + "Initial Catalog=Personnel;"
        + "Integrated Security=True;" + "Connect Timeout=30;" + "Encrypt=False;" + "User ID = PC-LUCASG\Lucas"
        + "TrustServerCertificate=False;" + "ApplicationIntent=ReadWrite;" + "MultiSubnetFailover=False";
    this->CNX = gcnew SqlConnection(this->cnx);
    this->CMD = gcnew SqlCommand(this->rq_sql, this->CNX);
    this->CMD->CommandType = CommandType::Text;
}



int NS_Composants::CL_CAD::actionRowsID(String^ rq_sql)
{
    int id;
    this->setSQL(rq_sql);
    this->CMD->CommandText = this->rq_sql;
    this->CNX->Open();
    id = Convert::ToInt32(this->CMD->ExecuteScalar());
    this->CNX->Close();
    return id;
}

void NS_Composants::CL_CAD::actionRows(String^)
{
    //throw gcnew System::NotImplementedException();
    this->setSQL(rq_sql);
    this->CMD->CommandText = this->rq_sql;
    this->CNX->Open();
    this->CMD->ExecuteNonQuery();
    this->CNX->Close();
}

DataSet^ NS_Composants::CL_CAD::getRows(String^ rq_sql, String^ dataTableName)
{
    //throw gcnew System::NotImplementedException();
    // TODO: insérer une instruction return ici
    this->setSQL(rq_sql);
    this->DA = gcnew SqlDataAdapter(this->CMD);
    this->CMD->CommandText = this->rq_sql;
    this->DS = gcnew DataSet();
    this->DA->Fill(this->DS, dataTableName);
    return this->DS;
}



void NS_Composants::CL_CAD::setSQL(String^)
{
    if (rq_sql == "" || rq_sql == "RIEN")
    {
        this->rq_sql = "RIEN";
    }
    else
    {
        this->rq_sql = rq_sql;
    }