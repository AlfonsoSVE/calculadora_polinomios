#include <stdio.h>
#include <stdlib.h>
#include"newfunciones.h"
 
int main()
{	
  int op;
  int gra1;
  float coef1;
  int num = 0;
  int cont=0;
  int op2;
  char grado[5], coeficiente[5];
  int graReal;
  float coefReal;
  int i, lon;
  int valida = 0, auxValida=0;
  
  
  do 
	{
  		printf("\n\n");
		menu();
		scanf("%d", &op);
		if((op <1) || (op > 9))
		{
			printf("Opcion invalida\n");
			while(op <1 || op > 9)
			{
				printf("Digita una opcion valida\n");
				scanf("%d", &op);
			}
		}

  

	
  	
  	if(op==1)
  		cont++;
  
  	
  
  	while (op==1)
	{
		do
	{
	 
		do 
		{
			printf("Ingresa el grado del termino\n");
			scanf("%s", &grado);
			lon = strlen(grado);
		
			for(i=0; i<lon; i++)
			{  //5s5
				if(isdigit(grado[i])==0)
					valida = valida + 1;
				else 
					valida = valida;
			}		
			auxValida = valida;
			valida = 0;
			if(auxValida !=0)
				printf("\tERROR\nSolo ingresa numeros enteros\n");
			
		}while(auxValida !=0);
		graReal = atoi(grado);
	
		do 
		{
			printf("Ingresa el coeficiente del termino\n");
			scanf("%s", &coeficiente);
			lon = strlen(coeficiente);
		
			for(i=0; i<lon; i++)
			{  //5s5
				if((coeficiente[i]=='.') || (isdigit(coeficiente[i])==1))
					valida = valida;
				else 
					valida = valida + 1;
			}		
			auxValida = valida;
			valida = 0;
			if(auxValida != 0)
				printf("\tERROR\nSolo ingresa numeros\n");
			
		}while(auxValida != 0);
		
		coefReal = atof(coeficiente);
	
		ingresarPol(graReal, coefReal);
		printf("%.2fx^%d", polinomio1->coeficiente, polinomio1->grado ); 
		printf("Deseas agregar otro termino al polinomio\n1.-Si\n2.-No\n");
		scanf("%d", &op2);	
		if(op2==1)
			cont++;
		
		
	}while(op2==1);
	
	
	int i=0;
	int graNew[cont];
	float coefNew[cont];
	
	while(polinomio1!=NULL){
		graNew[i]= polinomio1->grado; //0
		coefNew[i] = polinomio1->coeficiente;
		polinomio1 = polinomio1->sig;
		printf("%d..............", i);
		printf("####%d####", cont);
		i++;
	}
	
	int *ap;
	float *apun;
	
	ap = graNew;
	apun = coefNew;
	
	printf("\nEl polinomio que ingresaste es: ");
	
	for(i=0; i<cont; i++)
		printf("\n%.2fx^%d   ", *(apun+i), *(ap+i));
	
	

	op=0;
	
	
	

}
	

  		if (op!=0)
  		{
  
  			switch(op)
			  {
  				case 2: 
  				eliminar(); 
				break;
  				case 3: 
  				mostrarPol(polinomio1); 
  		
  	
  
				break;
	  			case 4: 
  				break;

  				default: 
  				printf("\nSaliendo del programa...");
  
  				return 0;
			  }
		  }
	}while(op!=4);

	
	
	return 0;
}


