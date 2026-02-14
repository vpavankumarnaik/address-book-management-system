#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

int validate_phone(AddressBook *addressBook, char *ph_no);
int validate_email(AddressBook *addressBook, char *gmail);

int searchbyname(AddressBook *addressBook, char *search_name, int ret);
int searchbyphone(AddressBook *addressBook, char *search_phone);
int searchbyemail(AddressBook *addressBook, char *search_email);

#endif
