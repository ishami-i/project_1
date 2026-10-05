#include <stdio.h>

#define MAX_ROUTES 100

/* calculating total distance */
int total_distance(const int distances[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total += distances[i];

    return total;
}

/* Average distance gets total from total_distance */
double average_distance(const int distances[], int n)
{
    return (double)total_distance(distances, n) / n;
}

/* Longest route */
int longest_route(const int distances[], int n)
{
    int longest = distances[0];

    for (int i = 1; i < n; i++)
    {
        if (distances[i] > longest)
            longest = distances[i];
    }

    return longest;
}

/* number of routes strictly greater than the given limit */
int count_above(const int distances[], int n, double limit)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (distances[i] > limit)
            count++;
    }

    return count;
}

int recursive_sum(const int distances[], int n)
{
    if (n <= 0)
        return 0;

    return distances[n - 1] + recursive_sum(distances, n - 1);
}

int main(void)
{
    int distances[MAX_ROUTES];
    int n;
    int limit;

    printf("Number of routes: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_ROUTES)
    {
        printf("Invalid number of routes (1 to %d).\n", MAX_ROUTES);
        return 1;
    }

    printf("Distances: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &distances[i]) != 1 || distances[i] < 0)
        {
            printf("Invalid distance.\n");
            return 1;
        }
    }

    printf("Distance limit: ");
    if (scanf("%d", &limit) != 1)
    {
        printf("Invalid limit.\n");
        return 1;
    }

    double average = average_distance(distances, n);

    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", total_distance(distances, n));
    printf("Average distance: %.2f km\n", average);
    printf("Longest route: %d km\n", longest_route(distances, n));
    printf("Routes above %d km: %d\n", limit, count_above(distances, n, limit));
    printf("Recursive sum: %d km\n", recursive_sum(distances, n));

    return 0;
}