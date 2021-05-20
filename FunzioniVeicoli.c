#include "HeaderConfigurazione.h"
#include "HeaderVeicoli.h"
#include "HeaderGestioneDati.h"
#include "HeaderInterfaccia.h"

void StampaProdotti() {

    system("cls");

    int pesoProdotto = 0;
    int codiceProdotto = 0;
    char nomeProdotto[PRODOTTO_NOME_DIM];

    FILE *fileListaProdotti;
    fileListaProdotti = fopen(FILE_LISTAPRODOTTI, "r");

    ControllaFile(fileListaProdotti, "StampaProdotti");

    MostraLogo("Carica veicolo");
    printf(CONSOLE_COLORE_CIANO "\t\tCodice Prodotto \tNome Prodotto  \t    Peso Prodotto (Kg)\n\n" CONSOLE_COLORE_BASE);

    while(fscanf(fileListaProdotti, "%d %s %d", &codiceProdotto, nomeProdotto, &pesoProdotto) == 3) {

        printf("\t\t\t%d \t\t   %s \t\t%d\n", codiceProdotto, nomeProdotto, pesoProdotto);

    }
}

int CaricaVeicoloConProdotto(Autista utente) {

    int codiceProdotto;
    int quantita;

    do {
        StampaProdotti();
        printf("\n\n\t\tPeso carico: %d",utente.pesoVeicolo+utente.pesoCarico);
        printf("\n\n\t\tScegli 0 per terminare la spesa.");
        printf("\n\t\tInserisci il codice prodotto: ");
        scanf("%d", &codiceProdotto);

        if(codiceProdotto == 0)
            break;

        printf("\t\tInserisci la quantita: ");
        scanf("%d", &quantita);

        utente.pesoCarico += PrelevaProdotto(codiceProdotto, quantita);
    } while(1);

    return utente.pesoCarico;
}

int PrelevaProdotto(int codice, int quantita) {

    int pesoProdotto = 0;
    int codiceProdotto = 0;
    char nomeProdotto[PRODOTTO_NOME_DIM];

    FILE *fileListaProdotti;
    fileListaProdotti = fopen(FILE_LISTAPRODOTTI, "r");

    ControllaFile(fileListaProdotti, "PrelevaProdotto");

    while(fscanf(fileListaProdotti, "%d %s %d", &codiceProdotto, nomeProdotto, &pesoProdotto) == 3) {
        if (codice == codiceProdotto) {
            return quantita*pesoProdotto;
        }
    }

    return 0;
}
