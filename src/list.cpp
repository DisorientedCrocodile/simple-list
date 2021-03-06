#include "include/list.h"

void List::print_menu() {
    system("clear");
    int choice;
    cin.clear();

    cout << "*********************\n";
    cout << " 1 - Print List\n";
    cout << " 2 - Add To List\n";
    cout << " 3 - Delete From List\n";
    cout << " 4 - Save List\n";
    cout << " 5 - Quit\n";
    cout << "*********************\n";
    cout << "Enter your choice and press Enter: ";

    cin >> choice;

    if (choice == 5) {
        cout << "Qutting...\n";
        return;
    }
    else if (choice == 1) {
        system("clear");
        print_list();
    }
    else if (choice == 2) {
        system("clear");
        add_item();
    }
    else if (choice == 3) {
        system("clear");
        delete_item();
    }
    else if (choice == 4) {
        save_list();
    }
    else {
        cout << "Sorry choice not implemented yet\n";
    }
}

void List::add_item() {
    cout << "***Add Item***\n";
    cout << "Type in an item and press Enter: ";
    string item;
    cin >> item;
    list.push_back(item);
    cout << "Successfully added an item to the list\n\n\n\n";
    cin.clear();

    print_menu();
}

void List::delete_item() {
    cout << "***Delete Item***\n";
    if (list.size()) {
        for (int i = 0; i < (int)list.size(); i++)
        {
            cout << i << ". " << list[i] << "\n";
        }
        cout << "Select an item index to delete: ";
        int choice_num;
        cin >> choice_num;
        list.erase(list.begin() + choice_num);
        print_menu();
    }
    else {
        cout << "No items to delete\n";
        cout << "M - Menu\n";
        char choice;
        cin >> choice;
        if (choice == 'M' || choice == 'm') {
            print_menu();
        }
        else {
            cout << "Invalid choice. Quitting...";
        }
    }
}

void List::print_list() {
    cout << "***Printing List***\n";

    for (int list_index = 0; list_index < (int)list.size(); list_index++)
    {
        cout << " * " << list[list_index] << "\n";
    }
    cout << "M - Menu\n";
    char choice;
    cin >> choice;

    if (choice == 'M' || choice == 'm') {
        print_menu();
    }
    else
    {
        cout << "Invalid choice. Quitting...\n";
    }
    
}

bool List::find_userList() {
    bool userFound = false;
    system("clear");
    cout << "***Welcome"  << name << "***\n";

    for (int userIndex = 0; userIndex < (int)mainList.size(); userIndex++) {
        if (mainList[userIndex][0] == name) {
            list = mainList[userIndex];
            currentUserIndex = userIndex;
            userFound = true;
            break;
        }
    }

    if (userFound == false) {
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size() - 1;
    }

    return userFound;
}

void List::save_list() {
    cout << "Saving the list.." << "\n";
    mainList[currentUserIndex] = list;
    print_menu();
}