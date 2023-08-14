#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100;

class Product
{
protected:
    string name;
    double price;
    int stock;
public:
    Product(string n, double p, int s) : name(n), price(p), stock(s)
    {
    }
    virtual ~Product()
    {
    }
    virtual void print1()
    {
    cout << "Name: " << name << "\nPrice: " << price << "\nStock: " << stock << endl;
    cout<<"******************"<<endl;
    }
    virtual void restock(int amount)
    {
        stock += amount;
    }
};

class ExpirableProduct1 : public Product
{
private:
    int expiration;
public:
    ExpirableProduct1(string n, double p, int s, int e) : Product(n, p, s), expiration(e)
    {
    }
    void print1()

    {
        Product::print1();
        cout << "Expiration: " << expiration << endl;
    }
};
class ExpirableProduct2 : public Product
{
private:
    int expiration;
public:
    ExpirableProduct2(string n, double p, int s, int e) : Product(n, p, s), expiration(e)
    {
    }
    void print1()
    {
        Product::print1();
        cout << "Expiration: " << expiration << endl;
    }
};
class ExpirableProduct3 : public Product
{
private:
    int expiration;
public:
    ExpirableProduct3(string n, double p, int s, int e) : Product(n, p, s), expiration(e)
    {
    }
    void print1()
    {
        Product::print1();
        cout << "Expiration: " << expiration << endl;
    }
};
class NonexpirableProduct1 : public Product
{
public:
    NonexpirableProduct1(string n, double p, int s) : Product(n, p, s)
    {
    }

};
class NonexpirableProduct2 : public Product
{
public:

    NonexpirableProduct2(string n, double p, int s) : Product(n, p, s)
{
}


};
class NonexpirableProduct3 : public Product
{
public:

    NonexpirableProduct3(string n, double p, int s) : Product(n, p, s)
{
}


};
class NonexpirableProduct4 : public Product
{
public:

    NonexpirableProduct4(string n, double p, int s) : Product(n, p, s)
{
}


};
class NonexpirableProduct5 : public Product
{
public:

    NonexpirableProduct5(string n, double p, int s) : Product(n, p, s)
{
}


};



class Inventory
{
private:
    Product* products[MAX_PRODUCTS];
    int numProducts;

public:
    string name;
    string searchproduct;
    Inventory() : numProducts(0)
    {
    }
    ~Inventory()
    {
        for (int i = 0; i < numProducts; i++)
            {
            delete products[i];
        }
    }
    inline void add(Product* p)
    {
        if (numProducts == MAX_PRODUCTS)
            {
            cerr << "Error: maximum number of products reached" << endl;
            return;
        }
        products[numProducts++] = p;

    }
    void print()
    {
        for (int i = 0; i < numProducts; i++)
            {
            products[i]->print1();
            cout << endl;
        }
    }
};

int main()
{
string name;
int price;
int stock;
int expiration;

    Inventory i;
    cout<<"Enter product name 1:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;
    cout<<"Enter month of expiry:"<<endl;
    cin>>expiration;
    i.add(new ExpirableProduct1(name,price,stock,expiration));

    cout<<"Enter product name 2:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;
    cout<<"Enter month of expiry:"<<endl;
    cin>>expiration;

    i.add(new ExpirableProduct2(name,price,stock,expiration));

    cout<<"Enter Non expirable product name 3:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;

    i.add(new ExpirableProduct3(name,price,stock,expiration));

    cout<<"Enter Non expirable product name 1:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;


    i.add(new NonexpirableProduct1(name,price,stock));

    cout<<"Enter Non expirable product name 2:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;


    i.add(new NonexpirableProduct2(name,price,stock));

    cout<<"Enter Non expirable product name 3:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;

    i.add(new NonexpirableProduct4(name,price,stock));

    cout<<"Enter Non expirable product name 5:"<<endl;
    cin>>name;
    cout<<"Enter price of product:"<<endl;
    cin>>price;
    cout<<"Enter available stock:"<<endl;
    cin>>stock;

    i.add(new NonexpirableProduct5(name,price,stock));

    i.print();

    return 0;
}
