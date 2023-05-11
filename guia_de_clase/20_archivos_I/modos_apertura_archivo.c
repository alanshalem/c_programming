#include <stdio.h>

int main()
{
    FILE *file_ptr;
    char data[100];

    // r mode - opening file for reading
    file_ptr = fopen("file.txt", "r");
    if (file_ptr == NULL)
    {
        printf("Error: could not open file for reading");
        return 1;
    }
    fgets(data, 100, file_ptr);
    printf("Data from file: %s\n", data);
    fclose(file_ptr);

    // r+ mode - opening file for reading and writing
    file_ptr = fopen("file.txt", "r+");
    if (file_ptr == NULL)
    {
        printf("Error: could not open file for reading and writing");
        return 1;
    }
    fputs("New data", file_ptr);
    fseek(file_ptr, 0, SEEK_SET); // move file pointer to beginning
    fgets(data, 100, file_ptr);
    printf("Data from file after write: %s\n", data);
    fclose(file_ptr);

    // w mode - opening file for writing (truncates file if it exists)
    file_ptr = fopen("new_file.txt", "w");
    if (file_ptr == NULL)
    {
        printf("Error: could not open file for writing");
        return 1;
    }
    fputs("Data to write", file_ptr);
    fclose(file_ptr);

    // w+ mode - opening file for reading and writing (truncates file if it exists)
    file_ptr = fopen("new_file.txt", "w+");
    if (file_ptr == NULL)
    {
        printf("Error: could not open file for reading and writing");
        return 1;
    }
    fputs("New data", file_ptr);
    fseek(file_ptr, 0, SEEK_SET); // move file pointer to beginning
    fgets(data, 100, file_ptr);
    printf("Data from new file after write: %s\n", data);
    fclose(file_ptr);

    // a mode - opening file for appending data
    file_ptr = fopen("file.txt", "a");
    if (file_ptr == NULL)
    {
        printf("Error: could not open file for appending");
        return 1;
    }
    fputs("Data to append", file_ptr);
    fclose(file_ptr);

    // a+ mode - opening file for reading and appending data
    file_ptr = fopen("file.txt", "a+");
    if (file_ptr == NULL)
    {
        printf("Error: could not open file for reading and appending");
        return 1;
    }
    fputs("New data to append", file_ptr);
    fseek(file_ptr, 0, SEEK_SET); // move file pointer to beginning
    fgets(data, 100, file_ptr);
    printf("Data from file after append: %s\n", data);
    fclose(file_ptr);

    return 0;
}
