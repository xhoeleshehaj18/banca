#ifndef CREAZIONEEMAIL_H_   /* Include guard */
#define CREAZIONEEMAIL_H_

#define C 100

typedef struct {
   int nClienti;
   char nomeCliente[C][C], cognomeCliente[C][C], emailCliente[C][C], dataDiNascitaCliente[C][C];
} Cliente;

int creazioneEmail(Cliente*, Cliente*, Cliente*, Cliente*, Cliente);  /* An example function declaration */

#endif