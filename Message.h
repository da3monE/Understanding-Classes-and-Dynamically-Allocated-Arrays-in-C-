#include <string>
#include <iostream>

using std::ostream;
using std::string;
using std::endl;

#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
private:
    string to;
    string from;
    string date;
    string message;
public:
    Message();

    void setTo( string newTo );
    void setFrom( string newFrom );
    void setDate( string newDate );
    void setMessage( string newMessage );

    string getTo() const;
    string getFrom() const;
    string getDate() const;
    string getMessage() const;

    void outputMessage( ostream &out ) const;
};

#endif 
