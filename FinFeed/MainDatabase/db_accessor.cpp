#include "db_accessor.h"
#include <iostream>
#include <string>
#include <string.h>

DB_Accessor::DB_Accessor()
{
    string pathstr;
    cout << endl;
    cout << "Please specify database path: ";
    getline( cin, pathstr ); // get the users path for the database.
    cout << "You entered: " << pathstr << endl;
    cout << endl;

    // specify the location of the database
    QString path( pathstr.c_str() );

    // create a database driver
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");

    // establish a link to the database
    m_db.setDatabaseName(path);

    // verify the database opened
    if (!m_db.open())
    {
        std::cout << "Error: "
                  << m_db.lastError().text().toStdString()
                  << std::endl;
        exit(1);
    }
    else
    {
        std::cout  << "Database: connection ok"
                  << std::endl;
        //printDatabase();
    }

    // create a query object to the database
    query = new QSqlQuery(m_db);

    // store the most recent command.
    QString str;
    (*this).sqlcmd = str;
}

DB_Accessor::DB_Accessor( string loc )
{
    // specify the location of the database
    QString path( loc.c_str() );

    // create a database driver
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");

    // establish a link to the database
    m_db.setDatabaseName(path);

    // verify the database opened
    if (!m_db.open())
    {
        std::cout << "Error: "
                  << m_db.lastError().text().toStdString()
                  << std::endl;
        exit(1);
    }
    else
    {
        std::cout  << "Database: connection ok"
                  << std::endl;
        //printDatabase();
    }

    // create a query object to the database
    query = new QSqlQuery(m_db);

    // store the most recent command.
    QString str;
    (*this).sqlcmd = str;
}

DB_Accessor::~DB_Accessor()
{
    // close the database before exiting
    m_db.close();

    // delete the query object.
    delete query;
}

/**
 * @brief DB_Accessor::do_query runs the internal query object pntr with the given sqlcmd.
 * (Note: If run successfully, the internal sqlcmd will be changed to the given argument.)
 * @param sqlcmd is the sqlcmd for this query.
 * @return a boolean whether or not the query was run successfully.
 */
bool DB_Accessor::do_query( string sqlcmd )
{
    QString new_cmd(sqlcmd.c_str());

    // execute the provided sql call
    if(query->exec(new_cmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text();
        cout << "SQL Query ERROR: " << err.text().toStdString() << endl;
        return false;
    }

    // store the most recent command.
    (*this).sqlcmd = new_cmd;
    return true;
}

/**
 * @brief DB_Accessor::do_query will run the query with the current stored sqlcmd.
 * @return a boolean whether or not the query was run successfully.
 */
bool DB_Accessor::do_query()
{
    if ( (*this).sqlcmd.isNull() ) return false;
    if ( (*this).sqlcmd.isEmpty() ) return false;
    else return do_query( (*this).sqlcmd.toStdString() );
}

/**
 * @brief get_query gets the internal query object pntr.
 * @return a QSqlQuery object pntr. This object should never be destroyed. Otherwise, the database object will not have an internal QSqlQuery.
 */
QSqlQuery* DB_Accessor::get_query() { return (*this).query; }

/**
 * @brief get_sqlcmd gets the current sqlcmnd QString object as a string.
 * @return a string.
 */
string DB_Accessor::get_sqlcmd() { return sqlcmd.toStdString(); }

/**
 * @brief build_sqlcmd takes the sqlcmd parameter and changes the current sequal command within this object.
 * @param sqlcmd is a string.
 */
void DB_Accessor::build_sqlcmd( string sqlcmd )
{
    // store the most recent command.
    QString new_cmd(sqlcmd.c_str());
    (*this).sqlcmd = new_cmd;
}

/**
 * @brief query_size returns the query size of the current query.
 * @return a positive integer if there is a valid size, otherwise. If there is no existing query object, then this will return -1.
 */
int DB_Accessor::query_size() { return query->size(); }

void DB_Accessor::printDatabase()
{
    //cout << "Current database: " << m_db.databaseName().toStdString() << endl;
    //cout << "Connection Name: " << m_db.connectionName().toStdString() << endl;
    //cout << "Is Valid?: " << m_db.isValid() << endl;
    //cout << "Driver Name: " << m_db.driverName().toStdString() << endl;
}
