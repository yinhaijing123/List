#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
List::List()
    :_head(new Node(DataType()))                //创建一个匿名对象初始化_data;(头节点数据不具有意义)
{
    _head->_next = _head;
    _head->_prev = _head;

}

List::List(const List& l)
    :_head(new Node(DataType()))
{
    _head->_next = _head;
    _head->_prev = _head;                       //首先，先构造一个空链表

    Node *cur = l._head->_next;
    while (cur != l._head)
    {
        PushBack(cur->_data);
        cur = cur->_next;
    }
}

List& List::operator=(const List &l)
{
    if (_head != l._head)
    {
        Clear();
        Node *cur = l._head->_next;
        while (cur != l._head)
        {
            PushBack(cur->_data);
            cur = cur->_next;
        }
    }
    return *this;
}

List::~List()
{
    Clear();
    delete _head;
}

void List::Clear()
{
    assert(_head);
    Node* cur = _head->_next;
    while (cur != _head)
    {
        Node* to_delete = cur;
        cur = cur->_next;
        delete to_delete;
    }
}

void List::PushBack(DataType data)
{
    assert(_head);

    Node *new_node = new Node(data);
    Node *prev = _head->_prev;

    prev->_next = new_node;
    new_node->_prev = prev;
    new_node->_next = _head;
    _head->_prev = new_node;
}

void List::PushFront(DataType data)
{
    assert(_head);

    Node *new_node = new Node(data);
    Node *next = _head->_next;                                

    _head->_next = new_node;
    new_node->_prev = _head;
    new_node->_next = next;
    next->_prev = new_node;
}

void List::PopBack()                   
{
    assert(_head);

    if (_head->_next == _head)
    {
        return;
    }
    Node *to_delete = _head->_prev;
    to_delete->_prev->_next = _head;
    _head->_prev = to_delete->_prev;
}

void List::PopFront()
{
    assert(_head);
    if (_head->_next == _head)           //空链表
    {
        return;
    }
    Node* to_delete = _head->_next;      //一个或者多个节点的链表
    _head->_next = to_delete->_next;
    to_delete->_next->_prev = _head;
}

LinkNode* List::Find(DataType to_find)
{
    assert(_head);
    if (_head->_next == _head)
    {
        return NULL;
    }
    Node* cur = _head->_next;
    while (cur != _head)
    {
        if (cur->_data == to_find)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}

void List::Insert(Node *pos, DataType data)
{
    assert(_head);

    Node *cur = _head->_next;
    if (pos == _head)                        //pos是头节点，在头节点前插入数据
    {
        Node *new_node = new Node(data);
        Node *prev = _head->_prev;
        prev->_next = new_node;
        new_node->_prev = prev;
        new_node->_next = _head;
        _head->_prev = new_node;
    }

    while(cur!=_head)
    {
        if (cur == pos)
        {
            Node* new_node = new Node(data);
            Node *prev = cur->_prev;
            prev->_next = new_node;
            new_node->_prev = prev;
            new_node->_next = cur;
            cur->_prev = new_node;
        }
        cur = cur->_next;
    }

    //if (pos == _head)                     //在头节点后插入某数据
    //{
    //    Node *new_node = new Node(data);
    //    _head->_next->_prev = new_node;
    //    new_node->_next = _head->_next;
    //    _head->_next = new_node;
    //    new_node->_prev = _head;
    //}

    //while (cur != _head)
    //{
    //    if (cur == pos)
    //    {
    //        Node *new_node = new Node(data);

    //        cur->_next->_prev = new_node;
    //        new_node->_next = cur->_next;
    //        cur->_next = new_node;
    //        new_node->_prev = cur;
    //    }
    //    cur = cur->_next;
    //}
    
}

void List::Erase(Node *pos)
{
    assert(_head);
    if (_head->_next == _head)
    {
        return;
    }
    Node *cur = _head->_next;
    while (cur != _head)
    {
        if (cur == pos)
        {
            cur->_prev->_next = cur->_next;
            cur->_next->_prev = cur->_prev;
            return;
        }
        cur = cur->_next;
    }
    return;
}

void List::Print()
{
    assert(_head);
    Node *cur = _head->_next;
    while (cur != _head)
    {
        cout << cur->_data << ' ';
        cur = cur->_next;
    }
    cout << endl;
}