class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            std::multiset<long long> bad;
            int oper = 0;
            for(int i =0 ; i < nums.size(); i++){
                if(nums[i] < k) bad.insert(nums[i]);
            }   
    
            std::multiset <long long>::iterator iter = bad.begin();
    
            while (iter != (bad.end())){
    
                if (iter == (--bad.end())) {
                    oper++;
                    break;    
                }
    
                /*
                std::multiset <long long>::iterator iterTest = bad.begin();
                while(iterTest != bad.end())std::cout << *iterTest++ << ',';
    
                std::cout << '\n';
                */
    
                long long operand1 = *iter, operand2 = *(++iter);
    
                if(std::min(operand1,operand2) * 2 + std::max(operand1,operand2) < k){
    
                bad.insert(std::min(operand1,operand2) * 2 + std::max(operand1,operand2));
                }
    
                iter++;
                oper++;
            }
    
            return oper;
    
        }
    };