#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    map<string, Node *> folderMap;
    map<string, string> fileMap;
    // Node(){
    //     folderMap = new map<string, Node*>();
    //     fileMap = new map<string, string> ();
    // }
};
class FileSystem
{
private:
    Node *root;
    static FileSystem *fileSystem;
    FileSystem();

public:
    Node *getNode();
    static void initialize();
    static FileSystem *getCurrentFileSystem();
    vector<string> ls(string input);
    void mkdir(string input);
    void addContentToFile(string content);
    string content(string fileName);
};
