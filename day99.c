#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Comparator to sort cars by position in descending order
int compare(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    
    // 1. Calculate time for each car and store with position
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // 2. Sort cars by position descending (closest to target first)
    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    // 3. Iterate through sorted cars
    for (int i = 0; i < positionSize; i++) {
        // If this car takes more time than the current leading fleet, 
        // it cannot catch up. It becomes the leader of a new fleet.
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int size = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, size, speed, size);
    printf("Number of car fleets: %d\n", result); // Output: 3

    return 0;
}