
#include <iostream>
using namespace std;


template <typename keytype>
class BHeap {
private:
    struct Node {
        int degree; //number of children
        // Node* p;
        Node *child;
        Node *sib;
        keytype key;
    };

    Node *head;
    Node *min;

    Node *binomialLink(Node *y, Node *z);
    void preorderhelp(Node *node);
    Node *mergeLists(Node *h1, Node *h2);
    void setMin();
    void delTree(Node *node);
    Node *cloneTree(Node *node);

public:

    BHeap(): head(nullptr), min(nullptr) { }
    BHeap(const BHeap<keytype> &otherHeap);
    //Constructor using repeated insertion
    BHeap(keytype k[], int s);
    void insert(keytype k);
    void merge(BHeap<keytype> &H2);
    void printKey();
    keytype peekKey();
    keytype extractMin();
    ~BHeap();
    BHeap<keytype> &operator=(const BHeap<keytype> &otherHeap);
    // This function will help with inserts. It works by merging two trees of the same degree 
    // this function will make z the parent of y
};

template<class keytype>
void BHeap<keytype>::insert(keytype k) {
    //create a new node with the given key which becomes the head  
    Node *newNode = new Node;
    newNode->key = k;
    newNode->degree = 0;
    // insert->p = nullptr;
    newNode->sib = nullptr;
    newNode->child = nullptr;
    // if(bhead.min->k == nullptr){
    //     bhead.min = insert;
    // }else if(bhead.min->k > insert.min->k){
    //     bhead.min = insert;
    // }
    BHeap<keytype> newHeap = BHeap<keytype>();
    newHeap.head = newNode;
    newHeap.min = newNode;
    merge(newHeap);
}

template<class keytype>
typename BHeap<keytype>::Node *BHeap<keytype>::mergeLists(Node *h1, Node *h2) {
    if (h1 == nullptr) {
        return h2;
    }
    if (h2 == nullptr) {
        return h1;
    }
    Node *newHead;
    if (h2->degree < h1->degree) {
        newHead = h2;
        h2 = h2->sib;
    } else {
        newHead = h1;
        h1 = h1->sib;
    }
    Node *current = newHead;
    while (h1 != nullptr && h2 != nullptr) {
        if (h2->degree < h1->degree) {
            current->sib = h2;
            current = h2;
            h2 = h2->sib;
        } else {
            current->sib = h1;
            current = h1;
            h1 = h1->sib;
        }
    }
    if (h1 == nullptr) {
        current->sib = h2;
    } else {
        current->sib = h1;
    }
    return newHead;
}

template<class keytype>
void BHeap<keytype>::merge(BHeap<keytype> &H2) {
    head = mergeLists(head, H2.head);
    H2.head = nullptr;
    H2.min = nullptr;
    if (head == nullptr) {
        return;
    }
    Node *prev = nullptr;
    Node *current = head;
    min = head;
    Node *next = current->sib;
    while (next != nullptr) {
        if ((current->degree != next->degree) ||
            (next->sib != nullptr && next->sib->degree == current->degree)) {
            prev = current;
            current = next;
        } else if (current->key <= next->key) {
            current->sib = next->sib;
            binomialLink(next, current);
        } else {
            if (prev == nullptr) {
                head = next;
            } else {
                prev->sib = next;
            }
            binomialLink(current, next);
            current = next;
        }
        if (current->key <= min->key) {
            min = current;
        }
        next = current->sib;
    }
    //If a root is null then return the other one.This would be for if you are adding something to an empty heap or trying to add an empty heap

// int i = 0;
// if (H2[i] != nullptr) {  
//     if(bheap[i]->degree <= H2->degree){

// if(bheap[i] != nullptr )

}

template<class keytype>
BHeap<keytype>::BHeap(keytype k[], int s): head(nullptr), min(nullptr) {
    for (int i = 0; i < s; i++) {
        insert(k[i]);
    }
}

template<class keytype>
void BHeap<keytype>::preorderhelp(BHeap<keytype>::Node *node) {
    if (node == nullptr) {
        return;
    }
    cout << node->key << " ";
    preorderhelp(node->child);
    preorderhelp(node->sib);
}

template<class keytype>
void BHeap<keytype>::printKey() {
    // Node* temp = head;
    for (Node *currentTree = head; currentTree != nullptr; currentTree = currentTree->sib) {
        cout << "B" << currentTree->degree << endl;
        cout << currentTree->key << " ";
        preorderhelp(currentTree->child);
        cout << endl << endl;
    }
}

template<class keytype>
keytype BHeap<keytype>::peekKey() {
    return min->key;
}

template<class keytype>
typename BHeap<keytype>::Node *BHeap<keytype>::binomialLink(Node *y, Node *z) {
    // y->p = z;
    y->sib = z->child;
    z->child = y;
    z->degree = z->degree + 1;
    return z;
}

template<class keytype>
keytype BHeap<keytype>::extractMin() {
    Node *prev = nullptr;
    Node *current = head;
    while (current != min) {
        prev = current;
        current = current->sib;
    }

    if (prev == nullptr) {
        head = current->sib;
    } else {
        prev->sib = current->sib;
    }

    keytype result = min->key;
    current = current->child;
    delete min;
    setMin();

    if (current != nullptr) {
        BHeap<keytype> newExHeap = BHeap<keytype>();
        while (current != nullptr) {
            Node *next = current->sib;
            current->sib = newExHeap.head;
            newExHeap.head = current;
            current = next;
        }
        newExHeap.setMin();
        merge(newExHeap);
    }

    return result;
}

template<class keytype>
void BHeap<keytype>::setMin() {
    if (head == nullptr) {
        min = nullptr;
    } else {
        min = head;
        for (Node *current = head->sib; current != nullptr; current = current->sib) {
            if (current->key < min->key) {
                min = current;
            }
        }
    }
}

template<class keytype>
BHeap<keytype>::~BHeap() {
    delTree(head);
}

template<class keytype>
void BHeap<keytype>::delTree(Node *node) {
    if (node == nullptr) {
        return;
    }
    Node *sib = node->sib;
    Node *child = node->child;
    delete node;
    delTree(child);
    delTree(sib);
}

template<class keytype>
BHeap<keytype>::BHeap(const BHeap<keytype> &otherHeap) {
    head = cloneTree(otherHeap.head);
    setMin();
}

template<class keytype>
BHeap<keytype> &BHeap<keytype>::operator=(const BHeap<keytype> &otherHeap) {
    if (this != &otherHeap) {
        delTree(head);
        head = cloneTree(otherHeap.head);
        setMin();
    }
    return *this;
}

template<class keytype>
typename BHeap<keytype>::Node *BHeap<keytype>::cloneTree(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node *newNode = new Node();
    newNode->key = node->key;
    newNode->degree = node->degree;
    newNode->sib = cloneTree(node->sib);
    newNode->child = cloneTree(node->child);
    return newNode;
}