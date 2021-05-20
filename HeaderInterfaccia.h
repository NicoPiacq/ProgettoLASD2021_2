// PROTOTIPI FUNZIONI PER LA GESTIONE DELL'INTERFACCIA GRAFICA SU CONSOLE
#include "HeaderConfigurazione.h"

#define CONSOLE_COLORE_ROSSO     "\x1b[31m"
#define CONSOLE_COLORE_VERDE     "\x1b[32m"
#define CONSOLE_COLORE_GIALLO    "\x1b[33m"
#define CONSOLE_COLORE_BLU       "\x1b[34m"
#define CONSOLE_COLORE_MAGENTA   "\x1b[35m"
#define CONSOLE_COLORE_CIANO     "\x1b[36m"
#define CONSOLE_COLORE_BASE      "\x1b[0m"

// MOSTRA SU CONSOLE IL LOGO DEL SOFTWARE
void MostraLogo(char[]);

// UGUALE ALLA FUNZIONE DI SOPRA MA CON IL LOGO BIANCO
void MostraLogoNoColore(char[]);

// GENERA RIGHI VUOTI QUANTE VOLTE SI VUOLE
void GeneraCampoUIVuoto(int);

// MOSTRA LA SCHERMATA DI ERRORE E CHIUDE IL PROGRAMMA
void MostraErrore(char[]);

// IMPOSTA IL TITOLO DELLA CONSOLE DI COMANDI CON LA STRINGA IN INPUT
void ImpostaTitoloConsole(char[]);
