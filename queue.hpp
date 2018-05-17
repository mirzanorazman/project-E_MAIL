// Author : Mirza Nor Azman


#ifndef queue_hpp
#define queue_hpp
const int BUFSIZE = 500;

template <typename T>
struct Node{
    T data;
    Node<T>*next;
};

template <typename T>
class Queue
{
private:
    T buf[BUFSIZE];
    int front;
    int rear;
    int nextIndex(int index) { // Calculates and returns the value of the next index with wrap-around.
        if (++index == BUFSIZE) index = 0;
        return index;
    }
public:
        Queue() {front = rear = 0;}
        ~Queue(){};
        bool insertQ(T &mailbox);
        bool removeQ(T &mailbox);
        bool isEmpty() {return (front == rear);}
        bool isFull() {return (nextIndex(rear) == front);}
        int returnUnread(){return rear-front;}
};


#endif /* queue_hpp */
