#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CMyIndex {

    private:

    std::vector<std::string> patients;

    public:
    void addPatient(std::string strPatient);
    void removeAllPatient();
    bool operator==(bool isValid)
    {
        if(patients.empty() != isValid)
            return true;
        return false; 
    }
    std::string& operator[](int nIndex)
    {
        if(nIndex < 0)
        {
            return patients[patients.size()-abs(nIndex)];
        }
        return patients[nIndex];
    }
};

void CMyIndex::addPatient(std::string strPatient)
{
    patients.push_back(strPatient);
}

void CMyIndex::removeAllPatient()
{
    patients.clear();
}

int main()
{
    CMyIndex pool;
    
    pool.addPatient("Tom");
    pool.addPatient("Jane");
    pool.addPatient("Jerry");
    pool.addPatient("Leo");
    pool.addPatient("Leo2");

    std::string last = pool[-1];
    std::string before_the_last = pool[-2];

    cout << last << endl;
    cout << before_the_last << endl;

    if(pool==false){
        cout << "pool is empty" <<endl;
    }
    else{
        cout << "pool is not empty" << endl;
    }

    pool.removeAllPatient();

    if(pool==false){
        cout << "pool is empty" <<endl;
    }
    else{
        cout << "pool is not empty" << endl;
    }

    if(pool==true){
        cout << "pool is not empty" <<endl;
    }
    else{
        cout << "pool is empty" << endl;
    }

    pool.addPatient("Joon");

    if(pool==true){
        cout << "pool is not empty" <<endl;
    }
    else{
        cout << "pool is empty" << endl;
    }

    return 0;
}

/*
 * CMyIndex 의 한계
 * 기본적으로 자료구조에 접근 시 []를 활용하는 경우 자료구조의 max를 벗어날 수 있어서 지양해야함
 * 현재 CMyIndex 클래스 또한 양수든 음수든 절다값이 size보다 큰 경우를 동작을 보장하지 못함
 */
