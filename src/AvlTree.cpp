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
    Node* node;		//���ڵ�
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

//�������������
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
        cout<<"��������"<<d<<endl;
        *pNode = new Node(d);
    }
    else if (d < (*pNode)->data)
    {
        _insert(&((*pNode)->left), d);
		if (_height((*pNode)->left) - _height((*pNode)->right) == 2)
		{
			if (d < (*pNode)->left->data)
			{
                cout<<"�����LL��ת"<<endl;
				*pNode = _llRotation(*pNode);
			}
			else
			{
                cout<<"�����LR��ת"<<endl;
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
                cout<<"�����RR��ת"<<endl;
				*pNode = _rrRotation(*pNode);
			}
			else
			{
                cout<<"�����RL��ת"<<endl;
				*pNode = _rlRotation(*pNode);
			}
		}
    }
	else
	{
		cout << "�����Ѿ�����" << endl;
		return ;
	}
	(*pNode)->height = _max(_height((*pNode)->left), _height((*pNode)->right)) + 1;
}

Node* AvlTree::_find(Node* pNode, int d)
{
    if (pNode == NULL)
    {
        cout<<"û���ҵ�����"<<d<<endl;
        return NULL;
    }
    else
    {
        if (pNode->data == d)
        {
            cout<<"�ҵ�����"<<d<<endl;
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

//����ɾ��������
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

//��ն����� 
void AvlTree::clear()
{
    cout<<"��ն�����"<<endl;
    if (node == NULL)
    {
        return ;
    }
    else
    {
        _clear(&node);
    }
}

//�ж϶������Ƿ�Ϊ�� 
bool AvlTree::empty()
{
    return node == NULL;
}

//�����ӡ������
void AvlTree::print()
{
    cout<<"���������������";
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

//��������d���Զ�����λ�� 
void AvlTree::insert(int d)
{
    _insert(&node, d);
}

//��������Ϊd�Ľڵ� 
Node* AvlTree::find(int d)
{
    cout<<"��������"<<d<<" ";
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
