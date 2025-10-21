#include "question1.hpp"

void addSnake(UniverseCoordinate** UniverseData, int rows, int cols) {
    int xx, yy;
    cout << "Enter x not greater than " << cols << " and y ngreater than " << rows << endl;
    cin >> yy >> xx;
    if(xx <= cols && yy <= rows) {
        UniverseData[yy-1][xx-1].is_snake = true;
    }
}

int s_number = 0;
void print(UniverseCoordinate** UniverseData, int rows, int cols) {
    cout << "\nThe 2D Universe" << endl;
    for(int j = 0; j < rows; j++) {
        cout << "-------------------";
    } 
    cout << endl;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(UniverseData[i][j].incrementSNo() != 0) {
                    s_number++;
                }
            }
        }
        UniverseCoordinate::s_number = 0;
        for(int i = cols - 1; i >= 0; i--) {
            cout << "| ";
            for(int j = 0; j < rows; j++) {
                // s_number = UniverseData[i][j].incrementSNo();
                UniverseData[j][i].x_position = j+1;
                UniverseData[j][i].y_position = i+1;
                cout << "x:" << UniverseData[j][i].x_position << " y:" << UniverseData[j][i].y_position << " " << ((UniverseData[j][i].is_snake == 1) ? "Snake" :     "     " )<< " ";
                
                if(UniverseData[j][i].incrementSNo() == 0) {
                    cout << "  "; 
                } else {
                    cout << "#" + to_string(s_number);
                    s_number--;
                } 
                
                cout << " | ";

            }
            cout << endl;
            for(int j = 0; j < rows; j++) {
                cout << "-------------------";
            }        
            cout << endl;
        }
}

int main() {
    int rows = 2, cols = 2, x, y;

    UniverseCoordinate** UniverseData = new UniverseCoordinate*[rows];
    for(int i = 0; i < rows; i++) {
        UniverseData[i] = new UniverseCoordinate[cols]; 
    }
    print(UniverseData, rows, cols);
    char ch2;
    do {
        cout << "Do you wanna expand the universe? (y/n): ";
        char choice;    
        cin >> choice;
        if(choice == 'y' || choice == 'Y') {

            cout << "Enter the x and then y coordinate to which you wanna expand: " << endl;
            cin >> y >> x;
            if(x > cols && y > rows) {
                UniverseCoordinate** UniverseCopiedData = new UniverseCoordinate*[rows];
                for(int i = 0; i < rows; i++) {
                    UniverseCopiedData[i] = new UniverseCoordinate[cols]; 
                }
                for(int i = 0; i < rows; i++) {
                    for(int j = 0; j < cols; j++) {
                        UniverseCopiedData[i][j] = UniverseData[i][j];
                    }
                }

                for(int i = 0; i < rows; i++) {
                    delete[] UniverseData[i];
                }
                delete[] UniverseData;

                int tempR = rows;
                int tempC = cols;



                // y >= 3
                if(y > rows) {
                    UniverseData = new UniverseCoordinate*[y - rows];  
                    for(int i = 0; i < y-rows; i++) {
                        UniverseData[i] = new UniverseCoordinate[cols]; 
                    }
                }
                rows = y;
                // x >= 3

                for(int i = 0; i < rows; i++) {
                    UniverseData[i] = new UniverseCoordinate[x];
                }
                cols = x; 

                for(int i = 0; i < tempR; i++) {
                    for(int j = 0; j < tempC; j++) {
                        UniverseData[i][j] = UniverseCopiedData[i][j];
                    }
                }

                for(int i = 0; i < tempR; i++) {
                    delete[] UniverseCopiedData[i];
                }
                delete[] UniverseCopiedData;

            cout << "Please specify if the specified coordinate have a snake or not: (y/n): ";
            char ch;
            cin >> ch;
            if(ch == 'y')  (UniverseData[y-1][x-1].is_snake = true);
            }
        } else if (choice == 'n' || choice == 'N') {
            cout << "Wanna add a snake? (y/n)";
            char ch1;
            cin >> ch1;
            if(ch1 == 'y') {
                addSnake(UniverseData, rows, cols);                


            }
        }

        print(UniverseData, rows, cols);
        
        cout << "Wanna do more operation? " << endl;
        cin >> ch2;
        if(ch2 == 'y') {
            UniverseCoordinate::s_number = 0;
            s_number = 0;
        }
    }  while(ch2 == 'y'); 

    for(int i = 0; i < rows; i++) {
        delete[] UniverseData[i];
    }
    UniverseData = nullptr;
    delete[] UniverseData;
    return 0;
}