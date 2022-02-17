// NOT MY CODE
#include <stdio.h>
#define max 20
int g[max][max], v1[max], v2[max], q[max], s[max], front = -1, rear = -1, top = -1, count;
void enqueue(int val)
{
    rear++;
    q[rear] = val;
}
int dequeue()
{
    front++;
    return q[front];
}
void push(int val)
{
    top++;
    s[top] = val;
}
int pop()
{
    int temp = s[top];
    top--;
    return s[top];
}
void bfs(int start)
{
    int i;
    enqueue(start);
    v1[start] = 1;
    while (rear != front)
    {
        start = dequeue();
        printf("%c\t", (start + 65));
        for (i = 0; i < count; i++)
        {
            if (g[start][i] == 1 && v1[i] == 0)
            {
                enqueue(i);
                v1[i] = 1;
            }
        }
    }
}
void dfs(int start)
{
    v2[start] = 1;
    printf("%c\t", (start + 65));
    push(start);
    int i;
    for (i = 0; i < count; i++)
    {
        if (g[start][i] == 1 && v2[i] != 1)
            dfs(i);
    }
    start = pop();
}
void main()
{
    int i, j, choice;
    printf("Enter number of vertices(less than 20): ");
    scanf("%d", &count);
    printf("Enter the adjacency matrix of graph:\n");
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count; j++)
            scanf("%d", &g[i][j]);
    }
    printf("Adjancency Matrix:\n");
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count; j++)
            printf("%d\t", g[i][j]);
        printf("\n");
    }
    printf("MENU\n1.Breadth First Search\n2.Depth First Search\n3.Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("BFS:\t");
            bfs(0);
            break;
        case 2:
            printf("DFS:\t");
            dfs(0);
            break;
        }
    } while (choice < 3);
}