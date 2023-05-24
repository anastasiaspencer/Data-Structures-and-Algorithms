#include <iostream>
using namespace std;
#ifndef CDA
#define CDA

template <class T>
class CircularDynamicArray {
    private:

        T *arr;
        int range, size, front, back, isReversed;

    public:

        CircularDynamicArray(){
            size = 0;
            range = 2;
            arr = new T[range];
            front = 0;
            back = -1;
            isReversed = 1;
        }
        CircularDynamicArray(int s){
            range = s;
            size = s;
            front = 0;
            back = s - 1;
            isReversed = 1;
            arr = new T[range];
        }

        T& operator[](int i);
        void delFront();
        void delEnd();
        void addEnd(T v);
        void addFront(T v);
        void reverse();
        void clear();

        int length();
        int capacity();
        ~CircularDynamicArray();

        int linearSearch(T e);
        void stableSort();
        int binSearch(T e);
        T QuickSelect(int k);
        void mergeSort(T a[], int n);
        void merge(T a[], T a1[], T a2[], int n);
        T select(T *a, int k, int v);
        //Copy assignment operator:

        
         CircularDynamicArray& operator=(const CircularDynamicArray& src){
            if(this != &src){
                delete[] arr;
                this->range = src.range;
                this->size = src.size;
                this->front = src.front;
                this->back = src.back;
                this->isReversed = src.isReversed;
                arr = new T[range];
                for(int i = front; i <size + front; i++){
                    this->arr[i % range]=src.arr[i % range];
                }
                return *this;
            }
            return *this;
        }

        //copy construcotr

     CircularDynamicArray(const CircularDynamicArray& src){
            this->range = src.range;
            this->size = src.size;
            this->front = src.front;
            this->back = src.back;
            this->isReversed = src.isReversed;
            arr = new T[range];
            for(int i = front; i < size + front; i++){
                this->arr[i % range] = src.arr[i % range];
            }
        }

      

};
    
    template <class T>
     CircularDynamicArray<T> :: ~CircularDynamicArray(){
        delete[] arr;
    }

    template <class T>
    int CircularDynamicArray<T> :: length(){
    return size;
    }

    template <class T>
    int CircularDynamicArray<T> :: capacity(){
    return range;
    }

    template <class T>
    T& CircularDynamicArray<T> :: operator[](int i){
         if( i <= size && i>=0 ){
            
            return arr[(front + range + (isReversed * i)) % range ];
        } else {
            cout << "ERROR OUT OF BOUNDS" << endl;
            T *temp = new T;
            return *temp ;

        }
    }

    template <class T>
    void CircularDynamicArray<T> :: delFront(){
        if(size <= range/4){
           T *newarr = new T[range/2];
            for(int j = 0; j < size; j++ ){
                newarr[j] = arr[front];
                front = ((front + isReversed) + range)% range;
            }
            //delete[] arr;
            arr = newarr;
            front = 0;
            size = size-1;
            back = size-1;
            range = range / 2;
            isReversed = 1;
        }
        size = size-1;
        front =((front + isReversed) + range)% range;

    }

    template <class T>
    void CircularDynamicArray<T> :: delEnd(){
        if(size <= range/4){
           T *newarr = new T[range/2];
            for(int j = 0; j < size; j++ ){
                newarr[j] = arr[front];
                front = ((front + isReversed) + range)% range;
            }
            //delete[] arr;
            arr = newarr;
            front = 0;
            size = size-1;
            back = size-1;
            range = range / 2;
            isReversed = 1;
        }

        size = size-1;
        back =( (back - isReversed) + range) % range;

    }

        template <class T>
    void CircularDynamicArray<T> :: addFront(T v){
         if(size == range){
             T *newarr = new T[range*2];
             for(int j = 1; j <= size; j++){
                  newarr[j] = arr[front];
                 
                  front = ((front + isReversed) + range)% range;
             }
              //delete[] arr;
          

              arr = newarr;
              front = 0; 
              back = size-1;
              range = range * 2;
              size = size + 1;
              arr[front] = v;
              isReversed = 1;
            
         }else{
        
            front = ((front - isReversed) + range) % range;

          size = size + 1;

            arr[front] = v;
            
        }

    }    

    template <class T>
    void CircularDynamicArray<T> :: addEnd(T v){
         if(size == range){
             T *newarr = new T[range*2];
             for(int j = 0; j < size; j++){
                  newarr[j] = arr[front];
                  front = ((front + isReversed) + range)% range;
             }
              //delete[] arr;
              arr = newarr;
              front = 0; 
               size = size + 1;
              back = size-1;
              range = range * 2;
              arr[back] = v;
              isReversed = 1;
            
         }else{
        
         size = size + 1;
            back = ((back + isReversed) + range)% range;

             if(back < 0){
            back += range;
          }      

            arr[back] = v;
            
        }

    }    

    template <class T>
    void CircularDynamicArray<T> :: reverse(){

        int temp = front;
        front = back;
        back = temp; 

        if(isReversed == -1){
            isReversed = 1;
        }else{
            isReversed = -1;
        }

    }

    template < class T>
    void CircularDynamicArray<T> :: clear(){
       delete[] arr;
        size = 0;
        range = 2;
        arr = new T[range];
        front = 0;
        back = -1;
        isReversed = 1;
    }

    template < class T >
    int CircularDynamicArray<T> :: linearSearch(T e){
        int j = front;
        for(int i= 0; i < size; i++ ){
            if(arr[j]== e){
                return ((j - front) + range ) % range;
            }
            j = (j + isReversed) % range;
        }
        return -1;
    }

    template < class T >
    int CircularDynamicArray<T> :: binSearch(T e){
        int left = front;
        int right = (front + size) -1;

        while(left<=right){
            int mid = ((left + right) / 2);
            if(arr[mid % range] == e){
                return ((mid-front) + range ) % range;
             }
            if(arr[mid % range] <= arr[right % range]){

                 if( e > arr[mid %range] && e <= arr[right %  range]){
                     left = (mid + 1) ;
                
                     }else{
                         right = (mid - 1) ;
                     }
                  }
                else{
                     if(arr[left % range] <= e && e < arr[mid % range]){
                         right = mid - 1;
                     }else{
                         left = mid + 1;
                     }
                 }
            }
         
        return -1;
    }

    template <class T>
    void CircularDynamicArray<T> :: stableSort(){
        T* mTemp = new T [size];
        int j = front;
        int newrange = range;
        for(int i = 0; i<size; i++){
            mTemp[i] = arr[j];
             j = ((j + isReversed) + range)% range;
        }
        mergeSort(mTemp, size);
        delete [] arr;
        arr = mTemp;
        front = 0; 
        back = size-1;
        range = newrange;
        isReversed = 1;

    }

    template<class T> 
    void CircularDynamicArray<T>::mergeSort(T *a, int n){
        if(n <= 1) return;
        T* a1 = new T[n/2];
        T* a2 = new T[n-(n/2)];
        for(int i = 0; i <n/2; i++){
            a1[i] = a[i];
        }
        for(int i = n/2; i<n; i++){
            a2[i-n/2] = a[i];           
        }
        mergeSort(a1, n/2);
        mergeSort(a2, n-n/2);
        merge(a, a1, a2, n);
    }

    template<class T> 
    void CircularDynamicArray<T>::merge(T *a, T *a1, T *a2, int n){
        int n1 = n/2;
        int n2 = n-(n/2);
        int p1 = 0;
        int p2 = 0;
        int i = 0;
        while(p1 < n1 && p2 < n2){
            a[i++] = a1[p1] < a2[p2] ? a1[p1++] : a2[p2++];
        }
        while(p1 < n1){
            a[i++] = a1[p1++];
        }
        while(p2 < n2){
            a[i++] = a2[p2++];
        }
    }

    template< class T >
    T CircularDynamicArray<T> :: select(T *A, int k, int loopsize){
        int left = 0;
        int right = loopsize-1;
        T pivot = A[((left+right)/2)];
        T* L = new T[loopsize];
        int lsize = 0;
        T* E = new T[loopsize];
        int esize = 0;
        T* G = new T[loopsize];
        int gsize = 0;
        for(int x = 0; x<loopsize; x++){
            if(A[x] < pivot){
                L[lsize] = A[x];
                lsize++;
            }else if(A[x]==pivot){
                E[esize] = A[x];
                esize++;
            }else{
                G[gsize] = A[x];
                gsize++;
            }      
        }

        if(k <= lsize){
            return select(L, k, lsize);
        }else if(k<=lsize+esize){
            return pivot;
        }else{
            return select(G, k - lsize - esize, gsize);
        } 
    }


    template<class T>
    T CircularDynamicArray<T> :: QuickSelect(int k){
       // cout<< "front" << arr[front] << " " << arr[back]<< " " << endl;
        T* A = new T [size];
        int j = front;
        int loopsize = size;
        for(int i = 0; i<size; i++){
            A[i] = arr[j];
             j = ((j + isReversed) + range)% range;
        }
        
        if( k > size){
            return -1;
        }
       return select(A, k, loopsize);
    }


#endif


    


