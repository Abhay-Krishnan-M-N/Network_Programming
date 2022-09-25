1. Go back N

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
int n,r;
struct frame
{
char ack;
int data;
}frm[10];

int sender()
{
int i;
printf("\nEnter the Frame list to be sent:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\nEnter data for packets[%d]",i);
scanf("%d",&frm[i].data);
frm[i].ack='y';
}
return 0;
}
void recvack()
{
int i;
rand();
r=rand()%n;
frm[r].ack='n';
for(i=1;i<=n;i++)
{
if(frm[i].ack=='n')
printf("\nThe packet number %d is not received\n",r);
}
}

void resend() 
{
int i;
printf("\n resending from packet %d",r);
for(i=r;i<=n;i++)
{
sleep(2);
frm[i].ack='y';
printf("\nReceived data of packet %d is %d",i,frm[i].data);
}
}
int main()
{
sender();
recvack();
resend();
printf("\n all packets sent successfully\n");
}



2. Selective Repeat


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
int n,r;
struct frame
{
char ack;
int data;
}frm[10];


int sender()
{
int i;
printf("\nEnter the no. of packets to be sent:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\nEnter data for packets[%d]",i);
scanf("%d",&frm[i].data);
frm[i].ack='y';
}
return 0;
}
void recvack()
{
int i;
rand();
r=rand()%n;
frm[r].ack='n';
for(i=1;i<=n;i++)
{
if(frm[i].ack=='n')
printf("\nThe packet number %d is not received\n",r);
}
}
void resend() 
{
printf("\nresending packet %d",r);
sleep(2);
frm[r].ack='y';
printf("\nThe received packet is %d",frm[r].data);
}

int main()
{
sender();
recvack();
resend();
printf("\nAll packets sent successfully");
}


3. Stop and wait

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
int n,r,i;
struct frame
{
char ack;
int data;
}frm[10];

int main()
{
printf("\nEnter the no. of packets to be sent:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\nEnter data for packets[%d]",i);
scanf("%d",&frm[i].data);
frm[i].ack='y';
}
int i;
rand();
r=rand()%n;
frm[r].ack='n';
for(i=1;i<=n;i++)
{
if(frm[i].ack=='n')
printf("\nThe packet number %d is not received\n",r);
}
printf("\nresending packet %d",r);
sleep(2);
frm[r].ack='y';
printf("\nThe received packet is %d",frm[r].data);
printf("\nAll packets sent successfully");
}