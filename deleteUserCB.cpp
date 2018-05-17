#include "labgui.h"

void deleteUserCB(Fl_Button*,void*){
    std::string username = remUser->value();
    std::string error = "User does not exist!";
    std::string success = "User deleted!";
    
    Subscriber s;
    s.name=username;
    subPtr = new TREENODE;
    subPtr = Find(root, s);
    if(subPtr==nullptr)
        fl_alert("%s", error.c_str());
    else{
        Remove(root, s);
        fl_alert("%s", success.c_str());
    }

}
