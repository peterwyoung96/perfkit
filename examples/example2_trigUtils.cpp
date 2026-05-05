// // HEADERS //////////////////////////////////////////////////////////////////

#include <vector>
#include <cstdint>
#include <chrono>
#include <cmath>
#include <iostream>

#include <perfkit/math/trig_utils.h>

// // HELPER & TEST FUNCTIONS //////////////////////////////////////////////////

// // MAIN LOOP ////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    // TEST #1
    // Convert an angle in degrees to radians and then back to degrees.
    float angle_deg = 90.0f;
    std::cout << "original angle (deg):    " << angle_deg << std::endl;

    float angle_rad = perfkit::math::deg_to_rad<float>(angle_deg);
    angle_deg = perfkit::math::rad_to_deg<float>(angle_rad);

    std::cout << "converted angle (rad):   " << angle_rad << std::endl;
    std::cout << "reconverted angle (deg): " << angle_deg << std::endl;
    std::cout << "\n";

    // TEST #2
    // Convert an angle from [0,2*pi) to [-pi,pi]
    angle_deg = 270.0f;
    angle_rad = perfkit::math::deg_to_rad<float>(angle_deg);
    std::cout << "original angle: " << angle_deg << std::endl;
    std::cout << ">> (" << angle_rad << " radians)\n";

    angle_rad = perfkit::math::normalize_pi<float>(angle_rad);
    angle_deg = perfkit::math::rad_to_deg<float>(angle_rad);
    std::cout << "new angle: " << angle_deg << std::endl;
    std::cout << ">> (" << angle_rad << " radians)\n";

    return 0;
}

// // EOF //////////////////////////////////////////////////////////////////////