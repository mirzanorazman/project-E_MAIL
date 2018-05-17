// Author : Mirza Nor Azman

//#include "queue.hpp"
#include "tree.h"

template<>
bool Queue<Message>::insertQ(Message &message)
{
    if (isFull()) return false;
    buf[rear] = message;
    rear = nextIndex(rear);
    return true;
}

//template <class T>
template<>
bool Queue<Message>::removeQ(Message &message){
    if (isEmpty()) return false;
    message = buf[front];
    front = nextIndex(front);
    return true;

}
