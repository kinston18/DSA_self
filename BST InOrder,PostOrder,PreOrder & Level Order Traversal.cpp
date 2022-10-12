#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* Right;
	//Constructor
	Node()
	{
		this->data = 0;
		this->left = NULL;
		this->Right = NULL;
	}
	//Parameterized Constructor 
	Node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->Right = NULL;
	}
};
Node* Add_Node(Node* R, Node* n)
{
	if (R == NULL)
	{
		R = n;
		cout<<endl << "Node Added In BST" << endl;
		return R;
	}
	else if (n->data < R->data)
	{
		R->left=Add_Node(R->left, n);
	}
	else
	{
		R->Right=Add_Node(R->Right, n);
	}
	return R;
}
void PreOrder(Node* R)
{
	if (R == NULL)
	{
		return;
	
	}
	cout << R->data<<"   ";
	PreOrder(R->left);
	PreOrder(R->Right);
}
void InOrder(Node* R)
{
	if (R == NULL)
	{
		return;

	}
	InOrder(R->left);
	cout << R->data << "   ";
	InOrder(R->Right);
}
void PostOrder(Node* R)
{
	if (R == NULL)
	{
		return;

	}
	PostOrder(R->left);
	PostOrder(R->Right);
	cout << R->data << "   ";
}
void Find_Minimum(Node* R)
{
	if (R == NULL)
	{
		cout << endl << "Tress is Empty" << endl;
		return;
	}
	Node* temp = R;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	cout << endl << "Minimum Value in BST is = " << temp->data << endl;
}
void Find_Maximum(Node* R)
{
	if (R == NULL)
	{
		cout << endl << "Tress is Empty" << endl;
		return;
	}
	Node* temp = R;
	while (temp->Right != NULL)
	{
		temp = temp->Right;
	}
	cout << endl << "Maximum Value in BST is = " << temp->data << endl;
}
//To Calculate the Height of Tree
int Height_of_BST(Node* R)
{
	if (R == NULL)
	{
		return -1;
	}
	int LeftHeight = Height_of_BST(R->left);
	int RightHeight = Height_of_BST(R->Right);
	if (LeftHeight > RightHeight)
	{
		return (LeftHeight + 1);
	}
	else
	{
		return(RightHeight + 1);
	}
}
//To Print the Tree in Breath First Search
void LevelOrderBreathFirstSearch(Node* r, int Level)
{
	if (r == NULL)
	{
		return;
	}
	else if (Level == 0)
	{
		cout << r->data << " ";
	}
	else
	{
		LevelOrderBreathFirstSearch(r->left, Level - 1);
		LevelOrderBreathFirstSearch(r->Right, Level - 1);
	}
}
void PrintLevelOrderBFS(Node* r)
{
	int height = Height_of_BST(r);
	for (int i = 0; i <= height; i++)
	{
		LevelOrderBreathFirstSearch(r, i);
	}
}
//Functions to Check that the Tree is a binary Search Tree or not
bool IsSubTreeLesser(Node* root, int Value)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data <= Value && IsSubTreeLesser(root->left, Value) && IsSubTreeLesser(root->Right, Value))
	{
		return true;
	}
	return false;
}
bool IsSubTreeGreater(Node* root, int Value)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data >= Value && IsSubTreeGreater(root->left, Value) && IsSubTreeGreater(root->Right, Value))
	{
		return true;
	}
	return false;
}
bool IsBinarySearchTree(Node* Root)
{
	if (Root == NULL)
	{
		return true;
	}
	if (IsSubTreeLesser(Root->left, Root->data) && IsSubTreeGreater(Root->Right, Root->data) && IsBinarySearchTree(Root->left) && IsBinarySearchTree(Root->Right))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//function to Delete a node
Node* Find_min(Node* Root)
{
	Node* temp = Root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}
Node* Delete_Node(Node* Root,int Data)
{
	if (Root==NULL)
	{
		return Root;
	}
	else if (Data < Root->data)
	{
		Root->left =Delete_Node (Root->left, Data);
	}
	else if (Data > Root->data)
	{
		Root->Right = Delete_Node(Root->Right, Data);
	}
	else
	{
	
		if (Root->left == NULL)
		{
			Node* temp = Root->Right;
			delete Root;
			return temp;
		}
		else if (Root->Right == NULL)
		{
			Node* temp = Root->left;
			delete Root;
			return temp;
		}
		else
		{
			Node*temp = Find_min(Root->Right);
			Root->data = temp->data;
			Root->Right=Delete_Node(Root->Right, temp->data);
		}
	}
	return Root;
}
int main()
{
	Node* Root = new Node();
	Root = NULL;
	string option;
	int d;
	cout << "Enter 1 to Add Node" << endl;
	cout << "Enter 2 to Print PreOrder BST" << endl;
	cout << "Enter 3 to Print InOrder BST" << endl;
	cout << "Enter 4 to Print PostOrder BST" << endl;
	cout << "Enter 5 to Find Minimum Value in BST" << endl;
	cout << "Enter 6 to Find Maximum Value in BST" << endl;
	cout << "Enter 7 to Find the Height Of BST" << endl;
	cout << "Enter 8 to Print in BFS(Breath First Sreach) / Level Order Search  " << endl;
	cout << "Enter 9 to Check that the Tree is a Binary Search Tree Or not" << endl;
	cout << "Enter 10 to Delete a Node from Binary Search Tree" << endl;
	cout << "Enter 0 to Exit" << endl;
	cout << endl << endl << "Enter Option = ";
	cin >> option;
	while (option != "0")
	{
		cout << endl;
		Node* n = new Node();
		if (option == "1")
		{
			cout << "Enter Value to Add in BSTree = ";
			cin >> d;
			n->data = d;
			Root=Add_Node(Root, n);
		}
		else if (option == "2")
		{
			cout <<"PreOrder BST = ";
			PreOrder(Root);
			cout << endl;
		}
		else if (option == "3")
		{
			cout << "InOrder BST = ";
			InOrder(Root);
			cout << endl;
		}
		else if (option == "4")
		{
			cout << "PostOrder BST = ";
			PostOrder(Root);
			cout << endl;
		}
		else if (option == "5")
		{
			Find_Minimum(Root);
		}
		else if (option == "6")
		{
			Find_Maximum(Root);
		}
		else if (option == "7")
		{
			cout << endl << "Height of BST is = " << Height_of_BST(Root) << endl;
		}
		else if (option == "8")
		{
			cout << endl << "BFS(Breath First Sreach) / Level Order Search = ";
				PrintLevelOrderBFS(Root);
				cout<< endl;
		}
		else if (option == "9")
		{
			bool check;
			check=IsBinarySearchTree(Root);
			if (check == true)
			{
				cout << endl << "It is a Binary Search Tree" << endl;
			}
			else
			{
				cout << endl << "It is not a Binary Search Tree" << endl;
			}
		}
		else if (option== "10")
		{
			int del;
			cout << endl << "Enter the Data Value to be Deleted = ";
			cin >> del;
			Delete_Node(Root, del);
		}
		else
		{
			cout << endl << "Invalid Option" << endl;
		}
		cout << endl <<"Enter Option = ";
		cin >> option;
	}
}