#include<stdio.h>
#define MAX_SIZE 100
#define KEY 7

typedef struct {
    char name[10];
    long long phone;
} Contact;

int ask_choice() {
    int choice;
    printf("Select Operations: \n");
    printf("  1. Add Contact: \n");
    printf("  2. Delete Contact: \n");
    printf("  3. Display Phonebook: \n");
    printf("  4. Exit: \n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    return choice;
}

Contact inputContact() {
    Contact new_contact;
    printf("Enter Name: ");
    scanf("%s", new_contact.name);
    printf("Enter Phone Number: ");
    scanf("%lld", &new_contact.phone);
    return new_contact;
}

void printContact(Contact a) {
    printf("%s\t%lld\n", a.name, a.phone);
}

int hash(long long phone_number) {
    return phone_number % KEY;
}

void addContact(Contact HASHTABLE[KEY][MAX_SIZE], int no_of_entries[KEY]) {
    Contact new_contact = inputContact();
    int key = hash(new_contact.phone);
    HASHTABLE[key][no_of_entries[key]++] = new_contact;
}

void deleteContact(Contact HASHTABLE[KEY][MAX_SIZE], int no_of_entries[KEY]) {
    printf("Enter Phone Number to Delete: ");
    long long phone_number;
    scanf("%lld", &phone_number);

    int key = hash(phone_number);

    // linear search
    int target_index = -1;
    for (int i = 0; i < no_of_entries[key]; ++i)
    {
        if(HASHTABLE[key][i].phone == phone_number) {
            target_index = i;
            break;
        }
    }

    // check if phone number found
    if(target_index == -1) return;
    
    // deletion process
    no_of_entries[key]--;
    HASHTABLE[key][target_index] = HASHTABLE[key][no_of_entries[key]];
}

void displayContacts(Contact HASHTABLE[KEY][MAX_SIZE], int no_of_entries[KEY]) {
    for (int key = 0; key < KEY; ++key)
    {
        for (int i = 0; i < no_of_entries[key]; ++i)
        {
            printContact(HASHTABLE[key][i]);
        }
    }
}


int main() {
    Contact HASHTABLE[KEY][MAX_SIZE];
    int no_of_entries[KEY] = {0};

    int choice;
    while(choice != 4) {
        choice = ask_choice();
        switch(choice) {
            case 1:
                addContact(HASHTABLE, no_of_entries);
                break;
            case 2:
                deleteContact(HASHTABLE, no_of_entries);
                break;
            case 3:
                displayContacts(HASHTABLE, no_of_entries);
                break;
            case 4:
                break;
        }
    }
    return 0;
}