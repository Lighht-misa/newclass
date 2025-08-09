#include <iostream>
#include "derived.h"
int main()
{
   /* Derived d(1111,222);
    d.Derivedfunc();
    d.Basefunc();
*/
    
    Base *b1 = new Derived;
    b1->display();
    Derived*bp = new Derived;
    bp->display();
}