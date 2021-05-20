// DEFINIZIONI DELLE FUNZIONI RIGUARDANTI L'INTERFACCIA GRAFICA
#include "HeaderInterfaccia.h"

void MostraLogo(char sottotitolo[]) {

    printf(CONSOLE_COLORE_CIANO "\t\t _____            ________        _        _________    ______  \n");
    printf(CONSOLE_COLORE_CIANO "\t\t|_   _|          |_   __  |      / \\      |  _   _  | .' ____ \\ \n");
    printf(CONSOLE_COLORE_CIANO "\t\t  | |    ______    | |_ \\_|     / _ \\     |_/ | | \\_| | (___ \\_|\n");
    printf(CONSOLE_COLORE_BLU "\t\t  | |   |______|   |  _| _     / ___ \\        | |      _.____`. \n");
    printf(CONSOLE_COLORE_VERDE "\t\t _| |_            _| |__/ |  _/ /   \\ \\_     _| |_    | \\____) |\n");
    printf(CONSOLE_COLORE_VERDE "\t\t|_____|          |________| |____| |____|   |_____|    \\______.'\n");
    printf(CONSOLE_COLORE_GIALLO "\t\t%s                                                                \n\n\n" CONSOLE_COLORE_BASE ,sottotitolo);

}

void MostraLogoNoColore(char sottotitolo[]) {

    printf("\t\t _____            ________        _        _________    ______  \n");
    printf("\t\t|_   _|          |_   __  |      / \\      |  _   _  | .' ____ \\ \n");
    printf("\t\t  | |    ______    | |_ \\_|     / _ \\     |_/ | | \\_| | (___ \\_|\n");
    printf("\t\t  | |   |______|   |  _| _     / ___ \\        | |      _.____`. \n");
    printf("\t\t _| |_            _| |__/ |  _/ /   \\ \\_     _| |_    | \\____) |\n");
    printf("\t\t|_____|          |________| |____| |____|   |_____|    \\______.'\n");
    printf(CONSOLE_COLORE_GIALLO "\t\t%s                                                                \n\n\n" CONSOLE_COLORE_BASE ,sottotitolo);

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

    printf(CONSOLE_COLORE_ROSSO "\n\t\tErrore grave nel software.\n\t\tVerifica che tutti i file nella cartella 'Dati' siano presenti e riavvia il software.\n\n\t\tErrore in: %s\n\n" CONSOLE_COLORE_BASE, errorCode);
    printf(CONSOLE_COLORE_GIALLO "\t\tPremi INVIO per chiudere..." CONSOLE_COLORE_BASE);

    fflush(stdin);

    getchar();
    exit(-1);

}

void ImpostaTitoloConsole(char stringa[]) {

    SetConsoleTitle(stringa);

}
