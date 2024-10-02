#include <iostream>

int main(){
    std::cout << "Hello World!" << std::endl;
    int age = 15;
    std::string name = "John";
    std::cout << "Name: " << name << " Age: " << age << std::endl;

    if (age > 18){ // this is an if statement that will check if age is greater than 18
        std::cout << "You are an adult" << std::endl;
    } else if (age == 15){
        if (name == "John"){
            std::cout << "You are a minor and your name is John" << std::endl;
    }
    } else {
        std::cout << "You are a minor" << std::endl;
    }

    int grade;
    std::cout << "Your grade is: ";
    std::cin >> grade;

    switch (grade){ // this is a switch statement that will check the value of grade
        case 1 :
            std::cout << "You got a A" << std::endl;
            break;
        case 2 :
            std::cout << "You got a B" << std::endl;
            break;
        case 3 :
            std::cout << "You got a C" << std::endl;
            break;
        case 4:
            std::cout << "You got a D" << std::endl;
            break;
        default:
            std::cout << "unknwn grade" << std::endl;
    }

    for(int i = 0; i < 5; i++){ // this is a for loop that will run 5 times
        std::cout << "Iteration: " << i << std::endl;
    }
    int i = 5;
    while(i< 18){ // this is a while loop that will run as long as age is less than 18
        std::cout << "You are a minor" << std::endl;
        i++;
    }


    return 0;

}