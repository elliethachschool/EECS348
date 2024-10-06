#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    /* This function takes the temp_value, assuming that it's in celsius, converts it to fahrenheit. */
    return ((9.0/5.0)*celsius)+32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    /* This function takes the temp_value, assuming that it's in fahrenheit, converts it to celsius. */
    return (5.0/9.0)*(fahrenheit-32.0);
}

float celsiusToKelvin(float celsius) {
    /* This function takes the temp_value, assuming that it's in celsius, converts it to kelvin. */
    return celsius+273.15;
}

float kelvinToCelsius(float kelvin) {
    /* This function takes the temp_value, assuming that it's in kelvin, converts it to celsius. */
    return kelvin-273.15;
}

char categorize_temperature(float celsius) {
    /* This function takes the converting(temp_value, temp_scale, conversion_target) function (that is already converted to celsius) and categorizes the value into temperature categories and weather advisories based on a pre-set scale. */
    if (celsius < 0) {
        printf("\nTemperature Category: Freezing \nWeather Advisory: Stay indoors!");
    }
    else if (celsius <= 10) {
        printf("\nTemperature Category: Cold \nWeather Advisory: Wear a jacket!");
    }
    else if (celsius <= 25) {
        printf("\nTemperature Category: Comfortable \nWeather Advisory: Go enjoy the nice weather!");
    }
    else if (celsius <= 35) {
        printf("\nTemperature Category: Hot \nWeather Advisory: Take some water with you when going out!");
    }
    else {
        printf("\nTemperature Category: Extreme Heat \nWeather Advisory: Stay indoors!");
    }
    return 0;
}

float converting(int temp_value, int temp_scale, int conversion_target) {
    /* This function determines how to convert temp_value by first checking what the temp scale is and what the conversion target is. After it determines how to convert temp_value, it then calls the function needed to convert it. */
    if (temp_scale == 1) {
        if (conversion_target == 2) {
            printf("%f °F", celsiusToFahrenheit(temp_value));
        }
        else {
            printf("%f K", celsiusToKelvin(temp_value));
        }
    }
    else if (temp_scale == 2) {
        if (conversion_target == 1) {
            printf("%f °C",fahrenheitToCelsius(temp_value));
        }
        else {
            printf("%f K", celsiusToKelvin(fahrenheitToCelsius(temp_value)));
        }
    }
    else {
        if (conversion_target == 1) {
            printf("%f °C", kelvinToCelsius(temp_value));
        }
        else {
            printf("%f °F", celsiusToFahrenheit(kelvinToCelsius(temp_value))); //CHECK THIS ONE
        }
    }
    return 0;
}

int main()
{
    /* This function gets the input needed from the user and calls the functions needed to convert the temperatures. */
    int temp_value; // this variable holds the users input for the temperature value
    printf("Enter the temperature value: ");
    scanf("%d", &temp_value);

    int temp_scale; // this variable holds the users input for what value (F, C, or K) the temp_value is
    printf("Choose the temperature scale of the input value (1) Celsius, (2) Fahrenheit, or (3) Kelvin: ");
    scanf("%d", &temp_scale);
    if (temp_scale == 3) { // this if statement checks to see if temp_scale is equal to 3 in order to check to see if temp_value could potentially be negative
        while (temp_value < 0) { // this while statement is only ran if temp_value is less than 0 and temp_scale is equal to 3; the while statement stops when the user gives a positive value for temp_value
            printf("Kelvin temperature values cannot be negative. Enter in another temperature value: ");
            scanf("%d", &temp_value);
        }
    }

    int conversion_target; // this variable holds the users input for what value (F, C, or K) they want to convert to
    printf("Choose the conversion target (1) Celsius, (2) Fahrenheit, or (3) Kelvin: ");
    scanf("%d", &conversion_target);
    while (temp_scale == conversion_target) { // this while statement is only ran if temp_scale is equal to conversion_target, and only stops when the user gives a different value from temp_scale for conversion_target
        printf("You are trying to convert the temperature value to the same temperature scale it already is, choose a different temperature scale (1) Celsius, (2) Fahrenheit, or (3) Kelvin: ");
        scanf("%d", &conversion_target);
    }

    /* this chain of statements prints out the calls to the categorize_temperature function based off of the conversion target value*/
    if (conversion_target == 1) {
        printf("%c", categorize_temperature(converting(temp_value, temp_scale, conversion_target)));
    }
    else if (conversion_target == 2) {
        printf("%c", categorize_temperature(fahrenheitToCelsius(converting(temp_value, temp_scale, conversion_target))));
    }
    else {
        printf("%c", categorize_temperature(kelvinToCelsius(converting(temp_value, temp_scale, conversion_target))));
    }
}