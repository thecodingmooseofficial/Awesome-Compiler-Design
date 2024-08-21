#include <stdio.h>

int main(){

    FILE *fp; // Declare a file pointer to handle file operations
    fp = fopen("myFile.txt", "w"); // Open "myFile.txt" in write mode. If it doesn't exist, it is created when the code is run.
    fputs("XYZXYZXY C-Programming!", fp); // Write the string to the file
    fseek(fp, 0, SEEK_SET); // Move the file pointer to the beginning of the file (offset 0)
    fputs("Let's do ", fp);  // Overwites the string at the beginning of the file, replacing the first 8 characters of the previous content
    
    fseek(fp, 22, SEEK_SET); // Move the file pointer to the 23rd character in the file
    fputs(" today!", fp); // Overwrite the characters starting at the 15th position with "C Programming"

    fclose(fp); // Close the file, saving changes


    // Reopen the file in read mode to display its contents
    fp = fopen("myFile.txt", "r");
    char ch;
    printf("File content:\n");
    // Read and display the file content character by character
    while ((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    fclose(fp); // Close the file after reading

    return 0;
}