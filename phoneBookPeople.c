#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
this is a file for adding people in our list of peopel in people[i] and we defined a type for it
the type is defined in: typedef struct{} which we have defined the name: string and number as String as well.
then we added the names and the numbers of people[i] and then we wrote a function for searching inside our list.
the function uses a structure map: "strcmp" and takes the names of the people. */

typedef struct{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4];
    people[1].name = "Amir";
    people[1].number = "09123456789";

    people[2].name = "Bohrn";
    people[2].number = "09134567890";

    people[3].name = "Chad";
    people[3].number = "09145678901";

    people[0].name = "Dante";
    people[0].number = "09156789010";

    string name = get_string("Name: ");
    // string number = get_string("Number: ");

    for (int i=0; i<4; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        // if (strcmp(people[i].name, name) == 0 && strcmp(people[i].number, number) == 0)
        {
            printf("The phone number of %s is %s\n", people[i].name, people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
};
