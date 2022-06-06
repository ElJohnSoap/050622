
#include <iostream>
using namespace std;
#include "set.h"
int main()
{
    setlocale(LC_ALL, "ru");
   cout << Set (3, new int [] {2,3,4 });
   Set set2;
   cout << set2;
   set2.add(4);
   cout << set2;
   //cin >> set2;
   set2.add(7);
   cout << set2;
   cin >> set2 >> set2;
   cout << set2;
   Set set3(set2);
   cout << set3;
   set3.setMembershipCheck();
   set3.del();
   cout << set3;
}

