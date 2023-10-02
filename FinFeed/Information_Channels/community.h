#ifndef COMMUNITY_H
#define COMMUNITY_H
#include <string>
#include "subcommunity.h"

class Community : public Config
{
public:

    //Uses the tab table in database

    /**
     * @brief Community
     * Default constructor for Community class.
     */
    Community();

    /**
     * @brief Community
     * @param name
     * Constructor that takes a name for the community.
     */
    Community(std::string name);

    /**
     * @brief ~Community
     * Destructor for community class.
     */
    ~Community();

    /**
     * @brief add_subComm
     * Adds a subcommunity to the tab
     */
    void add_subComm(SubCommunity* sc);

    /**
     * @brief log_comm
     * Logs the community to the database
     */
    bool log_comm(int id);

    /**
     * @brief comm_exists
     * @return
     * Returns true if the community exists in the database.
     * Returns false otherwise.
     */
    bool comm_exists(int id);

    /**
     * @brief build_comm
     * Builds an existing community from the database.
     */
    void build_comm(int t_id);

    /**
     * @brief get_name
     * @return
     * Returns the name of the community.
     */
    std::string get_name();

    /**
     * @brief get_id
     * @return
     * Returns community id
     */
    int get_id();

    vector<SubCommunity*> get_subs();

private:
    // name of the channel
    std::string tab_name;

    // tab id
    int tab_id;

    // subcommunities
    vector<SubCommunity*> subs;

};

#endif // COMMUNITY_H

