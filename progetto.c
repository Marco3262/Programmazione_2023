/* Inclusione delle librerie */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Dichiarazione delle funzioni */

/* Funzione per la validazione del menu*/
int validator_cycle();

/* Funzione per la validazione di un intero maggiore/maggiore uguale di n*/
int validator_num(int n,
                  char x);

/* Funzione che stabilisce se il numero inserito è un numero primo */
int validator_first_num(int val);

/* Funzione per stabilire se ci sono fattori primi in comune */
void common_first_num(int a, 
                      int b, 
                      int c);

/* Funzione per validare la correttezza dell'equazione */
void equation_validator(int a, 
                        int b, 
                        int c,
                        int x,
                        int y,
                        int z);

/* Funzione per la verifica della congettura di Beal */
void beal_conjecture();

/* Funzione per la verifica della congettura di Collatz */
void collatz_conjecture();

/* Funzione per la validazione del numero primo successivo a quello inserito */
int validator_next_first_num(int val);

/* Funzione per la verifica della congettura di Cramer */
void cramer_conjecture();

/* Definizione della funzione main */
int main()
{
    int val;   /* Input: variabile per la selezione nel menu */
    
    /* Si stampa il menu */
    printf("Progetto di programmazione.\n");
    printf("Scegli quale congettura verificare tra le seguenti:\n");
    printf("0. Congettura di Beal.\n");
    printf("1. Congettura di Collatz\n");
    printf("2. Congettura di Cramer\n");
    printf("Inserisci valore corrispondente: ");
    
    /* Si acquisisce la variabile per la scelta nel menu */
    val = validator_cycle();
    
    /* Si avvia l'opzione inserita */
    switch(val)
    {
        case 0:
            beal_conjecture();
            break;
        case 1:
            collatz_conjecture();
            break;
        case 2:
            cramer_conjecture();
            break;
    }
 
    return 0;
}

/* Funzione per la validazione del menu*/
int validator_cycle()
{

    int val,            /* Input:  variabile che identifica il valore inserito da validare */
        control;        /* Lavoro: variabile di controllo della scanf */

    /* Acquisisco valore */ 
    control = scanf("%d",
                    &val);
    
    /* Avvio un ciclo quando il valore non è compreso tra 0 e 2 */
    while(val < 0 ||
          val > 2 ||
          control != 1)
    {
            
            printf("Il valore non è corretto. Riprova: ");
            /* Pulisco il buffer */
            scanf("%*[^\n]");
            /* Riacquisisco il valore */
            control = scanf("%d",
                            &val);
        
    }
    /* Restituisco il valore validato */
    return val;
}

/* Funzione per la validazione di un intero maggiore di n*/
int validator_num(int n,            /* Lavoro: variabile che identifica il valore da non superare */
                  char x)           /* Lavoro: variabile di controllo della stampa */
{

    int val,            /* Input:  variabile che identifica il valore inserito da validare */
        control;        /* Lavoro: variabile di controllo della scanf */
    
    /* Acquisisco valore */ 
    control = scanf("%d",
                    &val);
    /* Avvio un ciclo che impone che il valore sia maggiore di n */
    while(val < n ||
          control != 1)
    {

            /* Faccio un controllo per la stampa */
            if(x == 'y')
            {
                printf("Deve essere un NUMERO MAGGIORE di %d.\n"
                        "Inserisci di nuovo: ",
                        n-1);
            }else
            {
                printf("Deve essere un NUMERO MAGGIORE UGUALE di %d.\n"
                       "Inserisci di nuovo: ",
                       n);
            }
            
            /* Pulisco il buffer */
            scanf("%*[^\n]");
            /* Riacquisisco il valore */
            control = scanf("%d",
                            &val);   
    }
    /* Restituisco il valore validato */
    return val;
}

/* Funzione che stabilisce se il numero inserito è un numero primo */
int validator_first_num(int val)    /* Input: variabile che identifica il valore da validare */
{
    int i;              /* Lavoro: variabile contatore di ciclo */
    int control = 1;    /* Lavoro: variabile di controllo che indica se il numero è primo */
        
    /*  Verifico che il numero inserito sia un numero primo
        dividendolo ogni volta per due in su e verificando
        se si ottiene un resto oppure no */
    for(i = 2;
        control == 1 &&
        i < val;
        i++)
    {
        if(val%i == 0)
        {
            /*  Se non c'è resto vuol dire che il numero 
                non è primo poichè è divisibile perciò 
                setto control a zero e richiedo un nuovo inserimento */
            control = 0; 
        }
    }
    /* Restituisco il risultato */
    return control;
}

/* Funzione per stabilire se ci sono fattori primi in comune */
void common_first_num(int a,        /* Input: variabile che identifica il valore da confrontare */
                      int b,        /* Input: variabile che identifica il valore da confrontare */
                      int c)        /* Input: variabile che identifica il valore da confrontare */
{
    int i,              /* Lavoro: variabile contatore di ciclo */
        control = 0,    /* Lavoro: variabile di controllo che identifica se un numero è primo */
        count = 0;      /* Lavoro: variabile contatore che indica se c'è un fattore primo in comune */
    
    /* Confronto i fattori primi di a con quelli di b e c */
    for(i = 2;
        i <= a;
        i++)
    {
        /* Setto ogni volta la variabile control a 0 
            ogni volta che si ripete il ciclo */
        control = 0;
        
        /* Verifico prima di tutto che il fattore è primo */
        control = validator_first_num(i);
        
        /* Se il fattore è primo verifico che lo sia per tutti */
        if(control == 1 &&
           a%i == 0 && 
           b%i == 0 && 
           c%i == 0)
        {
            printf("Un fattore primo in comune è %d\n",i);
            count++;    
        }
    }
    
    /* Se non ci sono fattori primi, lo stampo a video */
    if(count == 0)
    {
        printf("Non ci sono fattori primi in comune.\n");
    }  
}

/* Funzione per validare la correttezza dell'equazione */
void equation_validator(int a,      /* Input: variabile che identifica il valore nell'equazione */
                        int b,      /* Input: variabile che identifica il valore nell'equazione */
                        int c,      /* Input: variabile che identifica il valore nell'equazione */
                        int x,      /* Input: variabile che identifica il valore nell'equazione */
                        int y,      /* Input: variabile che identifica il valore nell'equazione */
                        int z)      /* Input: variabile che identifica il valore nell'equazione */
{
    
    /* Calcolo le varie potenze */
    a = pow(a,
            x);
    b = pow(b,
            y);
    c = pow(c,
            z);
    
    /* Sommo a + b */
    a = a + b;
    
    /* Verifico se è valida e se non è così, lo stampo a video */
    if(a != c)
    {
        printf("L'equazione non è valida.\n");
    }  
}

/* Funzione per la verifica della congettura di Beal */
void beal_conjecture()
{
    int a,     /*Input: variabile che identifica il valore di a */
        b,     /*Input: variabile che identifica il valore di b */
        c,     /*Input: variabile che identifica il valore di c */
        x,     /*Input: variabile che identifica il valore di x */
        y,     /*Input: variabile che identifica il valore di y */
        z;     /*Input: variabile che identifica il valore di z */
    
    /* Acquisisco i dati */
    printf("Inserisci il valore di a: ");
    a = validator_num(1,
                      'n');
    printf("Inserisci il valore di b: ");
    b = validator_num(1,
                      'n');
    printf("Inserisci il valore di c: ");
    c = validator_num(1,
                      'n');
    printf("Inserisci il valore di x: ");
    x = validator_num(3,
                      'n');
    printf("Inserisci il valore di y: ");
    y = validator_num(3,
                      'n');
    printf("Inserisci il valore di z: ");
    z = validator_num(3,
                      'n');
    
    /* Verifico se l'equazione è valida */
    equation_validator(a,
                       b,
                       c,
                       x,
                       y,
                       z);
    
    /* Verifico se sono presenti fattori primi in comune */
    common_first_num(a,
                     b,
                     c);

}

/* Funzione per la verifica della congettura di Collatz */
void collatz_conjecture()
{
    
    int val;    /* Input: Variabile che identifica il valore inserito */
    
    printf("Inserisci valore: ");
    /* Acquisisco il valore */
    val = validator_num(1,
                        'y');
    
    /* Inizio a stampare la sequenza finchè non arrivo a uno o zero */
    printf("La sequenza è:\n");
    
    printf("%d\n",
           val);
    while(val != 1 || val != 0)
    {
        /* Stabilisco il caso in cui il numero è pari */
        if(val%2 == 0)
        {
            /* Lo divido per due e lo stampo */
            val = val/2;
            printf("%d\n",
                    val);
        }else
        {
            /* Se è dispari lo moltiplico per tre, aggiungo uno e lo stampo */
            val = val*3;
            val++;
            printf("%d\n",
                    val); 
        }
    }
}

/* Funzione per la validazione del numero primo successivo a quello inserito */
int validator_next_first_num(int val)
{
    
    int control = 0,    /* Lavoro: variabile di controllo che indica se un numero è primo */
        next,           /* Output: variabile che identifica il numero primo successivo */
        ins_val;        /* Input: variabile che indica il valore inserito da validare */
    
    /* Inizio dal valore successivo */
    val++;
    
    /*  Effettuo la verifica su ogni numero successivo al primo
        finchè non trovo quello primo */
    for(next = val;
        control == 0;
        next++)
    {
        control = validator_first_num(next);
    }
    
    /* Correggo il valore */
    next--;

    printf("Inserisci il numero primo successivo: ");
    /*  Richiedo il numero primo successivo finchè non è
        quello giusto */
    do{
        /* Acquisisco il valore */
        scanf("%d",
              &ins_val);

        /* Se non è il successivo stampo l'errore */
        if(ins_val != next)
        {
            fflush(stdin);
            printf("Non è corretto. Riprova: ");
        }
    }while(ins_val != next);
   
   /* Restituisco il valore successivo */
   return(next);
}

/* Funzione per la verifica della congettura di Cramer */
void cramer_conjecture()
{

    int val1,           /* Input: variabile che identifica il primo numero primo validato */
        val2,           /* Input: variabile che identifica il numero primo successivo */
        abs_diff,       /* Output: variabile che identifica il valore assoluto della differenza */
        control;        /* Lavoro: variabile di controllo che indica se il numero è primo */
    double squared_log; /* Output: variabile che identifica il quadrato del logaritmo naturale */
    
    printf("Inserisci un numero primo: ");
    do{
        val1 = validator_num(12,
                            'y');
        control = validator_first_num(val1);
        
        if(control == 0)
        {
            printf("Non è un numero primo.\n" 
                        "Inserisci di nuovo: ");
        }
    }while(control != 1);
    
    val2 = validator_next_first_num(val1);
    abs_diff = abs(val1-val2);
    printf("Il valore assoluto della differenza tra i due numeri primi è %d\n",
            abs_diff);
    
    squared_log = log(val1);
    squared_log = pow(squared_log,
                  2);
    printf("Il quadrato del logartimo naturale del numero primo più piccolo è %.2f\n",
            squared_log);

}
