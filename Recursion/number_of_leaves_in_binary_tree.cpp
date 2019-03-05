#include <iostream>
using namespace std;

class BinaryTree{
public:
	int publicCountLeaves();
private:
	struct binaryTreeNode{
		int data;
		binaryTreeNode* left;
		binaryTreeNode* right;
	};
	typedef binaryTreeNode* treePtr;
	treePtr _root;
	int privateCountLeaves(treePtr rootPtr);
}

int BinaryTree::privateCountLeaves(treePtr rootPtr){
	if(rootPtr == NULL) return 0;
	if(rootPtr->right == NULL && rootPtr->left == NULL) return 1;
	int leftCount = countLeaves(rootPtr->left);
	int rightCount = countLeaves(rootPtr->right);

	return leftCount + rightCount;
}

int BinaryTree::publicCountLeaves(){
	return privateCountLeaves(_root);
}

int main(){

	BinaryTree bt;
	int numLeaves = bt.countLeaves();

	return 0;
}