/*
 * SECONDO PROGETTO DI GRUPPO - LAB. DI ALGORITMI E STRUTTURE DATI
 * PARTECIPANTI: ALESSIO SERRA (N86002813)
 *               PIACQUADDIO NICOLA (N86002904)
 *
 * SOFTWARE: SPEDIZIONI I-EATS
 * SCOPO: GESTIRE LE CONSEGNE DELL'AZIENDA I-EATS SU UN ARCIPELAGO (GRAFO) TRAMITE DRIVER
 *
 * DATA ULTIMA BUILD: 19/05/2021
 */

#include "HeaderConfigurazione.h"
#include "HeaderGestioneDati.h"
#include "HeaderInterfaccia.h"

int main()
{
    ImpostaTitoloConsole("I-Eats");

    if(ControllaAvvio() == false) {
        MostraErrore("main");
    }

    int opzione = 0;

    do {
        system("cls");

        GeneraCampoUIVuoto(5);
        MostraLogo("Pagina di Accesso");

        printf("\t\tBenvenuto nel programma I-EATS\n\n");
        printf("\t\tSono disponibili due opzioni in questo menu:");
        printf("\n\n\t\t1. Accesso al software\n\t\t2. Registrazione nuovo utente");

        printf("\n\n\t\t3. Esci dal programma");

        printf("\n\n\n\t\tScegliere un'opzione: ");
        scanf("%d",&opzione);


        switch(opzione) {
            case 1: {
                MostraMenuPrincipale(AccessoUtente());
                break;
            }
            case 2: {
                RegistrazioneNuovoUtente();
                break;
            }
            case 3: {

                system("cls");
                GeneraCampoUIVuoto(5);
                MostraLogo(" ");

                printf(CONSOLE_COLORE_VERDE "\n\n\n\t\t\t\t\tArrivederci! :-)\n\n" CONSOLE_COLORE_BASE);
                Sleep(2000);
                return 0;
            }
        }
    }
    while(1);
}
