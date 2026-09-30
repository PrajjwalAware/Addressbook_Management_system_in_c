\# Address Book Management System in C



\## Project Overview



The Address Book Management System is a console-based application developed in C for managing contact information.



The application provides the basic operations required for maintaining an address book:



\- Create a new contact

\- Search for an existing contact

\- Edit contact information

\- Delete a contact

\- Display all contacts

\- Validate contact information

\- Save contact information to a file

\- Load previously stored contacts when the application starts



The project is implemented using multiple C source and header files to keep different responsibilities separated.



The main purpose of this project was to apply C programming concepts in a practical application and gain experience with structures, pointers, strings, arrays, functions, file handling, input validation, and modular programming.



\## Objectives



The main objectives of the project are:



\- Build a functional contact management application using C.

\- Implement Create, Read, Update, and Delete operations.

\- Use structures to represent contact information.

\- Implement a menu-driven console application.

\- Separate functionality into multiple source and header files.

\- Validate user input before accepting contact information.

\- Prevent duplicate mobile numbers and email addresses.

\- Store contact information using file handling.

\- Load previously stored contacts when the application starts.

\- Practice compiling and managing a multi-file C project using GCC.

\- Use Git and GitHub for source-code management.



\## Features



\### Create Contact



The application allows the user to add a new contact.



Each contact contains:



Name

Mobile Number

Email Address



\-------------------------------------------------------------------------------------------------------------



Addressbook-NewDesign/

│

├── main.c

├── contact.c

├── contact.h

├── file.c

├── file.h

├── populate.c

├── populate.h

├── contacts.txt

├── .gitignore

└── README.md


\-------------------------------------------------------------------------------------------------------------



\## Application Demo



The following examples demonstrate the main operations implemented in the Address Book Management System.



1\. List All Contacts



When the application starts, the contacts stored in `contacts.txt` are loaded into the address book.



Address Book Menu:



1\. Create contact

2\. Search contact

3\. Edit contact

4\. Delete contact

5\. List all contacts

6\. Save and Exit



Enter your choice: 5



\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

Name     :prajjwal

Phone    :8767927729

Email    :prajjwal@gmail.com

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

Name     :rahul k

Phone    :8877669910

Email    :rahul@gmail.com

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

Name     :mohit

Phone    :9878679876

Email    :mhitchillar@gmail.com

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*



\-----------------------------------------------------------------------------------------------------------------



2\. Search Contact by Name



The application provides three search options:



Select option by which you have to search contacts

1.NAME

2.PHONE

3.E-MAIL



Enter name to be searched:

prajjwal



Name      :prajjwal

Mobile    :8767927729

E-mail    :prajjwal@gmail.com



\-----------------------------------------------------------------------------------------------------------------



3\. Search Contact by Phone



A contact can also be searched using its mobile number.



Select option by which you have to search contacts

1.NAME

2.PHONE

3.E-MAIL



Enter phone number to be searched:

8767927729



Name      :prajjwal

Mobile    :8767927729

E-mail    :prajjwal@gmail.com



\-----------------------------------------------------------------------------------------------------------------



4\. Create Contact



A new contact can be added by providing the name, mobile number, and email address.



For demonstration, a sample contact was added:



Enter name :Test User



Enter mobile No.:9000000001



Enter email :test@example.com



After creation, the contact appears in the address book:



Name     :Test User

Phone    :9000000001

Email    :test@example.com



\---------------------------------------------------------------------------------------------------------------------



5\. Edit Contact



The application allows an existing contact to be edited.



The contact is first selected using its name.



Enter name: Test User



contact found



Select option to proceed edit

1.name

2.phone

3.E-MAIL



Enter new mobile number:

9000000002



Mobile Number Updated



\----------------------------------------------------------------------------------------------------------------------



6\. Delete Contact



An existing contact can be deleted by entering its name.



The application first displays the contact details and asks for confirmation.



Enter Name of contact: Test User



Name      :Test User

Mobile    :9000000002

E-mail    :test@example.com



Do you want to delete this contact(Y,y/N,n)

y



contact Deleted successfully



\-----------------------------------------------------------------------------------------------------------------------



7\. Save and Exit



After completing the required operations, the user can select Save and Exit.



Enter your choice: 6



Saving and Exiting...



\------------------------------------------------------------------------------------------------------------------------

