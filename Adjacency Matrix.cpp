#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int main()
{
    int n,q,edge,u,v,c;
    scanf("%d",&n);
    scanf("%d",&q);
    if(q==1)
        edge = n-1;
    else
        scanf("%d",&e);
    for(int i=0; i<edge; i++)
    {
        scanf("%d%d",&u,&v);
        a[u-1][v-1] = 1;
        a[v-1][u-1] = 1;
    }
    for(int i=0; i<n; i++)
    {
        c = 0;
        printf("Adjacent of %d: ",i+1);
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==1)
                printf("%d ",j+1);
        }
        printf("\n");
    }
    return 0;
}
