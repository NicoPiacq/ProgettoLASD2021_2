// QUESTO HEADER CONTIENE LE FIRME DELLE FUNZIONI NECESSARIE PER LA GESTIONE DATI

/* PER GESTIONE DATI SI INTENDE LA:
 *
 * 1) GESTIONE REGISTRAZIONE E LOGIN
 * 2) GESTIONE ASSEGNAZIONE VEICOLO
 * 3) GESTIONE PRODOTTI
 *
 */

#include "HeaderConfigurazione.h"

typedef struct utente {

    char nomeUtente[UTENTE_NOME_DIM];
    char idVeicolo[VEICOLO_ID_DIM];
    char nomeVeicolo[VEICOLO_NOME_DIM];
    int pesoCarico;

} Driver;

// FUNZIONI PER GESTIONE REGISTRAZIONE E LOGIN

// Funzione che raccoglie le informazioni del nuovo utente (nome e password) prima di scrivere su file
void RegistrazioneNuovoUtente();

// Verifica se la password rispetta i criteri di sicurezza stabiliti
bool VerificaPassword(char[]);

// Verifica se il nome ha almeno 3 caratteri e non oltre 15 caratteri
bool VerificaNome(char[]);

// Scrive sul file della lista utenti il nuovo utente
void ScriviSuFileRegistrazione(int, char[], char[], char[], int);

// Legge l'ultimo ID registrato prima di registrare l'utente
int LeggiUltimoIDRegistrato();

// Aggiorna il campo ultimoIDRegistrato nel file Configurazione.
void AggiornaIDFileConfigurazione(int);

// Funzione per accedere al software
void AccessoUtente();

///////////////////////////////////////////////////////////////////////////////////////

// FUNZIONE PER ASSEGNAZIONE VEICOLI

// Assegna il veicolo all'utente associandolo all'ID utente e scrive su file
void AssegnaVeicoloAUtente(int);

// Carica il veicolo con il prodotto scelto dal driver
void CaricaVeicoloConProdotto();

///////////////////////////////////////////////////////////////////////////////////////

// FUNZIONE PER GESTIONE PRODOTTI

// Prepara una nuova lista di prodotti prima di accedere al programma
void AggiornaListaProdottiAvvio();

// Stampa i prodotti disponibili
void StampaProdottiDisponibili();
