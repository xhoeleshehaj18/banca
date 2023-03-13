#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/creazioneEmail.h"
#include "../headers/loginEmail.h"

typedef struct Cliente palle;

int main() {
    int successoCreazioneEmail = -1;

    Cliente b;

    successoCreazioneEmail = creazioneEmail(&b, &b);

    printf("%d\n", successoCreazioneEmail);
    return 0;
}
