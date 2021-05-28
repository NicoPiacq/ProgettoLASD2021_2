// DEFINIZIONI DELLE StampaPercorsoZIONI RIGUARDANTI L'INTERFACCIA GRAFICA
#include "HeaderConfigurazione.h"

void MostraLogo(char sottotitolo[]) {

    printf(CONSOLE_COLORE_CIANO "\t _____            ________        _        _________    ______  \n");
    printf(CONSOLE_COLORE_CIANO "\t|_   _|          |_   __  |      / \\      |  _   _  | .' ____ \\ \n");
    printf(CONSOLE_COLORE_CIANO "\t  | |    ______    | |_ \\_|     / _ \\     |_/ | | \\_| | (___ \\_|\n");
    printf(CONSOLE_COLORE_BLU "\t  | |   |______|   |  _| _     / ___ \\        | |      _.____`. \n");
    printf(CONSOLE_COLORE_VERDE "\t _| |_            _| |__/ |  _/ /   \\ \\_     _| |_    | \\____) |\n");
    printf(CONSOLE_COLORE_VERDE "\t|_____|          |________| |____| |____|   |_____|    \\______.'\n");
    printf(CONSOLE_COLORE_GIALLO "\t%s                                                                \n\n" CONSOLE_COLORE_BASE ,sottotitolo);

}

void MostraLogoNoColore(char sottotitolo[]) {

    printf("\t _____            ________        _        _________    ______  \n");
    printf("\t|_   _|          |_   __  |      / \\      |  _   _  | .' ____ \\ \n");
    printf("\t  | |    ______    | |_ \\_|     / _ \\     |_/ | | \\_| | (___ \\_|\n");
    printf("\t  | |   |______|   |  _| _     / ___ \\        | |      _.____`. \n");
    printf("\t _| |_            _| |__/ |  _/ /   \\ \\_     _| |_    | \\____) |\n");
    printf("\t|_____|          |________| |____| |____|   |_____|    \\______.'\n");
    printf(CONSOLE_COLORE_GIALLO "\t%s                                                                \n\n" CONSOLE_COLORE_BASE ,sottotitolo);

}

void GeneraCampoUIVuoto(int n) {
    int i = 0;

    for(i = 0; i < n; i++) {
        printf("\n");
    }

    return;
}

void MostraErrore(char errorCode[]) {

    system("cls");
    GeneraCampoUIVuoto(5);
    MostraLogoNoColore("");

    printf(CONSOLE_COLORE_ROSSO "\n\tErrore grave nel software.\n\tSi e' verificato un errore e non e' possibile proseguire.\n\n\tErrore in: %s\n\n" CONSOLE_COLORE_BASE, errorCode);
    printf(CONSOLE_COLORE_GIALLO "\tPremi INVIO per chiudere..." CONSOLE_COLORE_BASE);

    fflush(stdin);

    getchar();
    exit(-1);

}

void ImpostaTitoloConsole(char stringa[]) {

    SetConsoleTitle(stringa);

}

void MostraBarraPeso(float pesoCarico, float pesoMassimoPonti) {

    printf(CONSOLE_COLORE_VERDE "\n\t   0%%" CONSOLE_COLORE_BASE);
    printf(CONSOLE_COLORE_GIALLO " \t\t      50%%" CONSOLE_COLORE_BASE);
    printf(CONSOLE_COLORE_ROSSO "\t\t\t100%%\n\t   " CONSOLE_COLORE_BASE);

    int i = 0;
    float pesoInPercentuale;

    pesoInPercentuale = (pesoCarico / pesoMassimoPonti) * 50;

    for(i = 0; i < pesoInPercentuale; i++) {

        if(pesoInPercentuale > 50) {
            pesoInPercentuale = 50;
            i = 0;
            continue;
        }

        if(i >= 40) {
            printf(CONSOLE_COLORE_ROSSO "%c" CONSOLE_COLORE_BASE, 219);
        }
        else if(i >= 20) {
            printf(CONSOLE_COLORE_GIALLO "%c" CONSOLE_COLORE_BASE, 219);
        }
        else {
            printf(CONSOLE_COLORE_VERDE "%c" CONSOLE_COLORE_BASE, 219);
        }
    }

}
