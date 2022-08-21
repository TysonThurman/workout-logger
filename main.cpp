#include <iostream>
#include "SessionLog.h"
#include <fstream>
#include <iomanip>
#include <boost/predef.h>

SessionLog create_log(std::string title, std::string notes);
void display_log(SessionLog log);
void print_menu();
bool add_session_log();
void read_session_logs();
void init();
char option;

int main(){    
    init();
    return 0;
}

void init(){
    do {
        print_menu();
        std::cin >> option;
    } while (option != '1' && option !='2' && option !='3' && option !='4'); 
    
    switch(option) {
       case '1'  :
          add_session_log();
          init();
          break;
       case '2'  :
          read_session_logs();
          init();
          break;
       case '3'  :
          break;
       case '4'  :
          break;
    }
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
    if(BOOST_OS_WINDOWS)
        system("cls");
    else if(BOOST_OS_LINUX)
        system("clear");
    else
        system("clear");
    std::cout << "----------Workout Logger----------" << std::endl << std::endl;
    std::cout <<  "1.) Add Session Log\n2.) Read Session Logs\n3.) Delete Session Log\n4.) Exit Program" << std::endl << std::endl;
    std::cout << "Please select an option: " << std::endl;
}

bool add_session_log() {
    std::string title_holder{};
    std::cout << "Enter title: ";
    std::getline(std::cin, title_holder);
    std::cin.get();
    std::string notes_holder{};
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
    output_file.close();
    return true;
}

void read_session_logs() {
    std::cout << "Reading Session Logs:" << std::endl;
    std::cout << "**********************\n\n";
    std::string line;
    std::ifstream input_file;
    input_file.open("../Session_Log.txt");
    if(!input_file){
        std::cerr << "Error reading from Session_Log.txt file" << std::endl;
    }
    if (input_file.is_open()) {
        while (std::getline(input_file, line)) {
            std::cout << line << std::endl;
        }
        std::cout << "\n**********************\n";
        input_file.close();
        //add way to pause the window so we can see the output
    }
}