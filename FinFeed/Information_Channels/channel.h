#ifndef CHANNEL_H
#define CHANNEL_H
#include <string>

class Channel
{
public:
    //COMMUNITY

    /**
     * @brief Channel
     * Channel constructor
     */
    Channel();

    /**
     * @brief ~Channel
     * Channel destructor
     */
    ~Channel();

    // TODO:

    // Maybe this is all just an information class

private:
    // name of the channel
    std::string chan_name;

    // number of users following this channel
    // or active in it
    int num_users;

    // TODO:
    // Vector of posts?
    // Vector of current users?
};

#endif // CHANNEL_H
