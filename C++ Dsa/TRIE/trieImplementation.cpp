#include<iostream>
#include<string>
using namespace std;

// Define the TrieNode class to represent each node in the Trie
class TrieNode {

public:
    char data;             // Store the character of the node
    TrieNode* children[26]; // Array of pointers to children nodes (one for each letter A-Z)
    bool isTerminal;        // Flag to check if it's the end of a word

    // Constructor to initialize a TrieNode
    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;  // Initially, all children are NULL
        }
        isTerminal = false;  // Initially, no node is terminal (i.e., end of word)
    }
};

// Define the Trie class which handles insertion, searching, and removal of words
class Trie {
public:
    TrieNode* root;  // Root of the Trie

    // Constructor to initialize the Trie with a root node
    Trie() {
        root = new TrieNode('\0');  // The root node does not store any character
    }

    // Helper function to insert a word into the Trie recursively
    void insertWord(TrieNode* root, string& word, int i) {
        // Base case: If we've reached the end of the word
        if (i == word.length()) {
            root->isTerminal = true;  // Mark the node as terminal (end of word)
            return;
        }

        // Find the index of the current character in the word (Assuming capital letters)
        int index = word[i] - 'A';
        TrieNode* child;

        // If the child node for the current character exists, move to it
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // If the child doesn't exist, create a new TrieNode
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }

        // Recursively insert the rest of the word
        insertWord(child, word, i + 1);
    }

    void insert(string str) {
        insertWord(root, str, 0);  // Start inserting from the root node
    }

    bool searchWord(TrieNode* root, string& word, int i) {
        // Base case: If we've reached the end of the word
        if (i == word.length()) {
            return root->isTerminal;  // Return whether it's a valid word (terminal node)
        }

        // Find the index of the current character in the word (Assuming capital letters)
        int index = word[i] - 'A';
        TrieNode* child;

        // If the child node exists, continue searching
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;  // If no child exists for the character, word doesn't exist
        }

        // Recursively search for the next character in the word
        return searchWord(child, word, i + 1);
    }


    bool search(string str) {
        return searchWord(root, str, 0);  // Start searching from the root node
    }

    void removeWord(TrieNode* root, string& word, int i) {
        // Base case: If we've reached the end of the word
        if (i == word.length()) {
            // If the word is present, mark the current node as not terminal (i.e., word is removed)
            if (root->isTerminal) {
                root->isTerminal = false;
                return;  // Successfully removed the word
            }
            else {
                // If word wasn't found at the terminal node, output an error
                cout << "Word not present!" << endl;
                return;
            }
        }

        // Find the index of the current character in the word (Assuming capital letters)
        int index = word[i] - 'A';
        TrieNode* child;

        // If the child node exists, continue to the next character
        if (root->children[index]) {
            child = root->children[index];
        }
        else {
            // If no child exists for the character, word doesn't exist
            cout << "Word not present!" << endl;
            return;
        }

        // Recursively move to the next character in the word
        removeWord(child, word, i + 1);
    }


    void remove(string str) {
        removeWord(root, str, 0);  // Start removing from the root node
    }

    bool removeWord2(TrieNode* root, string word, int depth) {
        if (root == NULL) return false;

        if (depth == word.length()) {
            if (root->isTerminal) {
                root->isTerminal = false;
            }

            // Check if the current node has any child nodes
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    return false; // If there are any children, don't delete this node
                }
            }

            return true; // No children left, safe to delete this node
        }

        int index = word[depth] - 'A';
        TrieNode* child = root->children[index];
        if (!child) return false; // Word not found, return false

        bool shouldDeleteChild = removeWord2(child, word, depth + 1);

        // If the child node should be deleted
        if (shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;
        }

        // After deleting the child, check if this node can be deleted
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return false; // This node has children, can't delete it
            }
        }

        return true; // Safe to delete this node as it has no children
    }


    void remove2(string str) {
        removeWord2(root, str, 0);  // Start removing from the root node
    }

    bool startsWithWord(TrieNode* root,string word,int i){
        if(i==word.length()){
            return true;
        }
        int index=word[i]-'A';
        TrieNode* child=root->children[index];
        if(!child) return false;

        return startsWithWord(child,word,i+1);
    }

    bool startsWith(string str){
        return startsWithWord(root,str,0);
    }
};


int main() {
    Trie* t = new Trie();

    t->insert("");
    cout << t->search("ABCD") << endl;

    // t->remove2("ABCD");
    cout << t->search("ABCD") << endl;
    cout << t->startsWith("ABC") << endl;

    string a="hello";
    cout<<a.substr(0,1);

    return 0;
}
