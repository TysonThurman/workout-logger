#include <iostream>
#include "SessionLog.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono; 

int main(){
    SessionLog sample_log {"Log 1", "Sunday 8-14-2022 - Back, Biceps, Triceps, Abs", 1, 0, 1, 0};
    std::cout << std::boolalpha;
    sample_log.display_timestamp();
    std::cout << "Title: " << sample_log.get_title() << std::endl;
    std::cout << "Workout Notes: " << sample_log.get_notes() << std::endl;
    std::cout << "Upper Body Completed?: " << sample_log.get_upper_body() << std::endl;
    std::cout << "Lower Body Completed?: " << sample_log.get_lower_body() << std::endl;
    std::cout << "Core Work Completed?: " << sample_log.get_core() << std::endl;
    std::cout << "Cardio Completed?: " << sample_log.get_cardio() << std::endl;
    std::cout << std::noboolalpha;
    
    sleep_until(system_clock::now() + seconds(5));
    
    SessionLog sample_log2 {"Log 2", "Monday 8-15-2022 - Boxing HIIT 20 30 minute workout", 1, 0, 0, 1};
    std::cout << std::boolalpha;
    sample_log2.display_timestamp();
    std::cout << "Title: " << sample_log2.get_title() << std::endl;
    std::cout << "Workout Notes: " << sample_log2.get_notes() << std::endl;
    std::cout << "Upper Body Completed?: " << sample_log2.get_upper_body() << std::endl;
    std::cout << "Lower Body Completed?: " << sample_log2.get_lower_body() << std::endl;
    std::cout << "Core Work Completed?: " << sample_log2.get_core() << std::endl;
    std::cout << "Cardio Completed?: " << sample_log2.get_cardio() << std::endl;
    std::cout << std::noboolalpha;
    
    
    
    return 0;
    
    
}