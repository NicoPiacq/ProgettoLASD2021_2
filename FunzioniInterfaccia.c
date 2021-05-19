// DEFINIZIONI DELLE FUNZIONI RIGUARDANTI L'INTERFACCIA GRAFICA
#include "HeaderInterfaccia.h"

void MostraLogo(char sottotitolo[]) {

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
