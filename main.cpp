#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;

class ConsoleSet: public Set
{
    public:
        void output(Set &tr,int n) const;
};


int main()
{
    int w=0,n;
    cout<<"Input a size of set: ";
    cin>>n;
    Set tr(n);
    Set tr2(n);
    ConsoleSet A;
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
            if(tr.check(data)!=false)
                cout<<"value already in set"<<endl;
            else
                tr.push(data);
            break;
        case 2:
            {
            if(tr.is_empty()==true)
                cout<<"First set empty";
            else
            {
                cout<<"Set 1:"<<endl;
                A.output(tr,n);
            }
            cout<<endl<<endl;
            if(tr2.is_empty()==true)
                cout<<"Second set empty";
            else
            {
                cout<<"Set 2:"<<endl;
                A.output(tr2,n);
            }
            cout<<endl<<endl;
            break;
        }
        case 3:
        {
            if(tr.is_empty()==true)
                cout<<"Tree empty";
            else
            {
                int key;
                cout<<"enter value to check: ";
                cin>>key;
                if((tr.check(key))!=false)
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
            tr3=tr+tr2;
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
            tr3=tr-tr2;
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


void ConsoleSet::output(Set &tr, int n) const
{
    int l=0,i=0;
            tr.nextDatum(false, false, true, l);
            cout<<"l1 = "<<l<<endl;
            i++;
            while(i<n/2)
            {
                tr.nextDatum(false, false, false, l);
                cout<<"l1 = "<<l<<endl;
                i++;
            }
            i=0;
            tr.nextDatum(true,true, false, l);
            cout<<"l = "<<l<<endl;
            while(i<n/2)
            {
                tr.nextDatum(false, true, false, l);
                i++;
                cout<<"l2 = "<<l<<endl;
            }
}
