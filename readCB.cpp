// Author : Mirza Nor Azman

#include "labgui.h"
Message mail;

void readCB(Fl_Button*,void*){
    subPtr->user.mailbox.removeQ(mail);
    std::string content;
    content= "From:"+mail.from +"\n"
            + "To: "+mail.to +"\n"
            + "Message: " +mail.text;
    //subPtr->user.mailbox.insertQ(mail);
    dispBfr->text(content.c_str());
    
}
