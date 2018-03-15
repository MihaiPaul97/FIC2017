#include <iostream>
using namespace std;
class Shape{
    public:
    Shape(double wid=0.0,double hei=0.0){
        width=wid;
        height=hei;
    }
    Shape(const Shape &obj) {
        cout<<"Crearea copy constructorului"<<endl;
        ptr = new int;
        *ptr = *obj.ptr;
    }
    ~Shape(void) {
        cout<<"se va sterge obiectul creat!"<<endl;
        delete ptr;
    }
    void setPoint(int p){
        this->point=p;
    }
    void getPoint(){
        cout<<"Point: "<<this->point<<endl;
    }
    virtual void area()=0;
    protected:
        double width;
        double height;
        int *ptr;
    private:
        int point=0;
};
class Rectangle:public Shape{
public:
    Rectangle(double wid=0.0,double hei=0.0):Shape(wid,hei){}
    void area(){
        cout<<"the area of the rectangle is:"<<width*height<<endl;

    }
    Rectangle(const Rectangle &obj):Shape(obj){
        cout<<"Crearea copy Rectangle"<<endl;
        ptr = new int;
        *ptr = *obj.ptr;
    }

};
class Triangle:public Shape{
public:
    Triangle(double wid=0.0,double hei=0.0):Shape(wid,hei){}
    void area(){
        cout<<"the area of the TRIANGLE is:"<<(width*height)/2<<endl;
    }
    Triangle(const Triangle &obj):Shape(obj){
        cout<<"Crearea COPY triangle"<<endl;
        ptr = new int;
        *ptr = *obj.ptr;
    }


};
int main()
{
    Shape *s;
    Rectangle rec[5];
    Triangle tri[5];
    rec[0]= Rectangle(2.3,4.5);
    tri[0]= Triangle(1.1,2.2);
    rec[1]= Rectangle(1.1,1.1);
    tri[1]= Triangle(2.2,2.2);
    rec[2]= Rectangle(3.3,3.3);
    tri[2]= Triangle(4.1,1.4);
    rec[3]= Rectangle(2.3,4.5);
    tri[3]=Triangle(5.1,0.2);
    rec[4]= Rectangle(5.3,4.5);
    tri[5]= Triangle(4.3,1.2);
    for(int i=0;i<5;i++){
        tri[i].area();
        rec[i].area();
    }
    Shape *sh=new Triangle(1.1,6.4);
    sh->getPoint();
    s=sh;
    s->getPoint();
    sh->setPoint(5);
    sh->getPoint();
    s->getPoint();
    return 0;
}
