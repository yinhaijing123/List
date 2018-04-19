#pragma once
#include<iostream>  
#include<stdlib.h>
#include<assert.h>

using namespace std;

typedef int DataType;

struct LinkNode                                        //链表基本单元0:节点(对外数据成员都是共有的,故直接用struct定义结构体)
{
    LinkNode(DataType data)
        :_data(data),
        _prev(NULL),
        _next(NULL)
    {}

    DataType _data;
    LinkNode *_prev;
    LinkNode *_next;
};

class List                                         //带头节点的双向循环链表(完成增删查改等功能)      
{
public:

    typedef LinkNode Node;

    List();
    List(const List& l);
    List& operator=(const List &l);
    ~List();

    void PushBack(DataType data);
    void PushFront(DataType data);
    void PopBack();
    void PopFront();
    Node* Find(DataType to_find);
    void Insert(Node *pos, DataType data);
    void Erase(Node *pos);
    void Clear();                                     //将链表置为空链表
    void Print();

private:
    Node *_head;
};
