#include <unordered_map> 
class Node{
    public: 
        char val;
        unordered_map<char, Node*> children;
        bool endOfWord = false;
};

class WordDictionary {
Node * root;
public:
    WordDictionary() {
        root = new Node();
    }
    void addWord(string word) {
        Node * cur = root;
        for(char c: word){
            if(nullptr == cur->children[c]){
                Node * newNode = new Node();
                newNode->val = c;
                cur->children[c] = newNode;
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    bool search(string word) {
        return dfsHelper(word, 0, root);
    }

    bool dfsHelper(string word, int index, Node * root){
        Node * cur = root;
        for(int i = index; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(const auto & [key, child] : cur->children){
                    if(nullptr != child && dfsHelper(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(nullptr == cur->children[c]) return false;
                cur = cur->children[c];
            }
        }
        return cur->endOfWord;
    }
};
