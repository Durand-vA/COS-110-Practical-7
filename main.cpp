#include <iostream>
#include <sstream>

#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"


int main() {
    Tuple<int, bool> tuple1(5, false);

    Dictionary<int, std::string> dict1;

    ScoreBoard<double> scoreBoard1;

    std::string s = "naam";
    double n = 10;

    for (int i = 0; i < 10; i++) {
        std::stringstream ss;
        ss << s;
        ss << i;
        n += i*5;
        std::cout << ss.str() << ": " << n << std::endl;
        scoreBoard1.addScore(ss.str(), n);
    }

    scoreBoard1.removeScore("naam2");

    std::string string = "naam3";

    double score = scoreBoard1.getScore(string);
    if (score != 40) {
        std::cout << "getScore error\nScore was: " << scoreBoard1.getScore("naam3") << std::endl;
    }

    score = scoreBoard1.getHighScore();
    if (score != 235)
        std::cout << "getHighScore error\nScore was: " << scoreBoard1.getScore("naam3") << std::endl;



    scoreBoard1.addScore("Toets12", 235);

    Tuple<int, std::string*> tuple2 = scoreBoard1.getHighScoreUser();

    std::cout << tuple2.getFirst() << std::endl;
    for (int i = 0; i < tuple2.getFirst(); i++) {
        std::cout << tuple2.getSecond()[i] << std::endl;
    }

    return 0;
}
