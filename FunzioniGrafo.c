#include "HeaderConfigurazione.h"
#include "HeaderGestioneDati.h"
#include "HeaderInterfaccia.h"
#include "HeaderVeicoli.h"

// StampaPercorsozione per creare il grafo
Isole* creaGrafo(int vertici) {
  Isole* graph = malloc(sizeof(Isole));
  graph->numeroIsole = vertici;

  graph->adiacente = malloc(vertici * sizeof(Ponte*));
  graph->visitati = malloc(vertici * sizeof(int));

  int i;
  for (i = 0; i < vertici; i++) {
    graph->adiacente[i] = NULL;
    graph->visitati[i] = 0;
  }

  return graph;
}

Ponte* createNode(int vertice, char nomeIsola[]) {
  Ponte* newNode = malloc(sizeof(Ponte));
  newNode->key = vertice;
  strcpy(newNode->nomeIsolaAttuale, nomeIsola);
  newNode->next = NULL;
  return newNode;
}

void AggiungiPonte(Isole *grafo, int sorgente, int destinazione, int peso, char nomeIsolaSorgente[], char nomeIsolaDestinazione[]) {
  // Add edge from src to dest
  Ponte* newNode = createNode(destinazione, nomeIsolaDestinazione);
  newNode->next = grafo->adiacente[sorgente];
  newNode->portataMassima = peso;
  grafo->adiacente[sorgente] = newNode;

  // Add edge from dest to src
  newNode = createNode(sorgente, nomeIsolaSorgente);
  newNode->next = grafo->adiacente[destinazione];
  newNode->portataMassima = peso;
  grafo->adiacente[destinazione] = newNode;
}

int grafoVuoto(Isole *grafo) {

    return (grafo == NULL);

}

// StampaPercorsozione solo per debug
void stampaGrafo(Isole *grafo) {

    int i;
    int ne = 0;

    Ponte *e;

    if(!grafoVuoto(grafo)) {
        printf("L'arcipelago ha %d isole\n\n",grafo->numeroIsole);
    }

    for(i = 0; i < grafo->numeroIsole; i++) {

        switch(i) {
            case 0: {
                printf("Isole adiacenti a Capri ->");
                break;
            }
             case 1: {
                printf("Isole adiacenti a Procida -> ");
                break;
            }
            case 2: {
                printf("Isole adiacenti a Ischia -> ");
                break;
            }
            case 3: {
                printf("Isole adiacenti a Stromboli -> ");
                break;
            }
            case 4: {
                printf("Isole adiacenti a Sicilia -> ");
                break;
            }
            case 5: {
                printf("Isole adiacenti a Vulcano -> ");
                break;
            }
            case 6: {
                printf("Isole adiacenti a Corsica -> ");
                break;
            }
            case 7: {
                printf("Isole adiacenti a Sardegna -> ");
                break;
            }
            case 8: {
                printf("Isole adiacenti a Nisida -> ");
                break;
            }
            case 9: {
                printf("Isole adiacenti a Elba -> ");
                break;
            }
        }

        e = grafo->adiacente[i];

        while(e != NULL) {
           // printf("%s (portata ponte: %d) ",e->nomeIsolaDestinazione, e->portataMassima);

            ne = ne + 1;

            e = e->next;
        }
        printf("\n");
    }

    printf("Il grafo ha %d archi ",ne/2);

}

void StampaIsolePartenze(Isole *mappa, int *partenzaIsola, int *destinazioneIsola) {

    system("cls");

    GeneraCampoUIVuoto(3);
    MostraLogo("Scegli il percorso");

    printf(CONSOLE_COLORE_CIANO "\tCodice Isola \tNome Isola\n\n" CONSOLE_COLORE_BASE);

    printf("\t\t1 \tCapri\n");
    printf("\t\t2 \tProcida\n");
    printf("\t\t3 \tIschia\n");
    printf("\t\t4 \tStromboli\n");
    printf("\t\t5 \tSicilia\n");
    printf("\t\t6 \tVulcano\n");
    printf("\t\t7 \tCorsica\n");
    printf("\t\t8 \tSardegna\n");
    printf("\t\t9 \tNisida\n");
    printf("\t\t10 \tElba\n");

    printf("\n\n\tPremi 0 per uscire.");
    printf("\n\tInserisci il codice dell'isola di partenza: ");
    scanf("%d",partenzaIsola);

    *partenzaIsola = *partenzaIsola - 1;

    if(*partenzaIsola == -1) {
        return;
    }

    printf("\n\tInserisci il codice dell'isola di destinazione: ");
    scanf("%d",destinazioneIsola);

    *destinazioneIsola = *destinazioneIsola - 1;

    if(*destinazioneIsola == -1) {
        return;
    }

    if(*partenzaIsola == *destinazioneIsola) {
        printf(CONSOLE_COLORE_ROSSO "\n\tPartenza e destinazione coincidono!\n\tScegli nuovamente il percorso!");
        Sleep(3000);
    }
}

void CostruisciPonti(Isole *grafoIsole) {

    AggiungiPonte(grafoIsole, 0, 1, 25000, "Capri", "Procida");
    AggiungiPonte(grafoIsole, 0, 2, 15000, "Capri", "Ischia");
    AggiungiPonte(grafoIsole, 0, 8, 40000, "Capri", "Nisida");
    AggiungiPonte(grafoIsole, 1, 3, 30000, "Procida", "Stromboli");
    AggiungiPonte(grafoIsole, 1, 9, 50000, "Procida", "Elba");
    AggiungiPonte(grafoIsole, 2, 3, 30000, "Ischia", "Stromboli");
    AggiungiPonte(grafoIsole, 2, 7, 25000, "Ischia", "Sardegna");
    AggiungiPonte(grafoIsole, 3, 4, 10000, "Stromboli", "Sicilia");
    AggiungiPonte(grafoIsole, 4, 5, 30000, "Sicilia", "Vulcano");
    AggiungiPonte(grafoIsole, 5, 6, 45000, "Vulcano", "Corsica");
    AggiungiPonte(grafoIsole, 6, 7, 30000, "Corsica", "Sardegna");
    AggiungiPonte(grafoIsole, 8, 9, 35000, "Nisida", "Elba");

}

// Create a queue
Coda* CreaCoda() {
  Coda* q = malloc(sizeof(Coda));
  q->fronte = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(Coda* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void Enqueue(Coda* q, int value) {
  if (q->rear == 40 - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->fronte == -1)
        q->fronte = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int Dequeue(Coda* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->fronte];
    q->fronte++;
    if (q->fronte > q->rear) {
      //printf("Resetting queue ");
      q->fronte = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(Coda* q) {
  int i = q->fronte;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    //printf("\nQueue contains \n");
    for (i = q->fronte; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}

void BFS1(Isole *g, int i, int *aux) {

    Ponte *e;
    Coda *q = CreaCoda();

    Enqueue(q, i);

    while(!isEmpty(q)) {

        i = Dequeue(q);
        aux[i] = 1;

        for(e = g->adiacente[i]; e; e = e->next) {
            if(!aux[e->key]) {
                Enqueue(q, e->key);
                printf("%d,", e->key);
                //printf("\t      %d \t%-10s\t\n", e->key+1, e->nomeIsolaAttuale);
                aux[e->key] = 1;
            }
        }
    }
}

void BFS(Isole *g) {

    int i, *aux = calloc(g->numeroIsole, sizeof(int));

    for(i=0; i<g->numeroIsole; i++) {
        if(!aux[i]) {
            printf("%d\n",i);
            //printf("\t      %d \t%-10s\t\n", e->key+1, e->nomeIsolaAttuale);
            BFS1(g, i, aux);
        }
        free(aux);
    }

}

int ScegliMinore(int *d, int *s, int n) {
    int i, minpos, min;
    min = INFINITO;
    minpos = -1;

    for(i=0; i < n; i++) {
        if(d[i] < min && !s[i]) {
            min=d[i];
            minpos=i;
        }
    }
    return minpos;
}

int CalcoloPercorsoMinimo(int v, int *d, int *path, Isole *grafoIsola) {
     int i, k;
     Ponte *p;
     p = grafoIsola->adiacente[v];
     int *s;

     if( v < 0 || v > grafoIsola->numeroIsole-1) {
         return -1;
     }

     s = (int*) malloc(sizeof(int) * grafoIsola->numeroIsole);

     for(i=0; i < grafoIsola->numeroIsole; i++) {
         s[i]=0;
         path[i] = -1;
         d[i] = INFINITO;
     }

     while(p) {
         d[p->key] = p->portataMassima;

         if(p->key != v && d[p->key] <= INFINITO) {
             path[p->key] = v;
         }

         p = p->next;
    }

     s[v]=1;
     d[v]=0;

     for(i=0; i < grafoIsola->numeroIsole; i++) {

         k = ScegliMinore(d, s, grafoIsola->numeroIsole);

         if(k == -1) {
             continue;
         }

         s[k] = 1;
         p = grafoIsola->adiacente[k];

         if(p == NULL) {
             continue;
         }


         while(p) {
             if(!s[p->key] && d[k] + p->portataMassima < d[p->key] )
             {
                 d[p->key]=d[k]+p->portataMassima;
                 path[p->key] = k;
             }
             p = p->next;
         }
     }
     return 0;
}

void AdattaPontiConPeso(Isole *grafoAux, int peso) {

    if(peso <= 10000) {
        AggiungiPonte(grafoAux, 3, 4, 10000, "Stromboli", "Sicilia");
    }

    if(peso <= 15000) {
        AggiungiPonte(grafoAux, 0, 2, 15000, "Capri", "Ischia");
    }

    if(peso <= 25000) {
       AggiungiPonte(grafoAux, 2, 7, 25000, "Ischia", "Sardegna");
       AggiungiPonte(grafoAux, 0, 1, 25000, "Capri", "Procida");
    }

    if(peso <= 30000) {
        AggiungiPonte(grafoAux, 1, 3, 30000, "Procida", "Stromboli");
        AggiungiPonte(grafoAux, 4, 5, 30000, "Sicilia", "Vulcano");
        AggiungiPonte(grafoAux, 2, 3, 30000, "Ischia", "Stromboli");
        AggiungiPonte(grafoAux, 6, 7, 30000, "Corsica", "Sardegna");
    }

    if(peso <= 35000) {
        AggiungiPonte(grafoAux, 8, 9, 35000, "Nisida", "Elba");
    }

    if(peso <= 40000) {
        AggiungiPonte(grafoAux, 0, 8, 40000, "Capri", "Nisida");
    }

    if(peso <= 45000) {
        AggiungiPonte(grafoAux, 5, 6, 45000, "Vulcano", "Corsica");
    }

    if(peso <= 50000) {
      AggiungiPonte(grafoAux, 1, 9, 50000, "Procida", "Elba");
    }

}

void StampaPercorso(Isole *grafoIsola, int partenza, int destinazione, int carico, TestaProdotto *Testa) {

    system("cls");
    MostraLogo("Consegna prodotti");

    Isole *grafoAux = creaGrafo(10);
    AdattaPontiConPeso(grafoAux, carico);

    BFS(grafoIsola);

    system("pause");

    int d[grafoIsola->numeroIsole];
    int path[grafoIsola->numeroIsole];

    CalcoloPercorsoMinimo(partenza, d, path, grafoAux);

    printf("\tIl percorso effettuato e': ");
    if(path[destinazione] == -1) {
        printf(CONSOLE_COLORE_ROSSO "Nessun percorso disponibile.\n" CONSOLE_COLORE_BASE);
        return;
    }

    while (path[destinazione] != -1) {
        //printf("%d <--- ",destinazione);

        switch(destinazione) {
            case 0: {
                printf("Capri <--- ");
                break;
            }
            case 1: {
                printf("Procida <--- ");
                break;
            }
            case 2: {
                printf("Ischia <--- ");
                break;
            }
            case 3: {
                printf("Stromboli <--- ");
                break;
            }
            case 4: {
                printf("Sicilia <--- ");
                break;
            }
            case 5: {
                printf("Vulcano <--- ");
                break;
            }
            case 6: {
                printf("Corsica <--- ");
                break;
            }
            case 7: {
                printf("Sardegna <--- ");
                break;
            }
            case 8: {
                printf("Nisida <--- ");
                break;
            }
            case 9: {
                printf("Elba <--- ");
                break;
            }
        }
        destinazione = path[destinazione];
    }

    switch(partenza) {
        case 0: {
            printf("Capri\n\n");
            break;
        }
        case 1: {
            printf("Procida\n\n");
            break;
            }
        case 2: {
            printf("Ischia\n\n");
            break;
            }
        case 3: {
            printf("Stromboli\n\n");
            break;
            }
        case 4: {
            printf("Sicilia\n\n");
            break;
            }
        case 5: {
            printf("Vulcano\n\n");
            break;
            }
        case 6: {
            printf("Corsica\n\n");
            break;
            }
        case 7: {
            printf("Sardegna\n\n");
            break;
        }
        case 8: {
            printf("Nisida\n\n");
            break;
        }
        case 9: {
            printf("Elba\n\n");
            break;
        }
    }

    SvuotaLista(Testa->next);

    system("pause");
}
