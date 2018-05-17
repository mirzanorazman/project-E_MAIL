// Author : Mirza Nor Azman

#include "labgui.h"

void addUserCB(Fl_Button*,void*){
    std::string newUsername = newuser->value();
    std::string defaultPass = "password";
    std::string alert = "User " + newUsername + " added.";
    Subscriber user;
    user.name = newUsername;
    user.password = defaultPass;
    bool flag = Insert(root, user);
    if(flag==true){
        fl_alert("%s", alert.c_str());
    }
}
