#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    FILE *file = fopen("coding journal.txt", "a");

    if (!file)
    {
        return 1;
    }

    char *entry = get_string("journal entry: ");

    fprintf(file, "%s\n", entry);

    fclose(file);
}