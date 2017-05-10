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

//清空链表 
void NodeList::clear()
{
    cout<<"清空链表"<<endl;
    if (node == NULL)
    {
        return ;
    }
    else
    {
        //这里要讲node链表赋NULL，所以要取指针 
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

//判断链表是否为空 
bool NodeList::empty()
{
    return node == NULL;
}

//返回链表长度 
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

//打印链表数据 
void NodeList::print()
{
    cout<<"输出链表：";
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

//获取链表位置为pos的数据 
int NodeList::get(int pos)
{
    cout<<"获取位置为"<<pos<<"的数据 ";
    if (pos < 1)
    {
        cout<<"pos值非法"<<endl;
        return 0;
    }
    if (node == NULL)
    {
        cout<<"链表为空"<<endl;
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
        cout<<"链表长度不足"<<pos<<endl;
        return 0;
    }
    cout<<"位置为"<<pos<<"的数据为："<<p->data<<endl;
    return p->data;    
}

//位置为pos的链表节点插入数据 
void NodeList::insert(int pos, int d)
{
    cout<<"位置为"<<pos<<"插入数据"<<d<<" ";
    if (pos < 1)
    {
        cout<<"pos值非法"<<endl;
        return ;
    }
    if (node == NULL)
    {
        cout<<"链表为空"<<endl;
        return ;
    }
    int size = this->size();
    if (size < pos)
    {
        cout<<"链表长度不足"<<pos<<endl;
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

//移除位置为pos的链表节点
int NodeList::remove(int pos)
{
    cout<<"移除位置为"<<pos<<"的数据 ";
    if (pos < 1)
    {
        cout<<"pos值非法"<<endl;
        return 0;
    }
    if (node == NULL)
    {
        cout<<"链表为空"<<endl;
        return 0;
    }
    int size = this->size();
    if (size < pos)
    {
        cout<<"链表长度不足"<<pos<<endl;
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

//链表头插入数据 
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
        cout<<"链表头插入"<<pNode->data<<endl;
        return ;
    }
}

//链表尾插入数据 
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
        cout<<"链表头插入"<<pNode->data<<endl;
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
