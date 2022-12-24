#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} node;

int n1, m1, n2, m2;

void push(node **head, int vertex)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->vertex = vertex;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    node *tempNode = *head;
    *head = newnode;
    newnode->next = tempNode;
}

int checkmember(node *head, int vertex)
{
    for (; head; head = head->next)
    {
        if (head->vertex == vertex)
            return 1;
    }
    return 0;
}

int checkIsomorphism(node *adjancencyList1[], node *adjacencyList2[], int map[])
{
    for (int i = 0; i < n1; i++)
    {
        for (node *p = adjancencyList1[i]; p; p = p->next)
        {
            if (!checkmember(adjacencyList2[map[i]], map[p->vertex]))
                return 0;
        }
    }
    return 1;
}

int generateFunc(node *adjancencyList1[], node *adjacencyList2[], int map[], int vertex = 0)
{
    if (vertex == n1)
        return checkIsomorphism(adjancencyList1, adjacencyList2, map);
    for (int i = 0; i < n1; i++)
    {
        int prevV = map[vertex], prevI = map[i];
        map[vertex] = map[i];
        map[i] = prevV;
        if (generateFunc(adjancencyList1, adjacencyList2, map, vertex + 1))
        {
            return 0;
        }
        map[vertex] = prevV;
        map[i] = prevI;
    }
    return 1;
}

int main()
{
    freopen("a.txt", "r", stdin);
    freopen("out-ac.txt", "w", stdout);
    scanf("%d %d", &n1, &m1);
    node *adjancencyList1[n1];
    int map[n1], rev_map[n1];
    for (int i = 0; i < n1; i++)
    {
        adjancencyList1[i] = NULL;
        map[i] = rev_map[i] = i;
    }
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        push(&(adjancencyList1[a]), b);
    }
    fclose(stdin);
    freopen("c.txt", "r", stdin);
    scanf("%d %d", &n2, &m2);
    node *adjacencyList2[n2];
    for (int i = 0; i < n2; i++)
    {
        adjacencyList2[i] = NULL;
    }
    for (int i = 0; i < m2; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        push(&(adjacencyList2[a]), b);
    }
    if (n1 != n2 || m1 != m2 || !generateFunc(adjancencyList1, adjacencyList2, map))
    {
        printf("Not Isomorphic, no bijection found.\n");
        return 0;
    }
    else
    {
        printf("Isomorphic.\n");
    }
    fclose(stdin);
    fclose(stdout);
}