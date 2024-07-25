#ContactManager
ContactManager is a console-based application implemented in C++ for managing contact information using a hash table data structure. The application provides a set of functionalities to create, search, update, delete, and display contact records. It utilizes open addressing with linear probing to handle collisions in the hash table.

#Features
Create Record: Add a new contact record with a unique ID, name, and contact number.
Search Record: Find and display a contact record based on its unique ID.
Update Record: Modify the name and contact number of an existing record.
Delete Record: Remove a contact record from the hash table.
Display Records: Print all existing contact records in the hash table.
Data Structure
The application uses a hash table with the following characteristics:

Hash Function: key % capacity for distributing contact records across the hash table.
Collision Resolution: Linear probing to handle collisions when inserting records.
Dynamic Resizing: The hash table resizes itself (doubles its capacity) when it becomes full to maintain efficient operations.
Implementation Details
Contact Class: Represents a contact with attributes for ID, name, and contact number. It also includes a default constructor.
HashTable Class: Manages the contact records with functions for adding, searching, updating, deleting, and displaying records. It includes methods for resizing the hash table when necessary.
Main Function: Provides a menu-driven interface for interacting with the hash table and performing various operations.
