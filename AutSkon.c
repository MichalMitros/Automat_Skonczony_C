#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>



int p[8];

int q;

int in=-1;

const int delay=1;



void clrscr()

{

    int i;

    for(i=0; i<20; i++)

        printf("\n");

}



void rysuj_diagram()

{

    printf("    ----   ");

    if(p[0]==1) printf(">0<"); else printf(" 0 ");

    printf("   ####\n   |    |------>#    #\n   |");

    if(q==0) printf(">q0<"); else printf(" q0 ");

    printf("|       #");

    if(q==1) printf(">q1<"); else printf(" q1 ");

    printf("#\n   |    |<------#    #\n    ----   ");

    if(p[1]==1) printf(">1<"); else printf(" 1 ");

    printf("   ####\n    |  ^         |  ^\n    |  |         |  |\n ");

    if(p[2]==1) printf(">1<"); else printf(" 1 ");

    printf("|  |");

    if(p[3]==1) printf(">0<"); else printf(" 0 ");

    printf("   ");

    if(p[4]==1) printf(">0<"); else printf(" 0 ");

    printf("|  |");

    if(p[5]==1) printf(">0<"); else printf(" 0 ");

    printf("\n    |  |         |  |\n    v  |         v  |\n    ----   ");

    if(p[6]==1) printf(">1<"); else printf(" 1 ");

    printf("   ----\n   |    |------>|    |START\n   |");

    if(q==2) printf(">q2<"); else printf(" q2 ");

    printf("|       |");

    if(q==3) printf(">q3<"); else printf(" q3 ");

    printf("|<----\n   |    |<------|    |\n    ----   ");

    if(p[7]==1) printf(">1<"); else printf(" 1 ");

    printf("   ----\n\n");

}



void czysc_p()

{

    int i;

    for(i=0; i<8; i++)

        p[i] = 0;

}



int przejscie(int we, int ob)

{

    if(ob==0 && we==0) return 1;

    else if(ob==0 && we==1) return 2;

    else if(ob==1 && we==0) return 3;

    else if(ob==1 && we==1) return 0;

    else if(ob==2 && we==0) return 0;

    else if(ob==2 && we==1) return 3;

    else if(ob==3 && we==0) return 1;

    else if(ob==3 && we==1) return 2;

}



void nast_p(int we, int ob)

{

    czysc_p();

    if(ob==0 && we==0) p[0]=1;

    if(ob==1 && we==1) p[1]=1;

    if(ob==0 && we==1) p[2]=1;

    if(ob==2 && we==0) p[3]=1;

    if(ob==1 && we==0) p[4]=1;

    if(ob==3 && we==0) p[5]=1;

    if(ob==2 && we==1) p[6]=1;

    if(ob==3 && we==1) p[7]=1;

}



int main(int argc, char ** argv)

{

    if(argc==1)

    {

        printf("\nBlad: Prosze wprowadzic tasme wejsciowa!\n\n");

        return EXIT_FAILURE;

    }



    czysc_p();

    int i;

    int j;



    in=-1;

    q=3;



    /*clrscr();

    printf("Tasma wejsciowa:");

    for(j=1; j<argc; j++)

        printf(" %s", argv[j]);

    printf("\n\n");



    rysuj_diagram();

    */

    sleep(delay);



    for(i=1; i<argc; i++)

    {

        clrscr();

        printf("Tasma wejsciowa:");

        for(j=1; j<argc; j++)

            printf(" %s", argv[j]);

        printf("\n\n");

        rysuj_diagram();

        sleep(delay);

        in = atoi(argv[i]);

        nast_p(in, q);

        clrscr();

        printf("Tasma wejsciowa:");

        for(j=1; j<argc; j++)

            printf(" %s", argv[j]);

        printf("\n\n");

        rysuj_diagram();

        sleep(delay);

        q = przejscie(in, q);

    }

    //in = atoi(argv[i]);

    //q = przejscie(q, in);

    clrscr();

    printf("Tasma wejsciowa:");

    for(j=1; j<argc; j++)

        printf(" %s", argv[j]);

    printf("\n\n");

    czysc_p();

    rysuj_diagram();

    sleep(delay);



    if(q==1)

        printf("\nAutomat zaakceptowal wejscie!\n\n");

    else

        printf("\nAutomat NIE zaakceptowal wejscia!\n\n");



    sleep(2*delay);



    return EXIT_SUCCESS;

}
