#include <stdio.h>

#define BOARD_SIZE 8
#define DARK "###"
#define LIGHT "   "

void print_file_labels(void)
{
    int col;
    printf("    ");
    for (col = 0; col < BOARD_SIZE; col++) {
        printf(" %c  ", 'A' + col);
    }
    printf("\n");
}

void print_horizontal_border(void)
{
    int col;
    printf("  +");
    for (col = 0; col < BOARD_SIZE; col++) {
        printf("---+");
    }
    printf("\n");
}

int main(void)
{
    int row, col;

    /* Top file labels */
    print_file_labels();

    /* Board */
    for (row = BOARD_SIZE; row >= 1; row--) {
        print_horizontal_border();

        /* Rank label (left) */
        printf("%d |", row);

        for (col = 0; col < BOARD_SIZE; col++) {
            /* Checkerboard pattern */
            if ((row + col) % 2 == 0) {
                printf("%s|", DARK);
            } else {
                printf("%s|", LIGHT);
            }
        }

        /* Rank label (right) */
        printf(" %d\n", row);
    }

    /* Bottom border */
    print_horizontal_border();

    /* Bottom file labels */
    print_file_labels();

    return 0;
}
