#ifndef BOOKITEM_HPP
#define BOOKITEM_HPP
#include <iostream>
#include"XStack.hpp"
#include <string>
using namespace std;

class BookItem
{
    int serialNum;
    string title;
    string author;
    int yearPublished;
    int copiesSold;
public:
    BookItem(int serialNum=0, string title="", string ath="", int year=0, int copiesSold=0)
    : serialNum(serialNum), title(title), author(ath), yearPublished(year), copiesSold(copiesSold) { }

    void  bookSerch (XStack <BookItem>* b, int serialToSearch)
    {
        BookItem t;     // temp element

        if (b->isEmpty()) return ;
        b->peek(t);
             if (t.serialNum== serialToSearch)
            {
                cout<< " \n" << t << endl;
            }
    else{

         XStack<BookItem>* temp = new XStack<BookItem>();
            while (t.serialNum != serialToSearch  && !b->isEmpty())
                {
                    b->pop(t);
                    temp->push(t);
                    b->peek(t);
                }
        if (b->isEmpty())
            cout << "\nThe Serial Number is not in the List!" << endl;
        else
            cout<< " \n" << t << endl;
            while (!temp->isEmpty())
                {
                    temp->pop(t);
                    b->push(t);
                }
            delete temp;
    }

}

    bool top5Seller(XStack <BookItem>*&b1)
    {
    BookItem temp1,temp2;
        XStack<BookItem>* b2 = new XStack<BookItem>();
        while(!b1->isEmpty())
        {

            b1->pop(temp1);
            b2->peek(temp2);
            while(!b2->isEmpty()&& temp2 > temp1 )
            {
                b2->pop(temp2);
                b1->push(temp2);
            }
            b2->push(temp1);
        }
        for (int i = 1; i < 6; i++)
                  {
                        b2->peek(temp2);
                        cout << temp2 << endl;
                        b2->pop(temp2);
                        b1->push(temp2);
                  }

          while(!b2->isEmpty())
            {
                b2->pop(temp1);
                b1->push(temp1);
            }
        delete b2;
    }

    bool bottom5Seller(XStack <BookItem>*&b1)
    {
     BookItem temp1,temp2;
        XStack<BookItem>* b2 = new XStack<BookItem>();
        while(!b1->isEmpty())
        {

            b1->pop(temp1);
            b2->peek(temp2);
            while(!b2->isEmpty()&& temp2 < temp1 )
            {
                b2->pop(temp2);
                b1->push(temp2);
            }
            b2->push(temp1);
        }
    for (int i = 1; i < 6; i++)
                  {
                       b2->peek(temp2);
                       cout << temp2 << endl;
                        b2->pop(temp2);
                        b1->push(temp2);
                  }
          while(!b2->isEmpty())
            {
                b2->pop(temp1);
                b1->push(temp1);
            }
        delete b2;
    }

    bool top10NewestBook(XStack <BookItem>*&b1)
    {
    BookItem temp1,temp2;
        XStack<BookItem>* b2 = new XStack<BookItem>();
        while(!b1->isEmpty())
        {

            b1->pop(temp1);
            b2->peek(temp2);


            while(!b2->isEmpty()&& (temp2.yearPublished > temp1.yearPublished ))
            {

                b2->pop(temp2);
                b1->push(temp2);

            }
         b2->push(temp1);
        }

            for (int i = 1; i < 11; i++)
              {
                   b2->peek(temp2);
                   cout << temp2 << endl;
                    b2->pop(temp2);
                    b1->push(temp2);
              }

            while(!b2->isEmpty())
            {
                b2->pop(temp1);
                b1->push(temp1);
            }
        delete b2;
    }

    friend std::ostream& operator<<(std::ostream& os, const BookItem& s)
    {
        os << "<" << s.serialNum << "> " << s.title << " : "
           << s.author << " (" << s.yearPublished << ") - "
           << s.copiesSold << " copies sold";
        return os;
    }

    friend bool operator< (BookItem& b1, BookItem& b2)
    {
        return b1.copiesSold < b2.copiesSold;
    }

    friend bool operator> (BookItem& b1, BookItem& b2)
    {
        return b1.copiesSold > b2.copiesSold;
    }
};



#endif // BOOKITEM_HPP

