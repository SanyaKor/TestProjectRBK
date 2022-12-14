#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#define FILE_NAME "tests.txt"
#define TOP_WORDS 10
#define SEED 1242


void MostFrequentWords(){

    std::map< std::string, int > Tree;
    std::vector< std::pair < std::string, int > > TopNWords(TOP_WORDS);

    std::ifstream InputStream;

    InputStream.open(FILE_NAME, std::ios::in);


    if(InputStream.fail()) {
        std::cout << "Error opening file";
        return ;
    }

    if(InputStream.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "File is empty";
        return ;
    }


    for( std::string line; getline( InputStream, line ); )
    {
        if(Tree.find(line) != Tree.end()){
            Tree[line] += 1;
        }
        else{
            Tree[line] = 1;
        }
    }


    std::partial_sort_copy(Tree.begin(),
                           Tree.end(),
                           TopNWords.begin(),
                           TopNWords.end(),
                           [](std::pair<const std::string, int> const& Node1,
                           std::pair<const std::string, int> const& Node2)
                           {
                               return Node1.second > Node2.second;
                           }
                           );

    std::cout << "TOP " << TOP_WORDS << " " << "WORDS" << std::endl;

    for(int i=0; i < TOP_WORDS; i++){
        std::cout << " " << i << ") \" "<< TopNWords[i].first << " \": " << TopNWords[i].second << std::endl;
    }

    std::cout << "----------------" << std::endl;
}

std::string randomWord( size_t length ){

    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

void WordsGen(const int AmountOfWords = 100000){

    size_t length;
    std::ofstream outfile;
    srand(time(NULL));
    //srand(SEED);

    outfile.open(FILE_NAME);
    outfile.clear();

    std::cout << "TestProject_RBK:" << std::endl;
    std::cout << "----------------" << std::endl;


    for(int i = 0; i < AmountOfWords; i++){
        length = 3 + rand () % 10;
        outfile << randomWord(length) << "\n";
    }
    std::cout << "generated " << AmountOfWords << " pseudo random words" << std::endl;
    std::cout << "----------------" << std::endl;

}


int main(int argc, char** argv)
{
    WordsGen();
    MostFrequentWords();
    return 0;
}
