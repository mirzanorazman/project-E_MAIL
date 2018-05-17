// Author : Mirza Nor Azman

#include "labgui.h"

void logoutCB(Fl_Button*,void*){
    inboxWin.hide();
    sendWin.hide();
    sysopWin.hide();
    loginWin.show();
}
