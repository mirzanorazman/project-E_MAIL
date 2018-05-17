// Author : Mirza Nor Azman

#ifndef email_h
#define email_h

#include<iostream>
#include"queue.hpp"

struct Message{
    std::string from;
    std::string to;
    std::string text;
};

class Subscriber{
public:
    std::string name;
    std::string password;
    int sentCount=0;
    Queue<Message> mailbox;
    Subscriber(){
        name="";
        password = "";
    }
};

extern Message mail;


#endif /* email_h */
