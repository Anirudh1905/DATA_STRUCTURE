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
        cout<<"Class A"<<this->x<<y<<endl;
    }
    static void print(string s)
    {
        cout<<s<<endl;
    }
    int operator +(Parent p1)
    {
        return p1.x*x + p1.y*y;
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
        cout<<"Class B "<<y<<endl;
    }
};

int main()
{
    Child obj(3,4),obj1(5,6);
    obj.printChild();
    obj.print();
    obj.print("Overloading");
    Parent::print("Hello");
    cout<<obj+obj1<<endl;
    
    return 0;
}
