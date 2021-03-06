#include<iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>


using namespace std;

struct Sort{

void b_sort(int tablica[10], int ile_liczb)
{
    int temp,i,zmiana;
    do{
        zmiana=0;
        i=ile_liczb-1;
        do
        {
            i--;
            if (tablica[i+1]< tablica[i]){
                temp=tablica[i];
                tablica[i]=tablica[i+1];
                tablica[i+1]=temp;
                zmiana=1;
            }
        }
        while (i!=0);
    }
    while (zmiana!=0);

printf("\nTablica po posortowaniu:");
//for(i=0; i<ile_liczb; i++) printf("\n%i",tablica[i]);
}

void orderNumbers(int sorted[], int sizee){
    //cout<<sizee<<endl;
    int result_set[sizee] = {0};
    int result_set2[sizee] = {0};

    for(int it1 = 0; it1<sizee; it1++){
        int get = sorted[it1];
        for(int it2 = 0; it2<sizee; it2++){
            if(get == sorted[it2]){
                if(!checkIfContains(result_set,get,sizee)){
                     result_set[it2] = get;

                }
                result_set2[it1] = result_set2[it1]+1;
            }
        }

    }

    int tmp_size = sizee;
    cout<<"RS : "<<sizeof(result_set)<<endl;
    for(int i = 0; i<tmp_size; i++){
            if(result_set[i] != 0){
                cout<<result_set[i]<<"   "<<result_set2[i]<<endl;
                i = i + (result_set2[i]-1);
            }
    }
}

bool checkIfContains(int array_i[],int value,int ilosc){
    for(int i = 0; i<ilosc; i++){
        if(array_i[i] == value)
            return true;
    }
    return false;
}

};

int main(){
    Sort sorter;
    int ilosc_liczb;
    srand(time(NULL));
    cout << "Podaj ilosc licz do posortowania: ";
    cin >> ilosc_liczb;
    int *tablica = new int [ilosc_liczb]; // utworzenie dynamicznej tablicy na 'ilosc_liczb' elementow

    for (int i = 0; i < ilosc_liczb; i++) // wczytywanie liczb do tablicy
    {
        tablica[i] = rand() % 10 + 1;
    }
    sorter.b_sort(tablica,ilosc_liczb); // wywolanie funkcji sortujacej
    for(int i = 0; i<ilosc_liczb; i++){
        cout<<tablica[i]<<endl;
    }
    cout<<endl;
    sorter.orderNumbers(tablica,ilosc_liczb);

    delete [] tablica; // zwolnienie tablicy zaalokowanej dynamicznie

    return 0;
}
