#include <iostream>

using namespace std;


typedef struct binaryTreeNode{
	char data;
	binaryTreeNode * lchild;
	binaryTreeNode * rchild;


}BiTNode;
static int i = 0;
BiTNode* createtree() //preorder: root->lchild->rchild
{
	char a[100] = {'s','e','a','0','c','0','0','r','h','0','0','0','x','0','0'};

	BiTNode* tree;
	if(a[i] == '0')
	{
		tree = NULL;
		i++;
	}
	else
	{
	
		tree = new BiTNode;
		tree->data = a[i++];
		tree->lchild = createtree();
		tree->rchild = createtree();
	}
	
	return tree;
}
int visit(BiTNode *Tree)  //preorder: root->lchild->rchild
{  
    if(Tree == NULL){   
        return 0;  
    }  
    cout<<Tree->data<<endl;
    if(Tree->lchild) visit(Tree->lchild);  
    if(Tree->rchild) visit(Tree->rchild);  
 
    return 0;  
}  

void PreOrder(BiTNode *Tree)
{  
    if(Tree)
	{  
		cout<<Tree->data<<endl;
        PreOrder(Tree->lchild);  
        PreOrder(Tree->rchild);  
    }  
}  
  
void midOrder(BiTNode *Tree)
{  
    if(Tree){  
        midOrder(Tree->lchild);  
		cout<<Tree->data<<endl;
        midOrder(Tree->rchild);  
    }  
}  
void lastOrder(BiTNode *Tree)
{  
    if(Tree){  
        lastOrder(Tree->lchild);  
        lastOrder(Tree->rchild);  
		cout<<Tree->data<<endl;
	}  
}  

int main(void)
{
	BiTNode* root;

	root = createtree();
	//int a = visit(root);
	PreOrder(root);
	midOrder(root);
	lastOrder(root);
	return 1;
}
