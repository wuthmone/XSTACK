#ifndef MAIN_CPP
#define MAIN_CPP
#include <fstream>
#include <iostream>
#include <string>
#include "XStack.hpp"
#include "XStack.cpp"
#include <cstdlib>
#include<stack>
#include "BookItem.hpp"
#include "BookItem.cpp"
using namespace std;

/* DO NOT MODIFY THIS FUNCTION IF YOU ARE NOT FAMILIAR! */
void readData(const char* filename,XStack <BookItem>*&stBooks) {
    string line;
    ifstream ifs(filename);
    if (ifs.is_open()) {
        cout << "Reading data...\n";
        int c = 0;
        while ( getline (ifs,line) && (*line.c_str() != '\0') )  {
            string delimiter = ",";
            size_t pos = 0;
            string* token = new string[5];
            int f = -1;
            while ((pos = line.find(delimiter)) != string::npos) {
                token[++f] = line.substr(0, pos);
                cout << " " << token[f] << " | " ;
                line.erase(0, pos + delimiter.length());
            }
            token[++f] = line;
            cout << token[f] << endl;       // last item in string
            c++;

            // push to stack (numerical data converted to int)
            BookItem b(atoi(token[0].c_str()), token[1], token[2], atoi(token[3].c_str()), atoi(token[4].c_str()));
            stBooks->push(b);
        }
        cout << c << " row(s) read." << endl;
        ifs.close();
    }
    else
        cout << "Unable to open file";
}
/* ************************************************ */


int main()
{ int choice;
    do{
         system("cls");
    cout << "************************            Welcome             ************************\n" << endl;

    cout << "                           1. To test the XStack   " << endl;
    cout << "                           2. To test the BookItem \n" << endl;
    cout << "********************************************************************************\n" << endl;
    int test;
    int select;
    cin >> test ;
    cout << endl;
    if(test == 1)
    {
         XStack<string> s;
         string z;
         cout << "\nEnter the Total no. of Data to enter: ";
         int total;
         cin>> total;
         cin.ignore(256,'\n');
         cout << endl;
         int i;
         for ( i = 1; i <= total ; i++)
         {
             cout <<" Please enter Data: " ;
             getline(cin,z);
             s.push(z);
         }
do
{
         cout << "\n1. To swap the top" << endl;
         cout << "2. To Duplicate the top" << endl;
         cout << "3. To Roll" << endl;
         cout << "4.Exit"<< endl;

         cin >> select;
         switch(select)
         {
         case 1:

            if (total <= 1)
            {
                cout << "Cant not be Swapped!" << endl;
            }
            else
            {
               cout << "\nOriginal Stack:\n" << endl;
                cout << s << endl;
                s.swapTop();
                cout << "\nStack After Swapping the top:\n" << endl;
                cout << s << endl;
            }

            break;
         case 2:
            cout << "\nOriginal Stack:\n" << endl;
            cout << s << endl;
            cout << "\nStack After Duplicating the top:\n" << endl;
            s.duplicate();
            cout << s << endl;
            total = total +1;
            break;
         case 3:

            int r;
            cout << "Please enter no. to be rolled:";
            cin >> r;
            if (r >= total ||total <= 1 )
            cout << "\nCan't be rolled!\n";
       else
       {
            cout << "\nOriginal Stack:\n" << endl;
            cout << s << endl;
            s.roll(r);
            cout << "\nStack After Rolling:\n" << endl;
            cout << s << endl;
       }

            break;
         default:
            cout << "wrong selection!" << endl;
         }

}while (select < 4);

    }

    else if(test == 2)
    {

             // You are to replace the STL Stack with XStack that you have created
           XStack <BookItem>* stBooks = new  XStack<BookItem>();

            // read database from text file, and store in the stack
            readData("db_big.txt", stBooks);

            BookItem item1,item2;
            int select;

            do
            {
                cout << endl;
            cout <<"\n\nSelect\n" << endl;
            cout <<"1.To Search Book" <<endl;
            cout <<"2.For Top 5 best sellers Books" <<endl;
            cout <<"3.For Bottom 5 worst sellers Books" <<endl;
            cout <<"4.For 10 newest books" <<endl;
            cout <<"5.EXIT" << endl;
            cin>> select;
            switch(select)
            {
            case 1:
                int serialNum;
                cout << "Enter the serialNum from the list: ";
                cin>> serialNum;
                item1.bookSerch(stBooks,serialNum);
                break;
            case 2:
                cout<< "\n\nList of Top 5 Best Seller Books:\n" << endl;
                item1.top5Seller(stBooks);

                break;
            case 3:
                cout<< "\n\nList of Bottom 5 Worst Seller Books:\n" << endl;
                item1.bottom5Seller(stBooks);
                break;
            case 4:
                 cout<< "\n\nList of Top 10  Newest Books:\n" << endl;
                item1.top10NewestBook(stBooks);
                break;

             }
    } while (select < 5);
}
    else
    cout << "Wrong selection!" << endl;
    cout << "\n\nIf you selected wrong number\nPress 1\nTo EXIT 0\n" << endl;
    cin >> choice;
}while (choice == 1);

}

#endif

