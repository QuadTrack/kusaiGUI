#pragma once
#include "fstream"
#include "iostream"
#include "vector"
#include "map"
#include "filesystem"
#include <google/protobuf/util/json_util.h>
#include "TextChain.hpp"
#include "NGramMarkov.hpp"
//#include "Graph.hpp"
//#include "markov.pb.h"

namespace ai {
    static int contextSize;
    static NGramMarkov* markovData;
    static TextChain* chain;
    bool Train(std::string fileName, int contextSize);
    bool ExportGraph();
    bool ImportGraph();
    bool RunAi(std::string ask, std::string& answer, uint32_t limit = 200);
};