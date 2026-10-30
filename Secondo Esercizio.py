import numpy as np
import random
from timeit import default_timer as timer
import matplotlib.pyplot as plt

def listaCasuale(num_elementi):
    # genera una lista di numeri interi casuali
    lista = list()
    for i in range(num_elementi):
        lista.append(random.randint(0, num_elementi * 10))
    return lista

def listaOrdinata(num_elementi):
    lista = list()
    for i in range(num_elementi):
        lista.append(i)
    return lista

def insertion_sort(A):
    for j in range(1,len(A)):
        key = A[j]
        i = j-1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key
        print(A)

def quickSort(lista, low, high):
    if low < high:
        div = partition(lista, low, high) 
        # richiamo quick-sort a sinistra del punto di divisione
        quickSort(lista, low, div - 1)
        #richiamo quick-sort a destra del punto di divisione
        quickSort(lista, div + 1, high)

def partition(lista, low, high):
    # decido di scegliere come pivot l'ultimo elemento della lista
    pivot = lista[high]
    
    i = low - 1
    for j in range(low, high):
        if lista[j] <= pivot:
            # incremento l'indice e faccio lo swap degli elementi
            i += 1
            lista[i], lista[j] = lista[j], lista[i]
            
    # infine scambio il pivot con l'elemento successivo all'indice nel punto di divisione
    lista[i + 1], lista[high] = lista[high], lista[i + 1]  
    return i + 1

def test(alg_lista):
    dimensioni_lista = []
    confronto = []
    insertion_sort_time= []
    quick_sort_time = []

    lista = alg_lista(100)
    dimensioni_lista.append(100)
    dimensioni_lista.append(500)
    dimensioni_lista.append(1000)
    dimensioni_lista.append(10000)
    copia_lista = lista.copy() # mi serve per fare il test successivo
    # esegui selection sort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    insertion_sort(lista)
    stop = timer()
    insertion_sort_time.append((stop - start))
        # esegui quicksort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    quickSort(copia_lista, 0, len(lista)-1)
    stop = timer()
    quick_sort_time.append((stop - start))
    lista = alg_lista(500)
    copia_lista = lista.copy() # mi serve per fare il test successivo
    # esegui selection sort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    insertion_sort(lista)
    stop = timer()
    insertion_sort_time.append((stop - start))
        # esegui quicksort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    quickSort(copia_lista, 0, len(lista)-1)
    stop = timer()
    lista = alg_lista(1000)
    copia_lista = lista.copy() # mi serve per fare il test successivo
    # esegui selection sort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    insertion_sort(lista)
    stop = timer()
    insertion_sort_time.append((stop - start))
        # esegui quicksort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    quickSort(copia_lista, 0, len(lista)-1)
    stop = timer()
    lista = alg_lista(10000)
    copia_lista = lista.copy() # mi serve per fare il test successivo
    # esegui selection sort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    insertion_sort(lista)
    stop = timer()
    insertion_sort_time.append((stop - start))
        # esegui quicksort e misura il tempo di esecuzione ad ogni iterazione
    start = timer()
    quickSort(copia_lista, 0, len(lista)-1)
    stop = timer()
    # crea un grafico che mostra l'andamento temporale dei due algoritmi
    plt.plot(dimensioni_lista, insertion_sort_time, label='Insertion-sort')
    plt.plot(dimensioni_lista, quick_sort_time, label='Quick-sort')
    plt.xlabel('Numero di elementi')
    plt.ylabel('Tempo di esecuzione (secondi)')
    plt.title('Andamento temporale di Insertion-sort e Quick-sort')
    plt.legend()
    plt.show()


def main():        
 
    test(listaCasuale)
    print('Secondo test...')
    test(listaOrdinata)
    
main()