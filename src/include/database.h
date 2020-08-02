#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Database {
    private:
    protected:
    public:
        Database() {
            //Constructor
        }
        ~Database() {
            //Deconstructor
        }
        vector<vector<string>> mainList;
        string name;

        void write(vector<vector<string>> mainlist);
        vector<vector<string>> read();
};