#ifndef COMSETDB_H
#define COMSETDB_H


class ComSetDB
{
public:
    ComSetDB();
    ~ComSetDB();

    /* Thread Methods */
    // Log thread within the database.
    void log_thread();
    // build existing thread from database.
    void build_thread();
    // find thread within the database.
    void find_thread();

    /* Message Methods */
    // Log thread within the database.
    void log_message();
    // build existing thread from database.
    void build_message();
    // find thread within the database.
    void find_message();

    /* getters and setters */

private:
    /*
    Database object...
    */
};

#endif // COMSETDB_H
