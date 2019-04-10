#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() 
{
	int menuOpt, i, opt = 0, itemNum = 1, qtyToAdd;
	int quantities[10] = {0,0,0,0,0,0,0,0,0,0};
	float prices[10] = {120,120,150,150,170,170,195,195,210,210};
	float total = 0, money;
	printf("=====================================================================\n");
	printf("||                        STARBUCK'S COFFEE                        ||\n");
	do {
		main:
		printf("=====================================================================\n");	
		printf("|| 1. View Menu                                                    ||\n");
		printf("|| 2. Add Coffee                                                   ||\n");
		printf("|| 3. Remove Coffee                                                ||\n");
		printf("|| 4. Payment                                                      ||\n");
		printf("|| 5. Exit                                                         ||\n");
		printf("=====================================================================\n");
		scanf("%d", &menuOpt);
		switch(menuOpt) {
			case 1:
				printf("===============================================\n");
				printf("||              Starbucks Menu               ||\n");
				printf("|---------------------------------------------|\n");
				printf("|| #    COFFEE                    PRICE      ||\n");
				printf("|| 1    Coffee of the Day          P120      ||\n");
				printf("|| 2    Iced Coffee                P120      ||\n");
				printf("|| 3    Classic Hot Chocolate      P150      ||\n");
				printf("|| 4    Starbucks® Signature       P150      ||\n");
				printf("|| 5    Coffee Frappuccino         P170      ||\n");
				printf("|| 6    Espresso Frappuccino       P170      ||\n");
				printf("|| 7    Mocha Frappuccino          P195      ||\n");
				printf("|| 8    Java Chip Frappuccino      P195      ||\n");
				printf("|| 9    Caramel Frappuccino        P210      ||\n");
				printf("|| 10   Strawberries Frappuccino   P210      ||\n");
				printf("===============================================\n\n");
				break;
			case 2:				
				do 
				{
					do 
					{
						printf("Please input the number of the coffee to be added: ");
						scanf("%d", &itemNum);
						if(itemNum < 1 || itemNum >  10) 
						{
							printf("\n\nCoffee is not for sale, please try a different coffee.\n\n");
						}
						else
						{
							printf("Please input quantity: ");
							scanf("%d" , &qtyToAdd);	
							quantities[itemNum-1] = quantities[itemNum-1] + qtyToAdd;		
							printf("\n\nCoffee(s) added!\n\n");
						}
					}
					while ( itemNum < 1 || itemNum > 10);		
					printf("Are you going to add another item?\n");
					printf("<1> - Yes <2> - No\n");
					scanf("%d", &opt);		
				} 
				while (opt == 1);
				break;
			case 3:
				do 
				{
					do 
					{
						printf("Please input the number of coffee you want to remove: ");
						scanf("%d", &itemNum);
						if(itemNum < 1 || itemNum >  10) 
						{
							printf("\n\nCoffee does not exist, try again.\n\n");
						}
						else
						{
							quantities[itemNum-1] = 0;	
							printf("\n\nCoffee(s) removed from cart!\n\n");
						}
					} 
					while ( itemNum < 1 || itemNum > 10);
					printf("Are you going to remove another item?\n");
					printf("<1> - Yes <2> - No\n");
					scanf("%d", &opt);
				} 
				while (opt == 1);
				break;
			case 4:
				printf("===================================================================\n");
				printf("||                          CHECKOUT                             ||\n");
				printf("===================================================================\n");
				printf(" COFFEE                      QTY                 PRICE\n");	
				for(i = 0; i < 10; i++) 
				{
					if(quantities[i] > 0) 
					{
					total = total + (prices[i]*quantities[i]);
					switch(i) 
						{
						case 0:
							printf("Coffee of the Day            %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 1:
							printf("Iced Coffee                  %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 2:
							printf("Classic Hot Chocolate        %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 3:
							printf("Starbucks® Signature         %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 4:
							printf("Coffee Frappuccino           %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 5:
							printf("Espresso Frappuccino         %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 6:
							printf("Mocha Frappuccino            %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 7:
							printf("Java Chip Frappuccino        %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 8:
							printf("Caramel Frappuccino          %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						case 9:
							printf("Strawberries Frappuccino     %d                   %.2f\n" , quantities[i], prices[i]*quantities[i]);
							break;
						}
					}
				}
					printf(" TOTAL:                                          %.2f\n\n" , total);	
					do {
						printf("Please enter amount of cash for payment: ");
						scanf("%f" , &money);
						
						if(money < total) 
							printf("\n\nInsufficient Amount. Please enter sufficient amount...\n\n");
					} while (money < total);
					
					printf("\nTOTAL: %.2f\n" , total);
					printf("CHANGE: %.2f\n\n", money-total);
					
					printf("Order is successful!");
					
					menuOpt = 6;
					break;
				case 5:
					exit(1);
					break;
				default:
					printf("\n\nInvalid input... try again.\n\n");
					break;
			}
			
		} while (menuOpt != 6);
		
		goto main;		
	}

