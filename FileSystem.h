#include <bits/stdc++.h>
using namespace std;
class Node {
    public :
    map<string, Node*> folderMap;
     map<string, string> fileMap;
    // Node(){
    //     folderMap = new map<string, Node*>();
    //     fileMap = new map<string, string> ();
    // }
};
class FileSystem {
    private:
     Node* root;
public:
    FileSystem();
    Node* getNode();
    vector<string> ls(string input);
     void mkdir(string input);
     void addContentToFile(string content);
     string content(string fileName);
};
