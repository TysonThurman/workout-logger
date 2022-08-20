#include <iostream>
#include "SessionLog.h"
#include <fstream>
#include <iomanip>

SessionLog create_log(std::string title, std::string notes);
void display_log(SessionLog log);
void print_menu();
bool add_session_log();
int option{0};

int main(){    
    
    add_session_log();
//        
//    while(option != 1 && option !=2 && option !=3 && option !=4){
//        print_menu();
//    }
//    

    
    return 0;
}

SessionLog create_log(std::string title, std::string notes){
    SessionLog log {title, notes};
    return log;
}

void display_log(SessionLog log){
    std::cout << std::endl;
    std::cout << "Log Entry for [" << log.get_title() << "] workout session" << std::endl;
    std::cout << "============================" << std::endl;
    log.display_timestamp();
    std::cout << "Log Notes: " << log.get_notes() << std::endl << std::endl;
    std::cout << std::endl;
}

void print_menu(){
    //this clear option will not work in windows
    system("clear");
    std::cout << "----------Workout Logger----------" << std::endl << std::endl;
    std::cout <<  "1.) Add Session Log\n2.) View Session Logs\n3.) Delete Session Log\n4.) Exit Program" << std::endl << std::endl;
    std::cout << "Please select an option: " << std::endl;
    std::cin >> option;
}

bool add_session_log() {
    std::string title_holder{};
    std::string notes_holder{};
    
    std::cout << "Enter title: ";
    std::getline(std::cin, title_holder);
    std::cout << "Enter notes: ";
    std::getline(std::cin, notes_holder);
    
    SessionLog new_log = create_log(title_holder, notes_holder);
    display_log(new_log);
    char* converted_timestamp = ctime(&new_log.timestamp);
    
    std::ofstream output_file {"../Session_Log.txt", std::ios::app};
    if(!output_file){
        std::cerr << "Error opening or creating Session_Log.txt file" << std::endl;
    }
    output_file << "Log Date: " << converted_timestamp<< "Title: " << title_holder << "\n" << "Notes: " <<notes_holder << "\n" << "**********************\n";
    return true;
}



