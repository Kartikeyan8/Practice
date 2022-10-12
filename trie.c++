#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL; 
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
     Node* get(char ch)
     {
        return links[ch-'a'];
     }
     void setend()
     {
        flag=true;
     }
     bool isend()
     {
        return flag;
     }
};
class Trie{
    Node* root;
     public:
    Trie()
    {
        root=new Node();
    }
  
    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
            {
                node->put(word[i],new Node());
            }
        }
        node->setend();
    }
    bool search(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
                return false;
            node=node->get(word[i]);    
        }
    }
};
int main()
{
    Trie t;
    t.insert("hello");

}