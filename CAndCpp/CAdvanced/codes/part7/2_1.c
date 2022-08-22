#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkNode
{
    // 数据域
    int id;
    // 指针域
    struct LinkNode *next;
} LinkNode;

LinkNode *initLinkList()
{
    // 创建头结点指针并分配内存
    LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode));
    if (head == NULL)
    {
        return NULL;
    }

    head->id = -1;
    head->next = NULL;

    LinkNode *current = head;
    int data = -1;
    while (1)
    {
        printf("input data:\n");
        scanf("%d", &data);

        // 输入 -1 退出循环
        if (data == -1)
        {
            break;
        }

        // 新节点分配内存
        LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
        if (node == NULL)
        {
            break;
        }

        node->id = data;
        node->next = NULL;

        current->next = node;
        current = node;
    }
    return head;
}

void foreachLinklist(LinkNode *head)
{
    if (head == NULL)
    {
        return;
    }

    LinkNode *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->id);
        p = p->next;
    }
    printf("\n");
}

void insertLinklist(LinkNode *head, int val, int data)
{
    if (head == NULL)
    {
        return;
    }

    LinkNode *pre = head;
    LinkNode *current = pre->next;

    while (current != NULL)
    {
        if (current->id == val)
        {
            break;
        }
        pre = current;
        current = pre->next;
    }

    if (current == NULL)
    {
        printf("不存在值为 %d 该节点\n", val);
        return;
    }

    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    node->id = data;
    node->next = NULL;

    node->next = current;
    pre->next = node;
}

void removeLinklist(LinkNode *head, int val)
{
    if (head == NULL)
    {
        return;
    }

    LinkNode *pre = head;
    LinkNode *current = pre->next;

    while (current != NULL)
    {
        if (current->id == val)
        {
            break;
        }
        pre = current;
        current = pre->next;
    }

    if (current == NULL)
    {
        return;
    }

    pre->next = current->next;
    free(current);
}

void destroyLinklist(LinkNode *head)
{
    if (head == NULL)
    {
        return;
    }

    LinkNode *p = head;
    LinkNode *tmp = NULL;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;

        free(tmp);
        tmp = NULL;
    }

    head = NULL;
}

int main()
{
    LinkNode *head = initLinkList();

    foreachLinklist(head);
    insertLinklist(head, 4, 3);
    foreachLinklist(head);
    removeLinklist(head, 2);
    foreachLinklist(head);
    destroyLinklist(head);

    /*
        input data:
        1
        input data:
        2
        input data:
        4
        input data:
        5
        input data:
        -1
        1 2 4 5
        1 2 3 4 5
        1 3 4 5
    */

    return 0;
}