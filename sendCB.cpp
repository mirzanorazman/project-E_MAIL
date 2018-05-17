// Author : Mirza Nor Azman

#include "labgui.h"

void sendCB(Fl_Button*,void*){
    std::string from = subPtr->user.name;
    std::string sendTo = toBox->value();
    std::string text = editBfr->text();
    std::string alert = "Message sent to: " + sendTo + ".";
    std::string err = "That user does not exist!";
    subPtr->user.sentCount++;
    
    Message newmail;
    newmail.from = from;
    newmail.to = sendTo;
    newmail.text = text;
    
    Subscriber findUser;
    findUser.name=sendTo;
    
    subPtr=Find(root, findUser);
    if(subPtr==nullptr){
        fl_alert("%s", err.c_str());
    }
    else{
        subPtr->user.mailbox.insertQ(newmail);
        fl_alert("%s", alert.c_str());
    }
    std::cout << from << "\n" << sendTo << "\n" << text << std::endl;
    
}
