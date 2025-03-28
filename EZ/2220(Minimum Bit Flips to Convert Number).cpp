#include<iostream>
#include <vector>

class Solution {
public:

    std::vector<bool> convertToBinaryArray(int number) {
        std::vector<bool> res;
        while(number){
            //sstd::cout << number << '\n';
            res.push_back((bool)(number%2));
            number /= 2;
        }

        return res;
    }

    int minBitFlips(int start, int goal) {
        //std::cin >> start >> goal;
        int res = 0;
        std::vector<bool> startArr, goalArr;

        startArr = convertToBinaryArray(start);
        goalArr = convertToBinaryArray(goal);

    for(int i = 0 ; i < startArr.size(); i++){
        std::cout << startArr[i] << ",";
    }
        std::cout << '\n';
    
    for(int i = 0 ; i < goalArr.size(); i++){
        std::cout << goalArr[i] << ",";
    }
      std::cout << '\n';
    

        if (goalArr.size() >= startArr.size())
        {
            for (int i = 0; i < startArr.size(); i++)
            {
                res += (startArr[i] ^ goalArr[i]);
                std::cout << (startArr[i] ^ goalArr[i]) << " == " << startArr[i] << "|" <<  goalArr[i] << "\n";
            }
            for (int i = startArr.size(); i < goalArr.size(); i++){
                res += (goalArr[i] ^ false);
                std::cout << (goalArr[i]) << " == " << 0 << "|" <<  goalArr[i] << '\n';
            }
            
        } else {
            for (int i = 0; i < goalArr.size(); i++)
            {
                res += (startArr[i] ^ goalArr[i]);
                std::cout << (startArr[i] ^ goalArr[i]) << " == " << startArr[i] << "|" <<  goalArr[i] << '\n';
            }
            for (int i = goalArr.size(); i < startArr.size(); i++){
                res += (startArr[i] ^ false);
                std::cout << (goalArr[i]) << " == " << 0 << "|" <<  goalArr[i] << '\n';
            }
        }
        

        return res;
    }
};

int main(){
    Solution S;

    int out = S.minBitFlips(10,7);

    std::cout << "\nres = " << out << "!!!!!\n";

    return 0;
}