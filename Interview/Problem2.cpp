#include <iostream>
#include <random>
#include <vector>

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

int compareDnaPosition(const void *a, const void *b)
{
    unsigned int x1 = ((DNA_DATA*)(a))->dna_position;
    unsigned int x2 = ((DNA_DATA*)(b))->dna_position;

    if(x1<x2)
        return -1;
    else if(x1>x2)
        return 1;
    return 0;
}

int compareCode1(const void *a, const void *b)
{
    unsigned int x1 = ((DNA_DATA*)(a))->code1;
    unsigned int x2 = ((DNA_DATA*)(b))->code1;

    if(x1<x2)
        return -1;
    else if(x1>x2)
        return 1;
    return 0;
}

int compareCode2(const void *a, const void *b)
{
    unsigned int x1 = ((DNA_DATA*)(a))->code2;
    unsigned int x2 = ((DNA_DATA*)(b))->code2;

    if(x1<x2)
        return -1;
    else if(x1>x2)
        return 1;
    return 0;
}

void myQuickSort(std::vector<DNA_DATA>& v)
{
    qsort(&v[0], v.size(), sizeof(v[0]), compareDnaPosition);

}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> disUint(0, 1000);
    std::uniform_int_distribution<char> disChar(0, 100);
    std::uniform_real_distribution<> disDouble(0,1);
    std::uniform_int_distribution<short> disShort(0, 1000);

    DNA_DATA stTemp;

    std::vector<DNA_DATA> v;

    for(int i = 0 ; i < 5 ; ++i)
    {
        stTemp.dna_position = disUint(gen);
        stTemp.code1        = disChar(gen);
        stTemp.code2        = disChar(gen);
        stTemp.probability1 = disDouble(gen);
        stTemp.probability2 = disDouble(gen);
        stTemp.displacement1 = disShort(gen);
        stTemp.displacement2 = disShort(gen);

        v.push_back(stTemp);
    }

    std::cout << "------------------- Out ---------------------" << std::endl;

    for(int i = 0 ; i < 5 ; ++i)
    {
        stTemp.dna_position = v[i].dna_position;
        stTemp.code1        = v[i].code1;
        stTemp.code2        =  v[i].code2;
        stTemp.probability1 =  v[i].probability1;
        stTemp.probability2 =  v[i].probability2;
        stTemp.displacement1 =  v[i].displacement1;
        stTemp.displacement2 =  v[i].displacement2;

        std::cout << "dna_position : " << stTemp.dna_position <<std::endl;
        std::cout << "code1 : " << int(stTemp.code1) <<std::endl;
        std::cout << "code2 : " << int(stTemp.code2) <<std::endl;

    }


    qsort(&v[0], v.size(), sizeof(v[0]), compareDnaPosition);

    std::cout << "------------------- Ordered Dna_Position Out ---------------------" << std::endl;

    for(int i = 0 ; i < 5 ; ++i)
    {
        stTemp.dna_position = v[i].dna_position;
        stTemp.code1        = v[i].code1;
        stTemp.code2        =  v[i].code2;
        stTemp.probability1 =  v[i].probability1;
        stTemp.probability2 =  v[i].probability2;
        stTemp.displacement1 =  v[i].displacement1;
        stTemp.displacement2 =  v[i].displacement2;

        //v.pop_back();

        std::cout << "dna_position : " << stTemp.dna_position <<std::endl;
        std::cout << "code1 : " << int(stTemp.code1) <<std::endl;
        std::cout << "code2 : " << int(stTemp.code2) <<std::endl;

    }

    

    std::cout << "------------------- Ordered Code1 Out ---------------------" << std::endl;

    qsort(&v[0], v.size(), sizeof(v[0]), compareCode1);

    for(int i = 0 ; i < 5 ; ++i)
    {
        stTemp.dna_position = v[i].dna_position;
        stTemp.code1        = v[i].code1;
        stTemp.code2        =  v[i].code2;
        stTemp.probability1 =  v[i].probability1;
        stTemp.probability2 =  v[i].probability2;
        stTemp.displacement1 =  v[i].displacement1;
        stTemp.displacement2 =  v[i].displacement2;

        //v.pop_back();

        std::cout << "dna_position : " << stTemp.dna_position <<std::endl;
        std::cout << "code1 : " << int(stTemp.code1) <<std::endl;
        std::cout << "code2 : " << int(stTemp.code2) <<std::endl;

    }

        std::cout << "------------------- Ordered Code2 Out ---------------------" << std::endl;

    qsort(&v[0], v.size(), sizeof(v[0]), compareCode2);

    for(int i = 0 ; i < 5 ; ++i)
    {
        stTemp.dna_position = v[i].dna_position;
        stTemp.code1        = v[i].code1;
        stTemp.code2        =  v[i].code2;
        stTemp.probability1 =  v[i].probability1;
        stTemp.probability2 =  v[i].probability2;
        stTemp.displacement1 =  v[i].displacement1;
        stTemp.displacement2 =  v[i].displacement2;

        //v.pop_back();

        std::cout << "dna_position : " << stTemp.dna_position <<std::endl;
        std::cout << "code1 : " << int(stTemp.code1) <<std::endl;
        std::cout << "code2 : " << int(stTemp.code2) <<std::endl;

    }

    
}