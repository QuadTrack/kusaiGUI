#include "gui.h"
#include "ai.hpp"

int main(int argc, char *argv[]){
//    std::cout << argc << '|' << argv[1] << std::endl;
    if(argc == 2 && argv[1][0] == 't') {
        ai::Train();
        return 0;
    }
    QApplication app(argc, argv);
    QMainWindow main;
    Ui_MainWindow root;
    root.setupUi(&main);
    main.show();
    return app.exec();
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
        ai::RunAi(task, answer);
        QMessageBox::information(nullptr, "Answer", QString::fromStdString(answer));
        std::cout << "DebugAnswer: " << answer << std::endl;
    }
}