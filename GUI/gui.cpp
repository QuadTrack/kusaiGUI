#include "gui.h"
#include "ai.hpp"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "russian");
    CLI::App app{"CLI tool to train TextChain Markov models"};
    int contextSize = 1;
    bool run = 0;
    std::string fileName = "";
    app.add_option("-t, --train", contextSize, "Context size for model");
    app.add_option("-f, --trainfile", fileName, "String data file for training model" );
    app.add_flag("-r, --run", run, "Run the model");
    CLI11_PARSE(app, argc, argv);
//    std::cout << argc << '|' << argv[1] << std::endl;
std::cout << "Debug: run:" << run << std::endl;
    if(!run) {
        ai::Train(fileName, contextSize);
        return 0;
    } else {
        QApplication app(argc, argv);
        QMainWindow main;
        Ui_MainWindow root;
        root.setupUi(&main);
        main.show();
        return app.exec();
    }
}

void Ui_MainWindow::ButtonClicked() {
    std::string task;
    bool prompt;
    if(radioButton->isChecked()){
        std::cout << "Debug: Btn 1(prompt) checked" << std::endl;
        prompt = true;
    }

    if(radioButton_2->isChecked()){
        std::cout << "Debug: Btn 2(ask) checked" << std::endl;
        prompt = false;
    }

    if(prompt){
        std::ifstream promptFile("../" + QString(textEdit->toPlainText()).toStdString());
        if(!promptFile.is_open()){ std::cout << "Error reading file" << std::endl; }
        getline(promptFile, task);
        std::cout << "DebugText: " << task << std::endl;
        promptFile.close();
    } else {
        task = QString(textEdit->toPlainText()).toStdString();
        std::cout << "DebugText: " << task << std::endl;
    }

    if(!task.empty()) {
        std::string answer;
        ai::RunAi(task, answer, 20);
        QMessageBox::information(nullptr, "Answer", QString::fromStdString(answer));
        std::cout << "DebugAnswer: " << answer << std::endl;
    } else {
        std::cout << "Debug: no answer" << std::endl;
    }
}