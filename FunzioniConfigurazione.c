// FUNZIONI PER HEADER CONFIGURAZIONE
#include "HeaderConfigurazione.h"

void ControllaFile(FILE *fileCheck, char funzione[]) {

    if(fileCheck == NULL) {
        printf("\n\nErrore grave! (Nome funzione: %s)\nNon riesco ad aprire il file!", funzione);
        exit(-1);
    }
}
