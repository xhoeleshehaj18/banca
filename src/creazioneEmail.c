#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/creazioneEmail.h"  /* Include the header (not strictly necessary here) */
#include "../headers/conversioneMinuscolo.h"


int creazioneEmail(Cliente *nomeCliente, Cliente *cognomeCliente, Cliente n) {
    int contNome = 0, contCognome = 0;
    char confermaNome[C], confermaCognome[C];

    while (strcmp(confermaNome, "si") != 0) {
        printf("Inserire il nome:\t");
        scanf("%[^\n]%*c", nomeCliente->nomeCliente[contNome]);

        printf("Confermare '%s' come nome?:\t", nomeCliente->nomeCliente[contNome]);
        scanf("%s", confermaNome);
        fflush(stdin);

        if (strcmp(confermaNome, "si") == 0) {
            conversioneMinuscolo(nomeCliente->nomeCliente[contNome], contNome);
        }
    }

    while (strcmp(confermaCognome, "si") != 0) {
        printf("Inserire il cognome:\t");
        scanf("%[^\n]%*c", cognomeCliente->cognomeCliente[contCognome]);

        printf("Confermare '%s' come cognome?:\t", cognomeCliente->cognomeCliente[contCognome]);
        scanf("%s", confermaCognome);
        fflush(stdin);

        if (strcmp(confermaCognome, "si") == 0) {
            conversioneMinuscolo(cognomeCliente->cognomeCliente[contCognome], contCognome);
        }
    }
    n.nClienti += 1;
    return n.nClienti;
}