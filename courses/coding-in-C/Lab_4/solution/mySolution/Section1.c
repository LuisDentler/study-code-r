#include <stdio.h>

void changeSecondLetter(char *str) {
    str[1] = 'c';
}


int main(void) {
    char text[] = "Curly bird catches the worm";

    char *ptr = text;

    printf("String:  %s\n", text);
    printf("Pointer: %s\n", ptr);

    ptr[0] = 'E';
    ptr[1] = 'a';

    printf("After Point 4): \n");
    printf("String:  %s\n", text);
    printf("Pointer: %s\n", ptr);

    char text2[] = "AActions speak louder than words";
    changeSecondLetter(text2);
    printf("Nach Funktionsaufruf: %s\n", text2);
    
    return 0;
}
