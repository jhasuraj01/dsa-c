#include<stdio.h>

struct Object {
    int id;
    int p;
    int w;
    float pbw;
};



int main(void) {
    int C, N;

    printf("Enter Capacity: ");
    scanf("%d", &C);

    printf("Enter No. of Items: ");
    scanf("%d", &N);

    struct Object objects[N];

    for(int i = 0; i < N; ++i) {
        int p, w;
        printf("Item Number: %d\n", i + 1);
        printf("    Enter Profit: "); scanf("%d", &p);
        printf("    Enter Weight: "); scanf("%d", &w);

        objects[i].id = i + 1;
        objects[i].p = p;
        objects[i].w = w;
        objects[i].pbw = (float) p/w;
    }

    // sort by profit/weight in dec order using bubble sort algorithm.
    for(int i = 0; i < N; ++i) {
        for(int j = 1; j < N - i; ++j) {
            if(objects[j - 1].pbw < objects[j].pbw) {
                struct Object object = objects[j - 1];
                objects[j - 1] = objects[j];
                objects[j] = object;
            }
        }
    }

    float total_profit = 0;
    
    printf("\n\nSelected Items:\n");

    for(int i = 0; C > 0 && i < N; ++i) {
        int weight = 0;
        float profit_obtained = 0;
        if(C > objects[i].w) {
            weight = objects[i].w;
            profit_obtained = objects[i].p;
            C -= objects[i].w;
        }
        else {
            weight = C;
            profit_obtained = objects[i].pbw * weight;
            C = 0;
        }
        total_profit += profit_obtained;

        printf("Item: %d, ", objects[i].id);
        printf("Selected Weight: %d/%d, ", weight, objects[i].w);
        printf("Profit Obtained: %.2f\n", profit_obtained);
    }

    printf("Total Profit: %.2f\n", total_profit);

    return 0;
}