#include <iostream>
#include <string>
using namespace std;

//creating a new class to store contacts

class Contact {
    string name;
    int number;
    int ID;

public:
    Contact(){
        name = "";
        number = 0 ;
        ID = 0 ;
    }

    friend class HashTable;
};

// crating hashTable class to do all function
// It's size will change dynamically 

class HashTable {
    Contact* data;
    int capacity;
    int size;
   
    // function to find the key 
 
    int hashFunction(int key) {
        return key % capacity;
    }

    // function that will resize the table ,
    // If the table is completely filled then it will double its size 
    // copy the data original data and the add new data on this new table
 
    void resize() {
        int newCapacity = capacity * 2;
        Contact* newData = new Contact[newCapacity];
        for (int i = 0; i < capacity; ++i) {
            if (data[i].ID != 0) {
                int newIndex = data[i].ID % newCapacity;
                while (newData[newIndex].ID != 0) {
                    newIndex = (newIndex + 1) % newCapacity;
                }
                newData[newIndex] = data[i];
            }
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    HashTable(int initialCapacity = 5) {
    capacity = initialCapacity;  
    size = 0;                    
    data = new Contact[capacity];  
    }

    ~HashTable() {
        delete[] data;
    }

    // function to create new record 

    void createRecord() {
        int ID;
        cout << "Enter the ID: ";
        cin >> ID;
        if (ID <= 0) {
            cout << "Invalid ID. ID must be a positive integer." << endl;
            return;
        }
        string name;
        cout << "Enter the Name: ";
        cin >> name;
        int number;
        cout << "Enter the Contact Number: ";
        cin >> number;

        if (size >= capacity) {
            resize();
        }

        int index = hashFunction(ID);
        while (data[index].ID != 0) {
            index = (index + 1) % capacity;
        }

        data[index].ID = index;
        data[index].name = name;
        data[index].number = number;
        ++size;

        cout << "Record added successfully!" << endl;
    }

    //function to search in the record on the basis of ID

    void searchRecord() {
        int key;
        cout << "Enter the ID to search: ";
        cin >> key;

        int index = hashFunction(key);
        int originalIndex = index;
        while (data[index].ID != key && data[index].ID != 0) {
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                cout << "Record not found!" << endl;
                return;
            }
        }

        if (data[index].ID == key) {
            cout << "Record found:" << endl;
            cout << "ID: " << data[index].ID << ", Name: " << data[index].name << ", Contact Number: " << data[index].number << endl;
        } else {
            cout << "Record not found!" << endl;
        }
    }

    //function to delete the record 

    void deleteRecord() {
        int key;
        cout << "Enter the ID to delete: ";
        cin >> key;

        int index = hashFunction(key);
        int originalIndex = index;
        while (data[index].ID != key && data[index].ID != 0) {
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                cout << "Record not found!" << endl;
                return;
            }
        }

        if (data[index].ID == key) {
            data[index].ID = 0;
            data[index].name = "";
            data[index].number = 0;
            --size;
            cout << "Record deleted successfully!" << endl;
        } else {
            cout << "Record not found!" << endl;
        }
    }

    // function to update record on the basis of ID

    void updateRecord() {
    int key;
    cout << "Enter the ID to update: ";
    cin >> key;

    int index = hashFunction(key);
    int originalIndex = index;
    while (data[index].ID != key && data[index].ID != 0) {
        index = (index + 1) % capacity;
        if (index == originalIndex) {
            cout << "Record not found!" << endl;
            return;
        }
    }

    if (data[index].ID == key) {
        cout << "Enter the new Name: ";
        cin >> data[index].name;
        cout << "Enter the new Contact Number: ";
        cin >> data[index].number;
        cout << "Record updated successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}   
   
   // function to print all the records present in the hashTable

    void displayRecord() {
        cout << "ID\tName\tContact Number" << endl;
        for (int i = 0; i < capacity; ++i) {
            if (data[i].ID != 0) {
                cout << data[i].ID << "\t" << data[i].name << "\t" << data[i].number << endl;
            }
        }
    }
};

int main() {
    HashTable contacts;
    int choice;
    do { 
        cout << "\n1. Create Record\n2. Search Record\n3. Delete Record\n4. Display Records\n5. Update Record\n6. Exit\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                contacts.createRecord();
                break;
            case 2:
                contacts.searchRecord();
                break;
            case 3:
                contacts.deleteRecord();
                break;
            case 4:
                contacts.displayRecord();
                break;
            case 5:
                contacts.updateRecord();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
