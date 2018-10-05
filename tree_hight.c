#include <stdio.h>
#include <stdlib.h>

int WhatHeight(int vertices, int* parrents)
{
    int height = 1;
    if (parrents[vertices] != -1) {
        height += WhatHeight(parrents[vertices], parrents);
    }
    return height;
}

int main()
{
    int vertices_num = 0;
    int height = 1;
    int* parrents;

    scanf("%d", &vertices_num);
    
    parrents = malloc(sizeof(vertices_num) * vertices_num);

    for (int i = 0; i < vertices_num; ++i) {
        scanf("%d", parrents+i);
    }

    for (int i = 0; i < vertices_num; ++i) {
        int temp = WhatHeight(i, parrents);
        if (temp > height) {
            height = temp; 
        }
    }

    printf("%d\n", height);

    free(parrents);
    return 0;
}