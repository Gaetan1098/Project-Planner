/********* definitions.c ********

#include "a1_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void number_of_employees(milestone_t *project_details){
    project_details->num_employees = round(project_details->cost/(project_details->time*40*25));
}

milestone_t init_milestone(char stage_name[], float assigned_budget){
	milestone_t miles;
	strcpy(miles.name, stage_name);
	miles.cost = assigned_budget/5;
	miles.num_employees = 0;
	miles.time = 0;
	miles.completed = 0;

	return miles;
}

float get_input_f(void){
   float bdgt = 0;
    printf("Welcome to ABC Project Tracker\nEnter total project's budget: ");
    scanf("%f", &bdgt);
    while (bdgt < 0)
    {
        printf("The value you entered is not acceptable\nEnter a positive number: ");
        scanf("%f", &bdgt);
    }
	return bdgt ;
}

float get_input_f2(void){
	float dur = 0;
	printf("Enter total project's duration in weeks: ");
    scanf("%f", &dur);
    while (dur < 0)
    {
        printf("The value you entered is not acceptable\nEnter a positive number: ");
        scanf("%f", &dur);
    }
	return dur;
}

float get_input_f3(void){
	float dur = 0;
	printf("Enter the milestone's actual time: ");
    scanf("%f", &dur);
    while (dur < 0)
    {
        printf("The value you entered is not acceptable\nEnter a positive number: ");
        scanf("%f", &dur);
    }
	return dur;
}

void print_menu(void){
	printf("\nWhich milestone do you want to update?(0 to exit):\n1. Technical requirements\n2. System Design\n3. Software Development\n4. Testing\n5. Product release\n");
}

unsigned short int get_input_usi(void){
	unsigned short int input = 0;
	printf("\nYour choice is: ");
	scanf("%hu", &input);
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	while (input > 5)
    {
        printf("The value you entered is not acceptable\nEnter a integer between 0 and 5: ");
        scanf("%hu", &input);
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
	}
	return input;
}

unsigned short int get_input_usi2(void){
	unsigned short int input = 0;
	printf("Enter the milestone's actual number of employees: ");
	scanf("%hu", &input);
	return input;
}

char get_input_c(void){
	char completed;
	printf("Is this milestone complete?(Y/N): ");
	scanf(" %c", &completed);

	return completed;

}

char get_input_c2(void){
	char completed;
	printf("Do you want to finish the remaining milestones?(Y/N) ");
	scanf(" %c", &completed);

	return completed;

}

void print_stats(milestone_t details){
	if (details.completed == 1)
	{
		printf("\n---------------------------Milestone Stats--------------------------------------\n Below is '%s' current stats:\n", details.name);
		printf("--------------------------------------------------------------------------------\n");
		printf("\nActual time: %f", details.time);
		printf("\nAcutal number of employees: %d", details.num_employees);
		printf("\nActual cost: %f", details.cost); 
		printf("\nCompleted: Yes\n");
		printf("\n----------------------------------------------------------------------------------------------\n%s milestone is completed and cannot be updated\n", details.name);
		printf("------------------------------------------------------------------------------------------------\n");
	}

	else{
		printf("---------------------------Milestone Stats-------------------------\n Below is '%s' current stats:\n", details.name);
		printf("--------------------------------------------------------------------------------\n");
		printf("\nActual time: %f", details.time);
		printf("\nAcutal number of employees: %d", details.num_employees);
		printf("\nActual cost: %f", details.cost); 
		printf("\nCompleted: No\n");
	}
}


void update_stats(milestone_t milestone_array[], int milestone_num){
	if (milestone_num == 0){
		check_project_completion(milestone_array, 5);
		if (milestone_array[0].completed == 0)
				{
					printf("\n------------------------------------------");
					printf("\n---------Project's Performance-----------");
					printf("\n----------------------------------------\n");
					print_stats(milestone_array[0]);
					if(get_input_c2() == 'N'){
						print_final_stats(milestone_array, 5);
					}
				}	
	}

	else{
		printf("\n---------------------------------Update Stats----------------------------------------\n");

		milestone_array[milestone_num].time = get_input_f3();
		milestone_array[milestone_num].num_employees = get_input_usi2();
		if (get_input_c() == 'Y')
		{
			milestone_array[milestone_num].completed = 1;
		}
		print_stats(milestone_array[milestone_num]);
		printf("\nStats Updated!\n");
		milestone_array[milestone_num].cost = milestone_array[milestone_num].num_employees*milestone_array[milestone_num].time*40*25;
		print_stats(milestone_array[milestone_num]);
	}
	
	

}

void check_project_completion(milestone_t milestone_array[], int num_milestones){
	unsigned short int count = 0;
	for (int i = 1; i < num_milestones+1; i++)
	{
		if (milestone_array[i].completed == 1)
		{
			count++;
		}
	}

	if (count == 5)
	{
		milestone_array[0].completed = 1;
	}
	
	
}

void print_final_stats(milestone_t project[], int num_milestones){
	float cost_sum = 0;
	printf("\n------------------------------------------");
	printf("\n---------Final Project's Performance-----------");
	printf("\n----------------------------------------\n");
	for (unsigned short int i = 1; i < num_milestones+1; i++)
	{
		cost_sum += project[i].cost;
	}
	if (cost_sum < project[0].cost){
		printf("The project's cost is below budget!");
		printf("\nPlanned budget: %f", project[0].cost);
		printf("\nActual cost: %f", cost_sum);
	}

	else{
		printf("The project's cost is above budget!");
		printf("\nPlanned budget: %f", project[0].cost);
		printf("\nActual cost: %f", cost_sum);
	}

	printf("\n------------------------------------------");
	printf("\n----The program will quit now! Goodbye!----");
	printf("\n----------------------------------------\n");
	exit(0);
	
}
