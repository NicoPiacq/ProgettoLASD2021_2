#include "HeaderConfigurazione.h"
#include "HeaderInterfaccia.h"
#include "HeaderVeicoli.h"
#include "HeaderGestioneDati.h"

// FUNZIONI PER IL MENU

void MostraMenuPrincipale(Autista utente) {

    int opzione;

    do {
        system("cls");
        GeneraCampoUIVuoto(3);
        MostraLogo("Menu Principale");

        printf("\t\tBenvenuto %s nel Menu Principale\n", utente.nomeUtente);
        printf("\t\tPeso Veicolo: %d\t", utente.pesoVeicolo);
        printf("Carico attuale: %d\n\n", utente.pesoVeicolo+utente.pesoCarico);

        printf("\t\tLe opzioni disponibili sono:\n\n");

        if( (utente.pesoCarico+utente.pesoVeicolo) == utente.pesoVeicolo) {
            printf("\t\t1. Carica veicolo\n\t\t2. Seleziona percorso\n");
            printf(CONSOLE_COLORE_ROSSO "\t\t3. Consegna i prodotti\n\n" CONSOLE_COLORE_BASE);
            printf("\t\t4. Effettua il logout\n\n\n");
        } else {
            printf("\t\t1. Carica veicolo\n\t\t2. Seleziona percorso\n");
            printf("\t\t3. Consegna i prodotti\n\n");
            printf("\t\t4. Effettua il logout\n\n\n");
        }

        printf("\t\tScegli un'opzione: ");
        scanf("%d", &opzione);

        switch(opzione) {
            case 1: {
                utente.pesoCarico = CaricaVeicoloConProdotto(utente);
                break;
            }
            case 2: {

                break;
            }
            case 3: {

                if( (utente.pesoCarico+utente.pesoVeicolo) == utente.pesoVeicolo ) {
                    printf(CONSOLE_COLORE_GIALLO "\n\t\t/_!_\\ Non hai caricato nessun prodotto nel veicolo!" CONSOLE_COLORE_BASE);
                    Sleep(3000);
                }

                break;
            }
            case 4: {
                return;
            }
        }
    }
    while(1);

}
