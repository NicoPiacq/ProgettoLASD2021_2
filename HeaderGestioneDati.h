// QUESTO HEADER CONTIENE LE FIRME DELLE StampaPercorsoZIONI NECESSARIE PER LA GESTIONE DATI
#include "HeaderVeicoli.h"

/* PER GESTIONE DATI SI INTENDE LA:
 *
 * 1) GESTIONE REGISTRAZIONE E LOGIN
 * 2) GESTIONE ASSEGNAZIONE VEICOLO
 * 3) GESTIONE PRODOTTI
 *
 */

// Struttura dati Coda per contenere gli elementi visitati (e da visitare) con il BFS
typedef struct coda {
  int items[40];
  int fronte;
  int rear;
} Coda;

// Struttura dati per contenere le informazioni (dopo il login) del driver
typedef struct autista {

    char nomeUtente[UTENTE_NOME_DIM];
    char nomeVeicolo[VEICOLO_NOME_DIM];
    int pesoVeicolo;
    int pesoCarico;

} Autista;

// Struttura di un arco e nodo
typedef struct arco {

    char nomeIsolaAttuale[ISOLA_NOME_DIM];
    int key;
    int portataMassima;
    int numeroPonti;
    struct arco *next;

} Ponte;

// Struttura grafo
typedef struct grafo {

    int numeroIsole;
    int *visitati;
    Ponte **adiacente;

} Isole;

typedef struct nodoprodotto {

    int idProdotto;
    char nomeProdotto[PRODOTTO_NOME_DIM];
    int pesoSpecifico;
    int quantita;

    struct nodoprodotto *next;

} NodoProdotto;

typedef struct testaprodotto {

    NodoProdotto *next;

} TestaProdotto;


// PROTOTIPI StampaPercorsoZIONI PER GESTIONE REGISTRAZIONE E LOGIN

// StampaPercorsozione che raccoglie le informazioni del nuovo utente (nome e password) prima di scrivere su file
void RegistrazioneNuovoUtente();

// Verifica se una stringa rispetta i criteri prestabiliti (4 modalità: controllo nome, password, nome veicolo e peso veicolo)
bool VerificaCampo(char[], int);

// Scrive sul file della lista utenti il nuovo utente
void ScriviSuFileRegistrazione(int, char[], char[], char[], int);

// Legge l'ultimo ID registrato prima di registrare l'utente
int LeggiUltimoIDRegistrato();

// Aggiorna il campo ultimoIDRegistrato nel file Configurazione.
void AggiornaIDFileConfigurazione(int);

// StampaPercorsozione per accedere al software
Autista AccessoUtente();

// StampaPercorsozione per mostrare il menu principale
void MostraMenuPrincipale(Autista utente);

// Ritorna il nome dell'isola associato all'ID in input
char *EstraiNomeIsolaDaID(int);
/////////////////////////////////////////////////////////////////////////////////////////////////////

// PROTOTIPI StampaPercorsoZIONI GESTIONE GRAFI

// Crea un grafo vuoto
Isole *creaGrafo(int);

// Crea e lega con un arco due vertici e li inserisce nel grafo
void AggiungiPonte(Isole *grafo, int sorgente, int destinazione, int peso, char[], char[]);

// Restituisce il numero di vertici del grafo
int grafoVuoto(Isole *grafo);

// Stampa il grafo a video
void stampaGrafo(Isole *grafo);

// Richiama più volte la StampaPercorsozione "AggiungiPonte" per inserire automaticamente archi nel grafo
void CostruisciPonti(Isole *grafo);

// Stampa tutte le isole possibili
void StampaIsolePartenze(Isole *mappa, int *, int *);


////////////////////////////////////////////////////////////////////////////////////////////////

// PROTOTIPI StampaPercorsoZIONI PER BFS

Coda* CreaCoda();

void Enqueue(Coda* q, int);

int Dequeue(Coda* q);

int isEmpty(Coda* q);

void printQueue(Coda* q);

void BFS1(Isole *g, int i, int *aux);

void BFS(Isole *g);

///////////////////////////////////////////////////////////////////////////////////////////////

// PROTOTIPI StampaPercorsoZIONI PER CALCOLO PERCORSO MINIMO

int ScegliMinore(int *d, int *s, int n, int);

int CalcoloPercorsoMinimo(int v, int *d, int *path, Isole *grafoIsola, int);

void StampaPercorso(Isole *grafoIsola, int, int, int, TestaProdotto *Testa);


//////////////////////////////////////////////////////////////////////////////////////////////

int CaricaVeicoloConProdotto(Autista utente, TestaProdotto *Testa);

void StampaProdotti();

int PrelevaProdotto(TestaProdotto *Testa, int codice, int quantita);

TestaProdotto *CreaTestaListaProdotti();

NodoProdotto *CreaNodoProdotto(int idProdotto, char nomeProdotto[], int peso, int quantita);

int VerificaProdotto(TestaProdotto *Testa, int idProdotto, int quantita);

void InserimentoInCoda(TestaProdotto *Testa, int idProdotto, char nomeProdotto[], int peso, int quantita);

void SvuotaLista(NodoProdotto *Testa);

void StampaListaProdottiScelti(TestaProdotto *Testa);
