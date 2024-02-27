#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define SIZE 100

struct element
{
    long long int numer;
    element* next = NULL;
    element* prev = NULL;
};

struct list
{
    element* BEG = NULL;
    element* END = NULL;
};

void NOTHING()
{
    int n;
    std::cin >> n;
}

void ADD_ELEMENT_BEHIND(list* lista, element* tab[10])
{
    char command[SIZE];
    std::cin >> command;
    long long int liczba;
    std::cin >> liczba;
    element* nowy = new element;
    if (strcmp(command, "BEG") == 0)
    {
        nowy->numer = liczba;
        if (lista->BEG == NULL)
        {
            lista->BEG = nowy;
        }
        else if (lista->END == NULL)
        {
            lista->END = lista->BEG;
            lista->END = nowy;
            lista->BEG->next = lista->END;
            lista->END->prev = lista->BEG;
        }
        else
        {
            nowy->next = lista->BEG->next;
            nowy->prev = lista->BEG;
            lista->BEG->next->prev = nowy;
            lista->BEG->next = nowy;

        }
    }
    else if (strcmp(command, "END") == 0)
    {
        nowy->numer = liczba;
        if (lista->BEG == NULL)
        {
            lista->BEG = nowy;
        }
        else if (lista->END == NULL)
        {
            lista->BEG->next = nowy;
            lista->END = nowy;
            lista->END->prev = lista->BEG;
        }
        else
        {
            lista->END->next = nowy;
            nowy->prev = lista->END;
            lista->END = nowy;
        }
    }
    else if (command[0] - 48 < 10 && command[0] - 48 > -1)
    {
        nowy->numer = liczba;
        int iterator = command[0] - 48;
        if (lista->BEG == NULL)
        {
            lista->BEG = nowy;
        }
        else if (tab[iterator] == lista->END)
        {
            lista->END->next = nowy;
            nowy->prev = lista->END;
            lista->END = nowy;
        }
        else
        {
            nowy->next = tab[iterator]->next;
            nowy->prev = tab[iterator];
            tab[iterator]->next->prev = nowy;
            tab[iterator]->next = nowy;
        }
    }
}

void ADD_ELEMENT_BEFORE(list* lista, element* tab[10])
{
    char command[SIZE];
    std::cin >> command;
    long long int liczba;
    std::cin >> liczba;
    element* nowy = new element;
    if (strcmp(command, "BEG") == 0)
    {
        nowy->numer = liczba;
        if (lista->BEG == NULL)
        {
            lista->BEG = nowy;
        }
        else if (lista->END == NULL)
        {
            lista->END = lista->BEG;
            lista->BEG = nowy;
            lista->BEG->next = lista->END;
            lista->END->prev = lista->BEG;
        }
        else
        {
            lista->BEG->prev = nowy;
            nowy->next = lista->BEG;
            lista->BEG = nowy;
        }
    }
    else if (strcmp(command, "END") == 0)
    {
        nowy->numer = liczba;
        if (lista->BEG == NULL) lista->BEG = nowy;
        else if (lista->END == NULL)
        {
            lista->BEG = nowy;
            nowy->next = lista->END;
            lista->END->prev = lista->BEG;
        }
        else
        {

            nowy->next = lista->END;
            nowy->prev = lista->END->prev;
            lista->END->prev->next = nowy;
            lista->END->prev = nowy;
        }
    }
    else if (command[0] - 48 < 10 && command[0] - 48 > -1)
    {
        nowy->numer = liczba;
        int iterator = command[0] - 48;
        if (lista->BEG == NULL)
        {
            lista->BEG = nowy;
        }
        else if (tab[iterator] == lista->BEG)
        {
            lista->BEG->prev = nowy;
            nowy->next = lista->BEG;
            lista->BEG = nowy;
        }
        else
        {
            nowy->next = tab[iterator];
            nowy->prev = tab[iterator]->prev;
            tab[iterator]->prev->next = nowy;
            tab[iterator]->prev = nowy;
        }
    }
}

void POP_ELEMENT(list* lista, element* tab[10])
{
    char command[SIZE];
    std::cin >> command;
    if (strcmp(command, "BEG") == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if (tab[i] == lista->BEG && tab[i] != NULL) tab[i] = lista->BEG->next;
        }
        if (lista->BEG == NULL)
            return;
        element* k = lista->BEG;
        lista->BEG = lista->BEG->next;
        delete k;
        if (lista->BEG == lista->END)
            lista->END = NULL;
    }
    else if (strcmp(command, "END") == 0)
    {
        if (lista->END == NULL)
        {
            lista->BEG = NULL;
            for (int i = 0; i < 10; i++)
            {
                tab[i] = NULL;
            }
        }
        if (lista->BEG == NULL)
            return;
        for (int i = 0; i < 10; i++)
        {
            if (tab[i] == lista->END && tab[i] != NULL) tab[i] = lista->END->prev;
        }
        lista->END = lista->END->prev;
        lista->END->next = nullptr;
        if (lista->BEG == lista->END)
            lista->END = NULL;
    }
    else if (command[0] - 48 < 10 && command[0] - 48 > -1)
    {
        int iterator = command[0] - 48;
        if (tab[iterator] == lista->BEG)
        {
            for (int i = 0; i < 10; i++)
            {
                if (tab[i] == tab[iterator] && i != iterator) tab[i] = tab[iterator]->next;
            }
            if (lista->BEG == NULL)
                return;
            element* k = lista->BEG;
            lista->BEG = lista->BEG->next;
            delete k;
            if (lista->BEG == lista->END)
                lista->END = NULL;
            tab[iterator] = lista->BEG;
        }
        else if (tab[iterator] == lista->END)
        {
            for (int i = 0; i < 10; i++)
            {
                if (tab[i] == tab[iterator] && i != iterator)  tab[i] = lista->END->prev;
            }
            if (lista->END == NULL)
                lista->BEG = NULL;
            if (lista->BEG == NULL)
                return;
            lista->END = lista->END->prev;
            lista->END->next = nullptr;
            tab[iterator] = lista->END;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (tab[i] == tab[iterator] && i != iterator) tab[i] = tab[iterator]->next;
            }
            if (tab[iterator]->next != NULL)
            {
                tab[iterator]->next->prev = tab[iterator]->prev;
            }
            if (tab[iterator]->prev != NULL)
            {
                tab[iterator]->prev->next = tab[iterator]->next;
            }
            tab[iterator] = tab[iterator]->next;
        }
    }
}

void PRINT(list* lista, element* tab[10])
{
    char command[SIZE];
    std::cin >> command;
    if (strcmp(command, "ALL") == 0)
    {
        element* p = lista->BEG;
        while (p != NULL)
        {
            printf("%lld ", p->numer);
            p = p->next;
        }
        printf("\n");
    }
    else if (tab[command[0] - 48] == NULL)
        return;
    else printf("%lld\n", tab[command[0] - 48]->numer);
}

void SETITERATOR(list* lista, element* tab[10])
{
    int iterator;
    std::cin >> iterator;
    char command[SIZE];
    std::cin >> command;
    int j = atoi(command);
    if (strcmp(command, "BEG") == 0 && iterator < 10 && iterator > -1)
    {
        tab[iterator] = lista->BEG;
            return;
    }
    if (strcmp(command, "END") == 0 && iterator < 10 && iterator > -1)
    {
        tab[iterator] = lista->END;
        return;
    }
    if (iterator < 10 && iterator > -1 && j < 10 && j > -1)
    {
        tab[iterator] = tab[j];
    }        
}

void MOVE_FORWARD(list* lista, element* tab[10])
{
    int iterator;
    std::cin >> iterator;
    while (true)
    {
        if (tab[iterator] == lista->END || lista->END == NULL ) break;
        else
        {
            tab[iterator] = tab[iterator]->next;
            break;
        }
    }
}

void MOVE_BACKWARD(list* lista, element* tab[10])
{
    int iterator;
    std::cin >> iterator;
    while (true)
    {
        if (tab[iterator] == lista->BEG  || lista->BEG == NULL) break;
        else
        {
            tab[iterator] = tab[iterator]->prev;
            break;
        }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    list* lista = new list;
    element** table = new element * [10];
    for (int i = 0; i < 10; i++)
        table[i] = NULL;
    char command[SIZE];
    while (true)
    {
        scanf("%s", command);
        if (feof(stdin) != 0)
        {
            break;
        }
        if (strcmp(command, "I") == 0) NOTHING();
        else if (strcmp(command, ".A") == 0) ADD_ELEMENT_BEFORE(lista, table);
        else if (strcmp(command, "A.") == 0) ADD_ELEMENT_BEHIND(lista, table);
        else if (strcmp(command, "R") == 0) POP_ELEMENT(lista, table);
        else if (strcmp(command, "P") == 0) PRINT(lista, table);
        else if (strcmp(command, "i") == 0) SETITERATOR(lista, table);
        else if (strcmp(command, "+") == 0) MOVE_FORWARD(lista, table);
        else if (strcmp(command, "-") == 0) MOVE_BACKWARD(lista, table);
    }
    delete [] table;
    return 0;
}
