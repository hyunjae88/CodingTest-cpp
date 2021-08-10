#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

struct DNA_DATA{
    DNA_DATA()
    {
        dna_position    = 0;
        code1           = 0;
        code2           = 0;
        probability1    = 0.;
        probability2    = 0.;
        displacement1   = 0;
        displacement2   = 0;
    }
    unsigned int    dna_position;
    char            code1;
    char            code2;
    double          probability1;
    double          probability2;
    short           displacement1;
    short           displacement2;
};

void SearchData(std::map<unsigned int, DNA_DATA>& mapDataSet)
{
    unsigned int dna_pos;
    char         code1, code2;

    std::map<unsigned int, DNA_DATA>::iterator it;

    std::cin>>dna_pos >> code1 >> code2;

    while( mapDataSet.find(dna_pos) != mapDataSet.end()){
         if(it->second.code1 == code1 && it->second.code2 == code2)
         {
             std::cout << it->second.probability1 << " " << it->second.probability2 << " " << it->second.displacement1 << " " << it->second.displacement2 << std::endl;
         }
        
    }
}

int main()
{
    std::string filePath = "test.data";
    std::ifstream istrm(filePath, std::ios::binary);

    if(istrm.is_open()){
        std::cout << "filed to open " << filePath << '\n';
    }
    else{
        std::map<unsigned int, DNA_DATA> mapDataSet;
        DNA_DATA data;
        size_t   nCntData = 0;
        while(istrm.read(reinterpret_cast<char *>(&data), sizeof(DNA_DATA)))
        {
            nCntData++;
            mapDataSet.insert(std::make_pair(data.dna_position, data));
        }

        SearchData(mapDataSet);
    }
    return 0;
}



