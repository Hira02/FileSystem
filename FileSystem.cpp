#include "FileSystem.h"
#include <bits/stdc++.h>

vector<string> splitString(string s);

FileSystem ::FileSystem()
{
    this->root = new Node();
}
Node *FileSystem::getNode()
{
    return root;
}

void FileSystem::initialize(){
    fileSystem = nullptr;
}

FileSystem *FileSystem::getCurrentFileSystem()
{
    if (!fileSystem)
        fileSystem = new FileSystem();
    return fileSystem;
}

vector<string> FileSystem ::ls(string input)
{
    vector<string> ans;
    if (input.length() == 1)
        return ans;
    else
    {
        Node *temp = this->root;
        vector<string> names = splitString(input);
        int i;
        for (i = 0; i < names.size() - 1; i++)
        {
            temp = temp->folderMap[names[i]];
        }
        if ((temp->fileMap).find(names[i]) != (temp->fileMap).end())
        {
            ans.push_back(names[i]); // store the file names only
        }
        else
        { // if the last name is a folder name
            if (temp->folderMap[names[i]])
            {
                Node *folders = temp->folderMap[names[i]];
                //cout << (folders->folderMap).size();
                map<string, Node *>::iterator it;
                for (it = (folders->folderMap).begin(); it != (folders->folderMap).end(); it++)
                {
                    ans.push_back(it->first);
                }
            }
            return ans;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
}
void FileSystem ::mkdir(string input)
{
    Node *temp = this->root;
    vector<string> names = splitString(input);
    for (int i = 0; i < names.size(); i++)
    {
        if ((temp->folderMap).find(names[i]) == (temp->folderMap).end())
        {
            // cout<<names[i]<<" ";
            temp->folderMap[names[i]] = new Node();
        }
        temp = temp->folderMap[names[i]];
    }
    cout << "\n";
}
vector<string> splitString(string s)
{
    vector<string> storage;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '/')
        {
            str += s[i];
        }
        else
        {
            storage.push_back(str);
            str.clear();
        }
    }
    storage.push_back(str);
    return storage;
}