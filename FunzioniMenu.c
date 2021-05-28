#include "HeaderConfigurazione.h"
#include "HeaderGestioneDati.h"
#include "HeaderVeicoli.h"
#include "HeaderInterfaccia.h"

// StampaPercorsoZIONI PER IL MENU

void MostraMenuPrincipale(Autista utente) {

    Isole *grafoIsole = creaGrafo(10);
    TestaProdotto *Testa = CreaTestaListaProdotti();

    CostruisciPonti(grafoIsole);

    int partenzaIsola;
    int destinazioneIsola;

    int opzione;

    do {
        system("cls");
        GeneraCampoUIVuoto(3);
        MostraLogo("Menu Principale");

        printf("\tBenvenuto %s nel Menu Principale\n", utente.nomeUtente);
        printf("\tPeso Veicolo: %d\t", utente.pesoVeicolo);
        printf("Carico attuale: %d\n\n", utente.pesoVeicolo+utente.pesoCarico);

        printf("\tLe opzioni disponibili sono:\n\n");

        if( (utente.pesoCarico+utente.pesoVeicolo) == utente.pesoVeicolo) {
            printf("\t1. Carica veicolo\n\t2. Seleziona percorso\n");
            printf(CONSOLE_COLORE_ROSSO "\t3. Gestisci carico veicolo\n\n" CONSOLE_COLORE_BASE);
            printf(CONSOLE_COLORE_ROSSO "\t4. Consegna i prodotti\n\n" CONSOLE_COLORE_BASE);
            printf("\t5. Effettua il logout\n\n\n");
        } else {
            printf("\t1. Carica veicolo\n\t2. Seleziona percorso\n");
            printf("\t3. Gestisci carico veicolo\n\n");
            printf("\t4. Consegna i prodotti\n\n");
            printf("\t5. Effettua il logout\n\n\n");
        }

        printf("\tScegli un'opzione: ");
        scanf("%d", &opzione);

        switch(opzione) {
            case 1: {
                utente.pesoCarico = CaricaVeicoloConProdotto(utente, Testa);
                break;
            }
            case 2: {
                StampaIsolePartenze(grafoIsole, &partenzaIsola, &destinazioneIsola);
                break;
            }
            case 3: {
                if (Testa->next == NULL) {
                    printf(CONSOLE_COLORE_GIALLO "\n\t/_!_\\ Non hai caricato nessun prodotto nel veicolo!" CONSOLE_COLORE_BASE);
                    Sleep(3000);
                }
                else {
                    StampaListaProdottiScelti(Testa);
                }

                break;
            }
            case 4: {
                if( (utente.pesoCarico+utente.pesoVeicolo) == utente.pesoVeicolo || utente.pesoCarico+utente.pesoVeicolo > ARCO_PESO_MAX) {
                    printf(CONSOLE_COLORE_GIALLO "\n\t/_!_\\ Non puoi viaggiare con questo carico!" CONSOLE_COLORE_BASE);
                    Sleep(3000);
                }
                else {
                    StampaPercorso(grafoIsole, partenzaIsola, destinazioneIsola, (utente.pesoCarico+utente.pesoVeicolo), Testa);
                }
                break;
            }
            case 5: {

                SvuotaLista(Testa->next);

                return;
            }
        }
    }
    while(1);

}
