#include<stdio.h>
void tower(int n, char a, char b, char c)
{
    if(n==1)
    {
        printf("%c -> %c\n", a,c);
        return;
    }
    tower(n-1, a, c, b);
    printf("%c -> %c\n", a,c);
    tower(n-1, b, a, c);
}
int main()
{
    int n;
    printf("Number of Disks: ");
    scanf("%d",&n);
    printf("\n\nDisks Movements are : \n");
    tower(n, 'A', 'B', 'C');
}
