#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_NO_MEM "not enough memory\n"

typedef struct ll_element
{
    void *value;
    struct ll_element *next;
} ll_element_t;

typedef struct linked_list
{
    ll_element_t *head;
} linked_list_t;


int add_element_to_ll(linked_list_t *ll, void* element)
{
    if (NULL == ll->head)
    {
        ll->head = (ll_element_t*)malloc(sizeof(ll_element_t));
        if (NULL == ll->head)
        {
            printf("%s", ERR_NO_MEM);
            return 1;
        }
    }
    ll_element_t* current = ll->head;
    while (NULL != current->value && NULL != current->next)
    {
        current = current->next;
    }
    if (NULL == current->value)
    {
        current->value = element;
    }
    if (NULL == current->next)
    {
        current->next = (ll_element_t*)malloc(sizeof(ll_element_t));
        if (NULL == current->next)
        {
            printf("%s", ERR_NO_MEM);
            return 1;
        }
    }
    return 0;
}

// int remove_element_from_ll(linked_list_t *ll, void *element)
// {
//     ll_element_t* current = ll->head;
//     if (NULL == current)
//     {
//         return 0;
//     }

//     while (NULL != current)
//     {
//         if (0 == memcmp(element, current->value, strlen((const char*)element)))
//         {
//         }
//     }

//     return 0;
// }

int free_ll(linked_list_t *ll)
{
    if (NULL == ll->head)
    {
        return 0;
    }
    ll_element_t* current = ll->head;
    ll_element_t* next = current->next;

    while (NULL != current)
    {
        free(current);
        current = next;
        if (NULL != next)
        {
            next = next->next;
        }
    }
    free(ll);
    return 0;
}


void print_ll(linked_list_t* ll)
{
    ll_element_t* current = ll->head;
    size_t index = 0;
    while (NULL != current && NULL != current->value)
    {
        printf("%ld: %s\n", index, (char*)current->value);
        index++;
        current = current->next;
    }
}

int main(int argc, char** argv)
{
    if (1 == argc)
    {
        printf("No arguments were provided.\n");
        return 0;
    }
    //char* argv_2[] = {"prg", "ff", "jjj"};
    linked_list_t* argv_list = (linked_list_t*)malloc(sizeof(linked_list_t));
    if (NULL != argv_list)
    {
        for (int i = 1; i < argc; ++i)
        {
            add_element_to_ll(argv_list, argv[i]);
        }
    }
    else
    {
        printf("%s", ERR_NO_MEM);
        return 1;
    }
    print_ll(argv_list);
    free_ll(argv_list);
    return 0;
}