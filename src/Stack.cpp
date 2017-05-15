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

//清空栈 
template <class T>
void Stack<T>::clear()
{
    cout<<"清空栈"<<endl;
    max_len = 1;
    cur_len = 0;
    if (pData != NULL)
    {
        delete pData;
        pData = NULL;
    }
}

//判断栈是否为空 
template <class T>
bool Stack<T>::empty()
{
    return cur_len == 0;
}

//返回栈长度
template <class T> 
int Stack<T>::size()
{
    cout<<"栈长度"<<cur_len<<endl;
    return cur_len;
}

//从栈顶到栈底打印数据 
template <class T>
void Stack<T>::print()
{
    cout<<"输出栈：";
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

//数据压栈 
template <class T>
void Stack<T>::push(T d)
{
    cout<<"入栈数据"<<d<<" ";
    if (cur_len == 0 || cur_len == max_len)
    {
        max_len = max_len * 2;
        pData = static_cast<T*>(realloc(pData, max_len * sizeof(T)));
    }
    pData[cur_len++] = d;
    cout<<endl;
}

//数据出栈 
template <class T>
T Stack<T>::pop()
{
    cout<<"出栈数据 ";
    if (cur_len == 0)
    {
        cout << "栈空不能出栈" << endl;
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
