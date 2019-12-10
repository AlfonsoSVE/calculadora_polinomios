#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


typedef struct monomio{
	int exp;
	float coef;
}mon;

typedef struct polinomio pol;

struct polinomio{
	int grado;
	mon *terminos;
};

pol pol1, pol2;
pol pol10, pol20;

void mul(int nmul, int ter1, int ter2, pol n1, pol n2);
void suma(int nsum, pol n1, pol n2);
void resta(int nres, pol n1, pol n2);


int main(){
	
	int terminos, terminos2, terminosf;
	int i, j;
	int aux;
	float aux2;
	int k=0;
	int temp;
	int expAc1, expAc0;
	int i1, i2;
	//variables para los 0
	/*int expAc1;
	int expAc0, Auw_expAc0;
	int dexp;
	int cont=0, cont2=0;
	int k=0, k2=0;
	int termul;*/

	printf("Ingrese el primer polinomio\n");
	printf("Cuantos terminos tiene el primer polinomio\n");
	scanf("%d", &terminos);

	pol1.terminos = (mon*)malloc(terminos*sizeof(mon));

	for(i = 0; i<terminos; i++)
	{
		printf("Ingrese el coeficiente del termino %d\n", i+1);
		scanf("%f", &pol1.terminos[i].coef);
		printf("Ingrese el grado del termino %d\n", i+1);
		scanf("%d", &pol1.terminos[i].exp);
	}
	
	printf("El primer polinomio que ingresaste es: ");
	for(i=0; i<terminos; i++)
	{
		printf("%.2fx^%d ", pol1.terminos[i].coef, pol1.terminos[i].exp);
	}
	
	//ordenar pol1
	for(i=0; i<terminos-1; i++){
		for(j=0; j<terminos-i-1; j++){
			if (pol1.terminos[j].exp > pol1.terminos[j+1].exp){
				
				aux = pol1.terminos[j].exp;
				pol1.terminos[j].exp = pol1.terminos[j+1].exp;
				pol1.terminos[j+1].exp = aux;

				aux2 = pol1.terminos[j].coef;
				pol1.terminos[j].coef = pol1.terminos[j+1].coef;
				pol1.terminos[j+1].coef = aux2;				
				
			}
		}
	}
	
	printf("\nEl primer polinomio ordenado es: ");
	for(i=0; i<terminos; i++)
	{
		printf("%.2fx^%d ", pol1.terminos[i].coef, pol1.terminos[i].exp);
	}
	
	printf("\nIngrese el segundo polinomio\n");
	printf("Cuantos terminos tiene el segundo polinomio\n");
	scanf("%d", &terminos2);
	
	pol2.terminos = (mon*)malloc(terminos2*sizeof(mon));

	for(int i = 0; i<terminos2; i++)
	{
		printf("Ingrese el coeficiente del termino %d\n", i+1);
		scanf("%f", &pol2.terminos[i].coef);
		printf("Ingrese el grado del termino %d\n", i+1);
		scanf("%d", &pol2.terminos[i].exp);
	}
	printf("El segundo polinomio que ingresaste es: ");
	for(int i=0; i<terminos2; i++)
	{
		printf("%.2fx^%d ", pol2.terminos[i].coef, pol2.terminos[i].exp);
	}
	
	//ordenando pol2
	for(i=0; i<terminos2-1; i++){
		for(j=0; j<terminos2-i-1; j++){
			if (pol2.terminos[j].exp > pol2.terminos[j+1].exp){
				
				aux = pol2.terminos[j].exp;
				pol2.terminos[j].exp = pol2.terminos[j+1].exp;
				pol2.terminos[j+1].exp = aux;

				aux2 = pol2.terminos[j].coef;
				pol2.terminos[j].coef = pol2.terminos[j+1].coef;
				pol2.terminos[j+1].coef = aux2;				
				
			}
		}
	}	

	
	printf("El segundo polinomio ordenado es: ");
	for(i=0; i<terminos2; i++)
	{
		printf("%.2fx^%d ", pol2.terminos[i].coef, pol2.terminos[i].exp);
	}
	
	printf("\n###%d %d####  ", pol1.terminos[0].exp, pol1.terminos[terminos-1].exp);
	printf("$$$$%d %d$$$$", pol2.terminos[0].exp, pol2.terminos[terminos2-1].exp);
	
	if((pol1.terminos[terminos-1].exp)>(pol2.terminos[terminos2-1].exp))//saber quien es mayor
		expAc1 = pol1.terminos[terminos-1].exp;
	else 
		expAc1 = pol2.terminos[terminos2-1].exp;
	printf(".....%d.....  ", expAc1);
	
	if((pol1.terminos[0].exp)<(pol2.terminos[0].exp))//saber el menor
		expAc0 = pol1.terminos[0].exp;
	else 
		expAc0 = pol2.terminos[0].exp;
	printf("......%d......", expAc0);
	//Auw_expAc0 = expAc0;
	
	terminosf = (expAc1-expAc0)+1; //total de nuevo polinomio
	
	pol10.terminos = (mon*)malloc(terminosf*sizeof(mon));
	pol20.terminos = (mon*)malloc(terminosf*sizeof(mon));
	
	for(i=0; i<terminosf; i++)
	{
	
		pol10.terminos[i].exp = expAc0 + i;
		pol10.terminos[i].coef = 0;
	}
	
	
	printf("\n");
	for(i=0; i<terminosf; i++)
	printf("%.2fx^%d  ", pol10.terminos[i].coef, pol10.terminos[i].exp);

//primera suma
	for(i=0; i<=terminosf; i++)
	{
		
		i1=i;
		i2=0;
	  //                        				i			0,1,2,3,4,5,6
	  //										k				2,3,4
		if(pol10.terminos[i].exp == pol1.terminos[k].exp)   
		{	
			temp = 1;
			pol10.terminos[i].exp = pol10.terminos[i].exp;
			pol10.terminos[i].coef = pol10.terminos[i].coef + pol1.terminos[k].coef;
			k++;
			i=i+temp;
		}
			
		if(pol10.terminos[i].exp != pol1.terminos[k].exp)
		{	
			
			pol10.terminos[i].exp = pol10.terminos[i].exp;
			pol10.terminos[i].coef = pol10.terminos[i].coef;
		}
		i2=i;
		if(i1!=i2)
			i--;
	}
	printf("\n\n");
	for(i=0; i<terminosf; i++)
		printf("%.2fx^%d     ", pol10.terminos[i].coef, pol10.terminos[i].exp);

//···········································································································
//segunda suma
	for(i=0; i<=terminosf; i++)
	{
		k=0; 
		i1=i;
		i2=0;
	  //                        				i			0,1,2,3,4,5,6
	  //										k				2,3,4
		if(pol10.terminos[i].exp == pol2.terminos[k].exp)   
		{	
			temp = 1;
			pol10.terminos[i].exp = pol10.terminos[i].exp;
			pol10.terminos[i].coef = pol10.terminos[i].coef + pol2.terminos[k].coef;
			k++;
			i=i+temp;
		}
			
		if(pol10.terminos[i].exp != pol2.terminos[k].exp)
		{	
			
			pol10.terminos[i].exp = pol10.terminos[i].exp;
			pol10.terminos[i].coef = pol10.terminos[i].coef;
		}
		i2=i;
		if(i1!=i2)
			i--;
	}
	printf("\n\n");
	for(i=0; i<terminosf; i++)
		printf("%.2fx^%d     ", pol10.terminos[i].coef, pol10.terminos[i].exp);

/*	do
	{
	
		if((pol1.terminos[k].exp)==expAc0)
		{
			pol10.terminos[cont].coef = pol1.terminos[k].coef;
			pol10.terminos[cont].exp = pol1.terminos[k].exp;
			expAc0++;
			cont++;
			k++;
		}
	
		if((pol1.terminos[k].exp)!=expAc0)
		{
			dexp = pol1.terminos[k].exp - expAc0;
			for(i=0; i<dexp; i++)
			{
				pol10.terminos[cont].coef = 0;
				pol10.terminos[cont].exp = expAc0 + i;
				cont = cont + 1;
			}
			//cont = cont + i;
			k++;
			expAc0 = pol1.terminos[k].exp; 
		}
    }while(k<terminos);
	
	do
	{
	
		if((pol2.terminos[k2].exp)==Auw_expAc0)
		{
			pol20.terminos[cont2].coef = pol2.terminos[k2].coef;
			pol20.terminos[cont2].exp = pol2.terminos[k2].exp;
			Auw_expAc0++;
			cont2++;
			k2++;
		}
	
		if((pol2.terminos[k2].exp)!=Auw_expAc0)
		{
			dexp = pol2.terminos[k2].exp - Auw_expAc0;
			for(i=0; i<dexp; i++)
			{
				pol20.terminos[cont2].coef = 0;
				pol20.terminos[cont2].exp = Auw_expAc0 + i;
				cont2 = cont2 + 1;
			}
			//cont = cont + i;
			k2++;
			Auw_expAc0 = pol2.terminos[k2].exp;
		}
    }while(k2<terminos2);
    
    termul = terminos * terminos2;
    suma(terminosf, pol10, pol20);
    mul(termul, terminos, terminos2, pol1, pol2);
 */  
    
    
	
	
	free(pol1.terminos);
	free(pol2.terminos);
	free(pol10.terminos);
	free(pol20.terminos);
	
	return 0;
}

void mul(int nmul, int ter1, int ter2, pol n1, pol n2)
{
	int i, j;

	
	pol polmul;
	polmul.terminos =(mon*)malloc(nmul*sizeof(mon));

	for (i=0; i<ter1; i++)
    	for(j=0; i<ter2; j++)
			{   
				polmul.terminos[j].exp = pol1.terminos[i].exp + pol2.terminos[j].exp;
				polmul.terminos[j].coef = pol1.terminos[i].coef * pol2.terminos[j].coef;
			}
			
	free(polmul.terminos);

}

void suma(int nsum, pol n1, pol n2)
{
	
	int i;
	pol sum;
	sum.terminos =(mon*)malloc(nsum*sizeof(mon));

	for(i=0; i<nsum; i++)
		sum.terminos[i].exp = n1.terminos[i].exp;
		sum.terminos[i].coef = n1.terminos[i].coef + n2.terminos[i].coef;

	printf("La suma es: ");
	for(i=0; i<nsum; i++)
	printf("%fx^%d", sum.terminos[i].coef, sum.terminos[i].coef);
	free(sum.terminos);
}

void resta(int nres, pol n1, pol n2)
{
	
	int i;
	pol res;
	res.terminos =(mon*)malloc(nres*sizeof(mon));

	for(i=0; i<nres; i++)
		res.terminos[i].exp = n1.terminos[i].exp;
		res.terminos[i].coef = n1.terminos[i].coef - n2.terminos[i].coef;

	printf("La suma es: ");
	for(i=0; i<nres; i++)
	printf("%fx^%d", res.terminos[i].coef, res.terminos[i].coef);
	free(res.terminos);
}
/*2   10 ............2,3,4,5,6,7,8,9,10

3 5    3,4,5 


1   5   1.2.3.4.5
3   10  3.4.5.6.7.8.9.10
*/

