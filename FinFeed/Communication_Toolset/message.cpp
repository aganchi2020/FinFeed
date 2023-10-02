#include <ctime>
#include "message.h"

Message::Message( string message, int user_id, int thread_id ) : Config() // base constructor
{
    // set the associated variables.
    (*this).message = message;
    (*this).user_id = user_id;
    (*this).thread_id = thread_id;
    (*this).message_id = id;
}

Message::~Message()
{

}

/**
 * @brief message_exists checks whether the message exists within the database.
 * @param thread_id is the thread that the message belongs to.
 * @return a boolean true or false indicating whether or not the message exists in the database.
 */
bool Message::message_exists( int thread_id )
{
    // build the command.
    stringstream cmd;
    cmd << "select * "
        << "from messages "
        << "where message_id = "
        << message_id << ";";

    // run the command.
    do_query( cmd.str() );
    QSqlQuery *query = get_query();

    while (query->next())
    {
        int temp_id = query->value("message_id").toInt();

        if ( (*this).message_id == temp_id )
        {
            return true;
        }
    }

    // if the object does not exist in the database.
    return false;
}

/**
 * @brief log_message logs the message into the database.
 * @param thread_id is the thread that the message belongs to.
 * @return returns a boolean indicating whether the message was logged or if it was not due to errors or duplicates.
 */
bool Message::log_message( int thread_id )
{
    if ( !message_exists( thread_id ) )
    {
        stringstream cmd;
        cmd << "insert into messages ( message_id, user_id, thread_id, time, message, date ) "
            << "values ( "
            << message_id << ", "
            << user_id << ", "
            << thread_id << ", "
            << "\"" << time  << "\"" << ", "
            << "\"" << message << "\"" << ", "
            << "\"" << date << "\""
            << " );";

        return do_query( cmd.str() );
    } else return false;
}

// print the message for testing purposes.
void Message::print_message()
{
    cout << endl;
    cout << "User " << user_id << ": ";
    cout << message << endl;
    cout << "On " << date << endl;
    cout << "At " << time << endl;
}
