#include <stdio.h>
#include <string.h>

#define MAX_TAXIS 100
#define MAX_REQUESTS 100
#define ID_LEN 10
#define NAME_LEN 20

typedef struct {
    char id[ID_LEN];
    char location;
    int available;
} Taxi;

typedef struct {
    int request_id;
    char passenger[NAME_LEN];
    char time[6];
    char pickup_location;
} Request;

int main() {
    Taxi taxis[MAX_TAXIS];
    Request requests[MAX_REQUESTS];
    int taxi_count, request_count;

    // --- Input: Taxis ---
    printf("Enter number of taxis: ");
    scanf("%d", &taxi_count);

    for (int i = 0; i < taxi_count; i++) {
        printf("Enter Taxi ID and Location for Taxi %d (e.g., T1 A): ", i + 1);
        scanf("%s %c", taxis[i].id, &taxis[i].location);
        taxis[i].available = 1; // Initially all taxis are available
    }

    // --- Input: Requests ---
    printf("\nEnter number of ride requests: ");
    scanf("%d", &request_count);

    for (int i = 0; i < request_count; i++) {
        requests[i].request_id = i + 1;
        printf("Enter Passenger Name, Time (hh:mm), and Pickup Location for Request %d: ", i + 1);
        scanf("%s %s %c", requests[i].passenger, requests[i].time, &requests[i].pickup_location);
    }

    // --- Dispatching Taxis Using FCFS ---
    printf("\n🚖 Taxi Dispatch Assignments:\n\n");

    for (int i = 0; i < request_count; i++) {
        int assigned = 0;

        for (int j = 0; j < taxi_count; j++) {
            if (taxis[j].available) {
                printf("Passenger: %-10s | Taxi: %-3s | Pickup: %c | Time: %s\n",
                       requests[i].passenger, taxis[j].id,
                       requests[i].pickup_location, requests[i].time);
                taxis[j].available = 0;
                assigned = 1;
                break;
            }
        }

        if (!assigned) {
            printf("Passenger: %-10s | Taxi: %-20s | Pickup: %c | Time: %s\n",
                   requests[i].passenger, "No Taxi Available",
                   requests[i].pickup_location, requests[i].time);
        }
    }

    return 0;
}
