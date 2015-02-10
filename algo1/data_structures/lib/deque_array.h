/*
    The array implementation of deque.
*/
#ifndef __DEQUE_ARRAY_H__
#define __DEQUE_ARRAY_H__

class Deque{
    private:
        double *data_, *first_, *last_;
        unsigned size_, capacity_;
        void ReduceSize(void);
        void DoubleSize(void);
    public:
        Deque(void);
        bool IsEmpty(void){return size_ == 0;}
        int Size(void){return size_;}
        void AddFirst(double);
        void AddLast(double);
        double RemoveFirst(void);
        double RemoveLast(void);
        ~Deque(void);
}

Deque::Deque(void){
    data_   = new (3 * double);
    first_  = data_ + 1;
    last_   = data_ + 2;
}

void Deque::AddFirst(double x){
    if (first_ == data_)
        DoubleSize();
    first_--;
    (*first_) = x;
    size_++;
}
void Deque::AddLast(double x){
    if (first_ + capacity_ == last_)
        DoubleSize();
    last_++;
    (last_) = x;
    size_++;
}
double Deque::RemoveFirst(void){
    double value;
    value = *first_;
    first_++;
    size_--;
    if (size_ < capacity_ / 6.0)
        ReduceSize();
    return value;
}

double Deque::RemoveLast(void){
    double value;
    value = *last_;
    last_--;
    size_--;
    if(size_ < capacity_ / 6.0)
        ReduceSize();
    return value;
}

void Deque::DoubleSize(void){
    double *ptr = data_;
    data_ = new (capacity_ * 2) double;
    capacity_ *= 2;
    first_ = data_ + capacity_ / 3;
    for(auto i = 0; i < size_; i++)
        data_[capacity_ / 3 + i ] = ptr[capacity_ / 6 + i];
    last = data_ + i - 1;
    delete (capacity_ / 2) double;
}

void Deque::HalfSize(void){
    // Should be replace by ChopTail() and ChopHead()
}
#endif