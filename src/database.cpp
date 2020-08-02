#include "include/database.h"

void Database::write(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/lists.sl");
    if (db.is_open()) {
        for (int userIndex = 0; userIndex < (int)mainList[userIndex].size(), userIndex++;)
        {
            for (int list_index = 0; list_index < (int)mainList[userIndex][list_index].size(); list_index++) {
                db << mainList[userIndex][list_index] << "\n";
            }
        }
    }
    else {
        cout << "Can't open file\n";
    }
    db.close();
}

vector<vector<string>> Database::read() {
    string line;
    ifstream db;

    vector<string> userList;
    db.open("db/lists.sl");
    if (db.is_open()) {
        while (getline(db,line,'\n'))
        {
            if (line.front() == '#') {
                cout << "Found a hashtag: " << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if (line.front() == '%') {
                cout << "Found a Percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else {
                cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }
        }
        
    }
    else {
        cout << "Cannot open file";
    }

    db.close();

    return mainList;

}