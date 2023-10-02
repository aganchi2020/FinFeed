#ifndef CONFIG_H
#define CONFIG_H

#include <sstream>
#include <QDateTime>
#include <iostream>
#include <string>
#include <map>
#include "../MainDatabase/db_accessor.h"

using namespace std;

class Config
{
public:
    /* variables */
    static int id_cnt;
    static bool valid_id;
    int id;
    string date;
    string time;

    /* constructors */
    Config();
    ~Config();

    /* methods */
    /**
     * @brief do_query
     * @param sqlcmd
     * @return
     */
    bool do_query( string sqlcmd );

    /**
     * @brief get_query
     * @return
     */
    QSqlQuery* get_query();

    /* getters */
    /**
     * @brief find_date
     * @param info
     * @return
     */
    int find_date( string info );

    /**
     * @brief find_time
     * @param info
     * @return
     */
    int find_time( string info );


private:
    /* variables */
    QDateTime dt;
    static DB_Accessor* database;
    map<string, int> date_map;
    map<string, int> time_map;

    /* methods */
    bool check_database( string tuple, string args[], int arglen );
    map<string, int> build_date();
    map<string, int> build_time();
};

#endif // CONFIG_H
