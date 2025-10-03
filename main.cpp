#include <bits/stdc++.h>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare function for min-heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to check if node is a leaf
bool isLeaf(Node* root) {
    return (root->left == nullptr && root->right == nullptr);
}

// Recursive preorder traversal to print Huffman Codes
void preorder(Node* root, string code) {
    if (!root) return;

    // If it's a leaf node, print the character and its code
    if (isLeaf(root)) {
        cout << code << " ";
    }

    preorder(root->left, code + "0");
    preorder(root->right, code + "1");
}

// Build Huffman Tree and print codes in preorder
void HuffmanCodes(string S, vector<int> f) {
    int N = S.size();
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and push into the priority queue
    for (int i = 0; i < N; i++) {
        pq.push(new Node(S[i], f[i]));
    }

    // Iterate until the size of heap is 1
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create new internal node with frequency = sum of two smallest
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Preorder traversal
    preorder(root, "");
}

// Driver function
int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    cout << "Huffman Codes (Preorder):" << endl;
    HuffmanCodes(S, f);

    return 0;
}
