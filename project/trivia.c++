#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class Question {
public:
    Question(const string& q, const string& a) : question(q), answer(a) {}
    string question;
    string answer;
};

class FileReader {
public:
    static vector<Question> readQuestionsFromFile(const string& filename) {
        vector<Question> questions;
        ifstream file(filename);
        string line, question, answer;

        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                question = line.substr(0, pos);
                answer = line.substr(pos + 1);
                questions.emplace_back(question, answer);
            }
        }

        return questions;
    }

    static vector<Question> readQuestionsFromMultipleFiles(const vector<string>& filenames) {
        vector<Question> allQuestions;
        for (const auto& filename : filenames) {
            auto questions = readQuestionsFromFile(filename);
            allQuestions.insert(allQuestions.end(), questions.begin(), questions.end());
        }
        return allQuestions;
    }
};

class FileWriter {
public:
    static void writeQuestionToFile(const string& filename, const Question& question) {
        ofstream file(filename, ios::app);
        file << question.question << "," << question.answer << endl;
    }

    static void writeQuestionsToFile(const string& filename, const vector<Question>& questions) {
        ofstream file(filename, ios::app);
        for (const auto& question : questions) {
            file << question.question << "," << question.answer << endl;
        }
    }
};

class Deleter {
public:
    static void deleteQuestionByRowId(const string& filename, int rowId) {
        vector<string> lines;
        ifstream inFile(filename);
        string line;

        while (getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();

        if (rowId >= 0 && rowId < lines.size()) {
            lines.erase(lines.begin() + rowId);

            ofstream outFile(filename);
            for (const auto& l : lines) {
                outFile << l << endl;
            }
        }
    }
};

class GameFunctions {
public:
    static Question pickQuestionAndAnswer(const vector<Question>& questions) {
        if (questions.empty()) {
            return Question("No questions available", "");
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, questions.size() - 1);
        return questions[dis(gen)];
    }

    static int rollDice(int min, int max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    static bool checkAnswer(const string& userInput, const string& realAnswer) {
        return userInput == realAnswer;
    }
};

class GameSetup {
private:
    string playerName;
    int maxLives;
    int maxQuestions;
    vector<vector<Question>> categories;

public:
    GameSetup(const string& name, int lives, int questions) 
        : playerName(name), maxLives(lives), maxQuestions(questions) {
       
        vector<string> filenames = {"category1.csv", "category2.csv", "category3.csv", 
                                              "category4.csv", "category5.csv", "category6.csv"};
        for (const auto& filename : filenames) {
            categories.push_back(FileReader::readQuestionsFromFile(filename));
        }
    }

    void start() {
        int lives = maxLives;
        int correctAnswers = 0;

        while (lives > 0 && correctAnswers < maxQuestions) {
            cout << "Type 'roll' to roll the dice: ";
            string input;
            cin >> input;

            if (input != "roll") {
                cout << "Invalid input. Please type 'roll'." << endl;
                continue;
            }

            int roll = GameFunctions::rollDice(1, 6);
            cout << "You rolled a " << roll << "!" << endl;

            Question q = GameFunctions::pickQuestionAndAnswer(categories[roll - 1]);
            cout << "Question: " << q.question << endl;

            cout << "Your answer: ";
            string answer;
            cin.ignore();
            getline(cin, answer);

            if (GameFunctions::checkAnswer(answer, q.answer)) {
                cout << "Correct!" << endl;
                correctAnswers++;
            } else {
                cout << "Incorrect. The correct answer was: " << q.answer << endl;
                lives--;
            }

            cout << "Lives remaining: " << lives << endl;
            cout << "Correct answers: " << correctAnswers << "/" << maxQuestions << endl;
        }

        if (lives == 0) {
            cout << "Game over! You ran out of lives." << endl;
        } else {
            cout << "Congratulations! You answered all questions correctly." << endl;
        }
    }
};

int main() {
    string playerName;
    int lives, questions;

    cout << "Enter player name: ";
    getline(cin, playerName);

    cout << "Enter number of lives: ";
    cin >> lives;

    cout << "Enter maximum number of questions: ";
    cin >> questions;

    GameSetup game(playerName, lives, questions);
    game.start();

    return 0;
}