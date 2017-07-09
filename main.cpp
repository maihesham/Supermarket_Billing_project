#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include<cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "product.h"
#include<windows.h>
using namespace std;

int main()
{
    product p;
    while(true){
            cout<<"\t                   -------------------------"<<endl;
            cout<<"\t                     need to exti enter 0  "<<endl;
            cout<<"\t                   -------------------------";
            char x;
            cin>>x;
            if(x=='0'){ cout<<"\n\t\t\t thank you for used our app"<<endl;return 0;}
            cout<<"\t                    welcome "<<endl;
            cout<<"  if you are Administrator enter 1 \t if you are customer enter 2  ";
            char r;
            cin>>r;
            if(r=='1'){
               cout<<"               enter your name (lower case char )";
               string name;
               cin>>name;
               if(p.check(name)){
                   cout<<"  \n                      pass    "<<endl;
                Sleep(1000);
                system("cLs");
                   cout<<"\n\n\t1- add new admin "<<endl;
                   cout<<"\n\n\t2- display all  admins "<<endl;
                   cout<<"\n\n\t3- create product"<<endl;;
                   cout<<"\n\n\t4- modify product"<<endl;;
                   cout<<"\n\n\t5- delete product"<<endl;;
                   cout<<"\t";
                   char r;
                   cin>>r;
                system("cLs");
                  if(r=='1'){p.add_Administrator();}
                  else if(r=='2'){p.display_all_admins();
                  }else if(r=='3'){p.create_new_product();
                  }else if(r=='4'){p.modify_product();
                  }else if(r=='5'){p.delete_product();}
            }else{

                    cout<<"\n\n\t your name not found try again "<<endl;
            }
    }else if(r=='2'){
        cout<<"\n\n\t6.Display all products";
        cout<<"\n\n\t7.create bill";
        cout<<"\n\n\t";
        char r;
        cin>>r;
        system("cLs");
        if(r=='6'){
            p.display_all_product();
        }else if(r=='7'){
            p.create_bill();
        }
    }else{cout<<"error"<<endl;}

    }


    return 0;
}
