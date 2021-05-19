// SORGENTE SOLO PER LA DEFINIZIONE DELLE FUNZIONI DEDICATE AL LOGIN E PASSWORD
#include "HeaderGestioneDati.h"
#include "HeaderInterfaccia.h"

// Funzione per registrare un nuovo utente nel programma
void RegistrazioneNuovoUtente() {

    system("cls");

    // Dichiariamo le variabili per conservare i dati dell'utente
    char nomeUtente[UTENTE_NOME_DIM];
    char passwordUtente[UTENTE_PSW_DIM];
    char nomeVeicolo[VEICOLO_NOME_DIM];
    int pesoVeicolo = 0;

    int ultimoID = 0;
    bool passwordOk = false;
    bool nomeOk = false;

    // Chiediamo, di volta in volta, i dati all'utente che si sta registrando
    do {

        system("cls");

        GeneraCampoUIVuoto(5);
        MostraLogo("Registrazione nuovo utente (PASSO 1/2)");

        printf("\t\tBenvenuto nella pagina di registrazione utente!\n");
        printf("\t\tAdesso le verranno chieste un paio di informazioni da inserire qui.");
        printf("\n\n\t\tInserire il Nome: ");
        scanf("%s", nomeUtente);

        nomeOk = VerificaNome(nomeUtente);

        if(nomeOk == false) {
            continue;
        }

        printf("\n\t\tInserire la password (min 4 - max 10 caratteri): ");
        scanf("%s", passwordUtente);

        passwordOk = VerificaPassword(passwordUtente);

        if(passwordOk == false) {
            continue;
        }

        // Preleviamo l'ultimo ID disponibile dal file Configurazione
        ultimoID = LeggiUltimoIDRegistrato();

        system("cls");

        GeneraCampoUIVuoto(5);
        MostraLogo("Registrazione nuovo utente (PASSO 2/2)");

        printf("\t\tIn questo passo devi inserire i dati del veicolo.\n\n");
        printf("\t\tInserisci il nome del veicolo: ");
        scanf("%s", nomeVeicolo);

        printf("\n\n\t\tInserisci il peso del veicolo in Kg: ");
        scanf("%d", &pesoVeicolo);

        // Scriviamo su file i dati ottenuti
        ScriviSuFileRegistrazione(ultimoID, nomeUtente, passwordUtente, nomeVeicolo, pesoVeicolo);

        fflush(stdin);

        system("cls");

        GeneraCampoUIVuoto(5);
        MostraLogo("Registrazione confermata");

        // Notifichiamo l'utente che la registrazione è terminata e può uscire dalla funzione
        printf(CONSOLE_COLORE_VERDE "\n\t\tRegistrazione terminata con successo!\n\n\t\t" CONSOLE_COLORE_BASE);
        printf("\n\t\tI tuoi dati sono:\n");
        printf("\t\tNome: %s-%04d\tPassword: %s\n", nomeUtente, ultimoID, passwordUtente);
        printf("\t\tVeicolo: %s\tPeso: %d", nomeVeicolo, pesoVeicolo);

        printf("\n\n\t\tPremere un tasto per ritornare indietro...");
        getchar();

        fflush(stdin);

        return;
    }
    while(1);

}


bool VerificaPassword(char password[]) {

    if(strlen(password) < 4 || strlen(password) > 10) {
        printf(CONSOLE_COLORE_ROSSO "\n\t\tLa password inserita non e' valida!" CONSOLE_COLORE_BASE);
        Sleep(3000);
        return false;
    }

    return true;
}


bool VerificaNome(char nome[]) {

    if(strlen(nome) < 4 || strlen(nome) > 15) {
        printf(CONSOLE_COLORE_ROSSO "\n\t\tIl nome inserito non e' valido!" CONSOLE_COLORE_BASE);
        Sleep(3000);
        return false;
    }

    return true;
}

// Funzione che scrive sul file dedicato alla memorizzazione degli utenti registrati al programma (Salva nel formato: NOME_UTENTE-ID_UTENTE PASSWORD)
void ScriviSuFileRegistrazione(int id, char nome[], char psw[], char nomeVeicolo[], int pesoVeicolo) {

    FILE *FileListaUtenti = fopen(FILE_LISTAUTENTI, "a");

    ControllaFile(FileListaUtenti, "ScriviSuFileRegistrazione");

    fprintf(FileListaUtenti, "%s-%04d %s %s %d\n", nome, id, psw, nomeVeicolo, pesoVeicolo);

    fclose(FileListaUtenti);

    return;
}

// Ritorna l'ultimo ID disponibile letto dal file di configurazione.
int LeggiUltimoIDRegistrato() {

    char IDPrelevato[5];
    int IDDaSalvare;

    FILE *fileConfigurazione = fopen(FILE_CONF, "r");

    ControllaFile(fileConfigurazione, "LeggiUltimoIDRegistrato");

    fseek(fileConfigurazione, 179, SEEK_SET);
    fscanf(fileConfigurazione, "%s", IDPrelevato);

    fclose(fileConfigurazione);

    IDDaSalvare = atoi(IDPrelevato);
    AggiornaIDFileConfigurazione(IDDaSalvare);

    return IDDaSalvare;
}

// Aggiorna il campo "ultimoIDRegistrato" all'interno del file di configurazione
void AggiornaIDFileConfigurazione(int id) {

    FILE *fileConfigurazione = fopen(FILE_CONF, "w");

    ControllaFile(fileConfigurazione, "AggiornaIDFileConfigurazione");

    fprintf(fileConfigurazione, "// QUESTO FILE CONTIENE ALCUNI PARAMETRI CHE IL SOFTWARE USA.\n// NON MODIFICARE.\n\n// PARAMETRO PER SAPERE IN FASE DI REGISTRAZIONE L'ULTIMO ID DISPONIBILE\nultimoIDRegistrato= %04d",id+1);

    fclose(fileConfigurazione);

    return;
}

void AccessoUtente() {

    system("cls");

    GeneraCampoUIVuoto(5);
    char nomeUtente[UTENTE_NOMECONID_DIM];
    char password[UTENTE_PSW_DIM];

    char nomeUtenteDaFile[UTENTE_NOMECONID_DIM];
    char passwordDaFile[UTENTE_PSW_DIM];

    FILE *fileListaUtenti = fopen(FILE_LISTAUTENTI, "r");
    ControllaFile(fileListaUtenti, "AccessoUtente");

    MostraLogo("Login Utente");

    do {

        printf("\n\t\tPagina di Accesso:\n\n");
        printf("\t\tInserire nome utente: ");
        scanf("%s",nomeUtente);

        printf("\t\tInserire password: ");
        scanf("%s",password);

        while(fscanf(fileListaUtenti, "%s %s", nomeUtenteDaFile, passwordDaFile) == 2) {
           if ( strcmp(nomeUtente, nomeUtenteDaFile) == 0 && strcmp(password, passwordDaFile) == 0) {
                printf("\n\t\tAccesso effettuato!\n\t\tSto andando nella pagina principale...");
                Sleep(3000);
                return;
           }
           else {
                printf("\n\t\tErrore:\n\t\tI dati inseriti sono incorretti.\n\t\tRitorno al menu di accesso...");
                Sleep(3000);
                return;
           }
        }
    }
    while(1);

}
