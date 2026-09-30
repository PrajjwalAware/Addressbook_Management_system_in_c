#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr=fopen("contacts.txt","w");
    if(fptr==NULL){
        printf("File cannot be opened\n");
        return;
    }
    

    for(int i=0;i<addressBook->contactCount;i++){
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr=fopen("contacts.txt","r");
    if(fptr==NULL){
        printf("File cannot be opened\n");
        return ;
    }int i=0;
    
    while(fscanf(fptr," %[^,],%[^,],%[^\n]",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email)==3){
        i++;
    }
    addressBook->contactCount=i;
    
    fclose(fptr);
}

