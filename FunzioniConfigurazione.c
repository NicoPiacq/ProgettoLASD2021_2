// StampaPercorsoZIONI PER HEADER CONFIGURAZIONE
#include "HeaderConfigurazione.h"

// VERIFICA SE IL FILE IN INPUT ESISTE - VIENE INSERITO ANCHE IL NOME DELLA StampaPercorsoZIONE DA DOVE PROVIENE IL FILE
void ControllaFile(FILE *fileCheck, char StampaPercorsozione[]) {

    if(fileCheck == NULL) {
        MostraErrore(StampaPercorsozione);
    }
}

bool ControllaFileBool(FILE *fileCheck) {

    if(fileCheck == NULL) {
        return false;
    }

    return true;
}

// VERIFICA SE IL PROGRAMMA PUO' ESSERE CORRETTAMENTE AVVIATO
bool ControllaAvvio() {

    FILE *fileCheck = fopen(FILE_LISTAUTENTI, "r");

    if(ControllaFileBool(fileCheck) == false) {
        return false;
    }
    fclose(fileCheck);

    fileCheck = fopen(FILE_LISTAPRODOTTI, "r");
    if(ControllaFileBool(fileCheck) == false) {
        return false;
    }
    fclose(fileCheck);

    fileCheck = fopen(FILE_CONF, "r");
    if(ControllaFileBool(fileCheck) == false) {
        return false;
    }
    fclose(fileCheck);

    return true;
}
