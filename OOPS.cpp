#include <iostream>
using namespace std;

class Parent
{
    protected:
    int y=0;
    public:
    int x=0;
    void print()
    {
        cout<<"Class Parent"<<this->x<<y<<endl;
    }
    static void print(string s)
    {
        cout<<s<<endl;
    }
    int operator +(Parent p1)
    {
        return p1.x*x + p1.y*y;
    }
    void test()
    {
        cout<<"Testing in Parent"<<endl;
    }
};
class Child:public Parent
{
    public:
    Child(int a,int b)
    {
        this->x=x;this->y=y;
    }
    void printChild()
    {
        cout<<"Class Child "<<y<<endl;
    }
    void test()
    {
        cout<<"Testing in Child"<<endl;
    }
};
class A //abstract class
{
    public:
    virtual void f()=0; //pure virtual function
};
class B:public A
{
    public:
    void f()
    {
        cout<<"Data Abstraction"<<endl;
    }
};
int main()
{
    Child obj(3,4),obj1(5,6);
    obj.printChild();
    obj.print();
    obj.print("Overloading");   //fn overloading
    Parent::print("Hello"); //static fn call
    cout<<obj+obj1<<endl;   //op overloading
    Parent *p=&obj; //fn overriding
    p->test();
    obj.test();
    B b;b.f();  //data Abstraction
    return 0;
}
