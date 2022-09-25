Algorithm:

    Start
    By convention, the distance of the node to itself is assigned to zero and when a node is unreachable the distance is accepted as 999.
    Accept the input distance matrix from the user (dm[][]) that represents the distance between each node in the network.
    Store the distance between nodes in a suitable varible.
    Calculate the minimum distance between two nodes by iterating.
        If the distance between two nodes is larger than the calculated alternate available path, replace the existing distance with the calculated distaance.
    Print the shortest path calculated.
    Stop.

Code: filename.c


#include <stdio.h>


struct node {
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;

    printf("Enter no of nodes.\n");
    scanf("%d",&no);
    printf( "Enter the distance matrix:\n ");
    for (int i = 0; i < no; i++) {
        for (int j = 0; j < no; j++) {
            scanf("%d",&dm[i][j]);
       
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do {
        flag = 0;
        for (int i = 0; i < no; i++) {
            for (int j = 0; j < no; j++) {
                for (int k = 0; k < no; k++) {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j])) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++) {
        printf( "Dest\tNext Hop\tDist\n" );
        for (int j = 0; j < no; j++)
            printf("%d\t%d\t\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
    }
    return 0;
}

