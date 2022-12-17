#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int validator_cycle();
int validator_num(int n,char x);
int validator_first_num(int a);
void common_first_num(int a, int b, int c);
void equation_validator(int a, int b, int c, int x, int y, int z);
void beal_conjecture();
void collatz_conjecture();
int validator_next_first_num(int val);
void cramer_conjecture();

int main()
{
    int a;
    
    printf("Progetto di programmazione.\n");
    printf("Scegli quale congettura verificare tra le seguenti:\n");
    printf("0. Congettura di Beal.\n");
    printf("1. Congettura di Collatz\n");
    printf("2. Congettura di Cramer\n");
    printf("Inserisci valore corrispondente: ");
    
    a = validator_cycle();
    switch(a){
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
int validator_cycle(){

    int a,
        control;
    
    /* Acquisisco valore */ 
    control = scanf("%d",&a);
    
    /* Avvio un ciclo quando il valore non è compreso tra 0 e 2 */
    
    while(a < 0 || a > 2 || control != 1){
            
            printf("Non è corretto. Riprova: ");
            
            /* Pulisco il buffer */
            scanf("%*[^\n]");
            /* Riacquisisco il valore */
            control = scanf("%d",&a);
        
    }
    
    return a;

}

/* Funzione per la validazione di un intero maggiore di n*/
int validator_num(int n,char x){

    int a,
        control;
    
    /* Acquisisco valore */ 
    control = scanf("%d",&a);
    /* Avvio un ciclo che impone che il valore sia maggiore di n */
    while(a < n || control != 1){
            
            /* Faccio un controllo per la stampa */
            if(x == 'y'){
                printf("Deve essere un NUMERO MAGGIORE di %d.\n"
                        "Inserisci di nuovo: ",n-1);
            }else{
                printf("Deve essere un NUMERO MAGGIORE UGUALE di %d.\n"
                    "Inserisci di nuovo: ",n);
            }
            
            /* Pulisco il buffer */
            scanf("%*[^\n]");
            /* Riacquisisco il valore */
            control = scanf("%d",&a);
        
    }
    
    return a;

}

/* Funzione che stabilisce se il numero inserito è un numero primo */
int validator_first_num(int a){
    
    int i;
    int control = 1;
        
    /* Verifico che il numero inserito sia un numero primo */
    /* dividendolo ogni volta per due in su e verificando */
    /* se si ottiene un resto oppure no */
    for(i = 2; control == 1 && i < a; i++){
        
        if(a%i == 0){
            /* Se non c'è resto vuol dire che il numero */
            /* non è primo poichè è divisibile perciò */
            /* setto control a zero e richiedo un nuovo inserimento */
            control = 0;
            
        }
    }
    return control;
}

/*Funzione per stabilire se ci sono fattori primi in comune */
void common_first_num(int a, int b, int c){
    
    int i,
        control = 0,
        count = 0;
    
    /* Confronto i fattori primi di a con quelli di b e c */
    for(i = 2; i <= a; i++){
        
        /* Setto ogni volta la variabile control a 0 ogni volta che */
        /* si ripete il ciclo */
        control = 0;
        
        /* Verifico prima di tutto che il fattore è primo */
        control = validator_first_num(i);
        
        /* Se il fattore è primo verifico che lo sia per tutti*/
        if(control == 1 && a%i == 0 && b%i == 0 && c%i == 0){
            

            
            /* DA RIVEDERE CICLI IF ANNIDATI */
            
            
            /* Controllo perchè un numero non può essere fattore primo di se stesso */
            if(i != a && i != b && i != c){
                printf("Un fattore primo in comune è %d\n",i);
                count++;
            }
        }
    }
    
    /* Se non ci sono fattori primi, lo stampo a video */
    if(count == 0){
        printf("Non ci sono fattori primi in comune.\n");
    }
    
}

/* Funzione per validare la correttezza dell'equazione */
void equation_validator(int a, int b, int c, int x, int y, int z){
    
    /* Calcolo le varie potenze */
    a = pow(a,x);
    b = pow(b,y);
    c = pow(c,z);
    
    /* Sommo a + b */
    a = a + b;
    
    /* Verifico se è valida e se non è così, lo stampo a video */
    if(a != c){
        printf("L'equazione non è valida.\n");
    }
    
}

/* Funzione per la verifica della congettura di Beal */
void beal_conjecture(){
    int a,
        b,
        c,
        x,
        y,
        z;
    
    /* Acquisisco i dati */
    printf("Inserisci il valore di a: ");
    a = validator_num(1,'n');
    printf("Inserisci il valore di b: ");
    b = validator_num(1,'n');
    printf("Inserisci il valore di c: ");
    c = validator_num(1,'n');
    printf("Inserisci il valore di x: ");
    x = validator_num(3,'n');
    printf("Inserisci il valore di y: ");
    y = validator_num(3,'n');
    printf("Inserisci il valore di z: ");
    z = validator_num(3,'n');
    
    /* Verifico se l'equazione è valida */
    equation_validator(a,b,c,x,y,z);
    
    /* Verifico se sono presenti fattori primi in comune */
    common_first_num(a,b,c);

}

/* Funzione per la verifica della congettura di Collatz */
void collatz_conjecture(){
    
    int val;
    
    printf("Inserisci valore da testare: ");
    /* Acquisisco il valore */
    val = validator_num(1,'y');
    
    /* Inizio a stampare la sequenza */
    printf("La sequenza è:\n");
    /* Stampo la sequenza finchè non arrivo a uno */
    
    printf("%d\n",val);
    while(val != 1){
        /* Stabilisco il caso in cui il numero è pari */
        if(val%2 == 0){
            /* Lo divido per due e lo stampo */
            val = val/2;
            printf("%d\n",val);
        }else{
            /* Se è dispari lo moltiplico per tre, aggiungo uno e lo stampo */
            val = val*3;
            val++;
            printf("%d\n",val);
            
        }
    }
}

/* FUNZIONI PER LA CONGETTURA DI CRAMER */

int validator_next_first_num(int val){
    
    int control = 0,
        next,
        val_ins;
    
    /* Inizio dal valore successivo */
    val++;
    
    /* Effettuo la verifica su ogni numero successivo al primo */
    /* finchè non trovo quello primo */
    for(next = val; control == 0; next++)
    {
        control = validator_first_num(next);
    }
    
    next--;

    printf("Inserisci il numero primo successivo: ");
    /* Richiedo il numero primo successivo fnchè non è */
    /* quello giusto */
    do{
        /* Acquisisco il valore */
        scanf("%d",&val_ins);
        if(val_ins != next){
            fflush(stdin);
            printf("Non è corretto. Riprova: ");
        }
    }while(val_ins != next);
   
   return(next);
}

/* Funzione per la verifica della congettura di Cramer */
void cramer_conjecture(){

    int diff,
        val1,
        val2,
        control;
    double log_nat;
    
    printf("Inserisci un numero primo: ");
    do{
        
        val1 = validator_num(12,'y');
        control = validator_first_num(val1);
        
        if(control == 0){
            printf("Non è un numero primo.\n" 
                        "Inserisci di nuovo: ");
        }

    }while(control != 1);
    
    val2 = validator_next_first_num(val1);
    diff = abs(val1-val2);
    printf("Il valore assoluto della differenza tra i due numeri primi è %d\n",diff);
    
    log_nat = log(val1);
    log_nat = pow(log_nat,2);
    printf("Il quadrato del logartimo naturale del numero primo più piccolo è %.2lf\n",log_nat);

}
