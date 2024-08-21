#include <stdio.h>
#include <stdlib.h>  // Include for exit() function
#include <ctype.h>   // Include for tolower() function to handle both uppercase and lowercase

int main()
{
    FILE *fp;
    int vowel = 0, consonant = 0;
    char ch, message[200];   
      
    fp = fopen("myFile.txt", "r");
    if(fp == NULL)
    {
        printf("Source can't be opened\n");
        exit(-1);
    }

    // Read and print the content of the file
    while (fgets(message, sizeof(message), fp) != NULL)
    {
        printf("%s", message);
    }

    printf("\n\n");

    // Reset file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // Count vowels and consonants
    while((ch = fgetc(fp)) != EOF)
    {
        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u')
        {
            vowel++;
            printf("%c", ch);
        }
        else if (isalpha(ch)) // Check if character is an alphabetic letter
        {
            consonant++;
            printf("%c", ch);
        }   
    }

    fclose(fp);
    printf("\nNumber of vowels in the text: %d\nNumber of consonants: %d\n", vowel, consonant);
    return 0;
}
