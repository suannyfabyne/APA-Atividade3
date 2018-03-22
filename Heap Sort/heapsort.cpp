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

void heapify(int arr[], int n, int i)
{
   int largest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;

   if (left < n && arr[left] > arr[largest])
     largest = left;

   if (right < n && arr[right] > arr[largest])
     largest = right;

   if (largest != i)
   {
     swap(arr[i], arr[largest]);
     heapify(arr, n, largest);
   }
}

void heapSort(int arr[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
     heapify(arr, n, i);

   for (int i=n-1; i>=0; i--)
   {
     swap(arr[0], arr[i]);
     
     heapify(arr, i, 0);
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
	heapSort(array, linhas);
	Printsort(array, linhas);
	return 0;
}