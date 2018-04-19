#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#define TEST_HEADER printf("==========================%s===========================\n",__FUNCTION__)
void TestConstruct()
{
    TEST_HEADER;
    List l1;
    List l2(l1);
    l1.Print();
    l2.Print();

    l1.PushFront(5);
    l1.PushFront(4);
    l1.PushFront(3);
    l1.PushFront(2);
    l1.PushFront(1);
    l1.Print();
    l2 = l1;
    l2.Print();

}
void TestPush()
{
    TEST_HEADER;
    List l1;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l1.PushBack(4);
    l1.Print();

}

void TestPop()
{
    TEST_HEADER;

    List l1;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l1.Print();
    
    l1.PopBack();
    l1.Print();
}
int main()
{
    TestConstruct();
    TestPush();
    TestPop();

    system("pause");
    return 0;
}