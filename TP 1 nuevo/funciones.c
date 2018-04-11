
int suma (int x,int z)
{
    int valor;
    valor=x+z;
    return valor;
}

int resta (int x,int z)
{
    int valor;
    valor=x-z;
    return valor;
}

float division (float x,int z)
{
    float valor;
    valor=(float)x/z;
    return valor;
}

int multiplicacion (int x,int z)
{
    int valor;
    valor=x*z;
    return valor;
}

int factorial (int n)
{
    int i;
    int resp =1;
    if (n==1)
    {
        return 1;
    }
    else
    {
        for (i=n;i>1;i--)
        {
            resp = resp*i;
        }
    }
        return (resp);
}
