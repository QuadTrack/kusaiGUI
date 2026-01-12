#include "ai.hpp"

bool ai::ImportGraph() {
    std::ifstream importedGraph("graph.json");
    if(std::filesystem::exists("graph.json")){
        std::cout << "Existing graph will be imported." << std::endl;
    } else {
        std::cout << "Existing graph not found. Skipping" << std::endl;
        return 0;
    }
    if(!importedGraph.is_open()){
        std::cout << "Error opening \'graph.json\' file!" << std::endl;
        return 0;
    }
    markovData = new NGramMarkov;
    chain = new TextChain(*markovData);
    markovData->deserializeFromIstream(importedGraph);
    importedGraph.close();
    return 1;
}

bool ai::ExportGraph() {
    if(std::filesystem::exists("graph.json")){
        std::cout << "File \'graph.json\' will be overwritten!" << std::endl;
    } else {
        std::cout << "File \'graph.json\' will be created!" << std::endl;
    }
    std::ofstream exportGraph("graph.json");
    if(!exportGraph.is_open()){
        std::cout << "Error opening/creation \'graph.json\' file!" << std::endl;
        return 0;
    }
    markovData->serializeToOstream(exportGraph);
    exportGraph.close();
    return 1;
}

bool ai::Train(std::string fileName, int contextSize) {
    ImportGraph();
    markovData = new NGramMarkov(contextSize);
    chain = new TextChain(*markovData);
    std::ifstream readFile("../" + fileName);
    if (!readFile.is_open()) {
        std::cout << "Error opening \'train.txt\' file!" << std::endl;
        return 0;
    }
    std::vector<std::string> data;
    std::string temp;
//    std::cout << "Debug: reading" << std::endl;
    while (std::getline(readFile, temp)){
        data.push_back(temp);
//        std::cout << temp << std::endl;
    }
//    std::cout << "Debug: finished reading" << std::endl;
    readFile.close();
//    std::cout << "Begin train" << std::endl;
    chain->train(data);
//    std::cout << "End train" << std::endl;
    ExportGraph();
    delete markovData;
    delete chain;
    return 1;
}

bool ai::RunAi(std::string ask, std::string &answer, uint32_t limit) {
    ImportGraph();
    answer = chain->generateTokens(ask, limit);
    if(answer.empty()){
        std::cout << "Error answering!" << std::endl;
        return 0;
    }
    return 1;
}

//int main(){
//    std::string input1;
//    std::string input2;
//    while(true){
//        std::cout << "Your command (train/exec/exit): ";
//        std::cin >> input1;
//        if(input1 == "train"){
////            std::cout << "Debug: train" << std::endl;
//            std::cout << ai::Train() << std::endl;
//        } else if(input1 == "exec"){
////            std::cout << "Debug: exec" << std::endl;
//            std::cout << "Enter preprompt: ";
//            std::cin >> input2;
//            std::string out;
//            ai::RunAi(input2, out);
//            std::cout << "Answer: " << out << std::endl;
//        } else if(input1 == "exit"){
////            std::cout << "Debug: exit" << std::endl;
//            break;
//        } else {
//            std::cout << "Command undefined" << std::endl;
//        }
//    }
//    return 0;
//}
