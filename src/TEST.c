#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("text.cub", "r"); 
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[100];    
    int map_start_line = -1;
    char map_symbols[] = "NSWE";

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "NO ", 3) == 0 ||
            strncmp(line, "SO ", 3) == 0 ||
            strncmp(line, "WE ", 3) == 0 ||
            strncmp(line, "EA ", 3) == 0 ||
            strncmp(line, " ", 1) == 0  ||
            strncmp(line, "F ", 2) == 0 ||
            strncmp(line, "C ", 2) == 0) {
            continue;
        }

        int line_length = strlen(line);
        if (line_length >= 3 &&
            line[line_length - 2] == '1' &&
            strchr(map_symbols, line[line_length - 1])) {
            map_start_line = -1;
            break;
        }

        map_start_line++;
    }

    fclose(file);

    if (map_start_line >= 0) {
        printf("Map start found at line: %d\n", map_start_line);
    } else {
        printf("Map start not found\n");
    }

    return 0;
}
