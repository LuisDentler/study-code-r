#include <stdio.h>

int main(void)
{
    char column;
    int row;

    /* Rows from 8 down to 1 */
    for (row = 8; row >= 1; row--) {
        /* Columns from A to H */
        for (column = 'A'; column <= 'H'; column++) {
            printf("%c%d", column, row);

            /* Print space between fields, but not after the last column */
            if (column < 'H') {
                printf(" ");
            }
        }
        /* New line after each row */
        printf("\n");
    }

    return 0;
}
