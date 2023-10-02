#ifndef PROFILESDB_H
#define PROFILESDB_H


class ProfilesDB
{
public:
    ProfilesDB();

    /* Profile Methods */
    // Log thread within the database.
    void log_profile();
    // build existing thread from database.
    void build_profile();
    // find thread within the database.
    void find_profile();

private:
    /*
    Database object...
    */
};

#endif // PROFILESDB_H
