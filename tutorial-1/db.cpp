#include <iostream>
#include <string>
using namespace std;

class DB
{
private:
    /* data */
public:
    void start();
    void print_prompt();
    bool parse_meta_command(string);
};



void DB::print_prompt() {
   cout << "db > ";
}

// 解析元命令
bool DB::parse_meta_command(string command) {
    if (command == ".exit") {
        cout << "Bye!" << endl;
        exit(EXIT_SUCCESS);
    }else {
        cout << "Unrecognized command: " << command << endl;
        return true;
    }

    return false;
}

void DB::start() {
    while(true) {
        print_prompt();

        string input_line;
        getline(cin, input_line);

        if (parse_meta_command(input_line)) {
            continue;
        }
    }
}

int main(int argc, char **argv) {
    DB db;
    db.start();
    return 0;
}