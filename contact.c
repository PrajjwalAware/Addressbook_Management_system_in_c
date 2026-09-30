#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
//Edit contacts
void s_phone(AddressBook *addressBook);    
void s_name(AddressBook *addressbook);
void s_email(AddressBook *addressBook);



int validate_name(char *name);  //validation for NAME

int validate_mob(char *phone,AddressBook*addressbook,int index);  //validation for MOBILE NUMBER

int validate_email(char* email,AddressBook*addressBook,int index);   //validate EMAIL

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    for(int i=0;i<addressBook->contactCount;i++){
        printf("*******************************************************\n");
        printf("Name     :%s\n",addressBook->contacts[i].name);
        printf("Phone    :%s\n",addressBook->contacts[i].phone);
        printf("Email    :%s\n",addressBook->contacts[i].email);
        printf("*******************************************************\n");
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    loadContactsFromFile(addressBook);
    
 
 
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

//************************************************************************************************************************************************** */
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int n_flag;
    do
    {
        
        printf("------------------------------------------------------\n");
        printf("Enter name :");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
        printf("=======================================================\n");
        n_flag=validate_name(addressBook->contacts[addressBook->contactCount].name);  //function call
        if(n_flag==0)
        {
            printf("Name should not contain NUMBERS, please enter valid name\n");
        }
        
    }while (n_flag==0);//when flag=0 run loop again
    
    int m_flag;
    do 
    {
        printf("------------------------------------------------------\n");
        printf("Enter mobile No.:");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
        printf("=======================================================\n");
        m_flag=validate_mob(addressBook->contacts[addressBook->contactCount].phone,addressBook,-1);
        
        if(m_flag==0){
            printf("Mobile number should not contain Alphabets, please enter valid mobile number\n");
        }
        else if(m_flag==2){
            printf("Mobile number should have 10 digits, Please enter valid mobile number\n");
        }
        else if (m_flag==3)
        {
            printf("This mobile number already exists,  Please try with another mobile number\n");
        }
        
    }while(m_flag!=1);
    int e_flag;
    do{
        e_flag=0;
        printf("------------------------------------------------------\n");
        printf("Enter email :");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
        printf("=======================================================\n");
        e_flag=validate_email(addressBook->contacts[addressBook->contactCount].email,addressBook,-1);
        if(e_flag==0){
            printf("E-mail should contain @ and .com\n");
        }
        else if(e_flag==2){
            printf("Email already exists, please try another Email\n");
        }
    }while(e_flag!=1);

 
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int opt;
    printf("Select option to search contacts\n");
    printf("1.NAME\n2.PHONE\n3.E-MAIL\n");
    scanf(" %d",&opt);
    switch(opt){
        case 1: s_name(addressBook);
        break;
        case 2: s_phone(addressBook);
        break;
        case 3: s_email(addressBook);
        break;
        default: printf("Invalid option, Try again\n");
    }
    
}
/************************************************************************************************************************************************ */
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char name[30];
    int found=0;
    printf("Enter name:");
    scanf(" %[^\n]",name);
    int index;

    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(name,addressBook->contacts[i].name)==0){
            
            found=1;
            index=i;
            break;
        }
    }
    if(found==0){
        printf("contact not found\n");
        return;
    }
    printf("contact found\n");
    printf("Select option to edit\n");
    printf("1.name\n2.phone\n3.E-MAIL\n");
    int opt;
    scanf("%d",&opt);

    if(opt==1){
        char n_name[50];
        while(1){
            printf("Enter new name:\n");
            scanf(" %[^\n]",n_name);
            if(validate_name(n_name)){
                strcpy(addressBook->contacts[index].name,n_name); 
                printf("Name Updated\n");
                break;
            }
            else{
                printf("Invalid Name\n");
            }
        }

    }
    else if(opt==2){
        char n_mobile[20];
        while(1){
            printf("Enter new mobile number:\n");
            scanf(" %[^\n]",n_mobile);
            if(validate_mob(n_mobile,addressBook,index)==1){
                strcpy(addressBook->contacts[index].phone,n_mobile);
                printf("Mobile Number Updated\n");
                break;
            }
            else{
                printf("invalid mobile number");
            }
        }

    }
    else if(opt==3){
        char n_email[60];
        while(1){
            printf("Enter new email:\n");
            scanf(" %[^\n]",n_email);
            if(validate_email(n_email,addressBook,index)==1){
                strcpy(addressBook->contacts[index].email,n_email);
                printf("E-Mail Updated\n");
                break;
            }
            else{
                printf("invalid E-mail\n");
            }
        }
    }
}
/*************************************************************************************************************************************************** */
//delete contact

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char name[50];
    int found=0;
    int index;
    printf("Enter Name of contact:");
    scanf(" %[^\n]",name);
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(name,addressBook->contacts[i].name)==0){
            found=1;
            index=i;
            break;
            
        }
    }
        if(found==0){
            printf("Contact doesnot exists\n");
            return;
        }
        printf("Name      :%s\n",addressBook->contacts[index].name);
        printf("Mobile    :%s\n",addressBook->contacts[index].phone);
        printf("E-mail    :%s\n",addressBook->contacts[index].email);
        
        char opt;
        printf("Do you want to delete this contact(Y,y/N,n)\n");
        scanf(" %c",&opt);
        if(opt=='Y' || opt =='y'){
            for(int i=index;i<addressBook->contactCount-1;i++){
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
            addressBook->contactCount--;
            printf("contact Deleted succesfully\n");
        }
        else{
            printf("Contact not Deleted\n");
        }

    
}

//************************************************************************************************************************************************** */
//Validate contact
int validate_name(char *name){
    for(int i=0;name[i]!='\0';i++){
            if(isalpha(name[i])==0 && name[i]!=' '){
                return 0;
            }
            
    }
    return 1;
}

int validate_mob(char *phone,AddressBook*addressbook,int index){
int i;
    for(i=0;phone[i]!='\0';i++){
        if(isdigit(phone[i])==0){
            return 0;
        }
    }
    if(i!=10){
        return 2;
    }
    for(int i=0;i<addressbook->contactCount;i++){
        if(i!=index && strcmp(addressbook->contacts[i].phone,phone)==0){
            return 3;
        }
    }
    
    return 1;
    

}

int validate_email(char* email,AddressBook*addressBook,int index){
    if(strstr(email,"@")==0 || strstr(email,".com")==0){
        return 0;
    }
    for(int i=0;i<addressBook->contactCount;i++){
        if(i!=index && strcmp(addressBook->contacts[i].email,email)==0){
            return 2;
        }
    }
    return 1;
}

//************************************************************************************************************************************************** */
//search contacts

void s_name(AddressBook *addressbook){
    char name[20];
    int i;
    int found=0;
    printf("Enter name to be searched:\n");
    scanf(" %[^\n]",name);

    for(i=0;i < addressbook->contactCount;i++){
       
        if(strcmp(name,addressbook->contacts[i].name)==0){
            printf("Name      :%s\n",addressbook->contacts[i].name);
            printf("Mobile    :%s\n",addressbook->contacts[i].phone);
            printf("E-mail    :%s\n",addressbook->contacts[i].email);
            found=1;
        }
    }
    if(found==0){
        printf("Contact doesn't exists\n");
    }
}

void s_phone(AddressBook *addressBook){

    char phone[20];
    int i;
    int found=0;
    printf("Enter phone number to be searched:\n");
    scanf(" %[^\n]",phone);
    for(i=0;i < addressBook->contactCount;i++){
        if(strcmp(phone,addressBook->contacts[i].phone)==0){
            printf("Name      :%s\n",addressBook->contacts[i].name);
            printf("Mobile    :%s\n",addressBook->contacts[i].phone);
            printf("E-mail    :%s\n",addressBook->contacts[i].email);
            found=1;
        }
    }
    if(found==0){
        printf("Contact doesn't exists\n");
    }

}

void s_email(AddressBook *addressBook){

    char email[50];
    int i;
    int found=0;
    printf("Enter E-mail to be searched:\n");
    scanf(" %[^\n]",email);
    for(i=0;i < addressBook->contactCount;i++){
        if(strcmp(email,addressBook->contacts[i].email)==0){
            printf("Name      :%s\n",addressBook->contacts[i].name);
            printf("Mobile    :%s\n",addressBook->contacts[i].phone);
            printf("E-mail    :%s\n",addressBook->contacts[i].email);
            found=1;
        }
    }
    if(found==0){
        printf("Contact doesn't exists\n");
    }

}


