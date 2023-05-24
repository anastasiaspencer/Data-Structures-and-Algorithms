

// #include <iostream>
// #include <math.h>
// using namespace std;
// // correct file

// template <typename keytype, typename valuetype>
// class RBTree {
// private:
//     struct Node {
//         int color, nsize;
//         keytype key;
//         valuetype value;
//         Node *right, *left, *p;
//     };
//     int Tsize;  
//     Node *root;
//     Node *nil;
// public:
//      valuetype * search(keytype k);
//      int remove(keytype k);
// 	 int size();
// 	void preorder();
//     void inorder();
//     void postorder();
//     void recursPostorder(Node *post);
// 	void recursPreorder(Node *pre);
//     void recursDestruct(Node *dest);
//      void recursInorder(Node *In);
//      void LeftRotate(Node *x);
//      void RightRotate(Node *x);
//      int orderCheck(keytype k[], int s);
//      void RBInsertFixup(Node *z);
//      void insert(keytype k, valuetype v);
//      keytype * predecessor(keytype k);
//      keytype * successor(keytype k);
//      Node * minimum(Node *n);
//      Node * maximum(Node *n);
//      Node * FindNode(keytype k);
//     void RBTransplant(Node *u, Node *v);
//      void RBDeleteFixup(Node *x);
//      int rank(keytype k);
//      keytype select(int pos);
//      int recursRank(Node *x);
//      Node * osselect(Node *x, int i);
//      ~RBTree();
//      Node * copyCon(Node *c, Node *src_nil);
//      Node * insertSC(keytype k[], valuetype V[], int front, int back, int currlev, int lastlev);
//      //int median(int arr);
// 	   /*
//     Default Constructor for this class.
//     Creates an empty tree and a nil node. Sets root equal to nil. Creating nil node instead of using NULL will make implementation easier.
//     */
//     RBTree(){
//         nil = new Node;
//         nil->color = 1;
// 		//nil->value = 0;
//         nil->right = nil;
//         nil->left = nil;
//         nil->nsize = 0;
//         nil->p = nil;  
//         Tsize = 0; 
//         root = nil;
	
//     }
//     RBTree(keytype k[], valuetype V[], int s){
//         nil = new Node;
//         nil->color = 1;
// 		//nil->value = 0;
//         nil->right = nil;
//         nil->left = nil;
//         nil->nsize = 0;
//         nil->p = nil;  
//         Tsize = 0; 
//         root = nil; 

//        if(orderCheck(k, s) == 1){
// 			  root = insertSC( k, V, 0, s-1, 1, log2(s+1) );    
//        }else if(orderCheck(k,s) == 0){
//             for(int i = 0; i<s; i++){
//             insert(k[i],V[i]);
//              }
//          }   
//     }
//     //copy assignment operator
//     RBTree& operator=( const RBTree* src){
//         if (this != &src) {
//             this->~RBTree();
//             this->Tsize = src.Tsize;
//             nil = new Node();
//             nil->color = 1;
//             root = copyCon(src.root, src.nil);
//             root->p = nil;
//         }
//         return *this;
//     }

//     //copy constructor
//     RBTree(const RBTree& src ){
//         this->Tsize = src.Tsize;
//         nil = new Node();
//         nil->color = 1;
//         root = copyCon(src.root, src.nil);
//         root->p = nil;
//     }
	
// };

// template<class keytype, class valuetype>
// typename RBTree<keytype, valuetype>::Node *RBTree<keytype, valuetype>::copyCon(RBTree<keytype, valuetype>::Node *src, Node* src_nil){
//     if(src == src_nil){
// 		return this->nil;
// 	}
// 	Node *n = new Node();
//     n->color = src->color;
//     n->nsize = src->nsize;
//     n->value = src->value;
//     n->key = src->key;
// 	Node *left = copyCon(src->left, src_nil);
//     left->p = n;
//     n->left = left;
// 	Node *right = copyCon(src->right, src_nil);
//     right->p = n;
//     n->right = right;
//     return n;
//  }

// // template<class keytype, class valuetype> int RBTree<keytype, valuetype>::median(int arr){
    
// // }

// // Find the middle element of the sorted array.
// // Insert the middle element into the red-black tree.
// // Recursively repeat steps 1-2 on the left and right halves of the sorted array.

// template<class keytype, class valuetype>
// typename RBTree<keytype, valuetype>::Node *RBTree<keytype, valuetype>::insertSC(keytype *k, valuetype *V, int front, int back, int currlev, int lastlev){
//   int median = (front + back) /2;
//   if(front>back){
//     return nil;
//   }else{
//     Node *n = new Node;
//     n->key = k[median];
//     n->value = V[median];
//     n->nsize = 1;

//     if(currlev = lastlev){
//       n->color = 0;
//     }else{
//       n->color = 1;
//     }

//     n->left = insertSC(k, V, front, median-1, currlev+1, lastlev);
//     n->right = insertSC(k, V, median+1, back, currlev+1, lastlev);

  

//   //take care of size:::
//   n->nsize = n->nsize + n->left->nsize + n->right->nsize;

//   //parents dont set initially? trying to set them here

//   n->left->p = n;
//   n->right->p = n;

//   return n;

//   }

//  }

// template <typename keytype, typename valuetype>
// int RBTree<keytype, valuetype>::orderCheck(keytype k[], int s){
//     int count = 0;
//     for(int i = 0; i<s-1; i++){
//         if(k[i] < k[i+1]){
//             count ++;
//         }
//     }
//     if(count == s-1){
//         return 1;
//     }else{
//         return 0;
//     }
// }



//     template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::recursDestruct(Node *dest){
// 	if(dest == nil){
// 		return;
// 	}
// 	recursDestruct(dest->left);
// 	recursDestruct(dest->right);
//     delete dest;
// }


// template<class keytype, class valuetype> RBTree<keytype, valuetype>::~RBTree(){
//     recursDestruct(root);
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::insert(keytype k, valuetype v){
//      Tsize++;
//      Node *x = root;
//      Node *y = nil;
// 	 Node *z = new Node;
// 	 z->key = k;
//      z->nsize = 1;
//      while(x != nil){
//          y = x;
//       //   x->nsize++;
//          if(z->key < x->key){
//            x->nsize++;
//              x = x->left;
//         }else{
//             x->nsize++;
//             x = x->right;
//         }
//      }
//      z->p = y;
//      if(y == nil){
//          root = z;
//      }else if(z->key < y->key){
//          y->left = z;
//      }else{
//          y->right = z;
//      }
    
//      z->left = nil;
//      z->right = nil;
//      z->color = 0;
// 	 z->value = v;

//      RBInsertFixup(z);
// }

//  template <typename keytype, typename valuetype>
//  void RBTree<keytype, valuetype>::RBInsertFixup(Node *z){
//       Node *y;
//         while(z->p->color == 0){ 
//         if(z->p == z->p->p->left){
//             y = z->p->p->right;
//             if(y->color == 0){
//                 z->p->color = 1;
// 				y->color = 1;
// 				z->p->p->color = 0;
//                 z=z->p->p;
//              } else{
//              if(z == z->p->right){
//                 z = z->p;
//                 LeftRotate(z);
//             }
//             z->p->color = 1;
//             z->p->p->color = 0;
//             RightRotate(z->p->p);
//         }}else{        
// 		    y = z->p->p->left;
//             if(y->color == 0){
//                 z->p->color = 1;
// 				y->color = 1;
// 				z->p->p->color = 0;
//                 z=z->p->p;
//             }else{
//                 if(z == z->p->left){
//                 z=z->p;
//                 RightRotate(z);
//             }
//             z->p->color = 1;
//             z->p->p->color = 0;
//             LeftRotate(z->p->p);
// 		}
// 	 }
//         }
// 		root->color = 1;
//   }

//  template <typename keytype, typename valuetype>
//  void RBTree<keytype, valuetype>::LeftRotate(Node *x){
// 	   Node *y = x->right;
//        x->right = y->left;
//        if(y->left != nil){
//           y->left->p = x;
//         }
//        y->p = x->p;
//        if(x->p == nil){
//           root = y;
//         }else if(x == x->p->left){
//           x->p->left = y;
//         }else{
//           x->p->right = y;
//         }
//         y->left = x;
//         x->p = y;
//         y->nsize = x->nsize;
//         x->nsize = x->left->nsize + x->right->nsize + 1;
//    }

//  template <typename keytype, typename valuetype>
//  void RBTree<keytype, valuetype>::RightRotate(Node *x){
// 	   Node *y = x->left;
//        x->left = y->right;
//        if(y->right != nil){
//           y->right->p = x;
//         }
//        y->p = x->p;
//        if(x->p == nil){
//           root = y;
//         }else if(x == x->p->right){
//           x->p->right = y;
//         }else{
//           x->p->left = y;
//         }
//         y->right = x;
//         x->p = y;
//         y->nsize = x->nsize;
//         x->nsize = x->right->nsize + x->left->nsize + 1;
//    }

// template <typename keytype, typename valuetype>
// int RBTree<keytype, valuetype>::size(){
// 	return Tsize;
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::recursPreorder(Node *pre){
// 	if(pre == nil){
// 		return;
// 	}
// 	cout << pre->key << " ";
// 	recursPreorder(pre->left);
// 	recursPreorder(pre->right);
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::preorder(){
// 	recursPreorder(root);
// 	cout << endl;
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::recursInorder(Node *In){
// 	if(In == nil){
// 		return;
// 	}
// 	recursInorder(In->left);
//     cout << In->key << " ";
// 	recursInorder(In->right);
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::inorder(){
// 	recursInorder(root);
// 	cout << endl;
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::recursPostorder(Node *post){
// 	if(post == nil){
// 		return;
// 	}
// 	recursInorder(post->left);
// 	recursInorder(post->right);
//     cout << post->key << " ";
// }

// template <typename keytype, typename valuetype>
// void RBTree<keytype, valuetype>::postorder(){
// 	recursPostorder(root);
// 	cout << endl;
// }

// template<class keytype, class valuetype>
// valuetype *RBTree<keytype, valuetype>::search(keytype k){
//     Node *s = root;
//     while( s != nil){
//         if(k < s->key ){
//             s = s->left;
//         }else if(k > s->key){
//             s = s->right;
//         }else{
//             valuetype *v = &s->value;
//             return v;
//         }
//     }
//     return NULL;
// }

// template<class keytype, class valuetype> 
// typename RBTree<keytype, valuetype>::Node *RBTree<keytype, valuetype>::FindNode(keytype k){
//     Node *s = root;
//     while(s != nil){
//         if(k < s->key){
//             //s->nsize--;
//             s = s->left;
//         }else if(k> s->key){
//             //s->nsize--;
//             s = s->right;
//         }else{
//             return s;
//         }
//     }
//     return nil;
// }

// template<class keytype, class valuetype>
//  keytype *RBTree<keytype, valuetype>::predecessor(keytype k){
//     Node *x = FindNode(k);
//      if(x == nil){
//         return NULL;
//     }
//     // if(x->left = nil){
//     //     return NULL;
//     // }
//      if(rank(x->key) -1 <= 0){
//          return NULL;
//      }

//     if(x->left != nil){
//         Node *r = maximum(x->left);
//         keytype *h = &r->key;
//         return h;
//     }

//     Node *y = x->p;
//     while( y != nil && x == y->left){
//         x = y;
//         y = y->p;
//     }

//     // if(x == nil){
//     //     return NULL;
//     // }else{
//     keytype *f = &y->key;
//     return f;
//   //  }
//  }

//  template<class keytype, class valuetype>
//  keytype *RBTree<keytype, valuetype>::successor(keytype k){
//     Node *x = FindNode(k);
//    // cout << x->key << endl;
//     if(x == nil){
//         return NULL;
//     }
//    // int d = rank(x->key);
//    // cout << d;
//   // cout << x->key << endl;
//  //  cout << "Rank :" << rank(x->key) << endl;
//      if(rank(x->key) == Tsize ){
//          return NULL;
//      }
//     //  if(rank(x->key) -1 <= 0){
//     //      return NULL;
//     //  }



//     if(x->right != nil){
//         Node *r = minimum(x->right);
//         keytype *h = &r->key;
//         return h;
//     }

//     Node *y = x->p;
//     while( y != nil && x == y->right){
//         x = y;
//         y = y->p;
//     }
    
//     keytype *f = &y->key;
//     return f;
//  }

//  template<class keytype, class valuetype>
//  typename RBTree<keytype, valuetype>::Node* RBTree<keytype, valuetype>::minimum(RBTree<keytype, valuetype>::Node *n){
//     while(n->left != nil){
//         n = n->left;
//     }
//     return n;
//   }

// template<class keytype, class valuetype>
// typename RBTree<keytype, valuetype>::Node* RBTree<keytype, valuetype>::maximum(RBTree<keytype, valuetype>::Node *n){
//     while(n->right != nil){
//         n = n->right;
//     }
//     return n;
//   }

// template<class keytype, class valuetype> 
// int RBTree<keytype, valuetype>::remove(keytype k){  
//      Tsize--;
//      Node *z = FindNode(k);
//      if( z == nil){
//          return 0;
//      }
//      Node *y;
//      Node *x;

//     // Fixing size to help with rank and select
//      Node *search = root;
//      while(search != nil){
//         search->nsize--;
//         if(search->key > k){
//             search = search->left;
//         }else if(search->key < k){
//             search = search->right;
//          }else if(search->key == k){
//              break;
//          }
//      }

//      y = z;
//      int yog = y->color;
//      if(z->left == nil){
//          x = z->right;
//          RBTransplant(z, z->right);
//      }else if(z->right == nil){
//          x = z->left;
//          RBTransplant(z, z->left);
//       }else{
//          y = maximum(z->left);
//          yog = y->color;
//          x = y->left;
      
//         // x = y; //
//          Node *search = y;
//          while(search != z){
//             search = search->p;
//             search->nsize--;
//         }

//         if(y->p == z){
//             x->p = y;
//          }else{
//              RBTransplant(y, y->left);
//              y->left = z->left;
//              y->left->p = y;
//          }
//          RBTransplant(z,y);

//          y->nsize = z->nsize + 1; 
//          y->right = z->right;
//          y->right->p = y;
//          y->color = z->color;
//    }
//     if(yog == 1){
//         RBDeleteFixup(x);
//     }
    
//      delete z;
//      return 1;
// }

// template<class keytype, class valuetype>
// void RBTree<keytype, valuetype>::RBTransplant(RBTree<keytype, valuetype>::Node *u, RBTree<keytype, valuetype>::Node *v){
//     if(u->p == nil){
//         root = v;
//     }else if(u == u->p->left){
//         u->p->left = v;
//     }else{
//         u->p->right = v;
//     }
//     v->p = u->p;
// }

// template<class keytype, class valuetype>
//  void RBTree<keytype, valuetype>::RBDeleteFixup(RBTree<keytype, valuetype>::Node *x){
//     Node *w;
//     while((x != root) && (x->color == 1)){
//        // cout << x->key << endl;
//         if(x == x->p->left){
//             w = x->p->right;
//             if(w->color == 0){
//                 w->color = 1;
//                 x->p->color = 0;
//                 LeftRotate(x->p);
//                 w = x->p->right;
//             }
//             if((w->left->color == 1) && (w->right->color == 1)){
//                 w->color = 0;
//                 x = x->p;
//             }else{

//                 if(w->right->color == 1){
//                     w->left->color = 1;
//                     w->color = 0;
//                     RightRotate(w);
//                     w = x->p->right;
//                 }
//                 w->color = x->p->color;
//                 x->p->color = 1;
//                 w->right->color = 1;
//                 //cout << "case 4 " << endl;
//                 LeftRotate(x->p);
//                 x = root;
//             }
//         }else{
//              w = x->p->left;
//             if(w->color == 0){
//                 w->color = 1;
//                 x->p->color = 0;
//                 RightRotate(x->p);
//                 w = x->p->left;
//             }
//             if((w->right->color == 1) && (w->left->color == 1)){
//                 w->color = 0;
//                 x = x->p;
//             }else{
//                 if(w->left->color == 1){
//                     w->right->color = 1;
//                     w->color = 0;
//                     LeftRotate(w);
//                     w = x->p->left;
//                 }
//                 w->color = x->p->color;
//                 x->p->color = 1;
//                 w->left->color = 1;
//                // cout << "case 4" << endl;
//                 RightRotate(x->p);
//                 x = root;
//             }
//         }
//     }

//     x->color = 1;
//  }      
 
//  template<class keytype, class valuetype>
//  int RBTree<keytype, valuetype>::rank(keytype k){
//     Node *r = FindNode(k);
//     return recursRank(r);
//  }

//  template<class keytype, class valuetype> 
//  int RBTree<keytype, valuetype>::recursRank(RBTree<keytype, valuetype>::Node *x){
//     int r = x->left->nsize+1 ;
//     Node *y = x;
//     while(y != root){
//         if(y == y->p->right){
//             r = r + y->p->left->nsize + 1;
//         }
//         y = y->p;
//     }
//     return r;
//  }

// template<class keytype, class valuetype>
// keytype RBTree<keytype, valuetype>::select(int pos){
//     Node *r = osselect(root, pos);
//     return r->key;
// }

// template<class keytype, class valuetype>
// typename RBTree<keytype, valuetype>::Node *RBTree<keytype, valuetype>::osselect(RBTree<keytype, valuetype>::Node *x, int i){
//     int r = x->left->nsize + 1;
//     if(i == r){
//         return x;
//     }else if( i < r){
//         return osselect(x->left, i);
//     }else{
//         return osselect(x->right, i-r);
//     }
//  }


#include <iostream>
#include <string>
#include <array>
#include <cmath>
using namespace std;


template <typename keyType, typename valueType>
class RBTree{ // class representing a red-black tree
 
private:
    struct Node{
        keyType key;
        valueType val;
        Node *left;  // left child node
        Node *right; // right child node
        Node *parent;   //parent node
        string color; // color off red or black
        int nodeSize;
    };


     void insertFixup(Node *z){
        Node *y;
        while(z->parent->color == "RED"){
            if(z->parent == z->parent->parent->left){
                y = z->parent->parent->right;

                if(y->color == "RED"){
                    z->parent->color = "BLACK";
                    y->color = "BLACK";
                    z->parent->parent->color = "RED";
                    z = z->parent->parent;
                }
                else{
                    if(z == z->parent->right){
                        z = z->parent;
                        leftRotate(z);
                    }

                    z->parent->color = "BLACK";
                    z->parent->parent->color = "RED";

                    rightRotate(z->parent->parent);
                }
            }
            else{
                y = z->parent->parent->left;

                if(y->color == "RED"){
                    z->parent->color == "BLACK";
                    y->color = "BLACK";
                    z->parent->parent->color = "RED";
                    z = z->parent->parent;
                }
                else{
                    if(z == z->parent->left){
                        z = z->parent;
                        rightRotate(z);
                    }

                    z->parent->color = "BLACK";
                    z->parent->parent->color = "RED";

                    leftRotate(z->parent->parent);
                }
            }
        }

        root->color = "BLACK";
    }

    void leftRotate(Node *x){
        Node *y;
        y = x->right;
        x->right = y->left;

        if(y->left != nil){
            y->left->parent = x;
        }

        y->parent = x->parent;

        if(x->parent == nil){
            root = y;
        }
        else if(x == x->parent->left){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
        y->nodeSize = x->nodeSize;
        x->nodeSize = x->left->nodeSize + x->right->nodeSize + 1;
    }

    void rightRotate(Node *y){
        Node *x;
        x = y->left;
        y->left = x->right;

        if(x->right != nil){
            x->right->parent = y;
        }

        x->parent = y->parent;

        if(y->parent == nil){
            root = x;
        }
        else if(y == y->parent->right){
            y->parent->right = x;
        }
        else{
            y->parent->left = x;
        }

        x->right = y;
        y->parent = x;
        x->nodeSize = y->nodeSize;
        y->nodeSize = y->left->nodeSize + y->right->nodeSize + 1;
    }

    void transplantRB(Node *u, Node *v){
        if(u->parent == nil){
            root = v;
        }
        else if(u == u->parent->left){
            u->parent->left = v;
        }
        else{
            u->parent->right = v;
        }
        v->parent = u->parent;

    }

    void deleteFixupRB(Node *x){
        while((x != root) && (x->color == "BLACK")){
            if(x == x->parent->left){
                Node *w = x->parent->right;

                if(w->color == "RED"){
                    w->color = "BLACK";
                    x->parent->color = "RED";
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if((w->left->color == "BLACK") && (w->right->color == "BLACK")){
                    w->color = "RED";
                    x = x->parent;
                }
                else{
                    if(w->right->color == "BLACK"){
                        w->left->color = "BLACK";
                        w->color = "RED";
                        rightRotate(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = "BLACK";
                    w->right->color = "BLACK";
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else{
              Node *w = x->parent->left;

                if(w->color == "RED"){
                    w->color = "BLACK";
                    x->parent->color = "RED";
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if((w->right->color == "BLACK") && (w->left->color == "BLACK")){
                    w->color = "RED";
                    x = x->parent;
                }
                else{
                    if(w->left->color == "BLACK"){
                        w->right->color = "BLACK";
                        w->color = "RED";
                        leftRotate(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = "BLACK";
                    w->left->color = "BLACK";
                    rightRotate(x->parent);
                    x = root;
                }  
            }
        }
        x->color = "BLACK";
    }

    Node * deleteSearch(keyType k){
        Node *current = root;
        while(current != nil){
            if(current->key < k && current->key != k){
                current = current->right;
                //current->nodeSize--;
            }
            else if(current->key > k && current->key != k){
                current = current->left;
                //current->nodeSize--;
            }
            else{
                Node *found = current;
                while(current != nil){
                    current->parent->nodeSize--;
                    current = current->parent;
                }
                return found;
            }
        }
        
        return nullptr;

    }

    Node * findNode(keyType k){
        Node *current = root;
        while(current != nil){
            if(current->key < k && current->key != k){
                current = current->right;
            }
            else if(current->key > k && current->key != k){
                current = current->left;
            }
            else{
                Node *found = current;
                return found;
            }
        }
        
        return nullptr;

    }

    Node * treeMinimum(Node *x){
        while(x->left != nil){
            x = x->left;
        }
        return x;
    }

    Node * treeMaximum(Node *x){
        while(x->right != nil){
            x = x->right;
        }
        return x;
    }

    void printPreorder(struct Node* node){
        if(node == nil){
            return;
        }

        cout << node->key << " "; // Print value as soon as you touch it 
        printPreorder(node->left); //recursive calls on right and left subtrees
        printPreorder(node->right); 
    }

    void printPostOrder(struct Node* node){
        if(node == nil){
            return;
        }

        printPostOrder(node->left);  // recursive calls on right and left subtrees
        printPostOrder(node->right);
        cout << node->key << " ";       // print the value after its done being visited recursively
    }

    void postOrderDelete(struct Node * node){
        if(node == nil){
            return;
        }
        postOrderDelete(node->left);
        postOrderDelete(node->right);
        delete node;
    }

    void printInOrder(struct Node* node){
        if(node == nil){
            return;
        }

        printInOrder(node->left); // Recurse on smallest possible values left
        cout << node->key << " ";   //Print minimum values from least to greatest
        printInOrder(node->right); // Recurse through the right children after the left and parent have been printed 
    }

    bool arrayPowerOfTwoCheck (int constructCheck){
        if(constructCheck == 0){
            return false;
        }
        else{
           return (constructCheck & (constructCheck -1 )) == 0; 
        }
    }

    Node * sortedArrayToRedBlackTree(keyType k[], valueType v[], int start, int end, int treeHeight, int curDepth, bool powerOfTwo){
        if(start > end){
            return nil;
        }
        
        int mid = (start + end) / 2; 
        Node *left = sortedArrayToRedBlackTree(k, v, start, mid-1, treeHeight, curDepth+1, powerOfTwo);
        Node *right = sortedArrayToRedBlackTree(k, v, mid+1, end, treeHeight, curDepth+1, powerOfTwo);
        Node *root = newNode(k[mid], v[mid], left, right, nil, "BLACK");       

        if(left != nil){
            left->parent = root;
        }
        if(right != nil){
            right->parent = root;
        }
        if((root->right == nil && root->left == nil) && !powerOfTwo && (curDepth == treeHeight)){ 
            root->color = "RED";
        }

        return root;
    }
    
    Node *newNode(keyType k, valueType v, Node *leftChild, Node *rightChild, Node *parentNode, string nodeColor){
        Node *sortedNode = new Node();
        sortedNode->key = k;
        sortedNode->val = v;
        sortedNode->left = leftChild;
        sortedNode->right = rightChild;
        sortedNode->parent = parentNode;
        sortedNode->color = nodeColor;
        sortedNode->nodeSize = 1;

        if(leftChild != nil){
            sortedNode->nodeSize = sortedNode->nodeSize + leftChild->nodeSize;
        }
        if(rightChild != nil){
            sortedNode->nodeSize = sortedNode->nodeSize + rightChild->nodeSize;
        }

        return sortedNode;
    }

   Node* copyConstructorHelper(Node *src, Node *src_nil){
        if(src == src_nil){
            return this->nil;
        }

        Node *treeNext = new Node();
        treeNext->color = src->color;
        treeNext->nodeSize = src->nodeSize;
        treeNext->val = src->val;
        treeNext->key = src->key;
        Node *leftNode = copyConstructorHelper(src->left, src_nil);
        leftNode->parent = treeNext;
        treeNext->left = leftNode;
        Node *rightNode = copyConstructorHelper(src->right, src_nil);
        rightNode->parent = treeNext;
        treeNext->right = rightNode;

        return treeNext;
   }


public:
    
    Node *root; // root of the tree
    Node *nil; // null pointers th the end of the tree/childless nodes
    int treeSize;

    //Default Constructor. The tree should be empty
    RBTree(){
        treeSize = 0;
        nil = new Node();
        nil->color = "BLACK";
        nil->left = nil;
        nil->right = nil;
        nil->parent = nil;
        nil->nodeSize = 0;
        root = nil;
    }

 
    //Copy Constructor for the Red Black tree. For cases where in main T2 = T1 or anything like that. The copy assignment operator also takes part in that
    RBTree(const RBTree& src){
        this->treeSize = src.treeSize;
        nil = new Node();
        nil->color = "BLACK";
        root = copyConstructorHelper(src.root, src.nil);
        root->parent = nil;
    }

    //Copy Assignment Operator
    RBTree& operator=(const RBTree* src ){
        if(this != src){
            this->~RBTree();
            this->treeSize = src.treeSize;
            nil = newNode(nullptr, nullptr, nil, nil, nil, "BLACK");
            //nil->color = "BLACK";
            root = copyConstructorHelper(src.root, src.nil);
            root->parent = nil;
        }
        return *this;
    }
 

    /* For this constructor the tree should be built using the arrays K and V containing s items of keytype and valuetype. If the keytype array 
    is order then the tree should be built in O(s) time as described later. If the items are not in order, the tree should be built using 
    repeated insertion */
    RBTree(keyType k[], valueType v[], int s){
        treeSize = s;
        nil = new Node;
        nil->color = "BLACK";
        nil->left = nil;
        nil->right = nil;
        nil->parent = nil;
        nil->nodeSize=0;
        root = nil;

        if(s == 0){
            root = nil; 
            return;
        }
        if(s == 1){
            keyType key = keyType(k[0]);
            valueType val = valueType(v[0]);
            root = newNode(key, val, nil, nil, nil, "BLACK");
            return;
        }
        
        bool isArraySorted = true;
        for(int i = 0; i < s-1; i++){
            if(k[i] > k[i+1]){
                isArraySorted = false;
                break;
            }
        }


        if(isArraySorted){
            bool powerOfTwo = arrayPowerOfTwoCheck(s+1); // If its true color all nodes black, if false then the bottom nodes will be red
            int treeHeight = floor(log2(s)); //the log of the passed in size but rounds down to the lower value like shown in class;
            int curDepth = 0;
            root = sortedArrayToRedBlackTree(k, v, 0, s-1, treeHeight, curDepth, powerOfTwo);
        }
        else{
            treeSize = 0;
            root = nil;
            for(int i = 0; i < s; i++){
                insert(k[i], v[i]);
            }
        }
        
    }
    

    //Destructor for the class.
    ~RBTree(){
        Node *current = root;
        postOrderDelete(current);
        //delete current;
    }
  


    //code a copy constructor and a copy assignment operator

   /* Traditional search. Should return a pointer to the valuetype stored with the key. If the key 
    is not stored in the tree then the function 
    should return NULL. */
    valueType * search(keyType k){
        Node *current = root;
        while(current != nil){
            if(current->key < k && current->key != k){
                current = current->right;
            }
            else if(current->key > k && current->key != k){
                current = current->left;
            }
            else{
                valueType *v = &current->val;
                return v;
            }
        }
        
        return nullptr;

    }

    //Inserts the node with key k and value v into the tree
    void insert(keyType k, valueType v){
        Node *x;
        Node *y;
        Node *z = new Node;
        z->key = k;
        z->val = v;
        z->nodeSize = 1;
        y = nil;
        x = root;
        treeSize++;

        while(x!=nil){
            x->nodeSize = x->nodeSize + 1;
            y = x;
            if(z->key < x->key){
                x = x->left;
                //z->nodeSize = z->nodeSize + 1;
            }
            else{
                x = x->right;
                //z->nodeSize = z->nodeSize + 1;
            }
        }
        z->parent = y;

        if(y==nil){
            root = z;
        }
        else if(z->key < y->key){
            y->left = z;
        }
        else{
            y->right = z;
        }

        z->left = nil;
        z->right = nil;
        z->color = "RED";
        //cout << "fixing node" << endl;
        insertFixup(z);
        //cout << "inserted" << endl;
    }

   /* Removes the node with key k and returns 1. If key k is not found then remove should return 0. If the node with key k is not a leaf 
    then replace k by its predecessor */
 
    int remove(keyType k){
        Node *y;
        Node *x;
        Node *z;
        z = deleteSearch(k);
        if(z==nullptr){
            //cout << "Could not find node" << endl;
            return 0;
        }
        y = z;
       string y_original_color = y->color;

        if(z->left == nil){
            x = z->right;
            transplantRB(z, z->right);
        }
        else if(z->right == nil){
            x = z->left;
            transplantRB(z, z->left);
        }
        else{
            y = treeMaximum(z->left);
          
            Node *updateSizes = y->parent;
            while(updateSizes != z){
                //updateSizes->nodeSize--;
                updateSizes = updateSizes->parent;
            }
          
            

            y_original_color = y->color;
            x = y->left;

            if(y->parent == z){
                x->parent = y;
            }
            else{
                transplantRB(y, y->left);
                y->left = z->left;
                y->left->parent = y;
            }

            transplantRB(z, y);
            y->right = z->right;
            y->right->parent = y;
            y->color = z->color;
            y->nodeSize = y->left->nodeSize + y->right->nodeSize + 1;
        }



        if(y_original_color == "BLACK"){
            deleteFixupRB(x);
        }
        

        treeSize--;
        return 1;
    }

    //Returns the rank of the key k in the tree. Returns 0 if the key k is not found. The smallest item in the tree is rank 1.
    int rank(keyType k){
        Node *x;
        Node *y;
        x = findNode(k);
        if(x == nil){
            return 0;
        }
        int r = x->left->nodeSize + 1;
        y = x;
        while(y != root){
            if(y == y->parent->right){
                r = r + y->parent->left->nodeSize + 1;
            }

            y = y->parent;
        }
        return r;
    }
 
 /**/
    /* Order Statistics. Returns the key of the node at position pos in the tree. Calling with pos = 1 should return the smallest key in the tree, 
    pos = n should return the largest. */
 
    keyType select(int pos){
        Node *x;                                    
        x = root;
        int r = x->left->nodeSize + 1;
        while(pos != r){
            if(pos < r){
                x = x->left;
                r = x->left->nodeSize + 1;
            }
            else if(pos > r){
                x = x->right;
                pos = pos-r;
                r = x->left->nodeSize + 1;
            }
        } 

        return x->key;

    }
   
    //Returns a pointer to the key after k in the tree. Should return NULL if no successor exists.
    keyType *successor(keyType k){
        int r = rank(k);
        r = r + 1;
        if(r == 1 || r > treeSize){
            return nullptr;
        }

        keyType sucKey = select(r);
        return new keyType(sucKey);

       /* Node *pred = findNode(k);
        if(pred->right != nil){
            pred = pred->right;
            while(pred->left != nil){
                pred = pred->left;
            }
            keyType *preKey = &pred->key;
            return preKey;
        }
        else if(pred->parent){

        }
        else{
            cout << "No successor Exists" << endl;
            return nullptr;
        }
        */
    }

    //Returns a pointer to the key before k in the tree. Should return NULL if no predecessor exists.
    keyType *predecessor(keyType k){
       // Node *pred = findNode(k);
        int r = rank(k);
        r = r - 1;

        if(r <= 0){
            return nullptr;
        }

        keyType preKey = select(r);

        return new keyType(preKey);
     /*
        if(pred->left != nil){
            pred = pred->left;
            while(pred->right != nil){
                pred = pred->right;
            }
            keyType *preKey = &pred->key;
            return preKey;
        }
        else if(pred->parent != nil){
            while((pred!=nil) && (pred != pred->parent->right)){
                pred = pred->parent;
            }

            keyType *preKey = &pred->parent->key;
            return preKey;
        }
        else{
            cout << "No Predecessor Exists" << endl;
            return nullptr;
        }
     */
            
    }

    //Prints the keys of the tree in a preorder traversal. The list of keys are separated by a single space and terminated with a newline
    void preorder(){
        Node *current = root;
        printPreorder(current);
        cout << endl;
    }

    //Prints the keys of the tree in an inorder traversal. The list of keys are separated by a single space and terminated with a newline.
    void inorder(){
       Node *current = root;
       printInOrder(current);
       cout << endl;
        
    }

    //Prints the keys of the tree in a postorder traversal. The list of keys are separated by a single space and terminated with a newline.
    void postorder(){
        Node *current = root;
        printPostOrder(current);
        cout << endl;
    }
    
    //returns the number of nodes in the tree.
    int size(){
        return treeSize;
    }
};