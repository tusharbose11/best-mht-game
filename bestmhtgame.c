#include <stdio.h>
#define SIZE 100
#include<conio.h>
#include<math.h>
#define size1 25
int items[SIZE];
int front = -1, rear =-1;
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void enQueue(int element)
{
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}
int deQueue()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;

        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}
void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}
int parent(int i)
{
  return (i-1)/2;
}
int left(int i)
{
  return 2*i+1;
}
int right(int i)
{
  return 2*i+2;
}
void maxheapify(int player1[], int n, int i)
{
  int l, r,largest,temp;
  l = left(i);
  r = right(i);
  if(l<n && player1[l] > player1[i])
    largest = l;
  else
    largest = i;
  if(r<n && player1[r] > player1[largest])
    largest = r;
  if(largest != i)
  {
    temp = player1[i];
    player1[i] = player1[largest];
    player1[largest] = temp;
    maxheapify(player1,n,largest);
  }
}
int main()
{
    int i;
    for(i=200;i<300;i++)
    {
        enQueue(i);
    }
    display();

    int player1[size1];
    int player2[size1];
    int player3[size1];
    int player4[size1];
    int j=0;
    int k=0;
    int l=1;
    int m=2;
    int n=3;
    for(j=0;j<size1;j++)
    {
      player1[j]=items[k];
      k=k+4;
    }
    for(j=0;j<size1;j++)
    {
         player2[j]=items[l];
         l=l+4;
    }
    for(j=0;j<size1;j++)
    {
      player3[j]=items[m];
      m=m+4;
    }
    for(j=0;j<size1;j++)
    {
      player4[j]=items[n];
      n=n+4;
    }
    printf("\n\tPlayer1 before max heap \n\n");
    for(j=0;j<size1;j++)
    printf("%d ",player1[j]);
    printf("\n\n\n\n");
    printf("\n\tPlayer2 before max heap \n\n");
    for(j=0;j<size1;j++)
    printf("%d ",player2[j]);
    printf("\n\n\n\n");
    printf("\n\tPlayer3 before max heap \n\n");
    for(j=0;j<size1;j++)
    printf("%d ",player3[j]);
    printf("\n\n\n\n");
    printf("\n\tPlayer4 before max heap \n\n");
    for(j=0;j<size1;j++)
    printf("%d ",player4[j]);
    printf("\n\n\n\n");
    for(j=(size1-1)/2;j>=0;j--)
   {
       maxheapify(player1,size1,j);
   }

    for(j=(size1-1)/2;j>=0;j--)
    {
         maxheapify(player2,size1,j);
    }
    for(j=(size1-1)/2;j>=0;j--)
    {
        maxheapify(player3,size1,j);
    }
    for(j=(size1-1)/2;j>=0;j--)
    {
        maxheapify(player4,size1,j);
    }
    printf("\n\n\tPlayer1 after Maxheap \n\n");
    for(j=0;j<size1;j++)
    {
        printf("%d ",player1[j]);
    }
    printf("\n\n\n\n");
    printf("\n\n\tPlayer2 after Maxheap \n\n");
    for(j=0;j<size1;j++)
    {
        printf("%d ",player2[j]);
    }
    printf("\n\n\n\n");
    printf("\n\n\tPlayer3 after Maxheap \n\n");
    for(j=0;j<size1;j++)
    {
        printf("%d ",player3[j]);
    }
    printf("\n\n\n\n");
    printf("\n\n\tPlayer4 after Maxheap \n\n");
    for(j=0;j<size1;j++)
   {
      printf("%d ",player4[j]);
   }
    printf("\n\n\n\n");

    int arr[4]={player1[0],player2[0],player3[0],player4[0]};
    int max = arr[0];
    for (i = 1; i < 4; i++)
    {
        if (max < arr[i])
			max = arr[i];
    }
    printf("\n\tLargest element is : %d", max);
    printf("\n\n\n\n");
    if(max==player1[0])
        printf("\tThe WINNER is Player1!");
    else if(max==player2[0])
        printf("\tThe WINNER is Player2!");
    else if(max==player3[0])
        printf("\tThe WINNER is Player3!");
    else
        printf("\tThe WINNER is Player4!");

    getch();
    return 0;
}

