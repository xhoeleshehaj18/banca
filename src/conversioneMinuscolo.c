#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/creazioneEmail.h"
#include "../headers/conversioneMinuscolo.h"

void conversioneMinuscolo(Cliente *str, int n) {
	char *t = str;

    while (*t != '\0') {
        if (*t >= 'A' && *t <= 'Z' )
            *t = *t + ('a' - 'A');
        t++;
    }
}