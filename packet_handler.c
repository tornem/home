#include <stdio.h>
#include <stdlib.h>

typedef struct packinfo {
    int arrival;
    int duration;
} packinfo_t;

int main()
{
    int n            = 0;  // num of packets
    int buf_size     = 0;
    int current_time = 0;
    scanf("%d %d", &buf_size, &n);

    packinfo_t buffer[buf_size];

    for(int i = 0, j = 0; i < n; ++i) {
        if (i < buf_size) {  // место в буфере еще есть
            scanf("%d %d", &(buffer[j].arrival), &(buffer[j].duration));
            j++;
            printf("%d\n", current_time);
            current_time += buffer[j].duration;
        } else {
            if (buffer[0].duration < current_time) {
                for (int i = 0; i < buf_size - 1; ++i) {
                    buffer[i] = buffer[i+1];
                }
                scanf("%d %d",&(buffer[buf_size].arrival), &(buffer[buf_size].duration));
            } else {
                int temp;
                scanf("%d %d", &temp, &temp);
                printf("-1\n");
            }
        }
    }
}