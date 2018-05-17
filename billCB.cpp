#include "labgui.h"
std::string billSummary;
void billCB(Fl_Button*,void*){
//    std::string billSummary;
    TraverseInOrder(root);
    fl_alert("%s", billSummary.c_str());
}
