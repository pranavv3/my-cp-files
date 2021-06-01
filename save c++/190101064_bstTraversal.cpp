#include <iostream>
using namespace std;

//I used the template taught in class.
class BinTreeNode {
    public:
        BinTreeNode();
        virtual ~BinTreeNode();
        int getData();
        bool setData(int);
        BinTreeNode* getPar();
        bool setPar(BinTreeNode*);
        BinTreeNode* getLeftC();
        bool setLeftC(BinTreeNode*);
        BinTreeNode* getRightC();
        bool setRightC(BinTreeNode*);
        void setLinksNull();

    private:
        int data;
        BinTreeNode *leftC, *rightC, *par;

};

class BST1 {
    public:
        BST1();
        virtual ~BST1();
        BinTreeNode* addNode(BinTreeNode*);
        void postOrderTraversal();
    private:
        BinTreeNode* root;
        void postOrderInTree(BinTreeNode*);
};
int BinTreeNode::getData() {
    return data;
}
bool BinTreeNode::setData(int val) {
    data=val;
    return true;
}
BinTreeNode* BinTreeNode::getPar() {
    return par;
}
bool BinTreeNode::setPar(BinTreeNode* nodePtr) {
    par=nodePtr;
    return true;
}
BinTreeNode* BinTreeNode::getLeftC() {
    return leftC;
}
bool BinTreeNode::setLeftC(BinTreeNode* nodePtr) {
    leftC=nodePtr;
    return true;
}
BinTreeNode* BinTreeNode::getRightC() {
    return rightC;
}
bool BinTreeNode::setRightC(BinTreeNode* nodePtr) {
    rightC=nodePtr;
    return true;
}
void BinTreeNode::setLinksNull() {
    setPar(NULL);
    setLeftC(NULL);
    setRightC(NULL);
}
BinTreeNode::BinTreeNode() {
    data=0;
    leftC=NULL, rightC=NULL, par=NULL;
}
BinTreeNode::~BinTreeNode() {

}
BinTreeNode* BST1::addNode(BinTreeNode* nodePtr) {
    nodePtr->setLinksNull();
    if(root==NULL) {
        root=nodePtr;
        return NULL; //returning address of parent.
    }
    BinTreeNode* curr = root; //parent
    while(true) {
        if (nodePtr->getData()<=curr->getData()) {
            //insert to left.
            if (curr->getLeftC()==NULL) {
                //attach
                curr->setLeftC(nodePtr);
                nodePtr->setPar(curr);
                return curr; //returning address of parent.
            }
            else {
                //fill in left subtree.
                curr=curr->getLeftC();
            }

        }
        else {
            //insert to right
            if (curr->getRightC()==NULL) {
                //attach
                curr->setRightC(nodePtr);
                nodePtr->setPar(curr);
                return curr; //returning address of parent.
            }
            else {
                //fill in right subtree.
                curr=curr->getRightC();
            }

        }
    }
}
void BST1::postOrderInTree(BinTreeNode* nodePtr) {
    if (nodePtr==NULL) {
        return;
    }
    postOrderInTree(nodePtr->getLeftC());
    postOrderInTree(nodePtr->getRightC());
    cout<<nodePtr->getData()<<endl;
}
void BST1::postOrderTraversal() {
    postOrderInTree(root);
}
BST1::BST1() {
    root=NULL;
}
BST1::~BST1() {
}
int main()
{
    int num; cin>>num;
    BST1 tree;
    BinTreeNode* n1;
    for (int i=0; i<num; i++) {
        n1=new BinTreeNode();
        int val; cin>>val;
        n1->setData(val);
        tree.addNode(n1);
    }
    tree.postOrderTraversal();

    return 0;
}
