#include <iostream>
#include <string>
#include <vector>

int main() {
    int limitX, limitY, positionX, positionY; char direction;
    std::cin >> limitX >> limitY;
    std::vector<std::vector<bool> > lostRobots(limitY + 1, std::vector<bool> (limitX + 1, false));
    while (std::cin >> positionX >> positionY >> direction) {
        std::string instructions;
        std::cin >> instructions;
        bool isLost = false;
        for (char instruction : instructions) {
            if (instruction == 'F') {
                switch (direction) {
                    case 'N':
                        ++positionY;
                        break;
                    case 'E':
                        ++positionX;
                        break;
                    case 'S':
                        --positionY;
                        break;
                    case 'W':
                        --positionX;
                        break;
                }
            } else if (instruction == 'R'){
                switch (direction) {
                    case 'N':
                        direction = 'E';
                        break;
                    case 'E':
                        direction = 'S';
                        break;
                    case 'S':
                        direction = 'W';
                        break;
                    case 'W':
                        direction = 'N';
                        break;
                }
            } else if (instruction == 'L') {
                switch (direction) {
                    case 'N':
                        direction = 'W';
                        break;
                    case 'E':
                        direction = 'N';
                        break;
                    case 'S':
                        direction = 'E';
                        break;
                    case 'W':
                        direction = 'S';
                        break;
                }
            }
            if (positionX > limitX or positionY > limitY or positionX < 0 or positionY < 0) {
                switch (direction) {
                    case 'N':
                        --positionY;
                        break;
                    case 'E':
                        --positionX;
                        break;
                    case 'S':
                        ++positionY;
                        break;
                    case 'W':
                        ++positionX;
                        break;
                }
                if (lostRobots[positionX][positionY]) continue;
                isLost = true;
                lostRobots[positionX][positionY] = true;
                break;
            }
        }
        std::cout << positionX << ' ' << positionY << ' ' << direction << (isLost ? " LOST" : "") << '\n';
    }
    return 0;
}