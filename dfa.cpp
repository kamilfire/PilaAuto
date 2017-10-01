#include "iostream.h"
#include "istream.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
int **delta;	//matriz en donde se va a guardar la funcion de transicion delta
char *alfabeto; //arreglo en el cual se va a guardar el alfabeto
char *palabra;  //arreglo en donde se guarda la palabra a ser examinada por el dfa
int longi,qtemp,auxi=0, auxi2=0, auxi3=0; //longi para guardar longitud de palabra
										  //qtemp para ir guardando los estados 
										  //auxi 0 1 2 3 variables de control
		
void comprobar_estados(int estados, int estado_auxi);







//*********funcion en la cual el usuario introduce la palabra a ser examinada por el dfa*****/////

void introducir_palabra(int i){
	cout<<"Por favor ingrese su palabra formada por su alfabeto definido"<<endl;
	cout<<"su alfabeto definido es el siguiente; "<<endl<<endl;
	//despliega en pantalla el lafabeto definido por el usuario para que se base en el
	cout<<"{";
	for (int z=0; z<=i-1; z++){
		cout<<alfabeto[z]<<",";
	}
	//
	cout<<"}"<<endl<<endl;
	cout<<"Palabra:  ";
	cin>>palabra;
//	cout<<strlen(palabra)<<endl;
}


              //*******FUNCION PARA LLENAR LA FUNCION DE TRANSICION DELTA*****//////

void llenadodelta (int estados, int simbolos){
	int x,y, var3;   //X Y variables de control para for  y var3 variable de control para bucle
	cout<<endl<<"      **************DEFINIENDO LA MATRIZ DELTA*********"<<endl;
	cout<<endl<<endl<<endl<<"En estos momentos se iniciara el llenado de la funcion delta:"<<endl;

	for(x=0; x<=estados-1; x++){ //for que recorre los estados
		for(y=0; y<=simbolos-1; y++){//for que recorre los simbolos que contiene el alfabeto
			
			var3=1;
			while(var3==1){
			cout<<endl<<"Ingrese: "<<"S(q"<<x<<","<<alfabeto[y]<<")=  ";
			cin>>delta[x][y];
			comprobar_estados(estados, delta[x][y]); //llama a funcion que comprueba si el estado ingresado es correcto
			
			if(auxi2==0) //auxi tendra el valor de 0 en caso de haber escrito un q que este definido en los estados
				var3=0;  //se le pone el valor de 0 a var3 para que ya no siga preguntando por otro valor ya esta correcto

			}//fin del while

		}//fin del for que recorre el alfabeto
	}//fin del for que recorre los estados

	//se procede a imprimir en pantalla la matriz generada por el usuario
	cout<<endl<<endl<<endl<<endl<<"Esta es la matriz delta generada por el usuario "<<endl<<endl<<endl;
	for( x=0; x<=estados-1; x++){//for que recorre los estados
		for(y=0; y<=simbolos-1; y++){//for que recorre el alfabeto
			cout<<"S(q"<<x<<","<<alfabeto[y]<<")= "<<delta[x][y]<<" "<<" "<<" ";

		}//fin del for que recorre el alfabeto
		cout<<endl<<endl;
	}//fin del for que recorre los estados
	cout<<"presione una tecla para continuar"<<endl;
	getch();
}



//********FUNCION QUE COMPRUEBA QUE LA PALABRA ESCRITA ES VALIDA PARA EL ALFABETO DEFINIDO*****//

void comprobar_palabra(int i){
	int lon; 
	lon=strlen(palabra); //sacando la longitud de la palabra
	for (int x=0; x<=lon-1; x++){//for que recorre uno a uno los simbolos de la palabra
		for(int y=0; y<=i-1; y++){//for que recorre uno a uno los simblos del alfabeto
		//	cout<<endl<<"PALABRA["<<palabra[x]<<"]=?"<<"ALFABETO["<<alfabeto[y]<<"]"<<endl;
		//	getch();  //PARA EFECTOS DE PRUEBA
			if(palabra[x]==alfabeto[y]){  //si encuntro el simbolo de la palabra en el alfabeto
				break;					  //paro y tomo el siguiente simbolo de la palabra
			}//end if
			

			if(palabra[x]!=alfabeto[y] && y==i-1){ //si el simbolo de la palabra no es igual al del afabeto y estoy en 
												   //la ultima posicion del alafabeto
			cout<<"no he encontrado un simbolo de la palabra dentro del alfabeto "<<endl;
				auxi=1;           
				break;
			}
			


		}
		if(auxi==1){    //si este es el caso es porque ya encontre un simbolo que no pertenece al alfabeto
			break;

		}
	}

	while(auxi==1){  //mientras este mala la palabra repetir el proceso hasta que el usuario la ingrese bien
		auxi=0;
		introducir_palabra(i);
		comprobar_palabra(i);
	}
//	cout<<"ESTA ES AUXI EN LA FUNCION: "<<auxi; 

}


//****FUNCION QUE COMPRUEBA QUE UN ESTADO INGRESADO PERTENECE A LA LISTA DE ESTADOS DEFINIDOS***////

void comprobar_estados(int estados, int estado_auxi){  //recibe como parametros los estados definidos y el estado a ser examinado
	for(int q=0; q<=estados-1; q++){ //recorro los estados hasta encontrar uno que sea igual al que quiero verificar
			if(estado_auxi==q){
			auxi2=0;
			break; //si lo encuentro se acaba
		}

			if(estado_auxi!=q && q==estados-1){ //si no lo encontre y estoy en la ultima poss me devuelve el valor de aux2=1 que quiere decir que ese estado no pertenece a los estados definidos
			auxi2=1;
			
		}
	
	}

}


void bienvenida(){

	cout<<"***********************************************************************"<<endl;
	cout<<"***********************SIMULADOR DE DFA BIENVENIDO*********************"<<endl;
	cout<<"***********************************************************************"<<endl<<endl<<endl<<endl;
	cout<<"                   TEORIA DE LENGUAJES DE PROGRAMACION         "<<endl<<endl<<endl;
	cout<<"             UNIVERSIDAD CENTROAMERICANA JOSE SIMEON CANAS UCA"<<endl<<endl<<endl<<endl;
	cout<<"desarrolladores; "<<endl;
	cout<<"      Blanca Eugenia Molina Chavez      00006998"<<endl;
	cout<<"      Jorge Alberto Cortez Campos       00002000"<<endl<<endl<<endl<<endl;
	cout<<"                                       presiones una tecla para continuar"<<endl;

}


//****FUNCION QUE VERIFICA QUE NO SE METAN DOS SIMBOLOS IGUALES EN UN ALFABETO****///////

void comprobar_alfabeto(){
	int i=0;
	int l=0;
	i=strlen(alfabeto);
	for(int a=0; a<=i-1;a++){//Recorre el alfabato
		while(l<=i-1){//mientras no este en el fin del alfabeto
			if(alfabeto[a]==alfabeto[l] && a!=l){//comparar cada simbolo con todo el arreglo si hay otro igual pero que no sea el que esta en la misma poss entonces
				auxi3=1;   //darle el valor a auxi3=1 que quiere decir que ha sido mal escrito el alfabeto
				break;
			}
			else
				auxi3=0;  //poner el valor de auxi3=0 que quiere decir que todo esta bien
			l++; //aumentar en un el segundo contador para el alfabeto
		}
		l=0;//cuando paso a revisar el siguiente simbolo del alfabeto debo de empezar a comparar desde la primera poss
	
	}

}

void main(void){


    //declaracion de las variables//
	int numfinal;
	int i=0, v=0;
	int	estados,inicial, qtemp, var, var2;
	int final[sizeof(int)]; //arreglo donde guardo los estados finales
	bienvenida(); //imprimendo la bienvenida

 
	getch();  //una tecla para continuar
	system("cls");//limpiando lapantalla
	cout<<endl<<"        **********DEFINICION DE ESTADOS DEL DFA*********            "<<endl;

	while (estados <=0){//si introduzco un numero de estados negativos o cero me preguntara hasta que meta uno positivo
	cout<<endl<<"Ingrese el numero de estados:";
	cin>>estados;
	}
	//imprimiendo los estados //
	cout<<endl<<"El numero de estados ingresado es de: "<<estados;
	cout<<endl<<endl;
	for(int j=0; j<=estados-1; j++){
		cout<<"q["<<j<<"]"<<endl;
	}

	cout<<endl;

	
	var=1;// ES FALSO
	while(var==1){//mientras no ponga un estado valido la funcion me preguntara por el estado inicial
	cout<<endl<<endl<<"Ingrese el estado inicial (debe encontrarse en su conjunto de estados):"<<" q ";

	cin>>inicial;
	auxi2=0;
	comprobar_estados(estados, inicial); //comprobando si el estado es valido para los estados definidos
	if(auxi2==0) //si esto es 0 es porque el estado introducido es correcto
		var=0;// SE HACE VERDADERO
	}




	cout<<endl<<"cuantos estados finales desea definir? "<<endl;
	cin>>numfinal;
	while(v<numfinal){//introduciendo uno a uno los estados finales

	var2=1;
	while(var2==1){
	
	cout<<endl<<"Ingrese su estado final (debe encontrarse en su conjunto de estados): "<<" q ";

	cin>>final[v];
	comprobar_estados(estados, final[v]);//comprobando el estado introducido que se encuentre en el arreglo de estados

	if(auxi2==0)//de igual manera si es correcto este valor sera 0
		var2=0;

	}
		v++;//pasamos a preguntar por el siguiente estado final
	
	
	
	}


	
//imprimiendo los estados iniciales y finales
	cout<<endl<<endl<<"El estado inicial escogido es: q["<<inicial<<"]";

	cout<<endl<<"Estos son los estados finales escogidos : ";
	for(int p=0; p<numfinal; p++){//recorriendo e imprimiendo estados finales
		cout<<"q["<<final[p]<<"]"<<" ";
	}

	
	cout<<endl<<endl<<endl<<"                 Presione una tecla para continuar..."<<endl;
	getch();
	system("cls");


	cout<<endl<<"     ************DEFINICION DEL ALFABETO*********** "<<endl;
	alfabeto = new char[i];


//este bucle estara repitiendose hasta entrar un alfabeto que no contenga simbolos repetidos//
	auxi3=1;
	while (auxi3==1){
	auxi3=0;
	cout<<endl<<endl<<"Ingrese un tras otro simbolos de su alfabeto sin repetir simbolos : ";
	cin>>alfabeto;
	i=strlen(alfabeto);
	comprobar_alfabeto();//llamada a la funcion que revisa que el alfabeto este bien escrtio
	}



//imprimiendo el alfabeto
	cout<<endl<<" su alfabeto definido consta de "<<i<<" simbolos y estos son: "<<endl;
	cout<<"{";
	for (int z=0; z<i; z++)
		cout<<alfabeto[z]<<",";

	cout<<"}";



	palabra = new char[longi];
	delta= new int *[estados];


	for( int r=0; r<estados;r++){ //inicializando la matriz delta donde se guardan los estados
		delta[r]=new int [i];
	}
	cout<<endl<<endl<<endl<<"Presiones una tecla para continuar"<<endl;
	getch();
	system("cls");
	llenadodelta(estados, i);//llamado a la funcion para llenar la funcion de transicion delta

	char seguir='s';

	while(seguir=='s'){ //este bucle realizara la prueba para tantas palabras como queramos siempre que queramos otra palabra

	introducir_palabra(i); //llamado a funcion de introducir palabra
	comprobar_palabra(i); //llamado a la funcion de comprobar palabra

	cout<<"longitud de la palabra: "<<strlen(palabra)<<"  palabra: "<<palabra<<endl;

	longi=strlen(palabra);




	qtemp=inicial;//qtemp es el que nos ira dando el valor del estado dentro de la matriz de transicion para cada simbolo de la palabra


	for(int s=0; s<longi;s++){//recorriendo la palabra
		for(int a=0; a<i; a++){   //recorriendo el alfabeto

			if(palabra[s]==alfabeto[a]){//si encuentro el simbolo de la palabra en el alfabeto paro y ya tengo la posicion del simbolo en el alfabeto
			break;
			}
		}//find del for de recorrido de alfabeto

		cout<<"me estoy desplazando al estado q["<<qtemp<<"]["<<alfabeto[a]<<"] = "<<delta[qtemp][a]<<endl; //imprimendo el estado al cual se desplaza dentro de la matriz
		qtemp=delta[qtemp][a];//qtemp pasa a tomar el nuevo valor


		cout<<endl<<"                            presione una tecla para seguir con la transicion"<<endl;
		getch();
	}


	
//aqui pasamos a comprobar si el estado en que quedo qtemp pertence a algun estado final
	for(int c=0; c<=numfinal-1;c++){//recorriendo  los estados finales

	if(qtemp==final[c]){//preguntando qtemp pertenece a alguno de los estados finales si es asi es aceptado
		 cout<<"LA PALABRA ES ACEPTADA POR EL DFA!!!!"<<endl<<"qtemp="<<qtemp<<"  final="<<final[c]<<endl;
		 break; 	
	}
	else{//sino es asi y estoy en la ultima posicion de los estados finales quiere decir que el estado en que termino no es un estado final por lo tanto no es aceptado
		 if(c==numfinal-1)
		 cout<<"LA PALABRA NO FUE ACEPTADA POR EL DFA!!!"<<endl<<"qtemp="<<qtemp<<"  final="<<final[c]<<endl;
		}
	}


	cout<<endl<<"desea examinar otra palabra? "<<endl;//para examinar otra palabra
	cin>>seguir;

	}//fin del while

}
