#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    int i = get_positive_int("Height: ");

    int h, w, k;
    
    for (h=i*2;h>i;h--)
    {
        for (w=h;w>i+1;w--)
        {
            printf(" ");
        }
        for (k=h-i;k<i+1;k++)
        {
            printf("#");
        }
        
        
        printf("\n");
    }

}

int get_positive_int(string prompt)
{
   int p;
    do 
    {
        p = get_int("%s", prompt);
    }
    while (p < 1 || p > 8);
    return  p;   
}
