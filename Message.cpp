/**
*  For this final project, two files (Message.cpp and MessageList.cpp)
*  will be used to understand classes. The goal is to be able to store
*  and output the messages. This first file sets the information given
*  in the input file as strings so the main can read in the information,
*  return and update the information accordingly. The comments above
*  the functions in the following will indicate what each part does.
**/

#include "Message.h"

//Constructor
//Sets the private fields to the empty string. ""
Message::Message()
{
  to = "";
  from = "";
  date = "";
  message = "";
}

//This returns the date
string Message::getDate() const
{
  return date;
}

//This returns who the message is from
string Message::getFrom() const
{
  return from;
}

//This returns the message
string Message::getMessage() const
{
  return message;
}

//This returns who the message is to
string Message::getTo() const
{
  return to;
}

//This outputs who the message was sent to (to),
//who the message was from (from),
//when the message was sent (date),
//and the message that was sent (message)
void Message::outputMessage(ostream &out) const
{
  out << "To: " << to << endl;
  out << "From: " << from << endl;
  out << "Date: " << date << endl;
  out << "Message:" << endl;
  out << message << endl;
}

//This updates the date
void Message::setDate(string newDate)
{
  date = newDate;
}

//This updates who the message is from
void Message::setFrom(string newFrom)
{
  from = newFrom;
}

//This updates the message
void Message::setMessage(string newMessage)
{
  message = newMessage;
}

//This updates who the message is to
void Message::setTo(string newTo)
{
  to = newTo;
}

//end of program
