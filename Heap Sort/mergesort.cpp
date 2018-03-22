#include <iostream> 
#include <fstream>
#include <stdlib.h>
using namespace std;

void Printsort(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
	}

}

void lerVet( int *p, int t ){

	int i;

	for ( i=0; i 0 ) {

          i--;
          t = a[i];

      }
      else {

          n--;
          if (n == 0)
             return;

          t = a[n];
          a[n] = a[0];

      }
     
      pai = i;
      filho = i*2 + 1;
 
      while (filho < n) {

          if (( filho + 1 < n )  &&  ( a[filho + 1] > a[filho] ))
              filho++;

          if (a[filho] > t) {

             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;

          }
          else
             break;

      }
      a[pai] = t;

   }
}






int main() {

	char casodeteste[20]; 
	cout << "Digite um caso de teste: " << endl;
	cin >> casodeteste;

	int array[100000]; 
	int linhas = 0; 

	 ifstream myReadFile;
	 myReadFile.open(casodeteste);
	 char output[1000];
	 if (myReadFile.is_open()) {
	 while (!myReadFile.eof()) {


	    myReadFile >> output;
	    array[linhas] = atoi(output);
	   	linhas++;

	 }
	}
	myReadFile.close();

	int aux[linhas];
	lerVet(array, linhas-1);
	Printsort(array, linhas-1);
	return 0;
}