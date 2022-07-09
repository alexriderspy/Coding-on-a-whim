#include<iostream>
using namespace std;

class Shape{
public:
    Shape(int l,int w){
        length = l;
        width = w;
    }
    int get_Area(){
        cout<<"This is parent";
        return 1;
    }
protected:
    int length;
    int width;
};

class Rectangle: public Shape{
public:
    Rectangle(int l=5,int w=5)
    : Shape(l,w)
    {
    }
    int get_Area(){
        cout<<"This is rect";
        return (length*width);
    }
};

int main(){
    Rectangle r(5,9);
    cout<<r.get_Area()<<'\n';
}
