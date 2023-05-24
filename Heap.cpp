
#include "CircularDynamicArray.cpp"
#include <iostream>
using namespace std;


template <typename keytype>
class Heap {
    private:
    CircularDynamicArray<keytype> heap;
    public:

    Heap(){
        heap = CircularDynamicArray<keytype>();
    }

    Heap(keytype k[], int s){
        heap = CircularDynamicArray<keytype>(s);
        for(int j = 0; j < heap.length(); j++){
            heap[j] = k[j];
        }
        for(int i = (s-1)/2; i >= 0; i--){
            MinHeap(i);
        }
    }

    //Copy Constructor
    Heap(const Heap& src){
        heap = src.heap; //Copies the CircularDynamic Array Object
    }
    //Copy Assignment Operator
    Heap& operator=(const Heap& src){
        if(this != &src){ //Check for self assignment
            heap = src.heap; //Copy circular dynamic array object
        }
        return *this;
    }

    void MinHeap(int i);
    int Parent(int i);
    void printKey();
    ~Heap();
    keytype peekKey();
    keytype extractMin();
    void insert(keytype k);
    void Heapify(int s);

};

template<class keytype> void Heap<keytype>::Heapify(int s){
    if(heap[Parent(s)] > heap[s]){
        keytype swap = heap[s];
        heap[s] = heap[Parent(s)];
        heap[Parent(s)] = swap;
        Heapify(Parent(s));
    }

}

template<class keytype> void Heap<keytype>::insert(keytype k){
    heap.addEnd(k);
    Heapify(heap.length() - 1);
}

template<class keytype> keytype Heap<keytype>::extractMin(){
    if(heap.length() < 1 ){
        cout << "ERROR HEAP UNDERFLOW" << endl;
    }
    keytype min = heap[0]; 
    heap[0] = heap[heap.length()-1];
    heap.delEnd();
    MinHeap(0);
    return min; 
}

template<class keytype> keytype Heap<keytype>::peekKey(){
    return heap[0];
}

template<class keytype>
 void Heap<keytype>::printKey(){
    for(int i = 0; i <heap.length(); i++){
        cout <<heap[i] << " ";
    }
    cout << endl;
}
template<class keytype>
 Heap<keytype>::~Heap(){
 }

template<class keytype>
 int Heap<keytype>::Parent(int i){
    return (i-1)/2;
 }

template<class keytype>
void Heap<keytype>::MinHeap(int i){
    int left = (2 * i) + 1;;
    int right = (2 * i) + 2;;
    int smallest = i;
    if( (left < heap.length() ) && (heap[smallest] > heap[left]) ){
        smallest = left;
    }
    if((right < heap.length()) && (heap[smallest] > heap[right])){
        smallest = right;
    }
    if(smallest != i){
        keytype swap = heap[smallest];
        heap[smallest] = heap[i];
        heap[i] = swap;
        MinHeap(smallest);
    }
}