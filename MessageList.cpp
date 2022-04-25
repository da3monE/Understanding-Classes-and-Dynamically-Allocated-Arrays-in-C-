/**
*  For this project, two files (Message.cpp and MessageList.cpp)
*  will be used to understand classes. The goal is to be able to store
*  and output the messages. This second file will store the information
*  given in the input file in an array, and depending on the command read
*  in by the main, will either output all the contents of the message list,
*  output what was added to the array, output what was removed from the
*  array, or output how many messages were loaded into the array.The
*  comments above the functions and inside in the following will indicate
*  what each part does.
**/

#include "MessageList.h"

//Constructor
MessageList::MessageList()
{
  count = 0; //sets count to zero. used for counting
  //how many messages are in the array
  size = 10; //starting size of the array
  messages = new Message[size]; //allocates memory to array
}

//Destructor
MessageList::~MessageList()
{
  delete[] messages; //deletes memory from the array
  //because it is dynamically allocated
}

//adds the given message to the end of the message message list
//it will also grow the array if the array is full
void MessageList::addMessage(Message m)
{
  // This grows the array if it is full
  if(count == size)
  {
    Message *tempMessages = new Message[size*2];

    for(int i = 0; i < size; i++)
    {
      tempMessages[i] = messages[i];
    }

    delete[] messages; //deletes memory in array
    messages = tempMessages; //sets array to a temporary one
    tempMessages = NULL; //sets the array to be empty
    size *= 2; //doubles size
  }

  //Adds message to message list
  if(count >= 0 && count < size)
  {
    messages[count] = m;
    count++;
  }
}

//This will attempt to return the message at the given message_location
// if the message_location is valid.
//If it is invalid, it will return a message will all the fields set to
//string, ""
Message MessageList::getMessageAt(int message_location) const
{
  //This returns a message if the message index
  //is invalid
  if(message_location < 0 || message_location >= count)
  {
    return Message();//returns message
  }

  //if the index is valid, this will return
  //the message
  else
  {
    return messages[message_location]; //returns message
  }
}

//returns the number of messages in the list
int MessageList::getMessageCount() const
{
  return count; //returns count
}

//This will output each message that is in the list
//in the format that each message is output like
//in the previous Message.cpp file. At the end of the
//output, there will be a line that outputs the message
//count
void MessageList::outputMessage(ostream &out) const
{
  for (int i = 0; i < count; i++)
  {
    messages[i].outputMessage(out); //outputs message information
  }

  //outputs message count
  out << "Message Count: " << getMessageCount() << endl;
}

//This will attempt to remove and return the message at the
//given message_location if the message_location is valid.
//If it is invalid, it will return a message with all the fields
//set to string, "".
Message MessageList::removeMessageAt(int message_location)
{
  if(message_location >= 0 && message_location < count)
  {
    Message tempMessage = messages[message_location];

    for ( int i=message_location; i<count-1; i++ )
    {
      messages[i] = messages[i+1];//covers up index
    }

    count--; //decrement
    return tempMessage; //returns the temporary array

  }

  else
  {
    return getMessageAt(message_location); //returns message location
  }

}

//end of program
