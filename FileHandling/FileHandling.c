
#include <stdio.h>
#include <stdlib.h>
void writeToFile(const char* filename) {
FILE* file = fopen(filename, "w");
if (file == NULL) {
printf("Error opening file for writing.\n");
return;
}
fprintf(file, "This is a sample text file.\n");
fprintf(file, "This file demonstrates file handling in C.\n");
fclose(file);
}
void readFromFile(const char* filename) {
FILE* file = fopen(filename, "r");
if (file == NULL) {
printf("Error opening file for reading.\n");
return;
}
char buffer[256];
while (fgets(buffer, sizeof(buffer), file) != NULL) {
printf("%s", buffer);
}
fclose(file);
}
void appendToFile(const char* filename) {
FILE* file = fopen(filename, "a");
if (file == NULL) {
printf("Error opening file for appending.\n");
return;
}
fprintf(file, "This line is added to the file.\n");
fclose(file);
}
void fileOperations(const char* filename) {
writeToFile(filename);
printf("Contents of the file after writing:\n");
readFromFile(filename);
appendToFile(filename);
printf("\nContents of the file after appending:\n");
readFromFile(filename);
}int main() {
const char* filename = "sample.txt";
fileOperations(filename);
return 0;
}