// Asit Patel - 190309
// Quiz 2

#include<simplecpp>

int main() {
    int score = 0;

    // Question 1
    std::cout << "Question 1: What is the capital of France?" << std::endl;
    std::cout << "A. Berlin" << std::endl;
    std::cout << "B. Paris" << std::endl;
    std::cout << "C. Rome" << std::endl;
    std::cout << "D. Madrid" << std::endl;

    char answer1;
    std::cout << "Enter your answer (A, B, C, or D): ";
    std::cin >> answer1;

    // Add the score if the Answers is correct for the 1st question.
    if (answer1 == 'B' || 'b') {
        std::cout << "Correct!" << std::endl;
        score++;
    } else {
        std::cout << "Incorrect!" << std::endl;
    }

    // Question 2
    std::cout << "Question 2: How many continents are there?" << std::endl;
    std::cout << "A. 5" << std::endl;
    std::cout << "B. 6" << std::endl;
    std::cout << "C. 7" << std::endl;
    std::cout << "D. 8" << std::endl;

    char answer2;
    std::cout << "Enter your answer (A, B, C, or D): ";
    std::cin >> answer2;

    // Add the score if the ansers is correct for the 2nd question.
    if (answer2 == 'C' || 'c') {
        std::cout << "Correct!" << std::endl;
        score++;
    } else {
        std::cout << "Incorrect!" << std::endl;
    }

    // Display final score
    std::cout << "Final score: " << score << " out of 2" << std::endl;

    return 0;
}
