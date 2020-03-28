#include <stdio.h>
int current[5][5], max_claim[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5];
int counter = 0, i, j, exec, resources, processes, k;
 
int main()
{
	printf("\nEnter number of processes: ");
    	scanf("%d", &processes);
 
    	for (i = 0; i < processes; i++) 
		  {
        	running[i] = 1;
        	counter++;
    	}
    	printf("\nEnter number of resources: ");
    	scanf("%d", &resources);
 
    	printf("\nEnter Maximum resources :\n");
    	for (i = 0; i < resources; i++) 
		  { 
	        scanf("%d", &maxres[i]);
    	}
 
   	printf("\nEnter Allocated Resource Table:\n");
    	for (i = 0; i < processes; i++) 
	  	{
	        for(j = 0; j < resources; j++) 
			{
  			scanf("%d", &current[i][j]);
        	}
    	}
    	
   printf("\nEnter Maximum Reasources will be allocated :\n");
    	for (i = 0; i < processes; i++) 
	  	{
        	for(j = 0; j < resources; j++) 
			    {
            		scanf("%d", &max_claim[i][j]);
        	}
    	}
 
	printf("\nTotal reasources should be : ");
    	for (i = 0; i < resources; i++) 
	    {
	        printf("\t%d", maxres[i]);
	    }
 
    	printf("\nThe Allocated Resource Table:\n");
    	for (i = 0; i < processes; i++) 
	    {
	        for (j = 0; j < resources; j++) 
		      {
            		printf("\t%d", current[i][j]);
        	}
		      printf("\n");
    	}
 
    	printf("\nThe Maximum Reasources will be :\n");
    	for (i = 0; i < processes; i++) 
	   	{
        	for (j = 0; j < resources; j++) 
			    {
		        printf("\t%d", max_claim[i][j]);
        	}
        	printf("\n");
    	}
 
    	for (i = 0; i < processes; i++) 
		  {
        	for (j = 0; j < resources; j++) 
			    {
            		allocation[j] += current[i][j];
        	}
    	}
 
    	printf("\nAllocated resources:");
    	for (i = 0; i < resources; i++) 
	  	{
        	printf("\t%d", allocation[i]);
    	}
 
    	for (i = 0; i < resources; i++) 
    	{
	        available[i] = maxres[i] - allocation[i];
    	}
 
    	printf("\nAvailable resources:");
    	for (i = 0; i < resources; i++) 
		  {
        	printf("\t%d", available[i]);
    	}
    	printf("\n");

int request[processes][resources];
int safe[processes];
int count = 1;
while (counter != 0) 
{
    for (i = 0; i < processes; i++) 
	  {
	    	safe[i] = 0;
		    printf("Enter resources you want for Process(Request) :\n");
		    for (k = 0; k < resources; k++) 
	    	{
		      	scanf("%d", &request[i][k]);
        }
        if (running[i]) 
		    {
            exec = 1;
            for (j = 0; j < resources; j++) 
			      {
                if (request[i][j] != (max_claim[i][j] - current[i][j])) 
				        {
                    exec = 0;
                    break;
                }
				        else if(request[i][j] > available[j])
				        {
					          exec = 0;
                    break;
				        }
            }
	
            if (exec) 
			      {
                printf("\nProcess%d is executing\n", i + 1);
                running[i] = 0;
                counter--;
                safe[i] = 1;
 				
                for (j = 0; j < resources; j++) 
				        {
                    available[j] += request[i][j];
                }   
            }
            else
            {
            	printf("\nProcess%d is not executing\n",i+1);
			      }
			int z;
			printf("\nAvailable vector:");
       		for (z = 0; z < resources; z++) 
			    {
    	        printf("\t%d", available[z]);
    	    }
    	    printf("\n");
        }
    }
    for(i=0;i<processes;i++)
    {
    	if (!safe[i]) 
		{
        	printf("\nThe processes are in unsafe state.\n");
        	count = 0;
        	break;
    	}
	}
	if(count==1)
	{
        printf("\nThe process is in safe state");
        printf("\nAvailable vector:");
        for (i = 0; i < resources; i++) 
		    {
            printf("\t%d", available[i]);
        }
		    printf("\n");
  }
    counter=0;
}
    return 0;
}
