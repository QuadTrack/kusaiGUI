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
    static std::map<char, int> acts {
        {'t', 0}, //train
        {'e', 1}, //export
        {'i', 2}, //import
        {'r', 3}, //runai
    };
    static NGramMarkov markovData(2);
    static auto chain = TextChain(markovData);
    bool Train();
    bool ExportGraph();
    bool ImportGraph();
    bool RunAi(std::string ask, std::string& answer, uint32_t limit = 200);
};