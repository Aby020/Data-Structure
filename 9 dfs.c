#include<stdio.h>
#define max 100

int visited[max] = {0};
int graph[max][max];
char nodes[max];
int stack[max];
int n, i, j, e, start, top = -1, count = 0;

void push(int x)
{
    if (top == max - 1)
    {
        printf("Stack is full..\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty..\n");
    }
    else
    {
        top--;
    }
}

void dfs(int z)
{
    visited[z] = 1;
    push(z);
    printf("\nTraversal order is = ");
    while (top != -1)
    {
        int remove = stack[top];
        pop();
        printf("%c -> ", nodes[remove]);  

        for (i = 0; i < n; i++)
        {
            if (graph[remove][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                push(i);
            }
        }
    }
}

void starting()
{
    printf("Enter the starting node (letter): ");
    char start_node;
    scanf(" %c", &start_node);  // The space before %c is to consume any extra whitespace character.
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (start_node == nodes[i])
        {
            count += 1;
            dfs(i);
            break;
        }
    }
}

int main()
{
    printf("\n\t\t<<<<<< DFS TRAVERSING >>>>>>\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the node values (letters):\n");
    for (i = 0; i < n; i++)
    {
        printf("Node %d: ", i + 1);
        scanf(" %c", &nodes[i]);  // Reading a character
    }

    printf("Answer the following questions..\n\n");
    printf("Enter 1: if there is an edge between nodes\n");
    printf("Enter 0: if there is no edge between nodes\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("Edge between %c and %c: ", nodes[i], nodes[j]);
            scanf("%d", &e);
            if (e == 1)
            {
                graph[i][j] = graph[j][i] = 1;
            }
            else
            {
                graph[i][j] = graph[j][i] = 0;
            }
        }
    }

    starting();
    while (count == 0)
    {
        if (count == 0)
        {
            printf("Please enter a valid node value...\n");
        }
        starting();
    }

    return 0;
}

