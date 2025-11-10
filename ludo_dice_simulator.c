
#include <stdio.h>
#include <stdlib.h> // For rand(), srand()
#include <time.h>   // For time()
#include <math.h>   // For fabs()
// Define the total number of simulations
#define TOTAL_ROLLS 1000000

int main()
{
    srand(time(NULL));

    int counts[11] = {0}; // we create the practical_array of size 11 to store sum from 2 to 12 of two dices.

    // 3. Create array for theoretical analysis to stores the number of ways to get each sum (out of 36 total).
    int theoretical_ways[11] = {
        1, // Sum 2: (1+1)
        2, // Sum 3: (1+2), (2+1)
        3, // Sum 4: (1+3), (2+2), (3+1)
        4, // Sum 5: (1+4), (2+3), (3+2), (4+1)
        5, // Sum 6: (1+5), (2+4), (3+3), (4+2), (5+1)
        6, // Sum 7: (1+6), (2+5), (3+4), (4+3), (5+2), (6,1)
        5, // Sum 8: (2+6), (3+5), (4+4), (5+3), (6+2)
        4, // Sum 9: (3+6), (4+5), (5+4), (6+3)
        3, // Sum 10:(4+6), (5+5), (6+4)
        2, // Sum 11:(5+6), (6+5)
        1  // Sum 12: (6+6)
    };

    // Simulation
    printf("\033[H\033[J"); // to clear the screen.
    printf("Running %d simulations...\n", TOTAL_ROLLS);
    for (int i = 0; i < TOTAL_ROLLS; i++)
    {
        // Calculate the sum by rolling 2 die.
        int sum = (rand() % 6) + (rand() % 6) + 2; // basically we get no from 0to 5 so we did it twice nd add 2 to start from 1 instead of 0.
        counts[sum - 2]++;                         // because we are not including 1 in sum as dice atleat gives sum of 2, also index starts from 0;
    }
    printf("Simulation complete.\n\n");

    // Analysis & Report
    printf("--- Dice Roll Simulation Report ---\n");
    printf("=========================================================================================\n");
    printf("Sum\t\tSimulated %%\tTheoretical %%\tabsolute_error %%\trelative_error %%\n");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int sum = 2; sum <= 12; sum++)
    {
        // Calculate probabilities
        double simulated_prob = ((double)counts[sum - 2] / TOTAL_ROLLS) * 100.0;
        double theoretical_prob = ((double)theoretical_ways[sum - 2] / 36.0) * 100.0;
        double absolute_error = theoretical_prob - simulated_prob;
        double relative_error = fabs(absolute_error / theoretical_prob) * 100;

        // Print the formatted report line
        printf("%2d\t\t%6.3f%%\t\t%6.3f%%\t\t%6.3f%%\t\t\t%6.3f%%\n",
               sum, simulated_prob, theoretical_prob, absolute_error, relative_error);
    }
    printf("=========================================================================================\n");

    return 0;
}