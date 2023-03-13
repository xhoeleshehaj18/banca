#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/creazioneEmail.h" // --> definizione struct "Cliente"
#include "../headers/loginEmail.h"

int main() {
    int successoCreazioneEmail = -1;

    Cliente b;

    successoCreazioneEmail = creazioneEmail(&b, &b);

    printf("%d\n", successoCreazioneEmail);
    return 0;
}
