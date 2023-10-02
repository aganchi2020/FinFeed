#ifndef SUBCOMMUNITY_H
#define SUBCOMMUNITY_H
#include <string>
#include "../Communication_Toolset/thread.h"

class SubCommunity : public Config
{
public:

    //Uses the community table in database (really confusing I know)

    /**
     * @brief SubCommunity
     * Default constructor
     */
    SubCommunity();

    /**
     * @brief SubCommunity
     * @param name
     * Constructor for SubCommunity that takes a name and
     * Community as a parameter.
     */
    SubCommunity(int com_id, std::string name, std::string comm_des, std::string comm_interest,
                 int numMem, int numMod, int t_id);

    /**
     * @brief SubCommunity
     * @param t
     * Constructor for SubCommunity that takes a community
     * and a thread as a parameter.
     */
    SubCommunity(Thread* t, std::string comm_des, std::string comm_interest, int t_id);

    /**
     * @brief ~SubCommunity
     * Destructor
     */
    ~SubCommunity();

    /**
     * @brief log_comm
     * Logs the community to the database
     */
    bool log_comm();

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
    void build_comm(int id);

    /**
     * @brief get_name
     * @return
     * Returns the name of the subcommunity
     */
    std::string get_name();

    /**
     * @brief get_desc
     * @return
     * Returns description of subcommunity
     */
    std::string get_desc();

    /**
     * @brief get_interest
     * @return
     * Returns interests of the subcommunity
     */
    std::string get_interest();

    /**
     * @brief return_membs
     * @return
     * Returns number of members
     */
    int get_mems();

    /**
     * @brief get_mods
     * @return
     * Return number of mods
     */
    int get_mods();

    /**
     * @brief get_id
     * @return
     * Returns community id
     */
    int get_id();

    Thread* get_posts();

private:

    // name of the community
    std::string comm_name;

    // channel id
    int comm_id;

    // descrption of channel
    std::string comm_des;

    // interests of channel
    std::string comm_interest;

    // number of users
    int num_member;
    int num_mod;

    // id of parent tab
    int tab_id;

    // TODO:
    // threads
    Thread* posts;

};

#endif // SUBCOMMUNITY_H


