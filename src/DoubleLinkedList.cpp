#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* previous;
    Node* next;
    Node(int d){data=d;previous=NULL;next=NULL;}
};

class NodeList
{
private:
    Node* node;
public:
    NodeList();
    ~NodeList();
    void clear();
    bool empty();
    int size();
    void print();
    int get(int pos);
    void insert(int pos, int d);
    int remove(int pos);
    void push_front(int d);
    void push_back(int d);
};

NodeList::NodeList():node(NULL)
{
}

NodeList::~NodeList()
{
    clear();
}

//������� 
void NodeList::clear()
{
    cout<<"�������"<<endl;
    if (node == NULL)
    {
        return ;
    }
    else
    {
        //����Ҫ��node����NULL������Ҫȡָ�� 
        Node** p = &(node->next);
        while (*p != NULL && *p != node)
        {
            Node* pNext = (*p)->next;
            delete *p;
            *p = NULL;
            *p = pNext;
        }
        delete node;
        node = NULL;
    }
}

//�ж������Ƿ�Ϊ�� 
bool NodeList::empty()
{
    return node == NULL;
}

//���������� 
int NodeList::size()
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int count = 1;
        Node* p = node;
        while(p->next != NULL && p->next != node)
        {
            ++count;
            p = p->next;
        }
        return count;
    }
}

//��ӡ�������� 
void NodeList::print()
{
    cout<<"�������";
    if (node == NULL)
    {
        return ;
    }
    else
    {
        Node* p = node;
        do
        {
            cout<<p->data<<" ";
            p = p->next;
        }while(p != NULL && p != node);
    }
    cout<<endl;
}

//��ȡ����λ��Ϊpos������ 
int NodeList::get(int pos)
{
    cout<<"��ȡλ��Ϊ"<<pos<<"������ ";
    if (pos < 1)
    {
        cout<<"posֵ�Ƿ�"<<endl;
        return 0;
    }
    if (node == NULL)
    {
        cout<<"����Ϊ��"<<endl;
        return 0;
    }
    int index = 0;
    Node* p = node;
    do
    {
        ++index;
        if (index == pos)
        {
            break;
        }
        else
        {
            p = p->next;
        }
    }while(p != NULL && p != node);
    if (index < pos)
    {
        cout<<"�����Ȳ���"<<pos<<endl;
        return 0;
    }
    cout<<"λ��Ϊ"<<pos<<"������Ϊ��"<<p->data<<endl;
    return p->data;    
}

//λ��Ϊpos������ڵ�������� 
void NodeList::insert(int pos, int d)
{
    cout<<"λ��Ϊ"<<pos<<"��������"<<d<<" ";
    if (pos < 1)
    {
        cout<<"posֵ�Ƿ�"<<endl;
        return ;
    }
    if (node == NULL)
    {
        cout<<"����Ϊ��"<<endl;
        return ;
    }
    int size = this->size();
    if (size < pos)
    {
        cout<<"�����Ȳ���"<<pos<<endl;
        return ;
    }
    else
    {
        if (size == 1)
        {
            Node* pNode = new Node(d);
            pNode->previous = node;
            pNode->next = node;
            node->next = pNode;
            node->previous = pNode;
            node = pNode;
        }
        else
        {
            Node* current = node;
            int index = 0;
            while (current != NULL)
            {
                ++index;
                if (index == pos)
                {
                    break;
                }
                else
                {
                    current = current->next;
                }
            }
            Node* pNode = new Node(d);
            pNode->previous = current->previous;
            pNode->next = current;
            current->previous->next = pNode;
            current->previous = pNode;
        }
    }
}

//�Ƴ�λ��Ϊpos������ڵ�
int NodeList::remove(int pos)
{
    cout<<"�Ƴ�λ��Ϊ"<<pos<<"������ ";
    if (pos < 1)
    {
        cout<<"posֵ�Ƿ�"<<endl;
        return 0;
    }
    if (node == NULL)
    {
        cout<<"����Ϊ��"<<endl;
        return 0;
    }
    int size = this->size();
    if (size < pos)
    {
        cout<<"�����Ȳ���"<<pos<<endl;
        return 0;
    }
    else
    {
        int ret = 0;
        if (size == 1)
        {
            ret = node->data;
            delete node;
            node = NULL;
        }
        else
        {
            Node* current = node;
            int index = 0;
            while (current != NULL)
            {
                ++index;
                if (index == pos)
                {
                    break;
                }
                else
                {
                    current = current->next;
                }
            }            
            current->previous->next = current->next;
            current->next->previous = current->previous;
            ret = current->data;
            delete current;
            current = NULL;
        }
        if (size == 1)
        {
            node->previous = node->next = NULL;
        }
        return ret;
    }
}

//����ͷ�������� 
void NodeList::push_front(int d)
{
    Node* pNode = new Node(d);
    if (node == NULL)
    {
        node = pNode;
        return ;
    }
    else
    {
        int size = this->size();
        if (size == 1)
        {
            pNode->next = node;
            pNode->previous = node;
            node->next = pNode;
            node->previous = pNode;
        }
        else
        {
            pNode->next = node;
            pNode->previous = node->previous;
            node->previous->next= pNode;
            node->previous = pNode;
        }
        node = pNode;
        cout<<"����ͷ����"<<pNode->data<<endl;
        return ;
    }
}

//����β�������� 
void NodeList::push_back(int d)
{
    Node* pNode = new Node(d);
    if (node == NULL)
    {
        node = pNode;
        return ;
    }
    else
    {
        int size = this->size();
        if (size == 1)
        {
            pNode->next = node;
            pNode->previous = node;
            node->next = pNode;
            node->previous = pNode;
        }
        else
        {
            pNode->next = node;
            pNode->previous = node->previous;
            node->previous->next= pNode;
            node->previous = pNode;
        }
        cout<<"����ͷ����"<<pNode->data<<endl;
        return ;
    }
}

int main()
{
    NodeList* pNodeList = new NodeList;
    bool empty = pNodeList->empty();
    int size = pNodeList->size();
    
    pNodeList->push_back(3);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->insert(1, 7);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->push_front(5);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->push_front(8);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->remove(2);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->clear();
    pNodeList->print();
    pNodeList->get(2);
    
    system("pause");
    return 0;
}
