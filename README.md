Huffman Coding – Preorder Traversal

This project implements Huffman Coding in C++ to generate prefix-free binary codes for a given set of characters and their frequencies. Unlike standard implementations that print mappings directly, this program prints the codes in preorder traversal of the Huffman tree, as required by the assignment specification.

Example

Input:

S = "abcdef"
f = {5, 9, 12, 13, 16, 45}


Output:

Huffman Codes (Preorder):
0 100 101 1100 1101 111


This matches the assignment requirement, where:

f : 0

c: 100

d  101

a: 1100

b  1101

e: 111

 How It Works

Each character and frequency is inserted into a priority queue (min-heap).

The two smallest frequency nodes are extracted and merged into a new node.

This process repeats until a single root node remains (the Huffman tree).

A recursive function performs preorder traversal, printing codes as the tree is explored.

 Code Structure

Main.cpp → C++ source file containing the full implementation.

README.md → Documentation for the project.

Complexity

Time Complexity: O(N log N) where N is the number of characters (due to heap operations).

Space Complexity: O(N) for storing the Huffman tree.
