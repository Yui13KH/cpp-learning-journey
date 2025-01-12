#include <iostream>
#include <ctime>
#include <thread>
#include <cstring>

int main() {
    while (true) {
        // Get the current time as time_t
        std::time_t now = std::time(nullptr);

        // Convert time_t to a formatted string
        char* formatted_time = std::ctime(&now);

        // Remove the newline character at the end of formatted_time
        formatted_time[std::strlen(formatted_time) - 1] = '\0';

        // Print the formatted time using \r to overwrite the line
        std::cout << "\rFormatted time: " << formatted_time;
        std::cout.flush();  // Make sure the output is printed immediately

        // Sleep for 1 second to prevent constant CPU usage
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
