#ifndef CREAZIONEEMAIL_H_   /* Include guard */
#define CREAZIONEEMAIL_H_

#define C 100

typedef struct {
   int nClienti = 0;
   char nomeCliente[C][C], cognomeCliente[C][C];
} Cliente;

int creazioneEmail(Cliente*, Cliente*, Cliente);  /* An example function declaration */

#endif 