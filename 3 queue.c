# include<stdio.h>
# include<stdlib.h>
# define max 100

int queue[max],front=-1,rear=-1,size;

void add(int value)
{
    if(rear==size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front==-1)front=0;
        rear++;
        queue[rear]=value;
        printf("Enqueued in queue %d\n",value);

    }
}
void delete()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued from queue %d",queue[front]);
        front++;

        if(front>rear)
        {
            front=-1;
            rear=-1;
        }

    }
}
void display()
{
     if(front==-1||front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:-\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
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