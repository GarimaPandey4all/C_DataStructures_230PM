#include<stdio.h>
#include<conio.h>

struct pQueue
{
	int priority;
	int info;
	struct pQueue *link;
};

struct pQueue *front = NULL;

struct pQueue *createQueue()
{
       struct pQueue *n;

       n = (struct pQueue *)malloc(sizeof(struct pQueue));

       return(n);
};

void enQueue()
{
	struct pQueue *temp, *temp1;
	int priority;

	temp = createQueue();

	printf("Enter any value:");
	scanf("%d", &temp->info);

	printf("Enter Priority:");
	scanf("%d", &priority);

	temp->priority = priority;

	if(front == NULL || priority < front->priority)
	{
		temp->link = front;
		front = temp;
	}
	else
	{
		temp1 = front;
		while(temp1->link != NULL && temp1->link->priority <= priority)
		{
			 temp1 = temp1->link;
		}
		temp->link = temp1->link;
		temp1->link = temp;
	}
}

void deQueue()
{
	struct pQueue *temp;

	if(front == NULL)
	printf("Queue is Empty.");
	else
	{
		temp = front;
		printf("Deleted value is:%d.", temp->info);
		front = front->link;
		free(temp);
	}
}

void display()
{
	struct pQueue *temp;

	temp = front;

	if(front == NULL)
	printf("Queue is Empty.");
	else
	{
		while(temp != NULL)
		{
			printf("\nPriority = %d and Value = %d.", temp->priority, temp->info);
			temp = temp->link;
		}
	}
}

int main()
{
	int choice;
	clrscr();

	while(1)
	{
	printf("\n\n1. EnQueue.");
	printf("\n2. DeQueue.");
	printf("\n3. Display.");
	printf("\n4. Exit.");
	printf("\n\nEnter your choice:");
	scanf("%d", &choice);

	switch(choice)
	{
	case 1:
	enQueue();
	break;

	case 2:
	deQueue();
	break;

	case 3:
	display();
	break;

	case 4:
	exit(0);

	default:
	printf("Invalid Choice.");

	}
	}
	getch();
	return 0;
}