#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class mysingleton
{
public:
    static mysingleton* instance;
    static mysingleton* getinstance();
    void setcomment(string comment) {

    }
private:
    mysingleton();

};
mysingleton* mysingleton::instance = NULL;
mysingleton::mysingleton() {
    cout << "constructor called" << endl;
}
mysingleton* mysingleton::getinstance() {
    if (instance == NULL) {
        instance = new mysingleton();
    }
    return instance;
}
int main()
{
    mysingleton* obj;
    mysingleton::getinstance() ;
    mysingleton* obj2;
    mysingleton::getinstance() ;
    cin.get();

    return 0;
}
