#include <iostream>
using namespace std;

struct treeNode{
	int data;
	treeNode* left;
	treeNode* right;
};
typedef treeNode* treePtr;

int maxValue(treePtr root){
	if(root == NULL) return 0;
	if(root->right == NULL && root->left == NULL) return root->data;
	int leftMax = maxValue(root->left);
	int rightMax = maxValue(root->right);
	int maxNum = root->data;
	if(leftMax > maxNum) maxNum = leftMax;
	if(rihtMax > maxNum) maxNum = rightMax;

	return maxNum;
}