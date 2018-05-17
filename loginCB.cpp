// Author : Mirza Nor Azman

#include "labgui.h"
#include <string>
#include <algorithm>
#include <string>

void loginCB(Fl_Button*,void*){
    std::string nameInput = name->value();
    std::string passwordInput = password->value();
    std::transform(nameInput.begin(), nameInput.end(), nameInput.begin(), ::tolower);
    if(nameInput=="sysop" && passwordInput =="sysop"){
        sysopWin.show();
        loginWin.hide();
    }
    else{
        std::string error = "User does not exist!";
        std::string error2 = "Wrong password!";
        Subscriber s;
        s.name=nameInput;
        subPtr = new TREENODE;
        subPtr = Find(root, s);
        if(subPtr==nullptr)
            fl_alert("%s", error.c_str());
        else if (subPtr->user.password==passwordInput){
            int unread = subPtr->user.mailbox.returnUnread();
            std::string s = std::to_string(unread);
            std::string welcome = "Welcome : " + nameInput + "\nYou have " + s + " unread messages";
            std::cout << "Login: "<<nameInput<<std::endl;
            fl_alert("%s", welcome.c_str());
            loginWin.hide();
            inboxWin.show();
        }
        else{
            fl_alert("%s", error2.c_str());
        }
    }
}
