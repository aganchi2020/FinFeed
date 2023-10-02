#include "community.h"

/**
 * @brief Community::Community
 * Default Constructor for Community Class
 */
Community::Community() {

}

/**
 * @brief Community::Community
 * @param name
 * Constructor for Community Class. Takes name for the class
 * as a parameter.
 */
Community::Community(std::string name) {
    tab_name = name;
    tab_id = id;
}

/**
 * @brief Community::~Community
 * Destructor for Community Class
 */
Community::~Community(){

}

/**
 * @brief add_subComm
 * Adds a thread to the list community
 */
void Community::add_subComm(SubCommunity* sc){
    subs.push_back(sc);
}

/**
 * @brief log_comm
 * Logs the community to the database
 */
bool Community::log_comm(int id){
    // log the messages.
    for (SubCommunity* sc : subs) { sc->log_comm(); }

    if ( !comm_exists( id ) )
    {
        stringstream cmd;
        cmd << "insert into tab ( tab_id, tab_name, "
            << "num_communities) "
            << "values ( "
            << tab_id                      << ", "
            << "\"" << tab_name    << "\"" << ", "
            << "\"" << subs.size() << "\"" << ",);";

        //cout << "Doing query: " << cmd.str() << endl;
        return do_query( cmd.str() );
    }
    else return false;
}

bool Community::comm_exists(int id){
    // build the command.
    stringstream cmd;
    cmd << "select * "
        << "from communities "
        << "where community_id = "
        << id << ";";

    // run the command.
    do_query( cmd.str() );
    QSqlQuery *query = get_query();

    while (query->next())
    {
        int comm_id = query->value("community_id").toInt();

        if ( (*this).id == comm_id )
        {
            return true;
        }
    }

    // if the object does not exist in the database.
    return false;
}

/**
 * @brief build_comm
 * Builds an existing community from the database.
 */
void Community::build_comm(int t_id){
    // build the command.
    stringstream cmd;
    cmd << "select * "
        << "from communities;";

    // run the command.
    do_query( cmd.str() );
    QSqlQuery *query = get_query();

    //cout << endl << "Build Communities Query Size: ";
    //cout << query->size() << endl;

    while (query->next())
    {
        int comm_id = query->value("community_id").toInt();
        int tab = query->value("tab_id").toInt();

        if ( tab == t_id )
        {
            //int com_id, std::string name, std::string des, std::string interest,
            //int numMem, int numMod, int t_id
            QString name = query->value("community_name").toString();
            QString des = query->value("community_description").toString();
            QString interest = query->value("community_interest").toString();
            int numMem = query->value("num_members").toInt();
            int numMod = query->value("num_mods").toInt();
            SubCommunity* sc = new SubCommunity(comm_id, name.toStdString(), des.toStdString(),
                                                interest.toStdString(), numMem, numMod, tab);
            sc->build_comm( comm_id );
            subs.push_back( sc );
        }
    }

    tab_id = t_id;
}

/**
 * @brief Community::get_name
 * @return
 * Returns the name of the Community.
 */
std::string Community::get_name(){
    return tab_name;
}

/**
 * @brief get_id
 * @return
 * Returns community id
 */
int Community::get_id(){
    return id;
}

vector<SubCommunity*> Community::get_subs(){
    return subs;
}
