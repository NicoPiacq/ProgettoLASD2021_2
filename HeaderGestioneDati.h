// QUESTO HEADER CONTIENE LE FIRME DELLE FUNZIONI NECESSARIE PER LA GESTIONE DATI

/* PER GESTIONE DATI SI INTENDE LA:
 *
 * 1) GESTIONE REGISTRAZIONE E LOGIN
 * 2) GESTIONE ASSEGNAZIONE VEICOLO
 * 3) GESTIONE PRODOTTI
 *
 */

#include "HeaderConfigurazione.h"

typedef struct autista {

    char nomeUtente[UTENTE_NOME_DIM];
    char nomeVeicolo[VEICOLO_NOME_DIM];
    int pesoVeicolo;
    int pesoCarico;

} Autista;

// FUNZIONI PER GESTIONE REGISTRAZIONE E LOGIN

// Funzione che raccoglie le informazioni del nuovo utente (nome e password) prima di scrivere su file
void RegistrazioneNuovoUtente();

// Verifica se una stringa rispetta i criteri prestabiliti (4 modalità: controllo nome, password, nome veicolo e peso veicolo)
bool VerificaCampo(char[], int);

// Scrive sul file della lista utenti il nuovo utente
void ScriviSuFileRegistrazione(int, char[], char[], char[], int);

// Legge l'ultimo ID registrato prima di registrare l'utente
int LeggiUltimoIDRegistrato();

// Aggiorna il campo ultimoIDRegistrato nel file Configurazione.
void AggiornaIDFileConfigurazione(int);

// Funzione per accedere al software
Autista AccessoUtente();

// Funzione per mostrare il menu principale
void MostraMenuPrincipale(Autista utente);
