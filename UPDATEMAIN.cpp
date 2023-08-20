#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void addrec();
void read();
void display();

struct food{
    char name[50];
    float calo;
};

struct get{
    char na[50];
    float gm;
    float cal;
};


void addrec(){
    FILE *fp;
    struct food fo;
    char pw[50];
    int i,n;
    fp=fopen("foodref.txt","w");
    printf("Enter the password");
    gets(pw);
    if (strcmp(pw,"123@admin")!=0){
        printf("Error!Password mismatch");
        exit(1);
    }
    printf("Enter the number of food to write:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter for food item %d",i+1);
        printf("Enter the name of the food");
        scanf("%s",&fo.name);
        printf("\nEnter the amount of calories per 100 gm ");
        scanf("%f",&fo.calo);
        fwrite(&fo,sizeof(struct food),1,fp);
    }
    printf("File written!");
    fclose(fp);
}


void read(){
	FILE *fp;
	struct food fo;
	fp=fopen("foodref.txt","r");
	printf("Name\nCalories(/100gm)\n");
	while(!feof(fp)){
		fread(&fo,sizeof(struct food),1,fp);
		printf("%s\t%f\n",fo.name,fo.calo);
	}
	fclose(fp);
}



void giverec(){
    //user gives food data data
    struct get ufo;
    FILE *up;
    int i,ns;
    up=fopen("userfood.txt","a");
    printf("Enter the number of food you want to check");
    scanf("%d",&ns);
    printf("\nEnter the data");
        for(i=0;i<ns;i++)
		{
        printf("Enter for food item %d",i+1);
        printf("Enter the name of the food");
        scanf("%s",&ufo.na);
        printf("Enter the weight of food(in gram)");
        scanf("%f",&ufo.gm);
		
		
		int n=-1,i,c=0;
	    FILE *fp;
	    struct food fo;
	    fp=fopen("foodref.txt","r");
	    
	    while(!feof(fp))
	    {
	    	fread(&fo[++n],sizeof(struct food),1,fp);
	    	c++;
		}
		for(i=0;i<c;i++)
		{
			if(strcmp(ufo.na,fo[i].name)==0)
			{
				ufo.cal=ufo.gm*fo[i].calo;
				fwrite(&ufo,sizeof(ufo),1,up);
			}			
		}
		fclose(fp);	
    }
    fclose(up);
}

void recommend()
{
    double weight, age;
    char gender;
    int activityLevel;

    printf("Enter your weight (kg): ");
    scanf("%lf", &weight);

    printf("Enter your age: ");
    scanf("%lf", &age);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    printf("Enter your activity level (1-5):\n");
    printf("1: Sedentary\n2: Lightly active\n3: Moderately active\n");
    printf("4: Very active\n5: Super active\n");
    scanf("%d", &activityLevel);

    double bmr;
    
    if (gender == 'M' || gender == 'm') {
        bmr = 88.362 + (13.397 * weight) + (4.799 * age) - (5.677 * age);
    } else if (gender == 'F' || gender == 'f') {
        bmr = 447.593 + (9.247 * weight) + (3.098 * age) - (4.330 * age);
    } else {
        printf("Invalid gender input\n");
        exit(1); // Return an error code
    }

    double activityFactor;

    switch (activityLevel) {
        case 1:
            activityFactor = 1.2; // Sedentary (little to no exercise)
            break;
        case 2:
            activityFactor = 1.375; // Lightly active
            break;
        case 3:
            activityFactor = 1.55; // Moderately active
            break;
        case 4:
            activityFactor = 1.725; // Very active
            break;
        case 5:
            activityFactor = 1.9; // Super active
            break;
        default:
            printf("Invalid activity level input\n");
            exit(1); // Return an error code
    }

    double recommendedCalories = bmr * activityFactor;

    printf("Your recommended daily calories: %.2lf\n", recommendedCalories);

}



int main(){
	int n;
	
	printf("What do you want to do\n");
	printf("1.Write food items\n");//user
	printf("2.Add food items\n");//admin main file
	printf("3.Check recommended amount of your calories\n");
	printf("4.Display the name of foods we can calculate calorie for\n");
	printf("5.View your recommended amount of calorie intake\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			giverec();
		break;
		
		case 2:
			addrec();
		break;
		
		case 3:
			display();  //display name, mass in gm, calculated calorie 
		break;
		
		case 4:
			read();
			
		case 5:
			recommend();
		
		default:
			printf("Invalid choice");
	}
return 0;
}
