#include "treaded.h"

Node::Node(int data) {
	this->data = data;
	left = right = NULL;
	lFlag = rFlag = 'T';
}

void Node::setData(int data) {
	this->data = data;
}

int Node::getData() {
	return data;
}

void Node::setLeft(Node * left) {
	this->left = left;
}

Node * Node::getLeft() {
	return left;
}

void Node::setRight(Node * right) {
	this->right = right;
}

Node * Node::getRight() {
	return right;
}

void Node::setLFlag(char lFlag) {
	this->lFlag = lFlag;
}

char Node::getLFlag() {
	return lFlag;
}

void Node::setRFlag(char rFlag) {
	this->rFlag = rFlag;
}

char Node::getRFlag() {
	return rFlag;
}



BST::BST() {
	root = NULL;
}
int BST::insert(int data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
	{
		return false;
	}
	if (root == NULL)
	{
		root = NULL;
		return data;

	}
	Node* temp = root;
	while (temp->getData() != data)
	{
		if (data < temp->getData())
		{
			if (temp->getLFlag() == 'T')
			{
				newnode->setRight(temp);
				newnode->setLeft(temp->getLeft());
				temp->setLeft(newnode);
				temp->setLFlag('L');
				return data;


			}
			temp = temp->getLeft();

		}
		else
		{
			if (temp->getRFlag() == 'T')
			{
				newnode->setLeft(temp);
				newnode->setRight(temp->getRight());
				temp->setRight(newnode);
				temp->setRFlag('L');
				return data;


			}
			temp = temp->getRight();

		}
		delete newnode;
		return false;
	}

}

void BST::inOrder()
{
	Node* temp = root;
	char flag = 'L';
	cout << "inorder";
	while (temp!=NULL)
	{
		while (temp->getLFlag()== 'L' && flag == 'L')
		{
			temp = temp->getLeft();
		}
		cout << temp->getData()<<" ";
		flag = temp->getRFlag();
		temp = temp->getRight();
		
	}
	cout << "dikhao";
}

void BST::preOrder()
{
	
	Node* temp = root;
	char flag = 'L';
	cout << "preorder";
	while (temp)
	{
		while (temp->getLFlag() == 'L' && flag == 'L')
		{
			cout << temp->getData() << " ";
			temp = temp->getLeft();
		}
		if (flag == 'L')
		{
			cout << temp->getData() << " ";
		}
		flag = temp->getRFlag();
		temp = temp->getRight();
	}
}
