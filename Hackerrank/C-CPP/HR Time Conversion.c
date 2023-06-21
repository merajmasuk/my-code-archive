#include <stdio.h>

int main(){
    char time[10], time2[10];
    int i;
    scanf("%s", time);

    if (time[8] == 'A'){
        for (i = 0; i < 8; i++){
                printf("%c", time[i]);
        }
    }

    else if (time[8] == 'P'){
        for (i = 0; i < 8; i++){
            time2[i] = time[i];
        }
        time2[0] = time[0] + 1;
        time2[1] = time[1] + 2;
        time2[8] = '\0';
        printf("%s", time2);
    }

    return 0;
}

