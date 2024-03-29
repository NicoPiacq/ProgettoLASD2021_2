// DEFINIZIONI GLOBALI PER IL CODICE

// Librerie base del C e Windows
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdbool.h"
#include "windows.h"
#include "conio.h"

// DEFINIZIONI COLORI CONSOLE
#define CONSOLE_COLORE_ROSSO     "\x1b[31m"
#define CONSOLE_COLORE_VERDE     "\x1b[32m"
#define CONSOLE_COLORE_GIALLO    "\x1b[33m"
#define CONSOLE_COLORE_BLU       "\x1b[34m"
#define CONSOLE_COLORE_MAGENTA   "\x1b[35m"
#define CONSOLE_COLORE_CIANO     "\x1b[36m"
#define CONSOLE_COLORE_BASE      "\x1b[0m"

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
#define PRODOTTO_NOME_DIM       16

// DATI PER ISOLE
#define ISOLA_NOME_DIM          12
#define ARCO_PESO_MAX           50000

// DATI SOFTWARE
#define N_ISOLE                 10
#define INFINITO                99999


void ControllaFile(FILE *fileCheck, char[]);
bool ControllaFileBool(FILE *fileCheck);
bool ControllaAvvio();
