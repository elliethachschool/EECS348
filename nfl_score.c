#include <stdio.h>

void find_combo(int score) {
    /* This function finds all possible combinations of how many touchdowns + 2-point conversions, touchdowns + 1-point field goals, touchdowns, field goals, and safeties it takes to get the score given. */
    int twoPointConversion = 8;
    int onePointFieldGoal = 7;
    int touchdown = 6;
    int fieldGoal = 3;
    int safety = 2;

    // maximum possible numbers of each type of scoring play
    int maxTwoPointConversion = score/twoPointConversion;
    int maxOnePointFieldGoal = score/onePointFieldGoal;
    int maxTouchdown = score/touchdown;
    int maxFieldGoal = score/fieldGoal;
    int maxSafety = score/safety;

    printf("Possible combinations of scoring plays if a team's score is %d: ", score);

    // nested for loops explore all possible combinations of scoring plays by varying counts of each type of score incrementally
    for(int td_2pt = 0; td_2pt <= maxTwoPointConversion; td_2pt++) {
        for(int td_fg = 0; td_fg <= maxOnePointFieldGoal; td_fg++) {
            for(int td = 0; td <= maxTouchdown; td++) {
                for(int fg = 0; fg <= maxFieldGoal; fg++) {
                    for(int s = 0; s <= maxSafety; s++) {
                        int total_score = (td_2pt*twoPointConversion) + (td_fg*onePointFieldGoal) + (td*touchdown) + (fg*fieldGoal) + (s*safety);
                        if (total_score == score) {
                            printf("\n%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", td_2pt, td_fg, td, fg, s);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    /* This function takes input from the user and then runs the find_combo function with it. */
    int userNum; // variable that holds the users input for the score
    printf("Enter 0 or 1 to STOP \nEnter the NFL score: ");
    scanf("%d", &userNum);

    while(userNum > 1) { // this while function keeps prompting the user for scores to execute and only stops if given a number 1 or lower
        find_combo(userNum);
        printf("\nEnter 0 or 1 to STOP \nEnter the NFL score: ");
        scanf("%d", &userNum);
    }
}