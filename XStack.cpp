#include "XStack.hpp"
#include "BookItem.hpp"
#include<string>
using namespace std;

template <typename T>
 XStack<T> :: XStack () {top = NULL;}
template <typename T>
 XStack<T> :: ~XStack () { makeEmpty();}
template <typename T>
void XStack<T> :: push(T &element)
     {
             Node<T>* ptr = new Node<T>;
                ptr->info = element;
                ptr->next = top;
                top = ptr;
     }

template <typename T>
 bool XStack<T> ::pop( T & element )
     {
          if (isEmpty()) return false;
            element = top->info;
            Node<T>* ptr = top;
            top = top->next;
            delete ptr;
            return true;

     }

template <typename T>
bool XStack<T> ::peek ( T & element )
     {
         if (isEmpty()) return false;
        element = top->info;
        return true;
     }

template <typename T>
bool XStack<T> :: duplicate ()
{
    if (isEmpty()) {
        cout << "Cannot be duplicated!" << endl;
        return false;}
    Node<T>* ptr = new Node<T>;
    ptr->info = top->info ;
    ptr->next = top;
    top = ptr;
    return true;
}

template <typename T>
bool XStack<T> :: swapTop()
{
    if (isEmpty())
    {cout << "Cannot be swapped !" << endl;
     return false;}
    T temp;
    temp = top->info;
    top->info = top->next->info;
    top->next->info = temp;
    return true;

}

template <typename T>
bool XStack<T> :: roll(int n)
{
  T element;
  Node<T>* ptr1 = top;
  for (int i = 1 ; i <= n   ; i++)
  {
      ptr1 = ptr1->next;
  }
    pop(element);
    Node<T>* ptr2 = new Node<T>;
    ptr2->info = element;
    ptr2->next = ptr1->next;
    ptr1->next = ptr2;
}

template <typename T>
bool XStack<T> :: isEmpty( )
     {
          return top == NULL;
     }

template <typename T>
void  XStack<T> :: makeEmpty( )
     {
         T temp;
        while (pop(temp));
     }


template class XStack<int>;
template class XStack<string>;
template class XStack<double>;
template class  XStack <BookItem>;



