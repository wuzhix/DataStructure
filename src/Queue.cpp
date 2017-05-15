#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T* pData;
    int max_len;
    int cur_len;
public:
    Queue();
    ~Queue();
    void clear();
    bool empty();
    int size();
    void print();
    void push(T data);
    T pop();
};

template <class T>
Queue<T>::Queue():pData(NULL),max_len(1),cur_len(0)
{
}

template <class T>
Queue<T>::~Queue()
{
    clear();
}

//清空队列
template <class T>
void Queue<T>::clear()
{
    cout<<"清空队列"<<endl;
    max_len = 1;
    cur_len = 0;
    if (pData != NULL)
    {
        delete pData;
        pData = NULL;
    }
}

//判断队列是否为空 
template <class T>
bool Queue<T>::empty()
{
    return cur_len == 0;
}

//返回队列长度
template <class T> 
int Queue<T>::size()
{
    cout<<"队列长度"<<cur_len<<endl;
    return cur_len;
}

//从队列头到队列尾打印数据
template <class T>
void Queue<T>::print()
{
    cout<<"输出队列：";
    if (cur_len == 0)
    {
        cout<<endl;
        return ;
    }
    for (int i = 0; i < cur_len; ++i)
    {
        cout << pData[i] << " ";
    }
    cout<<endl;
}

//数据入队列
template <class T>
void Queue<T>::push(T d)
{
    cout<<"入队列数据"<<d<<" ";
    if (cur_len == 0 || cur_len == max_len)
    {
        max_len = max_len * 2;
        pData = static_cast<T*>(realloc(pData, max_len * sizeof(T)));
    }
    pData[cur_len++] = d;
    cout<<endl;
}

//数据出队列
template <class T>
T Queue<T>::pop()
{
    cout<<"出队列数据 ";
    if (cur_len == 0)
    {
        cout << "队列空不能出队列" << endl;
        return T(0);
    }
    else
    {
        T d = pData[0];
        cout<<d<<endl;
		for (int i = 0; i < cur_len; ++i)
		{
			pData[i] = pData[i+1];
		}
		--cur_len;
        return d;
    }
}

int main()
{
    Queue<int> Queue;
    
    Queue.pop();
    Queue.size();
    Queue.print();
    
    Queue.push(5);
    Queue.size();
    Queue.print();
    
    Queue.clear();
    Queue.size();
    Queue.print();
    
    Queue.push(1);
    Queue.size();
    Queue.print();
    Queue.pop();
    Queue.size();
    Queue.print();
    
    Queue.push(2);
    Queue.push(4);
    Queue.size();
    Queue.print();
    Queue.pop();
    Queue.size();
    Queue.print();
    
    Queue.push(6);
    Queue.push(8);
    Queue.size();
    Queue.print();
    Queue.pop();
    Queue.size();
    Queue.print();
    
    
    system("pause");
    return 0;
}
