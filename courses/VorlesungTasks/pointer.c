#include <stdio.h>

int main(void) {
    int myNumbers[5] = {10, 20, 30, 40, 50};

    int *ptr1 = &myNumbers[1];  
    int *ptr2 = &myNumbers[4];  

  
    printf("Adresse von ptr1 (2. Element): %p\n", (void*)ptr1);
    printf("Adresse von ptr2 (letztes Element): %p\n", (void*)ptr2);

    
    printf("Differenz der Zeiger (ptr2 - ptr1): %ld\n", ptr2 - ptr1);

    return 0;
}
