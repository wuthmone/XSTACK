#ifndef XSTACK_HPP
#define XSTACK_HPP
#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T info;
    Node<T>* next;
};

template <typename T>
class XStack {
 public:
     XStack () ;
     ~XStack ();
     void push(T &element);
     bool pop( T & element );
     bool peek ( T & element );
     bool duplicate ();
     bool swapTop();
     bool roll(int n);
     bool isEmpty( );
     void makeEmpty( );
         friend ostream& operator<< (ostream& os, XStack<T>& s)
    {

    if (s.isEmpty())
      os << "Empty ";
	else {
      os << "Top -> ";
	  Node<T> *ptr = s.top;
	  while (ptr != NULL) {
	    os << ptr->info << " -> ";
		ptr = ptr->next;
	  }
	  os << "NULL";
	}
    return os;
    }

private:
    Node<T>* top;
};
#endif // XSTACK


