#include "HeaderConfigurazione.h"
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
    printf(CONSOLE_COLORE_CIANO "\tCodice Prodotto \tNome Prodotto  \t    Peso Prodotto (Kg)\n\n" CONSOLE_COLORE_BASE);

    while(fscanf(fileListaProdotti, "%d %s %d", &codiceProdotto, nomeProdotto, &pesoProdotto) == 3) {

        printf("\t\t%d \t\t   %s \t\t%d\n", codiceProdotto, nomeProdotto, pesoProdotto);

    }
}

int CaricaVeicoloConProdotto(Autista utente, TestaProdotto *Testa) {

    int codiceProdotto;
    int quantita;
    int pesoTotale;

    do {
        StampaProdotti();
        pesoTotale =  utente.pesoVeicolo + utente.pesoCarico;;
        MostraBarraPeso( pesoTotale, ARCO_PESO_MAX);
        printf("\n\n\tPeso carico: %d\n",utente.pesoVeicolo+utente.pesoCarico);

        if( pesoTotale >= ARCO_PESO_MAX) {
            printf(CONSOLE_COLORE_ROSSO "\n\tHai raggiunto il limite di peso!\n\tPremi INVIO per uscire...\a");
            fflush(stdin);
            getchar();
            fflush(stdin);

            return utente.pesoCarico;
        }
        else {
            printf("\n\tScegli 0 per terminare la spesa.");
            printf("\n\tInserisci il codice prodotto: ");
            scanf("%d", &codiceProdotto);
        }

        if(codiceProdotto == 0)
            break;

        printf("\tInserisci la quantita: ");
        scanf("%d", &quantita);

        utente.pesoCarico += PrelevaProdotto(Testa, codiceProdotto, quantita);
    } while(1);

    return utente.pesoCarico;
}

int PrelevaProdotto(TestaProdotto *Testa, int codice, int quantita) {

    int pesoProdotto = 0;
    int codiceProdotto = 0;
    char nomeProdotto[PRODOTTO_NOME_DIM];

    FILE *fileListaProdotti;
    fileListaProdotti = fopen(FILE_LISTAPRODOTTI, "r");

    ControllaFile(fileListaProdotti, "PrelevaProdotto");

    while(fscanf(fileListaProdotti, "%d %s %d", &codiceProdotto, nomeProdotto, &pesoProdotto) == 3) {
        if (codice == codiceProdotto) {

            if(VerificaProdotto(Testa, codiceProdotto, quantita) == 0)
                InserimentoInCoda(Testa, codiceProdotto, nomeProdotto, pesoProdotto, quantita);

            return quantita*pesoProdotto;
        }
    }

    return 0;
}

TestaProdotto *CreaTestaListaProdotti() {

	TestaProdotto * TestaTemp = NULL;
	TestaTemp = (TestaProdotto *)malloc(sizeof (TestaProdotto));

	if(TestaTemp) {
		TestaTemp->next = NULL;
	}
	else
		return NULL;

	return TestaTemp;

}

NodoProdotto *CreaNodoProdotto(int idProdotto, char nomeProdotto[], int peso, int quantita) {

	NodoProdotto * tmp = (NodoProdotto *) malloc(sizeof(NodoProdotto));

	// VERIFICHIAMO CHE TMP E' STATO CORRETTAMENTE CREATO
	if (!tmp)
		return NULL; // TMP NON CREATO CORRETTAMENTE.
	else {
		tmp->next = NULL;

		strcpy(tmp->nomeProdotto, nomeProdotto);
		tmp->idProdotto = idProdotto;
		tmp->pesoSpecifico = peso;
		tmp->quantita = quantita;
	}

	return tmp;
}

int VerificaProdotto(TestaProdotto *Testa, int idProdotto, int quantita) {

    if(Testa->next == NULL)
        return 0;

     NodoProdotto *Ricerca = Testa->next;
     while(Ricerca != NULL && Ricerca->next != NULL) {
        if(idProdotto == Ricerca->idProdotto) {
            Ricerca->quantita += quantita;
            return 1;
        }
        Ricerca = Ricerca->next;
	}

	if(Ricerca->next == NULL)
        if(idProdotto == Ricerca->idProdotto) {
            Ricerca->quantita += quantita;
            return 1;
        }

	return 0;
}

void StampaListaProdottiScelti(TestaProdotto *Testa) {

    system("cls");

    NodoProdotto *Ricerca = Testa->next;

    MostraLogo("Gestisci carico veicolo");
    printf(CONSOLE_COLORE_CIANO "\tCodice Prodotto \tNome Prodotto  \t    Peso Prodotto (Kg)  \t    Quantita'\n\n" CONSOLE_COLORE_BASE);

    while(Ricerca != NULL && Ricerca->next != NULL) {
        printf("\t\t%d \t\t   %s \t\t%d \t\t%d\n", Ricerca->idProdotto, Ricerca->nomeProdotto, Ricerca->pesoSpecifico, Ricerca->quantita);
        Ricerca = Ricerca->next;
	}

	if(Ricerca->next == NULL) {
        printf("\t\t%d \t\t   %s \t\t%d \t\t%d\n", Ricerca->idProdotto, Ricerca->nomeProdotto, Ricerca->pesoSpecifico, Ricerca->quantita);
	}

	fflush(stdin);
	printf("\n\n\tPremi INVIO per uscire...");
	getchar();
	fflush(stdin);
}

void InserimentoInCoda(TestaProdotto *Testa, int idProdotto, char nomeProdotto[], int peso, int quantita) {
	NodoProdotto *temp = NULL;
	NodoProdotto *Ricerca = Testa->next;

	// Verifichiamo se la lista non ha prodotti inseriti (è vuota)
	if (!Testa->next) {
		temp = CreaNodoProdotto(idProdotto, nomeProdotto, peso, quantita);

		if(temp) {
			Testa->next = temp;
			return;
		}
	}
	// Se non lo è, aggiungiamo in coda il prodotto scelto dall'utente
	else {
		temp = CreaNodoProdotto(idProdotto, nomeProdotto, peso, quantita);

		while(Ricerca->next) {
			Ricerca = Ricerca->next;
		}

		Ricerca->next = temp;
	}

	return;
}

void SvuotaLista(NodoProdotto *testa){
    NodoProdotto *tmp;

    if(testa){
        tmp = testa;
        SvuotaLista(testa->next);
        free(tmp);
    }
}
