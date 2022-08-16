#include <iostream>
#include "SessionLog.h"
#include <fstream>

SessionLog create_log(std::string title, std::string notes);
void display_log(SessionLog log);

int main(){
    std::string title_holder{};
    std::string notes_holder{};
    
    std::cout << "Enter title: ";
    std::getline(std::cin, title_holder);
    std::cout << "Enter notes: ";
    std::getline(std::cin, notes_holder);
    
    SessionLog sample_log = create_log(title_holder, notes_holder);
    display_log(sample_log);
    
    //Write the contents to a text file
    std::ofstream output_file {"../Session_Log.txt", std::ios::app};
    if(!output_file){
        std::cerr << "Error opening or creating Session_Log.txt file" << std::endl;
    }
    output_file << title_holder << "\n" << notes_holder << "\n";
    
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



