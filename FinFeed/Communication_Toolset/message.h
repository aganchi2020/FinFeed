#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <QImage>
#include "../Config/config.h"

using namespace std;

class Message : public Config
{
public:
    /*variables*/
    int message_id;
    int user_id;
    int thread_id;
    string message;

    /*constructors*/
    Message( string message, int user_id, int thread_id ); // base constructor
    ~Message();

    /*methods*/
    /**
     * @brief message_exists checks whether the message exists within the database.
     * @param community_id is the community that the message belongs to.
     * @return a boolean true or false indicating whether or not the message exists in the database.
     */
    bool message_exists( int community_id );

    /**
     * @brief log_message logs the message into the database.
     * @param community_id is the community that the message belongs to.
     * @return returns a boolean indicating whether the message was logged or if it was not due to errors or duplicates.
     */
    bool log_message( int community_id );

    // print the message for testing purposes.
    void print_message();
private:
};

#endif // MESSAGE_H
