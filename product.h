#ifndef PRODUCT_H
#define PRODUCT_H
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
/*
product no, product name, price, qty, tax, discount.
*/
//sort in binary file
struct product_specification{
    char product_no[3];
    char product_name[20];
    char price[4];
    char qty[4];
    char discount[3];

};
class product
{
    public:
        product();
        virtual ~product();
        void  customer();
        void Administrator();
        bool create_new_product();
        void write_in_file(product_specification i);
        bool modify_product();
        void delete_product();/////?????
        void display_all_product();
        void create_bill();
        void add_Administrator();
       void display_all_admins();
       bool check(string n);
        vector<string >names;
    protected:
        int siz;
        int num;


};

#endif // PRODUCT_H
