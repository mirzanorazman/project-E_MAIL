// Author : Mirza Nor Azman

#include "labgui.h"
void saveCB(Fl_Button*,void*){
    //const char filename[] = "SubscriberList.txt";
    SaveTree("SubscriberList.txt", root);
    loginWin.hide();
}
