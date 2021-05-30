#include "HeaderConfigurazione.h"
#include "HeaderGestioneDati.h"
#include "HeaderVeicoli.h"
#include "HeaderInterfaccia.h"

// StampaPercorsoZIONI PER IL MENU

void MostraMenuPrincipale(Autista utente) {

    Isole *grafoIsole = creaGrafo(10);
    TestaProdotto *Testa = CreaTestaListaProdotti();

    CostruisciPonti(grafoIsole);

    int partenzaIsola = -1;
    int destinazioneIsola = -1;
    bool viaggioScelto = false;

    int opzione;

    do {
        system("cls");
        GeneraCampoUIVuoto(2);
        MostraLogo("Menu Principale");

        printf("\tBenvenuto %s nel Menu Principale!\n\n", utente.nomeUtente);
        printf("\tPeso Veicolo: %d\t  ", utente.pesoVeicolo);
        printf("Carico complessivo: %d (%d solo prodotti)\n", utente.pesoVeicolo+utente.pesoCarico, utente.pesoCarico);
        printf("\tIsola partenza: ");
        printf("%-10s",EstraiNomeIsolaDaID(partenzaIsola));
        printf(CONSOLE_COLORE_BASE "Isola destinazione: ");
        printf("%s",EstraiNomeIsolaDaID(destinazioneIsola));

        printf(CONSOLE_COLORE_BASE);

        printf("\n\n\n\tLe opzioni disponibili sono:\n\n");

        printf("\t1. Carica veicolo\n\t2. Seleziona percorso\n");
        printf("\t3. Gestisci carico veicolo\n\n");
        if( (utente.pesoCarico+utente.pesoVeicolo) == utente.pesoVeicolo || Testa->next == NULL || viaggioScelto == false) {
            printf(CONSOLE_COLORE_ROSSO "\t4. Consegna i prodotti\n\n" CONSOLE_COLORE_BASE);
        }
        else {
            printf("\t4. Consegna i prodotti\n\n");
        }
        printf("\t5. Effettua il logout\n\n\n");

        printf("\tScegli un'opzione: ");
        scanf("%d", &opzione);

        switch(opzione) {
            case 1: {
                utente.pesoCarico = CaricaVeicoloConProdotto(utente, Testa);
                break;
            }
            case 2: {
                StampaIsolePartenze(grafoIsole, &partenzaIsola, &destinazioneIsola);

                if(partenzaIsola != -1 && destinazioneIsola != -1)
                    viaggioScelto = true;

                break;
            }
            case 3: {
                StampaListaProdottiScelti(Testa);
                break;
            }
            case 4: {
                if( (utente.pesoCarico+utente.pesoVeicolo) == utente.pesoVeicolo || utente.pesoCarico+utente.pesoVeicolo > ARCO_PESO_MAX) {
                    printf(CONSOLE_COLORE_GIALLO "\n\t/_!_\\ Non puoi viaggiare con questo carico!" CONSOLE_COLORE_BASE);
                    Sleep(3000);
                }
                else if (viaggioScelto == false) {
                    printf(CONSOLE_COLORE_GIALLO "\n\t/_!_\\ Non hai selezionato correttamente il percorso!" CONSOLE_COLORE_BASE);
                    Sleep(3000);
                }
                else {
                    StampaPercorso(grafoIsole, partenzaIsola, destinazioneIsola, (utente.pesoCarico+utente.pesoVeicolo), Testa);
                    utente.pesoCarico = 0;
                    partenzaIsola = -1;
                    destinazioneIsola = -1;
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

char *EstraiNomeIsolaDaID(int id) {

    switch(id) {
        case 0: {
            return "Capri";
        }
        case 1: {
            return "Procida";
            }
        case 2: {
            return "Ischia";
            }
        case 3: {
            return "Stromboli";
            }
        case 4: {
            return "Sicilia";
        }
        case 5: {
            return "Vulcano";
        }
        case 6: {
            return "Corsica";
        }
        case 7: {
            return "Sardegna";
        }
        case 8: {
            return "Nisida";
        }
        case 9: {
            return "Elba";
        }
        default: {
            printf(CONSOLE_COLORE_ROSSO);
            return "N/A";
        }
    }
}
