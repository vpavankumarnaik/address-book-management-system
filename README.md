# Address Book Management System (C)

## Overview
A console-based contact management system implemented in C.
The application uses structures and file handling to provide persistent storage of contact information.

## Features
- Add new contact
- Search contact by name
- Edit existing contact
- Delete contact
- Data persistence using file operations

## Data Structure

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

Contacts are stored in a file using standard C file handling functions (fopen, fwrite/fprintf, fread/fscanf).

## Design Approach
- Modular programming using separate source and header files
- Structure-based data storage
- File handling for persistence
- Menu-driven interface using switch-case

## Compilation
gcc *.c -o address_book

## Run
./address_book
