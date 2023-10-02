#include "thread.h"

Thread::Thread( string threadName, int community_id ) // base constructor
{
    (*this).threadName = threadName;
    (*this).id = community_id;
}

Thread::~Thread()
{

}

/*methods*/
/**
 * @brief post_at will get the post at the specified index provided. If the index is not valid, the method will return a null pntr.
 * @param index is a size_t variable.
 * @return a Message object pntr.
 */
Message* Thread::post_at( size_t index )
{
    // check index, which is unsigned.
    if ( index < thread.size() ) return thread.at( index );
    return nullptr;
}

/**
 * @brief post_pop_back pops the last message object pntr in the internal thread vector.
 * @return a Message object pntr.
 */
Message* Thread::post_pop_back()
{
    if ( thread.empty() ) return nullptr;
    else {
        Message* p = thread.at( thread.size() - 1 );
        thread.pop_back();
        return p;
    }
}

/**
 * @brief post_peak_back peak at the back of the internal thread vector.
 * @return a Message object pntr.
 */
Message* Thread::post_peak_back()
{
    if ( thread.empty() ) return nullptr;
    else {
        Message* p = thread.at( thread.size() - 1 );
        return p;
    }
}

/**
 * @brief post_push_back pushes a Message object to the end of the internal thread vector.
 * @param post is Message object pntr.
 */
void Thread::post_push_back( Message* post ) { thread.push_back( post ); }


// comparator for sort thread functionality
bool compare_desc( Message* m1, Message* m2 ) { return ( m1->message_id > m2->message_id ); }
// comparator for sort thread functionality
bool compare_asc( Message* m1, Message* m2 ) { return ( m1->message_id < m2->message_id ); }

/**
 * @brief sort_thread sorts the messages in chronological order by their message_id.
 * @param direction is a string of either 'DESC' or 'ASC' specifying if the messages will be sorted in ascending or descending order.
 */
bool Thread::sort_thread( string direction )
{
    if ( direction == "ASC" ) sort( thread.begin(), thread.end(), compare_asc );
    if ( direction == "DESC" ) sort( thread.begin(), thread.end(), compare_desc );
    return ( direction == "ASC" ) || ( direction == "DESC" );
}

/**
 * @brief build_existing_thread will build the thread from the database according to the thread id.
 * @param thread_id is a unique thread if for all threads.
 */
void Thread::build_existing_thread( int thread_id )
{
    // build the command.
    stringstream cmd;
    cmd << "select * "
        << "from messages"
        << " where thread_id = "
        << thread_id << ";";

    // run the command.
    do_query( cmd.str() );
    QSqlQuery *query = get_query();

    while (query->next())
    {
        if ( thread_id == query->value("thread_id").toInt() )
        {
            int message_id = query->value("message_id").toInt();
            int user_id = query->value("user_id").toInt();
            int thread_id = query->value("thread_id").toInt();
            QString time = query->value("time").toString();
            QString message = query->value("message").toString();
            QString date = query->value("date").toString();

            Message* m = new Message( message.toStdString(), user_id, thread_id );
            m->time = time.toStdString();
            m->date = date.toStdString();
            m->id = message_id;


            post_push_back( m );
            //cout << "grabbing message: " << endl;
            //m->print_message();
        }
    }

    // change id
    (*this).id = thread_id;
}

/**
 * @brief thread_exists checks whether a thread exists in the database.
 * @param thread_id is the unique thread id of the thread you are looking for. Ideally this would be the id of the current thread object.
 * @return whether or not the the thread exists in the database.
 */
bool Thread::thread_exists( int thread_id )
{
    // build the command.
    stringstream cmd;
    cmd << "select * "
        << "from threads;";

    // run the command.
    do_query( cmd.str() );
    QSqlQuery *query = get_query();

    while (query->next())
    {
        int _thread_id = query->value("thread_id").toInt();

        if ( (*this).id == _thread_id )
        {
            return true;
        }
    }

    // if the object does not exist in the database.
    return false;
}

/**
 * @brief log_thread will log the thread in the database. This will call thread_exists determining if the thread can be logged.
 * (Note: this function will log all internal messages in the thread vector, if they are not duplicates).
 * @param thread_id is the unique thread id of this thread.
 * @return whether or not the thread exists.
 */
bool Thread::log_thread( int thread_id )
{
    // log the messages.
    for (Message* m : thread) { m->log_message( (*this).id ); }

    if ( !thread_exists( thread_id ) )
    {
        stringstream cmd;
        cmd << "insert into threads ( thread_id, thread_title, time, date ) "
            << "values ( "
            << id                         << ", "
            << "\"" << threadName << "\"" << ", "
            << "\"" << time       << "\"" << ", "
            << "\"" << date       << "\"" << " );";

        //cout << "Doing query: " << cmd.str() << endl;
        return do_query( cmd.str() );
    }
    else return false;
}

/**
 * @brief new_message adds a new message to the thread vector.
 * @param message is the text within the vector.
 * @param user_id is the unique user id to identify the post user.
 */
void Thread::new_message( string message, int user_id )
{
    Message* m = new Message( message, user_id, (*this).id );
    post_push_back( m );
}

size_t Thread::thread_size()
{
    return (*this).thread.size();
}
