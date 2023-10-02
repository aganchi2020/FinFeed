#include "config.h"

bool Config::valid_id = false;
DB_Accessor* Config::database = new DB_Accessor( "../../database_sqlite/example.sqlite" );
int Config::id_cnt = 0;

Config::Config()
{

    // get the date and time.
    dt = dt.currentDateTime();

    // build the date and time maps.
    build_date();
    build_time();

    // get the highest id cnt;
    // valid_id checks so that this is only done at the start of the program.
    if (!valid_id)
    {
        // create a cmd to get the ids in order.
        string sqlcmd;
        sqlcmd  = "SELECT highest_id FROM global ORDER by highest_id;";

        // run the command.
        database->do_query( sqlcmd );
        QSqlQuery *query = database->get_query();

        // the last query value will be the highest id recorded.
        while ( query->next() )
        {
            int temp = query->value( "highest_id" ).toInt();
            if ( temp > id_cnt ) id_cnt = temp;
        }

        // valid_id is now true.
        valid_id = true;
    }

    // set id.
    id = id_cnt;
    id_cnt++;
}

Config::~Config()
{
    // get the highest id.
    database->do_query( "SELECT highest_id FROM global;" );
    QSqlQuery *query = database->get_query();

    // get the highest_id in the database
    int highest_id = 0;
    while ( query->next() )
    {
        int temp = query->value( "highest_id" ).toInt();
        if ( temp > highest_id)
            highest_id = query->value( "highest_id" ).toInt();
    }

    // store the highest id cnt.
    if (id_cnt > highest_id) {
        // store the id count.
        stringstream sqlcmd;
        sqlcmd << "insert into global ( highest_id ) values ( " << id_cnt << " );";
        database->do_query( sqlcmd.str() );
    }
}

/**
 * @brief Config::do_query
 * @param sqlcmd
 * @return
 */
bool Config::do_query( string sqlcmd ) { return database->do_query( sqlcmd ); }

/**
 * @brief Config::get_query
 * @return
 */
QSqlQuery* Config::get_query() { return database->get_query(); }

/**
 * @brief Config::build_date
 * @return
 */
map<string, int> Config::build_date()
{
    // get the QDate obj.
    QDate d = dt.date();

    // fill the map.
    date_map.insert({"day", d.day()});
    date_map.insert({"month", d.month()});
    date_map.insert({"year", d.year()});
    date_map.insert({"day of the week", d.dayOfWeek()});
    date_map.insert({"day of the year", d.dayOfYear()});
    date_map.insert({"days in the month", d.daysInMonth()});

    // date stucture tools
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // build the date str
    QString temp("dddd, MMMM d, yyyy");
    date = d.toString( temp ).toStdString();

    // return the map.
    return date_map;
}

/**
 * @brief Config::build_time
 * @return
 */
map<string, int> Config::build_time()
{
    // get the QTime obj.
    QTime t = dt.time();

    // fill the map.
    time_map.insert({"hour", t.hour()});
    time_map.insert({"minute", t.minute()});
    time_map.insert({"second", t.second()});
    time_map.insert({"millisecond", t.msec()});

    // build the time str
    QString temp("h:mm AP, t");
    time = t.toString( temp ).toStdString();

    // return the map.
    return time_map;
}

/**
 * @brief Config::find_date
 * @param info
 * @return
 */
int Config::find_date( string info )
{
    map< string, int >::iterator i = date_map.find( info );
    if ( i != date_map.end() ) return i->second;
    else return -1;
}

/**
 * @brief Config::find_time
 * @param info
 * @return
 */
int Config::find_time( string info )
{
    map< string, int >::iterator i = time_map.find( info );
    if ( i != time_map.end() ) return i->second;
    else return -1;
}

