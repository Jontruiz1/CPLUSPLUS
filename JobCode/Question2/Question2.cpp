/*
*
* Jonathan Ruiz
*
*/

#include <iostream>
#include <chrono>
#include <vector>
const char* PlayerNames[] = {
               "Scorpion",
               "Kano",
               "Sonya Blade",
               "ShangTsung",
               "Reptile",
               "Baraka",
               "KungLao",
               "ShaoKahn",
               "SubZero",
               "LiuKang",
               "Mileena",
               "Noob Saibot",
               "Smoke",
               "Cyrax",
               "Rain",
               "Frost",
               "Jade",
               "Sheeva",
               "Raiden",
               "Kano",
               "JaxBriggs",
               "CassieCage",
               "JohnnyCage",
               "Goro",
               "Kitana"
};

bool IsValidPlayer(const char* player);

int main() {
    const char* p = "Sonya Blade";


    std::cout << IsValidPlayer(p);

    /*const int TESTS = 10000000;
    std::vector<std::chrono::milliseconds> lookup_timings;

    double lookup_avgs = 0;
    auto total_start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; i++) {
        auto lookup_start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < TESTS; i++) {
            IsValidPlayer("KungLao");
            IsValidPlayer("testing");
            IsValidPlayer("SubZero");
            IsValidPlayer("LiuKang");
            IsValidPlayer("not a real player");
            IsValidPlayer("Jade");
            IsValidPlayer("Sheeva");
            IsValidPlayer("Raiden");
            IsValidPlayer("%=4");
            IsValidPlayer("Kano");
            IsValidPlayer("_____");
            IsValidPlayer("JaxBriggs");
            IsValidPlayer("CassieCage");
            IsValidPlayer("JohnnyCage");
            IsValidPlayer("JohnnyCage");
        }
        auto lookup_stop = std::chrono::high_resolution_clock::now();
        auto lookup_duration = std::chrono::duration_cast<std::chrono::milliseconds>(lookup_stop - lookup_start);
        lookup_timings.push_back(lookup_duration);

    }
    auto total_stop = std::chrono::high_resolution_clock::now();
    auto total_duration = std::chrono::duration_cast<std::chrono::milliseconds>(total_stop - total_start);

    for (auto k : lookup_timings) {
        lookup_avgs += k.count();
    }

    std::cout << "Total time taken in milliseconds: " << total_duration.count() << std::endl;
    std::cout << "Milliseconds taken per 14*10,000,000 lookups: " << lookup_avgs / lookup_timings.size() << std::endl;*/

}


bool IsValidPlayer(const char* player)
{
    for (const char* p : PlayerNames) {
        if (p == player) return true;
    }
    return false;
}

