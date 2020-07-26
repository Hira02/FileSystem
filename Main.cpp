#include <bits/stdc++.h>
#include "FileSystem.h"
using namespace std;

int main()
{
    FileSystem* f1 = new FileSystem();
    // f1->getNode()->ls;
    vector<string> x = f1->ls("/");
    //   cout<<x.size();
    f1->mkdir("/a/b/c/d2");
    f1->mkdir("/a/b/c/d1");
    vector<string> y = f1->ls("/a/b/c");
   for(auto c : y){
       cout<< c <<" ";
   }
   cout<<"\n";
    return 0;
}
