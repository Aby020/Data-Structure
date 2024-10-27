# include<stdio.h>
# include<stdlib.h>
# define max 100

int queue[max],front=-1,rear=-1,size;

void add(int value)
{
    if((rear+1)%size==front)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front==-1)front=0;
        {
        rear=(rear+1)%size;
        queue[rear]=value;
        printf("enqueued to queue %d\n",value);
        }
    }
}
void delete()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dqueued from queue %d\n",queue[front]);

        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
    }
}
void display()
{
    if(front==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for(int i = front;i !=rear;i =(i+1)%size)
        {
            printf("%d\n",queue[i]);
        }
         printf("%d\n",queue[rear]);


    }
}
void main()
{
    int choice,value;
    printf("Enter the queue size\n");
    scanf("%d",&size);
    while(1)

    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Enqueue element\n");
            scanf("%d",&value);
            add(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);  
            break;          
        
        default:
            printf("Invalid input\n");
            return;
        }
    }

}