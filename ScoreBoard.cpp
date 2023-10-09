#ifndef SCOREBOARD_CPP
#define SCOREBOARD_CPP

#include "ScoreBoard.h"


template<class T>
ScoreBoard<T>::ScoreBoard() {

}

template<class T>
ScoreBoard<T>::~ScoreBoard() {

}

template<class T>
void ScoreBoard<T>::addScore(std::string user, T score) {
    T currScore = scores.at(user);

    if (currScore == T())
        scores.set(user, score);
    else {
        scores.set(user, score > currScore ? score : currScore);
    }
}

template<class T>
void ScoreBoard<T>::removeScore(std::string user) {
    scores.removeAt(user);
}

template<class T>
T ScoreBoard<T>::getScore(std::string user) {
    return scores.at(user);
}

template<class T>
T ScoreBoard<T>::getHighScore() {
    if (scores.size() == 0) {
        return T();
    }
    T max = scores.at(scores.getKeys()[0]);
    for (int i = 0; i < scores.size(); i++) {
        T score = scores.at(scores.getKeys()[i]);
        if (score > max)
            max = score;
    }

    return max;
}

template<class T>
Tuple<int, std::string*> ScoreBoard<T>::getHighScoreUser() {
    T max = getHighScore();
    return scores.keysWithValue(max);
}
#endif //SCOREBOARD_CPP