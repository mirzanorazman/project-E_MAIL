#include "tree.h"
int Compare(const Subscriber user1, const Subscriber user2){
    if(user1.name<user2.name)
        return -1;
    else if(user1.name>user2.name)
        return 1;
    else
        return 0;
}
