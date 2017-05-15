#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    T* pData;
    int max_len;
    int cur_len;
public:
    Stack();
    ~Stack();
    void clear();
    bool empty();
    int size();
    void print();
    void push(T data);
    T pop();
};

template <class T>
Stack<T>::Stack():pData(NULL),max_len(1),cur_len(0)
{
}

template <class T>
Stack<T>::~Stack()
{
    clear();
}

//���ջ 
template <class T>
void Stack<T>::clear()
{
    cout<<"���ջ"<<endl;
    max_len = 1;
    cur_len = 0;
    if (pData != NULL)
    {
        delete pData;
        pData = NULL;
    }
}

//�ж�ջ�Ƿ�Ϊ�� 
template <class T>
bool Stack<T>::empty()
{
    return cur_len == 0;
}

//����ջ����
template <class T> 
int Stack<T>::size()
{
    cout<<"ջ����"<<cur_len<<endl;
    return cur_len;
}

//��ջ����ջ�״�ӡ���� 
template <class T>
void Stack<T>::print()
{
    cout<<"���ջ��";
    if (cur_len == 0)
    {
        cout<<endl;
        return ;
    }
    for (int i = cur_len - 1; i >= 0; --i)
    {
        cout << pData[i] << " ";
    }
    cout<<endl;
}

//����ѹջ 
template <class T>
void Stack<T>::push(T d)
{
    cout<<"��ջ����"<<d<<" ";
    if (cur_len == 0 || cur_len == max_len)
    {
        max_len = max_len * 2;
        pData = static_cast<T*>(realloc(pData, max_len * sizeof(T)));
    }
    pData[cur_len++] = d;
    cout<<endl;
}

//���ݳ�ջ 
template <class T>
T Stack<T>::pop()
{
    cout<<"��ջ���� ";
    if (cur_len == 0)
    {
        cout << "ջ�ղ��ܳ�ջ" << endl;
        return T(0);
    }
    else
    {
        T d = pData[--cur_len];
        cout<<d<<endl;
        return d;
    }
}

int main()
{
    Stack<int> stack;
    
    stack.pop();
    stack.size();
    stack.print();
    
    stack.push(5);
    stack.size();
    stack.print();
    
    stack.clear();
    stack.size();
    stack.print();
    
    stack.push(1);
    stack.push(2);
    stack.push(4);
    stack.size();
    stack.print();
    stack.pop();
    stack.size();
    stack.print();
    
    system("pause");
    return 0;
}
