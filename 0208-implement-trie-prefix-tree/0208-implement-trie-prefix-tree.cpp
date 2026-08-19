class TrieNode{
    public:
    TrieNode* children[26];
    bool isLast;
    TrieNode(){
        isLast = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto u:word){
            int index = u- 'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode;
            }
            node = node->children[index];
        }
        node->isLast = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto u:word){
            int index = u - 'a';
            if(! node->children[index]){
                return false;
            }
            node = node->children[index];
        }
        return node->isLast;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto u:prefix){
            int index = u - 'a';
            if(!node->children[index]){
                return false;
            }
            node  = node->children[index];
        }
        return true;
    }
};






/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */