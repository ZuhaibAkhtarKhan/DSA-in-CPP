#include <iostream>
using namespace std;

struct UniverseCoordinate {
    static int s_number;
    int x_position, y_position;
    bool is_snake = false;

    int incrementSNo() {
        if(this->is_snake) {
            s_number++;
            return s_number;
        }
        return 0;
    }
};

int UniverseCoordinate::s_number = 0;
