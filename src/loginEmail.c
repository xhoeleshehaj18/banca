#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "3IB/banca/headers/functions.h"

int main() {
    FILE * fp;

	fp = fopen("emailClienti.txt", "r+");

	while(!feof(fp)) {
		fscanf(fp, "%s", &a.omma[i][j]);
		fflush(stdin);
		printf("%s\n", a.omma[i]);

		i++;
	}

	fclose(fp);

	i = 0;

	fp = fopen("passwordClienti.txt", "r+");

	while(!feof(fp)) {
		fscanf(fp, "%s", &a.appa[i][j]);
		fflush(stdin);
		printf("%s\n", a.appa[i]);

		i++;
	}

	fclose(fp);
	
	srand(time(NULL));

	while (loginEmail != 1) {
		printf("Inserire la mail:\t");
		scanf("%s", tempEmail);
		fflush(stdin);

		for (i = 0; i < nLines && confermaMail != 1; ++i) {
			if (strcmp(tempEmail, a.omma[i]) == 0) {
				confermaMail = 1;
				indiceCliente = i;
			}
		}

		if (confermaMail != 1)
			printf("Errore! la mail inserita non e' esistente!\n");	

		if (confermaMail == 1) {
			do {
				printf("\n%s\nInserire la password:\t", a.omma[indiceCliente]);
				scanf("%s", tempPassword);

				if (strcmp(tempPassword, a.appa[indiceCliente]) == 0)
					loginEmail = 1;

				else
					printf("Errore! la password inserita non e' corretta!\n");
			} while (loginEmail != 1);
		}
	}	
    return 0;
}


	