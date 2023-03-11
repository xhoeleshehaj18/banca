#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define N 100000
#define C 100

// union codiceConfermaCausale


// Rircorda password in base ad un UID (come una mail)

typedef struct {
	int codiceConfermaCasuale;
	char nomeCliente[C][C], cognomeCliente[C][C], passwordCliente[C][C], userNameCliente[C][C], omma[C][C], appa[C][C];
} loginCliente;

typedef struct {
	char accessoEmail[C][C], accessoPassword[C][C];
} accessoEmailCliente;

typedef struct {
	float contoCliente[N][N];
} conto;

int registrazione(loginCliente*, loginCliente*, loginCliente*, loginCliente, loginCliente*, int);
int login(loginCliente*, loginCliente*, int);
void clear();

int main() {
	int n = 0, menu = -1, confermaSuccesso = 0, i = 0, j = 0, loginEmail = -1, indiceCliente = 0, confermaMail = -1, nLines = 6;
	char tempEmail[C], tempPassword[C];

	loginCliente a, b;
	accessoEmailCliente c, d;

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

	while (menu != 5) {
		menu = -1;
		do {
			printf("Inserire un opzione\n[1] Login\n[2] Registrazione\n[3] Logout\n[5] Per uscire\n:\t");
			scanf("%d", &menu);

			if (menu < 1 || menu > 5) 
				printf("Errore! scegliere un opzione esistente! [1 .. 2]\n");

		} while (menu < 1 || menu > 5);

		switch (menu) {
		case 1:
			confermaSuccesso = login(&b, &b, n);

			if (confermaSuccesso == -1)
				printf("Un'errore e' stato riscontrato durante il login!\n");
			break;

		case 2:
			confermaSuccesso = registrazione(&b, &b, &b, a, &b, n);
			
			if (confermaSuccesso == 1) 
				n++;
			break;

		case 3:
			fflush(stdin);
			printf("Logout effettuato!\n");
			break;
		}
	}
	return 0;
}

int registrazione(loginCliente *userNameCliente, loginCliente *nomeCliente , loginCliente *passwordCliente, loginCliente codiceConfermaCasuale, loginCliente *cognomeCliente, int n) {
	int lunghezzaPassword, j, conferma = -1, i = 0, a, codice = -1, numeroNelNome = 0, lunghezzaNC, letteraNelCodiceConferma, numeroNelCognome = 0, controlloLetteraConferma, confermaSuccesso;
	char tempNome[C], tempCognome[C], tempPassword[C], passwordGlimpse[C], temp[C];

	do {
		numeroNelNome = 0;
		printf("Inserire il vostro nome:\t");
		scanf("%s", temp);
 
		fflush(stdin);

		lunghezzaNC = strlen(temp);

		for (i = 0; i < lunghezzaNC && numeroNelNome != 1; ++i) {
			if (temp[i] >= 48 && temp[i] <= 57) {
				numeroNelNome = 1;
				printf("Errore! il nome inserito non puo' contenere un numero!\n");
			}
		}

		if (numeroNelNome != 1) {
			do {
				printf("Siete sicuri di voler scegliere '%s' come nome?\n[1] Per confermare\n[2] Per cambiare nome\n:\t", temp);
				controlloLetteraConferma = scanf("%d", &conferma);
				fflush(stdin);

				if (controlloLetteraConferma == 0) {
					printf("\n\nErrore! Il valore inserito non e' valido! (un carattere e' stato inserito)\n\n");
					fflush(stdin);
				}

			} while (conferma < 1 || conferma > 2 || controlloLetteraConferma == 0);
		}

	} while(conferma != 1 || numeroNelNome == 1);

	strcpy(tempNome, temp);
	
	strcpy(nomeCliente->nomeCliente[n], tempNome);

	do {
		numeroNelCognome = 0;

		printf("Inserire il vostro cognome:\t");
		scanf("%s", temp);
		fflush(stdin);

		lunghezzaNC = strlen(temp);

		for (i = 0; i < lunghezzaNC && numeroNelCognome != 1; ++i) {
			if (temp[i] >= 48 && temp[i] <= 57) {
				numeroNelCognome = 1;
				printf("Errore! il cognome inserito non puo' contenere un numero!\n");
			}
		}

		do {
			printf("Siete sicuri di voler scegliere '%s' come cognome?\n[1] Per confermare\n[2] Per cambiare cognome\n:\t", temp);
			controlloLetteraConferma = scanf("%d", &conferma);
			fflush(stdin);

			if (controlloLetteraConferma == 0) {
				printf("\n\nErrore! Il valore inserito non e' valido! (un carattere e' stato inserito)\n\n");
				fflush(stdin);
			}

		} while (conferma < 1 || conferma > 2 || controlloLetteraConferma == 0);
		
	} while(conferma != 1 || numeroNelCognome == 1);

	conferma = -1;

	strcpy(tempCognome, temp);
	
	strcpy(cognomeCliente->cognomeCliente[n], tempCognome);

	do {
		printf("Scegliere una password:\t");
		scanf("%s", tempPassword);

		fflush(stdin);

		lunghezzaPassword = strlen(tempPassword);

		strcpy(temp, "*");

		for (j = 0; j < lunghezzaPassword / 1.5; ++j)
			strcpy(&passwordGlimpse[j], temp);

		for (j = lunghezzaPassword / 1.5; j < lunghezzaPassword; ++j)
			strcpy(&passwordGlimpse[j], &tempPassword[j]);

		printf("Siete sicuri di voler scegliere '%s' come password?\n[1] Per confermare\n[2] Per cambiare password\n:\t", passwordGlimpse);
		scanf("%d", &conferma);
		
	} while (conferma != 1);

	strcpy(passwordCliente->passwordCliente[n], tempPassword);

	j = 0;
	conferma = -1;

	printf("Controllare la mail per il codice di conferma ed inserirlo\n");

	for (i = 0; i < 6; ++i) {
		a = 0 + rand() % 9;
		codiceConfermaCasuale.codiceConfermaCasuale *= 10;
		codiceConfermaCasuale.codiceConfermaCasuale += a;
	}

	printf("codice:\t%d\n", codiceConfermaCasuale.codiceConfermaCasuale);
	sleep(5);

	clear();

	do {
		do {
		printf("Inserire il codice:\t");
		letteraNelCodiceConferma =  scanf("%d", &codice);

			if (letteraNelCodiceConferma == 0) {
				printf("Errore! e' stata inserita una lettera!\n");
				fflush(stdin);
			}
		} while (letteraNelCodiceConferma == 0);

		if (codice == codiceConfermaCasuale.codiceConfermaCasuale)
			conferma = 1;
		
		else
			printf("Il codice inserito e' errato!\n");

		j++;

		if (j > 1)
			printf("Tentativi esauriti!\n");
	} while (j < 2 && conferma != 1);

	if (conferma == 1) {
		strcpy(userNameCliente->userNameCliente[n], nomeCliente->nomeCliente[n]);
		strcat(userNameCliente->userNameCliente[n], ".");
		strcat(userNameCliente->userNameCliente[n], cognomeCliente->cognomeCliente[n]);
		a = 10 + rand() % 89;
		sprintf(temp, "%d", a);
		strcat(userNameCliente->userNameCliente[n], temp);

		printf("Username:\t%s\n", userNameCliente->userNameCliente[n]);

		printf("Registrazione avvenuta con successo!\n");
		confermaSuccesso = 1;
		return confermaSuccesso;
	}

	else {
		strcpy(cognomeCliente->cognomeCliente[n], "\0");
		strcpy(passwordCliente->passwordCliente[n], "\0");
		strcpy(passwordCliente->passwordCliente[n], "\0");
		confermaSuccesso = -1;
		return confermaSuccesso;
	}

	return confermaSuccesso;
}

int login(loginCliente *userNameCliente, loginCliente *passwordCliente, int n) {
	int i, conferma = -1, scelta = -1, indiceCliente = 0, nTentativi = 0;
	char tempUsername[C], tempPassword[C];

	do {
		for (i = 0; i < n && conferma != 1; ++i) {
			printf("Inserire il nome utente:\t");
			scanf("%s", tempUsername);

			fflush(stdin);

			if (strcmp(tempUsername, userNameCliente->userNameCliente[i]) == 0) {
				conferma = 1;
				indiceCliente = i;
			}

		}
			if (conferma == 1) {
				printf("Inserire la password:\t");
				scanf("%s", tempPassword);

				fflush(stdin);

				nTentativi++;

			if (strcmp(tempPassword, passwordCliente->passwordCliente[indiceCliente]) == 0)
				printf("Benvenuto %s!", userNameCliente->userNameCliente[indiceCliente]);

			else
				printf("Password errata! inserire [1] per riprovare o [0] per cambiare nome utente:\t");
				scanf("%d", &scelta);
			}
	} while (scelta != 0 && nTentativi < 3);
	return 0;
}

void clear() {
	printf("\033c");
}