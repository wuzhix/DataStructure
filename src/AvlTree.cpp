#include <iostream>

using namespace std;

struct Node
{
    int data;
	int height;
    Node* left;
	Node* right;
    Node(int d){data=d;height=0;left=right=NULL;}
};

class AvlTree
{
private:
    Node* node;		//根节点
public:
    AvlTree();
    ~AvlTree();
	int height();
    void clear();    
    void print();
    bool empty();
    void insert(int d);
	Node* find(int d);
private:
	int _height(Node* pNode);
	void _print(Node* pNode);
	void _clear(Node** pNode);
	void _insert(Node** pNode, int d);
	Node* _find(Node* pNode, int d);
	Node* _llRotation(Node* pNode);
	Node* _rrRotation(Node* pNode);
	Node* _lrRotation(Node* pNode);
	Node* _rlRotation(Node* pNode);
	int _max(int a, int b);
	
};

AvlTree::AvlTree():node(NULL)
{
}

AvlTree::~AvlTree()
{
    clear();
}

int AvlTree::_height(Node* pNode)
{
	if (pNode != NULL)
	{
		return pNode->height;
	}
	return 0;
}

//中序输出二叉树
void AvlTree::_print(Node* pNode)
{
	if (pNode != NULL)
	{
		_print(pNode->left);
		cout<<pNode->data<<" ";
		_print(pNode->right);
	}
}

void AvlTree::_insert(Node** pNode, int d)
{
    if (*pNode == NULL)
    {
        cout<<"插入数据"<<d<<endl;
        *pNode = new Node(d);
    }
    else if (d < (*pNode)->data)
    {
        _insert(&((*pNode)->left), d);
		if (_height((*pNode)->left) - _height((*pNode)->right) == 2)
		{
			if (d < (*pNode)->left->data)
			{
                cout<<"插入后LL旋转"<<endl;
				*pNode = _llRotation(*pNode);
			}
			else
			{
                cout<<"插入后LR旋转"<<endl;
				*pNode = _lrRotation(*pNode);
			}
		}
    }
    else if (d > (*pNode)->data)
    {
        _insert(&((*pNode)->right), d);
		if (_height((*pNode)->right) - _height((*pNode)->left) == 2)
		{
			if (d > (*pNode)->right->data)
			{
                cout<<"插入后RR旋转"<<endl;
				*pNode = _rrRotation(*pNode);
			}
			else
			{
                cout<<"插入后RL旋转"<<endl;
				*pNode = _rlRotation(*pNode);
			}
		}
    }
	else
	{
		cout << "数据已经存在" << endl;
		return ;
	}
	(*pNode)->height = _max(_height((*pNode)->left), _height((*pNode)->right)) + 1;
}

Node* AvlTree::_find(Node* pNode, int d)
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
void AvlTree::_clear(Node** pNode)
{
	if (*pNode != NULL)
	{
		_clear(&(*pNode)->left);
		_clear(&(*pNode)->right);
		delete *pNode;
		*pNode = NULL;
	}
}

int AvlTree::_max(int a, int b)
{
	return a > b ? a : b;
}

Node* AvlTree::_llRotation(Node* pNode)
{
	Node* n = NULL;
	n = pNode->left;
	pNode->left = n->right;
	n->right = pNode;
	
	pNode->height = _max(_height(pNode->left), _height(pNode->right)) + 1;
	n->height = _max(_height(n->left), pNode->height) + 1;
	
	return n;
}

Node* AvlTree::_rrRotation(Node* pNode)
{
	Node* n = NULL;
	n = pNode->right;
	pNode->right = n->left;
	n->left = pNode;
	
	pNode->height = _max(_height(pNode->left), _height(pNode->right)) + 1;
	n->height = _max(_height(n->right), pNode->height) + 1;
	
	return n;
}

Node* AvlTree::_lrRotation(Node* pNode)
{
	pNode->left = _rrRotation(pNode->left);
	
	return _llRotation(pNode);
}

Node* AvlTree::_rlRotation(Node* pNode)
{
	pNode->right = _llRotation(pNode->right);
	
	return _rrRotation(pNode);
}

int AvlTree::height()
{
	return _height(node);
}

//清空二叉树 
void AvlTree::clear()
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
bool AvlTree::empty()
{
    return node == NULL;
}

//中序打印二叉树
void AvlTree::print()
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
void AvlTree::insert(int d)
{
    _insert(&node, d);
}

//查找数据为d的节点 
Node* AvlTree::find(int d)
{
    cout<<"查找数据"<<d<<" ";
    return _find(node, d);
}

int main()
{
    AvlTree* tree = new AvlTree;
    bool empty = tree->empty();
    
    int d[] = {100,50,150,80,60,70,40,20,10,30,130,140,120,110,180,200,190,160,170,90};
    
    for(int i = 0; i < 20; ++i)
    {
        tree->insert(d[i]);
    }
    tree->find(30);
    tree->find(35);
    tree->print();
    system("pause");
    return 0;
}
