#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name,DOC;
    Person(string n,string m)
    {
        name=n;
        DOC=m;
    }
    void show_Person()
    {
        cout<<name<<endl;
    }
};
class Customer : public Person
{
public:
    string customer_id,sex;
    int catagory;   /** 1 for kids ; 2 for male ; 3 for female **/
    Customer(string m,string n,string k,string l,int y) : Person(n,m)
    {
        customer_id=k;
        sex=l;
        catagory=y;
    }
    void show_Customer()
    {
        if(catagory == 1)
            cout<<"Hey champ , ";
        else if(catagory == 2)
            cout<<"Hello sir , ";
        else if(catagory == 3)
            cout<<"Hello mem , ";
        cout<<"Customer ID : "<<customer_id<<endl;
    }
};

class Product;

class SuperShop
{
public:
    string product_Name,product_Catagory;
    int quantity;
    void getInfo(string n,string y,int m)
    {
        product_Name=n;
        product_Catagory=y;
        quantity=m;
    }
    friend bool Process(SuperShop,Product);
};

class Product : SuperShop
{
public:
    double price;
    void getData(string n,string y,int m,double k)
    {
        getInfo(n,y,m);
        price=k;
    }
    friend bool Process(SuperShop,Product);
};

bool Process(SuperShop s,Product p)
{
    if(s.product_Catagory==p.product_Catagory && s.product_Name==p.product_Name && s.quantity<=p.quantity)
    {
        cout<<"Total Cost: "<<s.quantity*p.price<<endl;
        cout<<"Thank You for shopping with us.\n";
        cout<<"Your shopping is successfully done! Thank You.\n\n";
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Product obj[5];
    obj[0].getData("Body Spray","Cosmetics",5,550.00);
    obj[1].getData("T-Shirt","Garments",5,1185.75);
    obj[2].getData("Pen","Stationary",5,15.50);
    obj[3].getData("Body Lotion","Cosmetics",5,395.00);
    obj[4].getData("Hijab","Garments",5,279.50);


    Customer c1("Araf","01/11/1997","56789","Female",3);

    SuperShop t1;
    t1.getInfo("Body Spray","Cosmetics",1);
    bool bd=false;
    for(int i=0; i<4; i++)
    {
        if(Process(t1,obj[i]))
        {
            bd=true;
        }
    }
    if(!bd)
    {
        c1.show_Customer();
        cout<<"Sorry! We don't have this product sufficiently. Please try again later.\n\n";
    }
    return 0;
}
