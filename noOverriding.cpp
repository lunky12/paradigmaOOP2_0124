#include <iostream>
using namespace std;

class baseClass {
public:
    virtual void perkenalan() final{
        cout << "Hallo saya Function dari base class";
    }

};
class darivedClass : public baseClass {
public:
    void perkenalan1() {
        cout << "Hallo saya Function dari derived Class";

    }
};
int main() {
    darivedClass a;
    a.perkenalan();
 
    return 0;
}