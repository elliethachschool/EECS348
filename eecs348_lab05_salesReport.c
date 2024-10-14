/*
Name: Ellie Thach
KUID: 3139476
LAB Session: 05
LAB Assignment Number: 05
Program Description: Program takes 12 monthly sales and generates a sales report (monthly sales report, sales summary report, six-month moving average report, and highest-to-lowest sales report).
Collaborators: None
*/

#include <stdio.h>
#include <string.h>

void monthlySalesReport(double *sales_report) {
    /* This function prints out the monthly sales report. */
    char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly Sales Report for 2024:\n");
    printf("Month\t\tSales\n");
    for(int l = 0; l < 12; l++) { // This for loop checks to see how many tabs are needed based on how many characters are in the current month.
        if (strlen(month[l]) < 8) {
            printf("%s\t\t%.2f\n", month[l], sales_report[l]);
        }
        else {
            printf("%s\t%.2f\n", month[l], sales_report[l]);
        }
    }
}

void salesSummaryReport(double *sales_report) {
    /* This function prints out the sales summary report (month with minimum sales, month with maximum sales, and the average of all sales). */
    char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* month_temp[12];
    for (int k = 0; k < 12; k++) {
        month_temp[k] = month[k];
    }

    double max_sales = sales_report[0];
    char* max_month = month_temp[0];
    double min_sales = sales_report[0];
    char* min_month = month_temp[0];
    double average_sales = sales_report[0];
    for (int i = 1; i < 12; i++) { // This for loop checks to see which month was the month with max sales, the month with min sales, and adds up all of the months sales in order to calculate the average.
        if (max_sales < sales_report[i]) {
            max_sales = sales_report[i];
            max_month = month_temp[i];
        }
        if (min_sales > sales_report[i]) {
            min_sales = sales_report[i];
            min_month = month_temp[i];
        }
        average_sales = average_sales + sales_report[i];
    }
    average_sales /= 12; // This finishes calculating up the average.
    printf("\n\nSales Summary Report:\n");
    printf("Minimum Sales: %.2f (%s)\nMaximum Sales: %.2f (%s)\nAverage Sales: %.2f", min_sales, min_month, max_sales, max_month, average_sales);
}

void sixMonthMovingAverageReport(double *sales_report) {
    /* This function prints out the six-month moving average report. */
    double january_june = (sales_report[0]+sales_report[1]+sales_report[2]+sales_report[3]+sales_report[4]+sales_report[5])/6;
    double february_july = (sales_report[1]+sales_report[2]+sales_report[3]+sales_report[4]+sales_report[5]+sales_report[6])/6;
    double march_august = (sales_report[2]+sales_report[3]+sales_report[4]+sales_report[5]+sales_report[6]+sales_report[7])/6;
    double april_september = (sales_report[3]+sales_report[4]+sales_report[5]+sales_report[6]+sales_report[7]+sales_report[8])/6;
    double may_october = (sales_report[4]+sales_report[5]+sales_report[6]+sales_report[7]+sales_report[8]+sales_report[9])/6;
    double june_november = (sales_report[5]+sales_report[6]+sales_report[7]+sales_report[8]+sales_report[9]+sales_report[10])/6;
    double july_december = (sales_report[6]+sales_report[7]+sales_report[8]+sales_report[9]+sales_report[10]+sales_report[11])/6;
    printf("\n\nSix-Month Moving Average Report:\n");
    printf("January-June \t\t%.2f \nFebruary-July \t\t%.2f \nMarch-August \t\t%.2f \nApril-September \t%.2f \nMay-October \t\t%.2f \nJune-November \t\t%.2f \nJuly-December \t\t%.2f", january_june, february_july, march_august, april_september, may_october, june_november, july_december);
}

void salesReportRanking(double *sales_report) {
    /* This function prints out the sales report ranking (highest to lowest). */
    char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* month_temp[12];

    for (int k = 0; k < 12; k++) {
        month_temp[k] = month[k];
    }

    for (int i = 0; i < 12; i++) { // This for loop rearranges sales_report and month_temp from highest to lowest in terms of sales.
        for (int j = 0; j < 11-i; j++) {
            if (sales_report[j] < sales_report[j+1]) {
                double temp = sales_report[j];
                sales_report[j] = sales_report[j+1];
                sales_report[j+1] = temp;

                char* temp_month = month_temp[j];
                month_temp[j] = month_temp[j+1];
                month_temp[j+1] = temp_month;
            }
        }
    }
    printf("\n\nSales Report (highest to lowest):\n");
    printf("Month\t\tSales\n");
    for(int l = 0; l < 12; l++) { // This for loop checks to see how many tabs are needed based on how many characters are in the current month.
        if (strlen(month_temp[l]) < 8) {
            printf("%s\t\t$%.2f\n", month_temp[l], sales_report[l]);
        }
        else {
            printf("%s\t$%.2f\n", month_temp[l], sales_report[l]);
        }
    }
}

int main() {
    /* This function runs the entire code. */
    double sales_report[12];
    FILE *file_pointer;
    file_pointer = fopen("sales_report.txt", "r");

    for (int i = 0; i < 12; i++) { // This for loop is reading the information given by the txt file.
        fscanf(file_pointer, "%lf", &sales_report[i]);
    }

    fclose(file_pointer);

    monthlySalesReport(sales_report);
    salesSummaryReport(sales_report);
    sixMonthMovingAverageReport(sales_report);
    salesReportRanking(sales_report);
}