#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int h, w, k, l, m, i;
    
     i = get_int("Height: ");

    
    for (h = i*2;h > i;h--)
    {
        for (w = h; w > i+1;w--)
        {
            printf(" ");
        }
        for (k= h-i;k < i+1;k++)
        {
            printf("#");
        }
        for (l = i-1;l < i;l++)
        {
            printf("  ");
        }
        for (m = h-i;m < i+1;m++)
        {
            printf("#");
        }
        
        
        
        printf("\n");
    }

}
