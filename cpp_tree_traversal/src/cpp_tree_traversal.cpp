
//============================================================================
// Name        : cpp_tree_traversal.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Node{

public:
    int value;
    Node* left;
    Node* right;
    Node(){ value = -1; left = nullptr; right = nullptr;}
    void setval(int val){ value = val;}
    void setleft(Node* lnode){ left = lnode;}
    void setright(Node* rnode){right = rnode;}
    int getval(){ return value;}
    Node* getLnode(){return left;}
    Node* getRnode(){return right;}

};

class Tree{
    Node* root;

public:
    Tree();
    ~Tree();
    Node* getroot(){ return root;}
    void addnode(int val);
    void Inorder(Node* node);
    void Preorder(Node* node);
    void Postorder(Node* node);
    void Postorder(Node* node, int count, vector<vector<int>> &v);

private:
    void addnode(int val, Node* leaf);
    void freenode(Node* leaf);

};

Tree:: Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    freenode(root);
}

void Tree :: freenode(Node* leaf)
{
    while(leaf != nullptr)
    {
        freenode(leaf->getLnode());
        freenode(leaf->getRnode());
        delete leaf;
    }
}

void Tree :: addnode(int val)
{
    if( root == nullptr)
    {
//        cout << " adding new node: " << val << endl;
        Node* n = new Node;
        n->value = val;
        root = n;
    }
    else
    {
//        cout << " adding new node: " << val << endl;
        addnode(val, root);
    }
}


void Tree :: addnode(int val, Node* leaf)
{
    if(val <= leaf->getval())
    {
        if(leaf->getLnode() != nullptr)
        {
            addnode(val, leaf->getLnode());
        }
        else
        {
            Node* n = new Node;
            n->setval(val);
            leaf->setleft(n);
        }
    }
    else
    {
        if(leaf->getRnode() != nullptr)
        {
            addnode(val, leaf->getRnode());
        }
        else
        {
            Node* n = new Node;
            n->setval(val);
            leaf->setright(n);
        }
    }
}

void Tree::Preorder(Node* node)
{
    if(node != nullptr)
    {
        cout<< node->getval()<< endl;
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Tree::Inorder(Node* node)
{
    if(node != nullptr)
    {
        Inorder(node->left);
        cout<< node->getval()<< endl;
        Inorder(node->right);
    }
}

void Tree::Postorder(Node* node)
{
    if(node != nullptr)
    {
        Postorder(node->left);
        Postorder(node->right);
        cout<< node->getval()<< endl;
    }
}
void Tree::Postorder(Node* node, int level, vector<vector<int>> &v)
{
    if(node != nullptr)
    {
        v[level].push(node->getval());
    	Postorder(node->left, level +1, v);
        Postorder(node->right, level +1, v);
//        v[level].push_back(node->getval());
        cout<< "value: " << node->getval()<< " level : " << level << endl;
    }
}

void minimal_BST(Tree* tree, vector<int> &v, int start, int end)
{

    cout << "start : " << start << " end : " << end << endl;
    if(end < start)
        return;

    int mid = (start+end)/2;
    //Tree* tree = new Tree;
    cout << " adding new position: " << mid << endl;
    tree->addnode(v[mid]);
    minimal_BST(tree, v, start, mid -1);
    minimal_BST(tree, v, mid+1, end);
}

void Create_BST(Tree* tree, vector<int> &v)
{
    minimal_BST(tree, v, 0, v.size()-1);
}

int main() {
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

    //	Tree* tree = new Tree;
    //
    //	tree->addnode(5);
    //	tree->addnode(3);
    //	tree->addnode(4);
    //	tree->addnode(2);
    //	tree->addnode(1);
    //	tree->addnode(7);
    //	tree->addnode(6);
    //	tree->addnode(8);
    //	tree->addnode(9);
    //
    //	tree->Preorder(tree->getroot());
    //
    //	cout<< "+++++++++++++++++"<< endl;
    //
    //	tree->Postorder(tree->getroot());

    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    Tree tree2 ;

    Create_BST(&tree2, vec);

    //assert(tree2);

    cout<< "+++++++++++++++++"<< endl;

    tree2.Preorder(tree2.getroot());

    cout<< "+++++++++++++++++"<< endl;

    vector<vector<int>> v;
    tree2.Postorder(tree2.getroot(), 0, v);

//    cout<< "+++++++++++++++++"<< endl;
//    for (auto &i: v) {
//    	for(auto &j:i) {
//            cout<< "value: " << j<<  endl;
//    	}
//        cout<< "+++++++++++++++++"<< endl;
//    }
    return 0;
}
