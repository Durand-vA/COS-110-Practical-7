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
    Tuple<int, bool> tuple3(5, false);

    tuple1.getFirst();
    tuple1.getSecond();

    if (tuple1 == tuple3) {
        std::cout << "equal\n";
    }

    Dictionary<std::string, int> dict1;

    dict1.set("one", 1);
    dict1.set("two", 2);
    dict1.set("two", 2);
    dict1.set("two", 2);
    dict1.set("two", 2);
    dict1.set("two", 2);
    dict1.set("three", 24);
    dict1.set("four", 24);
    dict1.set("five", 24);
    dict1.set("six", 24);
    dict1.set("seven", 30);
    dict1.set("eight", 30);
    dict1.set("nine", 30);
    dict1.set("ten", 30);
    std::cout << dict1.at("three") << std::endl;
    dict1.removeAt("one");
    dict1.remove(24);

    Tuple<int, std::string*> dictOut = dict1.keysWithValue(30);

    std::cout << dictOut.getFirst() << std::endl;
    for (int i = 0; i < dictOut.getFirst(); i++) {
        std::cout << dictOut.getSecond()[i] << std::endl;
    }

    delete [] dictOut.getSecond();

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

    delete [] tuple2.getSecond();

    return 0;
}
