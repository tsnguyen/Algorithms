/*
    The linked list implementation of deque. We will use template to make the
    implementation general, but for now we will just pretend that the data
    is a list of doubles.
*/
#ifndef __DEQUE_H__
#define __DEQUE_H__

template <typename DataType>
struct Node{
    DataType value;
    Node *next, *previous;
};
//template <typename DataType>
class Deque{
    private:
        Node *first_, *last_;
        unsigned size_;
    public:
        Deque(void);
        bool IsEmpty(void){return size_ ==0;}
        int Size(void){return size_;]
        void AddFirst(double);
        void AddLast(double);
        double RemoveFirst(void);
        double RemoveLast(void);
        ~Deque(void);
};

Deque::Deque(void){
    first_ = null_ptr; // should replace with nullptr
    last_ =  NULL;
    size_ = 0;
}
void Deque::AddFirst(double x){
    Node *ptr = new Node;
    ptr.value = x;
    ptr.next = first_;
    ptr.previous = NULL;
    first_.previous = ptr;
    first_ = ptr;
    size_++;
}

double Deque::RemoveFirst(void){
    Node *ptr = first_;
    first_ = first_.next;
    first_.previous = NULL;
    double value = ptr.value;
    delete ptr;
    size_--;
    return value;
}

void Deque::AddLast(double x){
    Node *ptr = new Node;
    ptr.value = x;
    ptr.next = NULL;
    ptr.previous = last_;
    last_.next = ptr;
    size_++;
}

double Deque::RemoveLast(void){
    Node *ptr = last_;
    last_ = last_.previous;
    double value = ptr.value;
    delete ptr;
    size_--;
    return value;
}
Deque::~Deque(void){
    while (size_ != 0)
        RemoveFirst();
}
#endif