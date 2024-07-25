# ContactManager

**ContactManager** is a C++ console application designed to manage contact information using a hash table. The application allows you to perform basic operations such as creating, searching, updating, deleting, and displaying contact records. 

## Features

- **Create Record**: Add a new contact with a unique ID, name, and contact number.
- **Search Record**: Find and display a contact based on its ID.
- **Update Record**: Modify the details of an existing contact.
- **Delete Record**: Remove a contact from the hash table.
- **Display Records**: List all contacts currently stored in the hash table.

## Data Structure

The application uses a hash table with the following characteristics:
- **Hash Function**: `key % capacity` to distribute records.
- **Collision Resolution**: Linear probing to handle hash collisions.
- **Dynamic Resizing**: Doubles the table's capacity when full to maintain performance.

## Implementation

- **Contact Class**: Represents a contact with ID, name, and contact number. Includes a default constructor.
- **HashTable Class**: Manages contact records, including functions for adding, searching, updating, deleting, and displaying records. Handles dynamic resizing of the table.
- **Main Function**: Provides a menu-driven interface for user interactions.
