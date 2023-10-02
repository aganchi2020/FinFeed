#ifndef THREAD_H
#define THREAD_H

#include <vector>
#include <string>
#include "message.h"
#include "../Config/config.h"

using namespace std;

class Thread : public Config
{
public:
    /*variables*/
    string threadName;

    /*constructors*/
    Thread( string threadName, int community_id ); // base constructor
    Thread( Thread &obj ); // copy constructor
    ~Thread();

    /*methods*/
    /**
     * @brief new_message adds a new message to the thread vector.
     * @param message is the text within the vector.
     * @param user_id is the unique user id to identify the post user.
     */
    void new_message( string message, int user_id );

    /**
     * @brief build_existing_thread will build the thread from the database according to the thread id.
     * @param thread_id is a unique thread if for all threads.
     */
    void build_existing_thread( int community_id );


    /**
     * @brief thread_exists checks whether a thread exists in the database.
     * @param thread_id is the unique thread id of the thread you are looking for. Ideally this would be the id of the current thread object.
     * @return whether or not the the thread exists in the database.
     */
    bool thread_exists( int community_id );

    /**
     * @brief log_thread will log the thread in the database. This will call thread_exists determining if the thread can be logged.
     * (Note: this function will log all internal messages in the thread vector, if they are not duplicates).
     * @param thread_id is the unique thread id of this thread.
     * @return whether or not the thread exists.
     */
    bool log_thread( int community_id );

    /**
     * @brief post_at will get the post at the specified index provided. If the index is not valid, the method will return a null pntr.
     * @param index is a size_t variable.
     * @return a Message object pntr.
     */
    Message* post_at( size_t index );

    /**
     * @brief post_pop_back pops the last message object pntr in the internal thread vector.
     * @return a Message object pntr.
     */
    Message* post_pop_back();

    /**
     * @brief post_peak_back peak at the back of the internal thread vector.
     * @return a Message object pntr.
     */
    Message* post_peak_back();

    /**
     * @brief post_push_back pushes a post object to the end of the internal thread vector.
     * @param post is post object pntr.
     */
    void post_push_back( Message* post );

    /**
     * @brief sort_thread sorts the messages in chronological order by their message_id.
     * @param direction is a string of either 'DESC' or 'ASC' specifying if the messages will be sorted in ascending or descending order.
     */
    bool sort_thread( string direction );

    size_t thread_size();

private:
    vector<Message*> thread; // internal message vector.
};

#endif // THREAD_H
