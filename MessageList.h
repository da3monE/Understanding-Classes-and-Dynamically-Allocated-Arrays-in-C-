#include "Message.h"
#include <iostream>
#include <fstream>
#include <string>

using std::endl;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;

#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

class MessageList
{
private:
    Message *messages;
    int count;
    int size;

    void grow();
public:
    MessageList();
    ~MessageList();

    void addMessage( Message m );
    Message getMessageAt( int message_location ) const;
    Message removeMessageAt( int message_location );

    void outputMessage( ostream &out ) const;
    int getMessageCount() const;

};

#endif
