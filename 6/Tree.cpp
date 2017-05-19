#pragma hdrstop

#include "Tree.h"

#pragma package(smart_init)


Tree::Tree()
{
	mRoot = 0;
	mCount = 0;
}

Tree::~Tree() {

}

void Tree::insertData(int key, string data)
{
	if (mRoot == 0) {

		TreeNode* node = new TreeNode();
		node->setKey(key);
		node->setData(data);

		mRoot = node;
	}
	else
	{
	   insert(mRoot, key, data);
	}
}

void Tree::insert(TreeNode* currentNode, int key, string data) {

	if (key > currentNode->getKey())
	{
		TreeNode* right = currentNode->getRightNode();
		if (right == 0)
		{
			right = new TreeNode();
			right->setKey(key);
			right->setData(data);
			right->addParent(currentNode);
			currentNode->addRightNode(right);
		}
		else
		{
			insert(right, key, data);
		}
	}

	else if (key < currentNode->getKey()) {
		TreeNode* left = currentNode->getLeftNode();
		if (left == 0)
		{
			left = new TreeNode();
			left->setKey(key);
			left->setData(data);
			left->addParent(currentNode);
			currentNode->addLeftNode(left);
		}
		else
		{
			insert(left, key, data);
		}
	}

	else if (key == currentNode->getKey())
	{
		currentNode->setData(data);
	}
}

string Tree::findData(int key)
{
	if (mRoot == 0)
	{
		return "";
	}

	else
	{
		return find(mRoot, key);
	}
}

string Tree::find(TreeNode* currentNode, int key) {
	if (currentNode->getKey() == key)
	{
		return currentNode->getData();
	}

	else if (key > currentNode->getKey())
	{
		TreeNode* right = currentNode->getRightNode();
		if (right == 0)
		{
			return "";
		}
		else
		{
			return find(right, key);
		}
	}

	else if (key < currentNode->getKey())
	{
		TreeNode* left = currentNode->getLeftNode();
		if (left == 0)
		{
			return "";
		}
		else
		{
			return  find(left, key);
		}
	}
}

bool Tree::deleteData(int key)
{
	if (mRoot == 0)
	{
		return false;
	}

	return remove(mRoot, key);
}

bool Tree::remove(TreeNode* currentNode, int key)
{
	TreeNode* parent = currentNode->getParent();
	if (currentNode->getKey() == key)
	{
		TreeNode* right = currentNode->getRightNode();
		TreeNode* left = currentNode->getLeftNode();
		if (right == 0 && left == 0) {
			if (parent != 0)
			{
				if (parent->getRightNode() == currentNode)
				{
					parent->addRightNode(0);
				}
				else
				{
					parent->addLeftNode(0);
				}
			}
			delete currentNode;
			return true;
		}
		else if (right == 0 || left == 0)
		{
			if (right != 0)
			{
				if (parent != 0)
				{
					if (parent->getRightNode() == currentNode)
					{
						parent->addRightNode(right);
					}
					else
					{
						parent->addLeftNode(right);
					}
				}
				right->addParent(parent);

				right->addLeftNode(left);
				delete currentNode;
			}
			if (left != 0)
			{
				if (parent != 0)
				{
					if (parent->getRightNode() == currentNode)
					{
						parent->addRightNode(left);
					}
					else
					{
						parent->addLeftNode(left);
					}
				}
				left->addParent(parent);

				left->addRightNode(right);
				delete currentNode;
			}

			return true;
		}
		else
		{
			TreeNode* subLeft = right->getLeftNode();
			while (subLeft->getLeftNode() != 0)
			{
				subLeft = subLeft->getLeftNode();
			}

			if (parent != 0)
			{
				if (parent->getRightNode() == currentNode)
				{
					parent->addRightNode(subLeft);
				}
				else
				{
					parent->addLeftNode(subLeft);
				}
			}
			subLeft->addParent(currentNode->getParent());

			subLeft->addLeftNode(left);
			subLeft->addRightNode(right);
			left->addParent(subLeft);
			right->addParent(subLeft);

			delete currentNode;
		}
	}

	if (key > currentNode->getKey())
	{
		TreeNode* right = currentNode->getRightNode();
		if (right == 0)
		{
			return false;
		}
		else
		{
			return remove(right, key);
		}
	}

	if (key < currentNode->getKey())
	{
		TreeNode* left = currentNode->getLeftNode();
		if (left == 0)
		{
			return false;
		}
		else
		{
			return remove(left, key);
		}
	}
}

string* Tree::infixTraverseDataList()
{
	if (mRoot == 0)
	{
		return 0;
	}

	string* list = new string[mCount];
	infixTraverse(mRoot, list);
	return list;
}

string* Tree::infixTraverse(TreeNode* currentNode, string* list) {
	if (currentNode->getLeftNode() != 0)
	{
		infixTraverse(currentNode->getLeftNode(), list);
	}

	list[0] = currentNode->getData();
	list++;

	if (currentNode->getRightNode() != 0)
	{
		infixTraverse(currentNode->getRightNode(), list);
	}
}

string* Tree::postfixTraverseDataList()
{
	if (mRoot == 0)
	{
		return 0;
	}

	string* list = new string[mCount];
	postfixTraverse(mRoot, list);
	return list;
}

string* Tree::postfixTraverse(TreeNode* currentNode, string* list) {
	if (currentNode->getLeftNode() != 0)
	{
		postfixTraverse(currentNode->getLeftNode(), list);
	}

	if (currentNode->getRightNode() != 0)
	{
		postfixTraverse(currentNode->getRightNode(), list);
	}

	list[0] = currentNode->getData();
	list++;
}


string* Tree::prefixTraverseDataList()
{
	if (mRoot == 0)
	{
		return 0;
	}

	string* list = new string[mCount];
	prefixTraverse(mRoot, list);
	return list;
}

string* prefixTraverse(TreeNode* currentNode, string* list)
{
	list[0] = currentNode->getData();
	list++;

	if (currentNode->getLeftNode() != 0)
	{
		prefixTraverse(currentNode->getLeftNode(), list);
	}

	if (currentNode->getRightNode() != 0)
	{
		prefixTraverse(currentNode->getRightNode(), list);
	}
}

void Tree::infixTraverseDataList(TreeNode* currentNode, TTreeView* view)
{
	if (currentNode == 0)
	{
		if (mRoot == 0)
		{
			return;
		}
		else
		{
			infixTraverseDataList(mRoot, view);
			return;
		}
	}


	if (currentNode->getLeftNode() != 0)
	{
		infixTraverseDataList(currentNode->getLeftNode(), view);
	}

	string s = currentNode->getData();
	if (view->Items->Count == 0)
	{
		view->Items->Add(0, currentNode->getData().c_str());
	}
	else
	{
		view->Items->AddChild((*view->Items)[view->Items->Count-1], currentNode->getData().c_str());
	}

	if (currentNode->getRightNode() != 0)
	{
		infixTraverseDataList(currentNode->getRightNode(), view);
	}
}

void Tree::postfixTraverseDataList(TreeNode* currentNode, TTreeView* view)
{
	if (currentNode == 0)
	{
		if (mRoot == 0)
		{
			return;
		} else {
			postfixTraverseDataList(mRoot, view);
			return;
		}
	}

	if (currentNode->getLeftNode() != 0)
	{
		postfixTraverseDataList(currentNode->getLeftNode(), view);
	}

	if (currentNode->getRightNode() != 0)
	{
		postfixTraverseDataList(currentNode->getRightNode(), view);
	}

	string s = currentNode->getData();
	if (view->Items->Count == 0)
	{
		view->Items->Add(0, currentNode->getData().c_str());
	}
	else
	{
		view->Items->AddChild((*view->Items)[view->Items->Count-1], currentNode->getData().c_str());
	}
}

void Tree::prefixTraverseDataList(TreeNode* currentNode, TTreeView* view)
{
	if (currentNode == 0)
	{
		if (mRoot == 0)
		{
			return;
		}
		else
		{
			prefixTraverseDataList(mRoot, view);
			return;
		}
	}

	string s = currentNode->getData();
	if (view->Items->Count == 0)
	{
		view->Items->Add(0, currentNode->getData().c_str());
	}
	else
	{
		view->Items->AddChild((*view->Items)[view->Items->Count-1], currentNode->getData().c_str());
	}

	if (currentNode->getLeftNode() != 0)
	{
		prefixTraverseDataList(currentNode->getLeftNode(), view);
	}

	if (currentNode->getRightNode() != 0)
	{
		prefixTraverseDataList(currentNode->getRightNode(), view);
	}
}

void Tree::clear(TreeNode* currentNode)
{
	if (currentNode == 0)
	{
		if (mRoot == 0)
		{
			return;
		}
		else
		{
            mRoot = 0;
			clear(mRoot);
		}
	}

	if (currentNode->getLeftNode() != 0)
	{
	clear(currentNode->getLeftNode());
	}

	if (currentNode->getRightNode() != 0)
	{
	   clear(currentNode->getRightNode());
	}

	delete currentNode;
}

void Tree::leftCount(TreeNode* currentNode, int& count) {
	if (currentNode == 0)
	{
		if (mRoot == 0)
			return;
		else
		{
			if (mRoot->getRightNode() == 0)
			{
				return;
			}
			else
			{
				leftCount(mRoot->getRightNode(), count);
				return;
			}
		}
	}

	count++;

	if (currentNode->getLeftNode() != 0)
	{
		leftCount(currentNode->getLeftNode(), count);
	}

	if (currentNode->getRightNode() != 0)
	{
		leftCount(currentNode->getRightNode(), count);
	}
}

void Tree::infixTraverseDataList(TreeNode* currentNode, TMemo* view)
{
	if (currentNode == 0)
	{
		if (mRoot == 0)
		{
			return;
		}
		else
		{
			infixTraverseDataList(mRoot, view);
			return;
		}
	}

	if (currentNode->getLeftNode() != 0)
	{
		infixTraverseDataList(currentNode->getLeftNode(), view);
	}

	view->Lines->Add(currentNode->getData().c_str());

	if (currentNode->getRightNode() != 0)
	{
		infixTraverseDataList(currentNode->getRightNode(), view);
	}
}

void Tree::postfixTraverseDataList(TreeNode* currentNode, TMemo* view)
{
	if (currentNode == 0)
	{
		if (mRoot == 0)
		{
			return;
		}
		else
		{
			postfixTraverseDataList(mRoot, view);
			return;
		}
	}

	if (currentNode->getLeftNode() != 0)
	{
		postfixTraverseDataList(currentNode->getLeftNode(), view);
	}

	if (currentNode->getRightNode() != 0)
	{
		postfixTraverseDataList(currentNode->getRightNode(), view);
	}

	view->Lines->Add(currentNode->getData().c_str());
}

void Tree::prefixTraverseDataList(TreeNode* currentNode, TMemo* view)
{
	 if (currentNode == 0)
	 {
		if (mRoot == 0)
		{
			return;
		}
		else
		{
			prefixTraverseDataList(mRoot, view);
			return;
		}
	}

	view->Lines->Add(currentNode->getData().c_str());

	if (currentNode->getLeftNode() != 0)
	{
		prefixTraverseDataList(currentNode->getLeftNode(), view);
	}

	if (currentNode->getRightNode() != 0)
	{
		prefixTraverseDataList(currentNode->getRightNode(), view);
	}
}


