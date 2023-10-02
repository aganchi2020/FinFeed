#include "subcommunity.h"

/**
 * @brief SubCommunity::SubCommunity
 * Default Constructor for SubCommunity
 */
SubCommunity::SubCommunity() {

}

/**
 * @brief SubCommunity::SubCommunity
 * @param name
 * Constructor for SubCommunity
 */
SubCommunity::SubCommunity(int com_id, std::string name, std::string des, std::string interest,
                           int numMem, int numMod, int t_id) {
    comm_name = name;
    posts = new Thread(name, (*this).comm_id);
    comm_id = com_id;
    tab_id = t_id;
    comm_des = des;
    comm_interest = interest;
    num_member = numMem;
    num_mod = numMod;
}

/**
 * @brief SubCommunity::SubCommunity
 * @param t
 * Constructor for SubCommunity
 */
SubCommunity::SubCommunity(Thread* t, std::string des, std::string interest, int t_id){
    posts = t;
    comm_name = t->threadName;
    comm_id = id;
    tab_id = t_id;
    comm_des = des;
    comm_interest = interest;
}

/**
 * @brief SubCommunity::~SubCommunity
 * Destructor for SubCommunity
 */
SubCommunity::~SubCommunity(){
    delete posts;
}

/**
 * @brief log_comm
 * Logs the community to the database
 */
bool SubCommunity::log_comm(){
    // log the thread
    posts->log_thread( (*this).id );

    if ( !comm_exists( id ) )
    {
        stringstream cmd;
        cmd << "insert into communities ( community_id, community_name, "
            << "community_description, community_interests, num_members, num_mods, tab_id ) "
            << "values ( "
            << comm_id                       << ", "
            << "\"" << comm_name     << "\"" << ", "
            << "\"" << comm_des      << "\"" << ", "
            << "\"" << comm_interest << "\"" << ", "
            << "\"" << num_member    << "\"" << ", "
            << "\"" << num_mod       << "\"" << ", "
            << "\"" << tab_id        << "\"" << ");";

        //cout << "Doing query: " << cmd.str() << endl;
        return do_query( cmd.str() );
    }
    else return false;
}

/**
 * @brief comm_exists
 * @return
 * Returns true if the community exists in the database.
 * Returns false otherwise.
 */
bool SubCommunity::comm_exists(int id){
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
        int c_id = query->value("community_id").toInt();

        if ( (*this).id == c_id )
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
void SubCommunity::build_comm(int id){
    // build the command.
    stringstream cmd;
    cmd << "select * "
        << "from threads "
        << "where thread_id = "
        << id << ";";

    // run the command.
    do_query( cmd.str() );
    QSqlQuery *query = get_query();

    QString thread_title = query->value( 0 ).toString();

    Thread* t = new Thread( thread_title.toStdString(), (*this).comm_id );
    t->build_existing_thread( (*this).comm_id );

    posts = t;
}

/**
 * @brief SubCommunity::get_name
 * @return
 * Returns the name of the subcommunity
 */
std::string SubCommunity::get_name(){
    return comm_name;
}

/**
 * @brief get_desc
 * @return
 * Returns description of subcommunity
 */
std::string SubCommunity::get_desc(){
    return comm_des;
}

/**
 * @brief get_interest
 * @return
 * Returns interests of the subcommunity
 */
std::string SubCommunity::get_interest(){
    return comm_interest;
}

/**
 * @brief get_mems
 * @return
 * Returns number of members
 */
int SubCommunity::get_mems(){
    return num_member;
}

/**
 * @brief get_mods
 * @return
 * Return number of mods
 */
int SubCommunity::get_mods(){
    return num_mod;
}

/**
 * @brief get_id
 * @return
 * Returns subcommunity id
 */
int SubCommunity::get_id(){
    return comm_id;
}

Thread* SubCommunity::get_posts(){
    return posts;
}

