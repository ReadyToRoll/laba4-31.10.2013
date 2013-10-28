#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;

int main()
{
    int w=0,n;
    cout<<"Input a size of set: ";
    cin>>n;
    Set tr(n);
    Set tr2(n);
    do
    {
        cout<<"select the required operation:"<<endl;
        cout<<" 1 - push element to set"<<endl;
        cout<<" 2 - show set"<<endl;
        cout<<" 3 - is in set"<<endl;
        cout<<" 4 - union"<<endl;
        cout<<" 5 - difference"<<endl;
        cout<<" 6 - intersection"<<endl;
        cout<<" 7 - exit"<<endl<<endl;
        cin>>w;
        switch(w)
        {
        case 1:
            int data;
            cout<<"Enter value ";
            cin>>data;
            if(tr.check(data)!=0)
                cout<<"value already in set"<<endl;
            else
                tr.push(data);
            break;
        case 2:
            if(tr.is_empty()==true)
                cout<<"First set empty";
            else
            {
                cout<<"Set 1:"<<endl;
                tr.show();
            }
            cout<<endl<<endl;
            if(tr2.is_empty()==true)
                cout<<"Second set empty";
            else
            {
                cout<<"Set 2:"<<endl;
                tr2.show();
            }
            cout<<endl<<endl;
            break;
        case 3:
        {
            if(tr.is_empty()==true)
                cout<<"Tree empty";
            else
            {
                node *u;
                int key;
                cout<<"enter value to check: ";
                cin>>key;
                if((u=tr.check(key))!=0)
                {
                    cout<<"Founded"<<endl<<endl;
                }
                else cout<<"Nothing";
            }
            break;
        }
        case 4:
        {
            cout<<"Set 1:"<<endl;
            tr.show();
            cout<<endl<<"Set 2:"<<endl;
            tr2.show();
            cout<<endl;
            Set tr3;
            //&tr3=tr+tr2;
            tr3.show();
            break;
        }
        case 5:
        {
            cout<<"Set 1:"<<endl;
            tr.show();
            cout<<endl<<"Set 2:"<<endl;
            tr2.show();
            cout<<endl;
            Set tr3;
          //  &tr3=tr-tr2;
            tr3.show();
            break;
        }
        case 6:
        {
            cout<<"Set 1:"<<endl;
            tr.show();
            cout<<endl<<"Set 2:"<<endl;
            tr2.show();
            cout<<endl;
            Set tr3;
            tr3=tr*tr2;
            tr3.show();
            break;
        }
        case 7:
            break;
        }
    }
    while(w!=7);
}
