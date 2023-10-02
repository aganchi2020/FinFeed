#ifndef DB_ACCESSOR_H
#define DB_ACCESSOR_H

#include <iostream>
#include <string>
#include <vector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QString>

using namespace std;

class DB_Accessor
{
public:
    DB_Accessor();
    DB_Accessor( string loc );
    ~DB_Accessor();

    /**
     * @brief DB_Accessor::do_query runs the internal query object pntr with the given sqlcmd.
     * (Note: If run successfully, the internal sqlcmd will be changed to the given argument.)
     * @param sqlcmd is the sqlcmd for this query.
     * @return a boolean whether or not the query was run successfully.
     */
    bool do_query( string sqlcmd );

    /**
     * @brief DB_Accessor::do_query will run the query with the current stored sqlcmd.
     * @return a boolean whether or not the query was run successfully.
     */
    bool do_query();

    /**
     * @brief get_query gets the internal query object pntr.
     * @return a QSqlQuery object pntr. This object should never be destroyed. Otherwise, the database object will not have an internal QSqlQuery.
     */
    QSqlQuery* get_query();

    /**
     * @brief get_sqlcmd gets the current sqlcmnd QString object as a string.
     * @return a string.
     */
    string get_sqlcmd();

    /**
     * @brief build_sqlcmd takes the sqlcmd parameter and changes the current sequal command within this object.
     * @param sqlcmd is a string.
     */
    void build_sqlcmd( string sqlcmd );

    /**
     * @brief query_size returns the query size of the current query.
     * @return a positive integer if there is a valid size, otherwise. If there is no existing query object, then this will return -1.
     */
    int query_size();

    void printDatabase();

private:
    QString sqlcmd;
    QSqlQuery* query;
    QSqlDatabase m_db;
};

#endif // DB_ACCESSOR_H
