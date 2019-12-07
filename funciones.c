#include "funciones.h"

pol* crear_polinomio(){
	pol *p;
	p = (pol*)malloc(sizeof(pol));
	p->primero = NULL;
	p->num = 0;
	return p;
}

mon* crear_monomio(int e, float c){
	mon* m;
	m = (mon*)malloc(sizeof(mon));
	m->grado=e;
	m->coef=c;
	m->sig=NULL;
	
	return m;
}

pol* llenar_polinomio()
{
	pol* p;
	
	char grado[5], coeficiente[5];
	int graReal;
	float coefReal;
	int i, lon, op;
	int valida = 0, auxValida=0;
	
	
	/*int i, n, e, a;
	n=1;
	a=1;
	
	float c;*/
	
	p = crear_polinomio();
	

		
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
	
		agregar(p, graReal, coefReal);
		printf("Deseas agregar otro termino al polinomio\n1.-Si\n2.-No\n");
		scanf("%d", &op);	
		
	}while(op==1);
		/*printf("Ingresa el coeficiente del monomio: ");
		scanf("%f", &c);
		
		printf("Ingresa el grado del monomio: ");
		scanf("%d", &e);
		
		agregar(p, c, e);
		printf("Desea agregar otro monomio\n1.-Si\n2.-No ");
		scanf("%d", &a);*/
		/*if(a==2){
			printf("Polinomio terminado....\n");
			a=0;
		}*/
	return p;
}


void agregar(pol *p, int e, float c){
	if(p==NULL){
		p = crear_polinomio();
		p->primero = crear_monomio(e, c);
	}else if(p->primero==NULL)
		p->primero = crear_monomio(e, c);
	else{
		mon* t;
		t = p->primero;
		
		while(t->sig!= NULL){
			t = t->sig;
		}
		t->sig = crear_monomio(e, c);
	}	
	p->num++;
}
