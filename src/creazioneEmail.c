#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/creazioneEmail.h"  /* Include the header (not strictly necessary here) */
#include "../headers/conversioneMinuscolo.h"
#include "../headers/acquisizioneDataDiNascita.h"

union Temp {
    int giorno, mese, anno;
    char suggerimentiEmail[C][C];
} temp;  

int creazioneEmail(Cliente *nomeCliente, Cliente *cognomeCliente, Cliente *dataDiNascitaCliente, Cliente *emailCliente, Cliente n) {
    int contNome = 0, contCognome = 0;
    char confermaNome[C], confermaCognome[C];
    char tempa[C];

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

    printf("Inserire la data di nascita: [DD/MM/YYYY]:\t");
    scanf("%s", tempa);

    // conversione da stringa acquisita a numeri interi utilizzabili per fare operazioni --> ../headers/acquisizioneDataDiNascita.c $.h
    // acquisire la stringa e fare un controllo sulla lunghezza per vedere se il formato e' corretto, poi dato che il formato e' sempre lo stesso
    // fare una funzione semplice che trasforma i valori ASCII di stringhe numeriche  ad ogni ignorando gli /
    
    time_t t1 = dateToInt(tempa);

    printf("Palle %d\n", t1);


    // suggerimenti sulla mail in base a nome, cognome e data di nascita
    printf("Crea la mail:\t");
    scanf("%s", emailCliente->emailCliente[contNome]);


    n.nClienti += 1;

    return n.nClienti;
}

