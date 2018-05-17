#include "labgui.h"

const int WIDTH = 300;
const int HEIGHT = 300;

Fl_Double_Window loginWin(WIDTH,HEIGHT,"E-mail login");
Fl_Double_Window inboxWin(WIDTH,HEIGHT,"Inbox");
Fl_Double_Window sendWin(WIDTH,HEIGHT,"Edit message");
Fl_Double_Window sysopWin(WIDTH,HEIGHT,"System Operator");

Fl_Input *name;
Fl_Input *newuser;
Fl_Input *remUser;
Fl_Input *password;
Fl_Input *toBox;
Fl_Text_Display *dispMsg;
Fl_Text_Editor *sendBox;
Fl_Text_Buffer *editBfr;
Fl_Text_Buffer *dispBfr;

TREENODE* subPtr;
TREENODE* root = 0;

int main(){
    //std::string fileName = "SubscriberList.txt";
    root = LoadTree("SubscriberList.txt");

    loginWin.begin();
    //loginWin.color(0x25F4FD);
        name = new Fl_Input(0.3*WIDTH,0.1*HEIGHT , 150, 30,"Name:");
        password = new Fl_Input(0.3*WIDTH,0.4*HEIGHT , 150, 30,"Password:");
        Fl_Button login (0.4*WIDTH,0.6*HEIGHT,70,30,"Login");
            login.callback((Fl_Callback*)loginCB);
        Fl_Button close (0.2*WIDTH,0.7*HEIGHT,180,30,"Close and Save all");
            close.callback((Fl_Callback*)saveCB);
    loginWin.end();

    inboxWin.begin();
        dispMsg = new Fl_Text_Display(WIDTH*0.1,HEIGHT*0.1,WIDTH*0.8,HEIGHT*0.6,"Inbox");
        dispBfr = new Fl_Text_Buffer();
        dispMsg->buffer(dispBfr);
        Fl_Button next (0.1*WIDTH,0.7*HEIGHT,115,30,"Next Unread");
            next.callback((Fl_Callback*)readCB);
        Fl_Button arch (0.1*WIDTH,0.8*HEIGHT,115,30,"Archive Message");
            arch.callback((Fl_Callback*)archCB);
        Fl_Button create(0.5*WIDTH,0.8*HEIGHT,115,30,"Create Msg");
            create.callback((Fl_Callback*)createCB);
        Fl_Button logout(0.5*WIDTH,0.7*HEIGHT,115,30,"Logout");
            logout.callback((Fl_Callback*)logoutCB);
    inboxWin.end();
    
    sendWin.begin();
        toBox = new Fl_Input(0.1*WIDTH,0.05*HEIGHT,120,30,"To:");
        sendBox = new Fl_Text_Editor(0.1*WIDTH,0.25*HEIGHT,WIDTH*.7,HEIGHT*.6,"Message:");
        editBfr = new Fl_Text_Buffer();
        sendBox->buffer(editBfr);
        Fl_Button send (0.35*WIDTH,0.85*HEIGHT,70,30,"SEND");
            send.callback((Fl_Callback*)sendCB);
        Fl_Button logout2(0.6*WIDTH,0.05*HEIGHT,115,30,"Logout");
            logout2.callback((Fl_Callback*)logoutCB);
    sendWin.end();
    
    sysopWin.begin();
        remUser = new Fl_Input(0.3*WIDTH,0.1*HEIGHT,120,30,"Username:");
        Fl_Button rem(0.3*WIDTH, 0.22*HEIGHT,115, 30,"Remove User");
            rem.callback((Fl_Callback*)deleteUserCB);
        newuser = new Fl_Input(0.4*WIDTH, 0.4*HEIGHT,120, 30,"New user name:");
        Fl_Button add(0.3*WIDTH, 0.55*HEIGHT,115, 30);add.label("Add user");
            add.callback((Fl_Callback*)addUserCB);
        Fl_Button logout3(0.3*WIDTH,0.75*HEIGHT,115,30,"Logout");
            logout3.callback((Fl_Callback*)logoutCB);
        Fl_Button bill(0.3*WIDTH,0.85*HEIGHT,115,30,"Call bill cycle");
            bill.callback((Fl_Callback*)billCB);
    sysopWin.end();
    
    loginWin.show();
    Fl::run();
}
