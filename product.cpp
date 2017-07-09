#include "product.h"
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
using namespace std;
product::product()
{
     siz=3+20+4+4+3;
     num=0;
     names.push_back("ahmed");
     names.push_back("mai");
     names.push_back("omer");
}

product::~product()
{
    //dtor
}
void product::write_in_file(product_specification i){
    fstream file;
    file.open("product.txt",ios::in|ios::out);
    file.seekg(num*siz,ios::beg);
    num++;
    file.write((char*)&i,sizeof(i));
    file.close();
}
bool product::create_new_product(){
    product_specification k;
    int q=0;
   while(true){
    cout<<"\n\n\tPlease Enter The Product No. of The Product ";
    cin>>k.product_no;
    string h(k.product_no);
    if(h=="-1"){cout<<"\n\n\tPlease try again , you can't make product number = -1  ";}else{break;}
    q++;
    if(q==4){cout<<"\n\n\t error try again  \n";return 0;}
   }
    cout<<"\n\tPlease Enter The Name of The Product ";
    cin>>k.product_name;
    cout<<"\n\tPlease Enter The Price of The Product ";
    cin>>k.price;
    cout<<"\n\tPlease Enter The Discount (%) ";
    cin>>k.discount;
    cout<<"\n\tPlease Enter The quantity (%) ";
    cin>>k.qty;
    write_in_file(k);
}
bool product::modify_product(){
    int n;
    cout<<"\n                Please Enter The Product No. of The Product ";
    cin>>n;
    system("cLs");
    fstream file;bool b=0;int ofest=-1;
    file.open("product.txt",ios::in|ios::out);
    product_specification q;
    for(int i=0;i<num;i++){
            file.seekg(i*siz,ios::beg);
            file.read((char*)&q,sizeof(q));
            string nu(q.product_no);
            int numberofproduct=atoll(nu.c_str());
            if(numberofproduct==n){
                b=1;ofest=i*siz;break;
            }

    }
    if(b){
        cout<<"\n\n \tThe Name of The Product ";
        cin>>q.product_name;
        cout<<"\n \tThe Price of The Product ";
        cin>>q.price;
        cout<<"\n \tThe Discount (%) ";
        cin>>q.discount;
        cout<<"\n \tThe quantity (%) ";
        cin>>q.qty;
        file.seekg(ofest,ios::beg);
        file.write((char*)&q,sizeof(q));
   }else{cout<<"not found "<<endl;}
   file.close();


}
bool product::check(string n){
    for(int i=0;i<names.size();i++){
        if(names[i]==n){return true;}
    }
    return false;


}
void product::delete_product(){
    int n;
    cout<<"\n                Please Enter The Product No. of The Product ";
    cin>>n;
    system("cLs");
    fstream file;bool b=0;int ofest=-1;
    file.open("product.txt",ios::in|ios::out);
    product_specification q;
    for(int i=0;i<num;i++){
            file.seekg(i*siz,ios::beg);
            file.read((char*)&q,sizeof(q));
            string nu(q.product_no);
            int numberofproduct=atoll(nu.c_str());
            if(numberofproduct==n){
                b=1;ofest=i*siz;break;
            }

    }
    if(b){
        cout<<"\n\n\t done , delete it "<<endl;
        file.seekg(ofest,ios::beg);
        string h="-1";
        strcpy(q.product_name,h.c_str());strcpy(q.product_no,h.c_str());strcpy(q.price,h.c_str());
        file.write((char*)&q,sizeof(q));
   }else{cout<<"not found "<<endl;}
   file.close();

}
void product::display_all_product(){
    fstream file;bool b=0;int ofest=-1;
    file.open("product.txt",ios::in|ios::out);
    for(int i=0;i<num;i++){
            product_specification q;
            file.seekg(i*siz,ios::beg);
            file.read((char*)&q,sizeof(q));
            string h(q.product_no);
            if(h=="-1"){continue ;}
            cout<<"\n The Product No. of The Product ";
            cout<<q.product_no;
            cout<<"\n The Name of The Product ";
            cout<<q.product_name;
            cout<<"\n The Price of The Product ";
            cout<<q.price;
            cout<<"\n The Discount (%) ";
            cout<<q.discount;
            cout<<"\n The quantity (%) ";
            cout<<q.qty<<endl;;

    }
    cout<<"\n";
    file.close();
 }
 void product::add_Administrator(){
    while(true){
        string name;
        cout<<"\n \n \t  enter name of new Administrator ";
        cin>>name;
        names.push_back(name);
        cout<<"\n \n \t  will enter anthor one enter 1 ";
        char r;
        cin>>r;
        system("cLs");
        if(r!='1'){
            break;
        }
    }
}
void product::display_all_admins(){
    for(int i=0;i<names.size();i++){
        cout<<"\n \n \t  "<<i+1<<" - "<<names[i]<<endl;
    }
}
void product::create_bill(){
    vector<product_specification>v;
    int num_of_products=0;
    int cost=0;
    fstream file;
    file.open("product.txt",ios::in|ios::out);
    while(true){
        bool fag=0;
        int n;
        cout<<"\n\n\t enter product no " ;
        cin>>n;
        int z;
        if(n==0||n==-1){break;}
        else{

            cout<<"\n\n\t enter quantity you need";
            cin>>z;
            system("cLs");
        }
        for(int i=0;i<num;i++){
            product_specification q;
            file.seekg(i*siz,ios::beg);
            file.read((char*)&q,sizeof(q));
            string nu(q.product_no);
            int numberofproduct=atoll(nu.c_str());
            if(numberofproduct==n){
                string quan(q.qty);
                int quantity=atoll(quan.c_str());
                if(quantity<z){cout<<"\n\n\t sorry the quanitiy not enogh "<<endl; break;}
                string price(q.price);
                num_of_products++;
                int price_prod=atoll(price.c_str());
                string discount(q.discount);
                int discount1=atoll(discount.c_str());
                int newprice=price_prod*z;
                if(discount1==0){discount1=100;}
                else{
                    cout<<"\n\n\t note this product has discount "<<discount1<<"%"<<endl;
                }
                cost+=(price_prod*discount1/100);
                int x=quantity-z;
                string newquantity;
                ostringstream convert;
                convert << x;
               newquantity = convert.str();
                strcpy(q.qty,newquantity.c_str());
                file.seekg(i*siz,ios::beg);
                 file.write((char*)&q,sizeof(q));
                v.push_back(q);
                fag=1;
                break;
            }
        }
        if(fag==0){cout<<"\n\n\t this product not found"<<endl;}
    }
    file.close();
    system("cLs");
    cout<<"final cost = "<<cost<<endl;
    cout<<"number of products = "<<num_of_products<<endl;
    cout<<"products and its cost "<<endl;
    cout<<"====================================================\n";
	cout<<"\tproduct_name.      product_cost           product_num\n";
	cout<<"\t====================================================\n";

    cout<<"                 "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<"\n\t"<<v[i].product_name<<"                       "<<v[i].price<<"                         "<<v[i].product_no<<endl;
    }


 }
