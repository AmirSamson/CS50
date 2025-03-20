#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //we create a file which is then opened and appended. for that, we use "FILE #file ="
    FILE *file = fopen("phonebook.csv", "a"); //the "a" is for Append. it will add the new value to the file. no overwrite it. for overwrtie we use "w".

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number); //printing to that file which is open in memeory.
    fclose(file);
}
