#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 1000
#define MAXLEN 1000
#define MAXFIELDS 10

typedef struct {
    int pos;
    int numeric;
    int fold;
} SortCriteria;

SortCriteria criteria[MAXFIELDS];
int num_criteria = 0;

void get_field(const char *line, char *field, int pos) {
    int curr_col = 1;
    int i = 0, j = 0;

    while (line[i] != '\0' && curr_col < pos) {
        while (isspace(line[i])) i++;
        if (line[i] == '\0') break;
        while (line[i] != '\0' && !isspace(line[i])) i++;
        curr_col++;
    }

    while (isspace(line[i])) i++;
    while (line[i] != '\0' && !isspace(line[i])) {
        field[j++] = line[i++];
    }
    field[j] = '\0';
}

int numcmp(const char *s1, const char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int charcmp(const char *s1, const char *s2, int fold) {
    if (fold) {
        while (*s1 && *s2) {
            int c1 = tolower((unsigned char)*s1);
            int c2 = tolower((unsigned char)*s2);
            if (c1 != c2) return c1 - c2;
            s1++; s2++;
        }
        return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
    }
    return strcmp(s1, s2);
}

int compare_lines(const void *a, const void *b) {
    const char *line1 = *(const char **)a;
    const char *line2 = *(const char **)b;
    char field1[MAXLEN], field2[MAXLEN];

    for (int i = 0; i < num_criteria; i++) {
        get_field(line1, field1, criteria[i].pos);
        get_field(line2, field2, criteria[i].pos);

        int result = 0;
        
        if (criteria[i].numeric) {
            result = numcmp(field1, field2);
        } else {
            result = charcmp(field1, field2, criteria[i].fold);
        }

        if (result != 0) {
            return result;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *lineptr[MAXLINES];
    int nlines = 0;

    criteria[0].pos = 2;
    criteria[0].numeric = 0;
    criteria[0].fold = 1;
    
    criteria[1].pos = 3;
    criteria[1].numeric = 1;
    criteria[1].fold = 0;
    
    num_criteria = 2;

    const char *sample_data[] = {
        "Nguyen_Van_A    Toan    9",
        "Tran_Thi_B      Anh     10",
        "Le_Van_C        Toan    7",
        "Bui_Thi_D       Anh     8"
    };
    
    int num_samples = sizeof(sample_data) / sizeof(sample_data[0]);

    printf("--- DU LIEU BAN DAU ---\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%s\n", sample_data[i]);
        lineptr[nlines] = malloc(strlen(sample_data[i]) + 1);
        strcpy(lineptr[nlines], sample_data[i]);
        nlines++;
    }

    qsort(lineptr, nlines, sizeof(char *), compare_lines);

    printf("\n--- KET QUA SAU KHI SAP XEP (Mon hoc -> Diem) ---\n");
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
        free(lineptr[i]);
    }

    return 0;
}