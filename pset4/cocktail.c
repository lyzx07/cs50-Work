#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    FILE *file = fopen("cocktails base liquor.csv", "a");
    if (file == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < 3; i++)
    {
        char *cocktail = get_string("cocktail: ");
        char *baseAlcohol = get_string("base alcohol: ");
    
        fprintf(file, "%s,%s\n", cocktail, baseAlcohol);
    }
    fclose(file);
    
}