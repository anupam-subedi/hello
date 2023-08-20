#include <stdio.h>
#include <stdlib.h>

struct Food {
    char name[100];
    double calories;
};


double calculateCalories(double weight, double age, char gender, int activityLevel);
int main() {
	
	//WELCOME ASCII 
    double weight, age;
    char gendera[10];
    int activityLevel,p;

    printf("Enter your weight (kg): ");
    scanf("%lf", &weight);

    printf("Enter your age: ");
    scanf("%lf", &age);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    printf("Enter your activity level (1-5):\n");
    printf("1: Inactive\n2: Lightly active\n3: Moderately active\n");
    printf("4: Very active\n5: Super active\n");
    scanf("%d", &activityLevel);

    double recommendedCalories = calculateCalories(weight, age, gender, activityLevel);

    if (recommendedCalories > 0) {
        printf("Your recommended daily calories: %.2lf\n", recommendedCalories);
    } else {
        printf("Calculation error occurred\n");
    }up:
	printf("1.Check Calories\n2.Add foor itemsn");
	printf("\nChoose the action to take");
	scanf("%d",&p);
	switch (p) {
    case 1:
    	clrscr();
        calculatecal();
        break;
    case constant2:
    	clrscr();
    	printf("\nEnter the paswword");
    	scanf("%s",a);
        addfood(a);// Code to execute if expression matches constant2
        break;
    // ... more cases ...
    default:
        // Code to execute if no case matches the expression
}
    return 0;

}
double calculateCalories(double weight, double age, char gender, int activityLevel) {
    double bmr;

    if (gender == 'M' || gender == 'm') {
        // For males
        bmr = 88.362 + (13.397 * weight) + (4.799 * age) - (5.677 * age);
    } else if (gender == 'F' || gender == 'f') {
        // For females
        bmr = 447.593 + (9.247 * weight) + (3.098 * age) - (4.330 * age);
    } else {
        printf("Invalid gender input\n");
        return -1; // Return a negative value to indicate an error
    }

    double activityFactor;
    switch (activityLevel) {
        case 1:
            activityFactor = 1.2; // Sedentary (little to no exercise)
            break;
        case 2:
            activityFactor = 1.375; // Lightly active (light exercise/sports 1-3 days a week)
            break;
        case 3:
            activityFactor = 1.55; // Moderately active (moderate exercise/sports 3-5 days a week)
            break;
        case 4:
            activityFactor = 1.725; // Very active (hard exercise/sports 6-7 days a week)
            break;
        case 5:
            activityFactor = 1.9; // Super active (very hard exercise, physical job, or training)
            break;
        default:
            printf("Invalid activity level input\n");
            return -1; // Return a negative value to indicate an error
    }

    return bmr * activityFactor;
}


// Structure to hold food details


void addfood(char a[]) {
	if(strcmp(a,'123')!=0){printf("Error!Wrong password");
	goto up;
	}
    FILE *foodFile = fopen("food.txt", "r");
    if (foodFile == NULL) {
        printf("Error opening food.txt for reading.\n");
        return 1; // Return an error code
    }

    // Read and store food data from food.txt
    int numFoods;
    fscanf(foodFile, "%d", &numFoods);
    struct Food *foods = (struct Food *)malloc(numFoods * sizeof(struct Food));

    for (int i = 0; i < numFoods; i++) {
        fscanf(foodFile, " %[^\n]", foods[i].name);
        fscanf(foodFile, "%lf", &foods[i].calories);
    }

    fclose(foodFile);

    // Display food options
    printf("Food Options:\n");
    for (int i = 0; i < numFoods; i++) {
        printf("%d. %s\n", i + 1, foods[i].name);
    }

    // Input food selection and weight
    int selectedFood;
    double weight;

    printf("\nEnter the number corresponding to the food: ");
    scanf("%d", &selectedFood);
    if (selectedFood < 1 || selectedFood > numFoods) {
        printf("Invalid food selection.\n");
        return 1; // Return an error code
    }

    printf("Enter the weight in grams: ");
    scanf("%lf", &weight);

    // Calculate product of weight and calories
    double product = weight * foods[selectedFood - 1].calories;

    // Store tracking information in tracking.txt
    FILE *trackingFile = fopen("tracking.txt", "a");
    if (trackingFile == NULL) {
        printf("Error opening tracking.txt for appending.\n");
        return 1; // Return an error code
    }

    fprintf(trackingFile, "%s - %.2lf grams - %.2lf calories\n", foods[selectedFood - 1].name, weight, product);
    fclose(trackingFile);

    printf("\nTracking information has been saved in tracking.txt.\n");

    free(foods); // Free allocated memory

    return 0;
}
