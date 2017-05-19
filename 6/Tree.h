#ifndef TreeH
#define TreeH

#include <string>

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>

using namespace std;

class TreeNode {

public:

	TreeNode() {
		mLeftNode = 0;
		mRightNode = 0;
		mParent = 0;
	}

	void addLeftNode(TreeNode* leftNode) {
		mLeftNode = leftNode;
	}

	TreeNode* getLeftNode() {
		return mLeftNode;
	}

	void addRightNode(TreeNode* rightNode) {
		mRightNode = rightNode;
	}

	TreeNode* getRightNode() {
		return mRightNode;
	}

	void addParent(TreeNode* parentNode) {
		mParent = parentNode;
	}

	TreeNode* getParent() {
		return mParent;
	}

	void setKey(int key) {
		mKey = key;
	}

	int getKey() {
		return mKey;
	}

	void setData(string data) {
		mData = data;
	}

	string getData() {
		return mData;
	}

private:

	TreeNode* mLeftNode;
	TreeNode* mRightNode;
	TreeNode* mParent;
	int mKey;
	string mData;

};

class Tree {

public:

	Tree();
	~Tree();

	void insertData(int key, string data);
	string findData(int key);
	bool deleteData(int key);
	string* infixTraverseDataList();
	string* postfixTraverseDataList();
	string* prefixTraverseDataList();

	void clear(TreeNode* currentNode);

	void infixTraverseDataList(TreeNode* currentNode, TTreeView* view);
	void postfixTraverseDataList(TreeNode* currentNode, TTreeView* view);
	void prefixTraverseDataList(TreeNode* currentNode, TTreeView* view);

	void infixTraverseDataList(TreeNode* currentNode, TMemo* view);
	void postfixTraverseDataList(TreeNode* currentNode, TMemo* view);
	void prefixTraverseDataList(TreeNode* currentNode, TMemo* view);

	void leftCount(TreeNode* currentNode, int& count);

private:

	TreeNode* mRoot;
	int mCount;

	void insert(TreeNode* currentRootNode, int key, string data);
	string find(TreeNode* currentRootNode, int key);
	bool remove(TreeNode* currentRootNode, int key);

	string* infixTraverse(TreeNode* currentNode, string* list);
	string* postfixTraverse(TreeNode* currentNode, string* list);
	string* prefixTraverse(TreeNode* currentNode, string* list);
};

#endif
