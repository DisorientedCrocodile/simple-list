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
        void write(vector<string> list);
        void read();
        
        vector<string> list;
        string name;
};