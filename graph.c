#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node
{
    int data;
    int status;
    struct node *next, *point;
} node;

typedef struct topsort
{
    int n;
    struct topsort *next;
} topsort;

int d[SIZE], f[SIZE], time1;
node *q[SIZE];
int front = 0, rear = 0;

node *g = NULL;
topsort *tsort = NULL;

void addvertex(int n)
{
    node *t = (node *)malloc(sizeof(node));
    t->data = n;
    t->point = NULL;
    t->next = g;
    t->status = 0;
    g = t;
}

node *find(int n)
{
    node *t = g;
    while (t != NULL && t->data != n)
        t = t->next;
    return t;
}

void addedge(int u, int v)
{
    node *v1 = find(u);
    node *v2 = find(v);

    node *t = (node *)malloc(sizeof(node));
    t->next = v1->point;
    v1->point = t;
    t->point = v2;
}

void printgraph()
{
    node *t1, *t2, *t3;

    printf("\nVertex\tEdge List\n");
    t1 = g;

    while (t1 != NULL)
    {
        printf("\n%d -->\t", t1->data);
        t2 = t1->point;
        while (t2 != NULL)
        {
            t3 = t2->point;
            printf("%d ", t3->data);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    printf("\n");
}

void topsorting(int n)
{
    topsort *z = (topsort *)malloc(sizeof(topsort));
    z->n = n;
    z->next = tsort;
    tsort = z;
}

void topsortout()
{
    while (tsort != NULL)
    {
        printf("%d ", tsort->n);
        tsort = tsort->next;
    }
}

void dfs_visit(node *u)
{
    node *t, *t1;

    u->status = 1;
    printf("%d ", u->data);
    time1++;

    t = u->point;
    while (t != NULL)
    {
        t1 = t->point;
        if (t1->status == 0)
        {
            dfs_visit(t1);
        }
        t = t->next;
    }

    time1++;
    f[u->data] = time1;
    topsorting(u->data);
}

void dfs(node *g1)
{
    node *t = g;
    while (t != NULL)
    {
        t->status = 0;
        t = t->next;
    }

    t = g1;
    while (t != NULL)
    {
        if (t->status == 0)
            dfs_visit(t);

        t = t->next;
    }
}

void enque(node *s)
{
    int r1 = rear;
    r1 = (r1 + 1) % SIZE;
    if (front == r1)
    {
        printf("Queue full!\n");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

int emptyq()
{
    return front == rear;
}

node *deque()
{
    if (emptyq())
    {
        printf("Queue empty!\n");
        exit(2);
    }
    front = (front + 1) % SIZE;
    return q[front];
}

void bfs(node *s)
{
    node *t = g, *t1, *u;

    while (t != NULL)
    {
        t->status = 0;
        t = t->next;
    }

    s->status = 1;
    printf("%d ", s->data);
    enque(s);

    while (!emptyq())
    {
        u = deque();
        t = u->point;

        while (t != NULL)
        {
            t1 = t->point;
            if (t1->status == 0)
            {
                printf("%d ", t1->data);
                t1->status = 1;
                enque(t1);
            }
            t = t->next;
        }
    }
}

int main()
{
    addvertex(1);
    addvertex(2);
    addvertex(3);
    addvertex(4);
    addvertex(5);

    addedge(1, 2);
    addedge(1, 4);
    addedge(2, 3);
    addedge(2, 4);
    addedge(4, 3);
    addedge(4, 5);

    printf("\nGraph:");
    printgraph();

    printf("\nDFS Traverse: ");
    dfs(find(1));

    printf("\nBFS Traverse: ");
    bfs(find(1));

    printf("\nTopological Sort Order: ");
    topsortout();

    return 0;
}

