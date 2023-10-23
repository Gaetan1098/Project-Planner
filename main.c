/********* main.c ********
	
#include <stdio.h>
#include "a1_functions.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    milestone_t milestones[6];
	strcpy(milestones[0].name, "Planned Details");
    milestones[0].cost = get_input_f();
	milestones[0].time = get_input_f2();
	milestones[0].completed = 0;
    number_of_employees(&milestones[0]);
    printf("The planned number of employees needed is : %d\n", milestones[0].num_employees);
    printf("\n-------------------------------------------------------------------------------\n");

    milestones[1] = init_milestone("Technical requirements", milestones[0].cost);
    milestones[2] = init_milestone("System Design", milestones[0].cost);
    milestones[3] = init_milestone("Software Development", milestones[0].cost);
    milestones[4] = init_milestone("Testing", milestones[0].cost);
    milestones[5] = init_milestone("Product release", milestones[0].cost);

	unsigned short int input;
	unsigned short int quit = 0;
	char *end;
	while(quit == 0)
	{
		print_menu();
		input = get_input_usi();
		if (input == 0)
		{
			check_project_completion(milestones, 5);
			if (milestones[0].completed)
			{
				print_final_stats(milestones, 5);
			}
		}
		print_stats(milestones[input]);
		if (!milestones[input].completed)
		{
			update_stats(milestones, input);
		}
		
	}
}
