#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("\n----------------------------------------------------------------------\n");
    printf("S.no\tName\t\t\tPh.no\t\temail\n");
    printf("----------------------------------------------------------------------\n");

    for(int i=0; i < addressBook->contactCount; i++)
    {
	    printf("%3d\t%-20s\t%10s\t%s\n",i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    printf("----------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
	printf("\nCreate contact Menu:\n");
	printf("Enter name : ");
	scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name );
	
	char ph_no[20];
	do
	{
		printf("Enter Phone number : ");
		scanf("%s",ph_no);
	}
	while( validate_phone(addressBook, ph_no) == 0);

	strcpy( addressBook->contacts[addressBook->contactCount].phone, ph_no );

	char gmail[50];
	do
	{
		printf("Enter email : ");
		scanf("%s", gmail);
	}
	while( validate_email( addressBook, gmail) == 0 );

	strcpy( addressBook->contacts[addressBook->contactCount].email, gmail );

	addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
	printf("\nSearch Contact Menu:\n");
	printf("1.Search by name\n2.Search by Phone\n3.Search by email\n");

	int option;
	printf("Enter your option : ");
	scanf("%d", &option);

	switch(option)
	{
		case 1 : char search_name[50];
			 printf("Enter name : ");
		 	 scanf(" %[^\n]", search_name);
			 
			 searchbyname( addressBook, search_name, 0 );
			 break;

		case 2 : char search_phone[10];
                         printf("Enter Phone number : ");
                         scanf("%s", search_phone);

                         searchbyphone( addressBook, search_phone );
                         break;

		case 3 : char search_email[50];
                         printf("Enter email : ");
                         scanf("%s", search_email);

                         searchbyemail( addressBook, search_email );
                         break;

		default : printf("Enter valid option.\n");
	} 

}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
	int option, index=-1;
	do
	{
		printf("\nSearch Contact Menu:\n");
		printf("1.search by name\n2.search by phone\n3.search by email\n4.Exit\n");
		printf("Enter option : ");
		scanf("%d",&option);

		switch(option)
		{
			case 1 : char search_name[50];
				 printf("Enter name : ");
				 scanf(" %[^\n]", search_name);

				 index = searchbyname( addressBook, search_name, 1 );
	
				 break;

			case 2 : char search_phone[20];
                	         printf("Enter phone number : ");
                        	 scanf("%s", search_phone);

                        	 index = searchbyphone( addressBook, search_phone );
                         
				 break;

			case 3 : char search_email[50];
        	                 printf("Enter email : ");
                	         scanf("%s", search_email);

                        	 index = searchbyemail( addressBook, search_email );
                        	 break;

		}

		if(0 <= index && index < addressBook->contactCount)
		{
			int option2;
			do
			{
				printf("\nChose which one you want to edit\n");
				printf("1.Edit name\n2.Edit phone number\n3.Edit email\n4.Exit\n");
        			printf("Enter option : ");
        			scanf("%d",&option2);

				switch(option2)
				{
					case 1 : char edit_name[50];
			 			 printf("Enter new name : ");
				 		 scanf(" %[^\n]",edit_name);

					 	 strcpy( addressBook->contacts[index].name, edit_name );
						 printf("Name updated successfully\n");
						 break;

					case 2 : char edit_phone[20];
				 
						 do
						 {
							 printf("Enter new phone number : ");
				 			 scanf("%s",edit_phone);
				 		 }
						 while( validate_phone( addressBook, edit_phone) == 0 );

						 strcpy( addressBook->contacts[index].phone, edit_phone );
                	        	         printf("Phone number updated successfully\n");
						 break;

					case 3 : char edit_email[50];

        	                	         do
                	                	 {
                        	                	 printf("Enter new email : ");
                          		      	         scanf("%s",edit_email);
                                		 }
                                		 while( validate_email( addressBook, edit_email) == 0 );

                                 		 strcpy( addressBook->contacts[index].email, edit_email );
                                 		 printf("Email updated successfully\n");
						 break;

				}
			}while(option2 != 4);

			index=-1;
		}
	}while(option !=4);
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
	int option, index=-1;
        do
        {
                printf("\nSearch Contact Menu:\n");
                printf("1.search by name\n2.search by phone\n3.search by email\n4.Exit\n");
                printf("Enter option : ");
                scanf("%d",&option);

                switch(option)
                {
                        case 1 : char search_name[50];
                                 printf("Enter name : ");
                                 scanf(" %[^\n]", search_name);

                                 index = searchbyname( addressBook, search_name, 1 );

                                 break;

                        case 2 : char search_phone[20];
                                 printf("Enter phone number : ");
                                 scanf("%s", search_phone);

                                 index = searchbyphone( addressBook, search_phone );

                                 break;

                        case 3 : char search_email[50];
                                 printf("Enter email : ");
                                 scanf("%s", search_email);

                                 index = searchbyemail( addressBook, search_email );
                                 break;

                }

		if(index >= 0)
		{
			int choice;
			printf("\nDo you want to delete\n");
			printf("1.yes\n2.no\n");
			printf("Enter your option : ");
			scanf("%d",&choice);
		
			if( choice == 1 )
			{
				for(int i=index; i < addressBook->contactCount - 1; i++)
				{
					addressBook->contacts[i] = addressBook->contacts[i+1];
				}
				addressBook->contactCount--;
				printf("Contact delited successfully\n");
			}
			index=-1;
		}
	}while(option != 4);
}

int validate_phone(AddressBook *addressBook, char *ph_no)
{
	unsigned int size = strlen(ph_no);
	if(size != 10)
	{
		printf("error : Enter 10 digits\n");
		return 0;
	}
	for(int i=0; i<10; i++)
	{
		if(ph_no[i] < '0' || ph_no[i] >'9')
		{
			printf("error : Enter only digits\n");
			return 0;
		}
	}
	for(int i=0; i < addressBook->contactCount; i++)
	{
		if( strcmp(addressBook->contacts[i].phone,ph_no) == 0)
		{
			printf("error : Duplicate phone number\n");
			return 0;
		}
	}

	return 1;
}

int validate_email(AddressBook *addressBook, char *gmail)
{
	char *at = strchr(gmail,'@');
	if(at == NULL)
	{
		printf("error : Enter '@' character\n");
		return 0;
	}

	char *com = strstr(gmail,".com");
	if(com == NULL)
	{
		printf("error : Enter .com\n");
		return 0;
	}
	if( strcmp(com,".com") != 0 )
	{
		printf("error : Enter .com at end\n");
		return 0;
	}

	int len = strlen(gmail);	
	for(int i=0; i<len; i++)
	{
		if(gmail[i] >= 'A' && gmail[i] <= 'Z')
		{
			printf("error : don't enter capital letters\n");
			return 0;
		}
	}

	if( at == gmail || *(at+1) == '.')
	{
		printf("error : enter atleast 1 alnum char beside of '@'\n");
		return 0;
	}

	for(int i=0; i < addressBook->contactCount; i++)
        {
                if( strcmp(addressBook->contacts[i].email, gmail) == 0)
                {
                        printf("error : Duplicate email id\n");
                        return 0;
                }
        }

        return 1;

}

int searchbyname(AddressBook *addressBook, char *search_name, int ret)
{
	int i, count=0;
	int arr[addressBook->contactCount];

	for(i=0; i < addressBook->contactCount; i++)
        {
                if( strcmp(addressBook->contacts[i].name, search_name ) == 0)
                {
			if(count == 0)
			{
				printf("\nPerson Details are :\n");
        			printf("S.no\tName\t\t\tPhone\t\temail\n");
			}

                        printf("%3d\t%-20s\t%10s\t%s\n", count+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email );
			arr[count++]=i;
                }
        }
	if(count == 0)
	{
		printf("Not found\n");
		return -1;
	}
	if(count == 1)
	{
		return arr[0];
	}
	if(ret == 1)
	{
		int index;
		printf("Choose which one is your details\n");
		printf("Enter option by choose s.no : ");
		scanf("%d",&index);

		for(int i=0; i< addressBook->contactCount; i++)
		{
			if(index == i+1)
			{
				return arr[index-1];
			}
		}
	}
}
int searchbyphone(AddressBook *addressBook, char *search_phone)
{
	int count =0;
	for(int i=0; i < addressBook->contactCount; i++)
        {
                if( strcmp(addressBook->contacts[i].phone, search_phone ) == 0)
                {
			if(count == 0)
			{
				printf("\nPerson Details are :\n");
        			printf("S.no\tName\t\t\tPhone\t\temail\n");
			}

                        printf("%3d\t%-20s\t%10s\t%s\n", count+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email );
			count++;
			return i;
                }
        }
	printf("Not found\n");
	return -1;
}
int searchbyemail(AddressBook *addressBook, char *search_email)
{
        int count =0;
	for(int i=0; i < addressBook->contactCount; i++)
        {
                if( strcmp(addressBook->contacts[i].email, search_email ) == 0)
                {
			if(count == 0)
			{
				printf("\nPerson Details are :\n");
        			printf("S.no\tName\t\t\tPhone\t\temail\n");
			}

                        printf("%3d\t%-20s\t%10s\t%s\n", count+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email );
			count++;
			return i;
                }
        }
        printf("Not found\n");
        return -1;
}
