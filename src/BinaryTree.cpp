#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
	Node* right;
    Node(int d){data=d;left=right=NULL;}
};

class BinaryTree
{
private:
    Node* node;		//根节点
public:
    BinaryTree();
    ~BinaryTree();
    void clear();    
    void print();
    bool empty();
    void insert(int d);
    void remove(int d);
	Node* find(int d);
private:
	void _print(Node* pNode);
	void _clear(Node** pNode);
	void _insert(Node** pNode, int d);
	void _remove(Node** pNode, int d);
	Node* _find(Node* pNode, int d);
	
};

BinaryTree::BinaryTree():node(NULL)
{
}

BinaryTree::~BinaryTree()
{
    clear();
}

//中序输出二叉树
void BinaryTree::_print(Node* pNode)
{
	if (pNode != NULL)
	{
		_print(pNode->left);
		cout<<pNode->data<<" ";
		_print(pNode->right);
	}
}

void BinaryTree::_insert(Node** pNode, int d)
{
    if (*pNode == NULL)
    {
        cout<<"插入数据"<<d<<endl;
        *pNode = new Node(d);
    }
    else if (d < (*pNode)->data)
    {
        _insert(&((*pNode)->left), d);
    }
    else
    {
        _insert(&((*pNode)->right), d);
    }
}

void BinaryTree::_remove(Node** pNode, int d)
{
    if (*pNode == NULL)
    {
        cout<<"未找到移除的数据"<<d<<endl;
        return ;
    }
    else
    {
        if ((*pNode)->data == d)
        {
            cout<<"移除数据"<<d<<"的节点以及子节点"<<endl;
            _clear(pNode);
            return ;
        }
        else if (d < (*pNode)->data)
        {
            _remove(&((*pNode)->left), d);
        }
        else
        {
            _remove(&((*pNode)->right), d);
        }
    }
}

Node* BinaryTree::_find(Node* pNode, int d)
{
    if (pNode == NULL)
    {
        cout<<"没有找到数据"<<d<<endl;
        return NULL;
    }
    else
    {
        if (pNode->data == d)
        {
            cout<<"找到数据"<<d<<endl;
            return pNode;
        }
        else if (d < pNode->data)
        {
            return _find(pNode->left, d);
        }
        else
        {
            return _find(pNode->right, d);
        }
    }
}

//后序删除二叉树
void BinaryTree::_clear(Node** pNode)
{
	if (*pNode != NULL)
	{
		_clear(&(*pNode)->left);
		_clear(&(*pNode)->right);
		delete *pNode;
		*pNode = NULL;
	}
}

//清空二叉树 
void BinaryTree::clear()
{
    cout<<"清空二叉树"<<endl;
    if (node == NULL)
    {
        return ;
    }
    else
    {
        _clear(&node);
    }
}

//判断二叉树是否为空 
bool BinaryTree::empty()
{
    return node == NULL;
}

//中序打印二叉树
void BinaryTree::print()
{
    cout<<"中序输出二叉树：";
    if (node == NULL)
    {
        return ;
    }
    else
    {
        _print(node);
    }
    cout<<endl;
}

//插入数据d，自动查找位置 
void BinaryTree::insert(int d)
{
    _insert(&node, d);
}

//删除数据为d的节点
void BinaryTree::remove(int d)
{
    cout<<"移除数据"<<d<<" ";
    _remove(&node, d);
}

//查找数据为d的节点 
Node* BinaryTree::find(int d)
{
    cout<<"查找数据"<<d<<" ";
    return _find(node, d);
}

int main()
{
    BinaryTree* tree = new BinaryTree;
    bool empty = tree->empty();
    
    int d[] = {100,50,150,80,60,70,40,20,10,30,130,140,120,110,180,200,190,160,170,90};
    
    for(int i = 0; i < 20; ++i)
    {
        tree->insert(d[i]);
        tree->print();
    }
    tree->find(30);
    tree->find(35);
    tree->remove(80);
    tree->print();
    system("pause");
    return 0;
}
