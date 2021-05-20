// DEFINIZIONI GLOBALI PER IL CODICE

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdbool.h"
#include "windows.h"
#include "conio.h"

// DEFINIZIONI PERCORSI FILE
#define FILE_LISTAUTENTI    "Dati/ListaUtenti.txt"
#define FILE_LISTAPRODOTTI  "Dati/ListaProdotti.txt"
#define FILE_CONF           "Dati/Configurazione.txt"

// DEFINIZIONE VALORI PER I DATI
// DATI UTENTE
#define UTENTE_NOME_DIM         16
#define UTENTE_PSW_DIM          11
#define UTENTE_NOMECONID_DIM    21

// DATI VEICOLI E PRODOTTI
#define VEICOLO_NOME_DIM        9
#define PRODOTTO_NOME_DIM       12

// DATI SOFTWARE
#define ESC                     27
#define N_ISOLE                 10


void ControllaFile(FILE *fileCheck, char[]);
bool ControllaFileBool(FILE *fileCheck);
bool ControllaAvvio();
