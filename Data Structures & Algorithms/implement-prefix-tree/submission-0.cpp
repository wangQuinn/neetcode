#include <unordered_map> 

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord = false;
    char val;
};
class PrefixTree {
Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* currentNode = root;
        for(char c : word){
            if(currentNode->children.find(c) == currentNode->children.end()){
                currentNode->children[c] = new Node();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->endOfWord = true;
    }
    
    bool search(string word) {
        Node* currentNode = root;
        for(char c: word){
            if(currentNode->children.find(c) == currentNode->children.end()){
                return false;
            }
            currentNode = currentNode->children[c];
        }
        return currentNode->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* currentNode = root;
        for(char c: prefix){
            if(currentNode->children.find(c) == currentNode->children.end()){
                return false;
            }
            currentNode = currentNode->children[c];
        }
        return true;
        
    }
};
