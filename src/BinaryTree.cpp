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
    Node* node;		//���ڵ�
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

//�������������
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
        cout<<"��������"<<d<<endl;
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
        cout<<"δ�ҵ��Ƴ�������"<<d<<endl;
        return ;
    }
    else
    {
        if ((*pNode)->data == d)
        {
            cout<<"�Ƴ�����"<<d<<"�Ľڵ��Լ��ӽڵ�"<<endl;
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

//��ն����� 
void BinaryTree::clear()
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
bool BinaryTree::empty()
{
    return node == NULL;
}

//�����ӡ������
void BinaryTree::print()
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
void BinaryTree::insert(int d)
{
    _insert(&node, d);
}

//ɾ������Ϊd�Ľڵ�
void BinaryTree::remove(int d)
{
    cout<<"�Ƴ�����"<<d<<" ";
    _remove(&node, d);
}

//��������Ϊd�Ľڵ� 
Node* BinaryTree::find(int d)
{
    cout<<"��������"<<d<<" ";
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
