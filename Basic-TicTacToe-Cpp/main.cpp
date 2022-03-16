#include <iostream>

using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
int n;
string message = "";

void Draw(){

    system("cls");
    cout<<endl;

    cout<< "Basic Tic-Tac-Toe in C++"<< endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout<< matrix[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<<message<<endl;

}

void Input(){
    int a;
    cout<<"Press field number: ";
    cin>>a;
    message = "";

    if (a == 1){
        if (matrix[0][0] == 'X' || matrix[0][0] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[0][0] = player;
            message = "";
        }
    } else if (a == 2){
        if (matrix[0][1] == 'X' || matrix[0][1] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[0][1] = player;
            message = "";
        }
    } else if (a == 3){
        if (matrix[0][2] == 'X' || matrix[0][2] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[0][2] = player;
            message = "";
        }
    } else if (a == 4){
        if (matrix[1][0] == 'X' || matrix[1][0] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[1][0] = player;
            message = "";
        }
    } else if (a == 5){
        if (matrix[1][1] == 'X' || matrix[1][1] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[1][1] = player;
            message = "";
        }
    } else if (a == 6){
        if (matrix[1][2] == 'X' || matrix[1][2] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[1][2] = player;
            message = "";
        }
    } else if (a == 7){
        if (matrix[2][0] == 'X' || matrix[2][0] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[2][0] = player;
            message = "";
        }
    } else if (a == 8){
        if (matrix[2][1] == 'X' || matrix[2][1] == 'O'){
            message = "Invalid parameter";
            message = "";
        }else{
            matrix[2][1] = player;
        }
    } else if (a == 9){
        if (matrix[2][2] == 'X' || matrix[2][2] == 'O'){
            message = "Invalid parameter";
        }else{
            matrix[2][2] = player;
            message = "";
        }
    } else{
        message = "Invalid parameter";
    }
}

void Player(){
    if (player == 'X'){
        player = 'O';
    } else{
        player = 'X';
    }
}

char Win(){
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
        if (matrix[0][0] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]){
        if (matrix[0][2] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]){
        if (matrix[0][0] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2]){
        if (matrix[1][0] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2]){
        if (matrix[2][0] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]){
        if (matrix[0][0] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[0][1] == matrix[1][1] &&matrix[1][1] == matrix[2][1]){
        if (matrix[0][1] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    } else if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]){
        if (matrix[0][2] == 'X'){
            return 'X';
        } else {
            return 'O';
        }
    }

    bool draw = false;

    for (int i = 0;i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(matrix[i][j] == 'X' || matrix[i][j] == 'O'){
                draw = true;
            }
            else{
                draw = false;
                break;
            }
        }
        if (!draw){
            break;
        }
    }

    if (draw){
        return 'D';
    }

    return '/';
}

int main() {

    //n=0;
    Draw();
    while(1){
        //n++;
        Input();
        Draw();

        if(!message.empty()){
            if (player == 'X'){
                player = 'O';
            } else{
                player = 'X';
            }
        }

        if(Win() == 'X'){
            cout<<"X is the Winner!!!"<<endl;
            break;
        } else if (Win() == 'O'){
            cout<<"O is the Winner!!!"<<endl;
            break;
        } else if (Win() == 'D'){
            cout<<"It's a Draw!!!"<<endl;
            break;
        }
        Player();
    }
    system("pause");



    return 0;
}
