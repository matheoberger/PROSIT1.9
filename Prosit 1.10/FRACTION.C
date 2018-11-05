typedef struct fraction
{
    int num;
    int denom;
} Fraction;


Fraction detect()
{
    Fraction frac1;
    char a;
    do
    {
        scanf("%i %c %i",&frac1.num,&a,&frac1.denom);
    }
    while(frac1.denom == 0);
    return frac1;
}

Fraction PGCD(Fraction frac)
{
    Fraction tampon = frac;
    while(frac.denom!=0)
    {
        int a = (frac.num)%(frac.denom);
        frac.num = frac.denom;
        frac.denom=a;
    }
    tampon.num = tampon.num / frac.num;
    tampon.denom = tampon.denom / frac.num;
    return tampon;
}
Fraction addition(Fraction fraca, Fraction fracb)
{
    Fraction result;
    if(fraca.denom == fracb.denom)
    {
        result.num = fraca.num + fracb.num;
        result.denom = fraca.denom;
    }
    else
    {
        fraca.num = fraca.num*fracb.denom;
        printf("%i\n", fraca.num);
        fracb.num = fracb.num*fraca.denom;
        result.denom = fraca.denom*fracb.denom;
        result.num = fraca.num+fracb.num;
    }

    return PGCD(result);
}

Fraction soustraction(Fraction fraca, Fraction fracb)
{
    Fraction result;
    if(fraca.denom == fracb.denom)
    {
        result.num = fraca.num - fracb.num;
        result.denom = fraca.denom;
    }
    else
    {
        fraca.num = fraca.num*fracb.denom;
        printf("%i\n", fraca.num);
        fracb.num = fracb.num*fraca.denom;
        result.denom = fraca.denom*fracb.denom;
        result.num = fraca.num-fracb.num;
    }
    return PGCD(result);
}
Fraction multiplication(Fraction fraca, Fraction fracb)
{
    Fraction result;
    result.denom = fraca.denom*fracb.denom;
    result.num = fraca.num*fracb.num;
    return PGCD(result);
}

Fraction division(Fraction fraca, Fraction fracb)
{
    Fraction result;
    result.num = fracb.denom;
    result.denom = fracb.num;
    return PGCD(multiplication(fraca,result));
}

Fraction operation(int ope, Fraction frac1, Fraction frac2)
{
    Fraction resultat;
    switch (ope)
    {
    case '+' :
        resultat = addition(frac1, frac2);
        return resultat;
    case '-' :
        resultat = soustraction(frac1, frac2);
        return resultat;
    case '*' :
        resultat = multiplication(frac1, frac2);
        return resultat;
    case '/' :
        resultat = division(frac1, frac2);
        return resultat;
    default :
        printf("HEY CALISSE CEST PARTI EN SUCETTE");
        exit(1);
    }
}
Fraction affichage (Fraction Fracresult)
{
    if (Fracresult.num == Fracresult.denom)
    {
        printf("_____________________________________");
        printf("   = 1 ");
        printf("_____________________________________");
    }
    else
    {
        if(Fracresult.num ==0)
        {
            printf("______________________________________");
            printf("   = 0 ");
            printf("______________________________________");
        }
        else
        {
            printf("_____________________________________");
            printf("   = %i / %i   ",Fracresult.num, Fracresult.denom);
            printf("_____________________________________");

        }

    }
}
void menu()
{
    char ope;
    printf("_______________________");
    printf("Hey, rentre le signe de ton operation");
    printf("_______________________\n");
    scanf("%c", &ope);
    printf("Quels sont les fractions a calculer?\n");
    Fraction FFrac = detect();
    Fraction SFrac = detect();
    affichage ( operation (ope, FFrac, SFrac));
}
