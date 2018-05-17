#ifndef labgui_h
#define labgui_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Cairo_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
#include <iostream>
#include "tree.h"

//window
extern Fl_Double_Window loginWin;
extern Fl_Double_Window inboxWin;
extern Fl_Double_Window sendWin;
extern Fl_Double_Window sysopWin;
//inputs
extern Fl_Input *name;
extern Fl_Input *password;
extern Fl_Input *toBox;
extern Fl_Input *newuser;
extern Fl_Input *remUser;
extern Fl_Text_Display *dispMsg;
extern Fl_Text_Buffer *dispBfr;
extern Fl_Text_Editor *sendBox;
extern Fl_Text_Buffer *editBfr;
//callbacks
void loginCB(Fl_Button*,void*);
void sendCB(Fl_Button*,void*);
void createCB(Fl_Button*,void*);
void readCB(Fl_Button*,void*);
void archCB(Fl_Button*,void*);
void logoutCB(Fl_Button*,void*);
void addUserCB(Fl_Button*,void*);
void deleteUserCB(Fl_Button*,void*);
void saveCB(Fl_Button*,void*);
void billCB(Fl_Button*,void*);




#endif /* labgui_h */
