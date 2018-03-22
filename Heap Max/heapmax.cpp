#include <iostream> 
#include <fstream>
#include <stdlib.h>

using namespace std;

void printsort(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
		
	}

}

void max_heapify(int arr[], int i, int n)
{
    int j, temp;
    temp = arr[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && arr[j+1] > arr[j])
            j = j + 1;
        if (temp > arr[j])
            break;
        else if (temp <= arr[j])
        {
            arr[j / 2] = arr[j];
            j = 2 * j;
        }
    }
    arr[j/2] = temp;
    return;
}
void maxheap(int arr[],int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(arr,i,n);
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

	maxheap(array, linhas);
	printsort(array, linhas);
	return 0;
}