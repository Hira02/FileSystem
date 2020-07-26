#include <bits/stdc++.h>
#include "FileSystem.h"
using namespace std;

FileSystem* FileSystem::fileSystem = nullptr;
//FileSystem::initialize();

int main()
{
    FileSystem *f1 = FileSystem::getCurrentFileSystem();
    f1->mkdir("/a/b/c/d2");
    f1->mkdir("/a/b/c/d1");
    vector<string> y = f1->ls("/a/b/c");
   for(auto c : y){
       cout<< c <<" ";
   }
   cout<<"\n";
    return 0;
}
