// Copyright (c) 2023 Noah Smith All rights reserved.
//
// Created by: Noah Smith
// Date: Dec. 11th, 2023
// This program asks the user to enter
// the large side, small side and height of a trapezoid,
// as well as the units being used.
// It then calculates and displays the area of the trapezoid.
#include <iostream>

float CalcArea(float smallSide, float largeSide, float height) {
    // Calculate area of trapezoid
    float area = (smallSide + largeSide) / 2 * height;

    // Return area to main
    return area;
}

int main() {
    do {
        // Declare variables
        std::string smallSideStr, largeSideStr, heightStr, unit;
        float smallSideFloat, largeSideFloat, heightFloat;

        // Greeting
        std::cout << "This program calculates the";
        std::cout << " area of a trapezoid by" << std::endl;
        std::cout << "asking you to enter the large";
        std::cout << " side, small side" << std::endl;
        std::cout << "and height of the trapezoid, as well";
        std::cout << " as the units you are using." << std::endl;
        std::cout << "" << std::endl;

        // get small side, large side, height and unit from user
        std::cout << "Enter the length of the small side: ";
        std::cin >> smallSideStr;
        std::cout << "Enter the length of the large side: ";
        std::cin >> largeSideStr;
        std::cout << "Enter the height: ";
        std::cin >> heightStr;
        std::cout << "Enter the unit: ";
        std::cin >> unit;

        // Catch invalid input
        try {
            smallSideFloat = std::stof(smallSideStr);

            // If the small side is less or equal to 0
            if (smallSideFloat <= 0) {
                std::cout << smallSideFloat;
                std::cout << " is not a valid side length." << std::endl;

                // Repeats section of the loop
                continue;
            }
            try {
                largeSideFloat = std::stof(largeSideStr);

                // If the large side is less or equal to 0
                if (largeSideFloat <= 0) {
                    std::cout << largeSideFloat;
                    std::cout << " is not a valid side length." << std::endl;

                    // Repeats section of the loop
                    continue;
                }
                try {
                    heightFloat = std::stof(heightStr);

                    // If the height is less or equal to 0
                    if (heightFloat <= 0) {
                        std::cout << heightFloat;
                        std::cout << " is not a valid";
                        std::cout << " side length." << std::endl;

                        // Repeats section of the loop
                        continue;
                    } else if (largeSideFloat < smallSideFloat) {
                        std::cout << "The small side cannot be";
                        std::cout << " longer than the large side." << std::endl;

                            // Repeats section of the loop
                            continue;
                    } else {
                        // Call function to find the answer
                        float calculatedArea =
                            CalcArea(
                                smallSideFloat,
                                largeSideFloat,
                                heightFloat);

                        // Display area
                        std::cout << "The area of the trapezoid is ";
                        std::cout << calculatedArea;
                        std::cout << " " << unit << "²." << std::endl;

                        // Breaks out of the loop
                        break;
                    }
                } catch (std::exception) {
                    // height is not a float
                    std::cout << heightStr << " is not a float." << std::endl;
                }
            } catch (std::exception) {
                // large side is not a float
                std::cout << largeSideStr << " is not a float." << std::endl;
            }
        } catch (std::exception) {
            // Small side is not a float
            std::cout << smallSideStr << " is not a float." << std::endl;
        }
    } while (true);
}
